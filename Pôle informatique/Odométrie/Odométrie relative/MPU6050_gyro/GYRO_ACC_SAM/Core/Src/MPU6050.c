/*
 * MPU6050.c
 *
 *  Created on: May 21, 2022
 *      Author: Samuel
 */

// private includes

#include "MPU6050.h"

// private defines

#define MPU6050_ERROR_LIMIT 32568
#define MPU6050_TIMEOUT 1000

#define MPU6050_BASE_SAMPLERATE_DLPF_OFF 8000.0f //8kHz
#define MPU6050_BASE_SAMPLERATE_DLPF_ON  1000.0f //1kHz

// private macros

#define ASSERT_FUNC(func) error = func; if(error!=HAL_OK) return error;

// private types

typedef struct {
	uint8_t raw[2];
	int16_t unified;
	float scaled;
} MPU6050_Data_t;

typedef struct {
	bool int_triggered;
	bool new_data;
	bool FSM_execute;
} MPU6050_Flags_t;

typedef enum {
	MPU6050_STATE_NOT_INIT = 0,
	MPU6050_STATE_INIT,
	MPU6050_STATE_READY,
	MPU6050_STATE_ERROR
} MPU6050_State_t;

typedef enum {
	MPU6050_REG_ST_X = 0x0D,
	MPU6050_REG_ST_Y,
	MPU6050_REG_ST_Z,
	MPU6050_REG_ST_A,

	MPU6050_REG_SMPLRT_DIV = 0x19,
	MPU6050_REG_CONFIG,
	MPU6050_REG_GYRO_CONFIG,
	MPU6050_REG_ACCEL_CONFIG,
	MPU6050_REG_FIFO_EN = 0x23,

	MPU6050_REG_I2C_MST_CTRL,

	MPU6050_REG_I2C_SLV0_ADDR,
	MPU6050_REG_I2C_SLV0_REG,
	MPU6050_REG_I2C_SLV0_CTRL,

	MPU6050_REG_I2C_SLV1_ADDR,
	MPU6050_REG_I2C_SLV1_REG,
	MPU6050_REG_I2C_SLV1_CTRL,

	MPU6050_REG_I2C_SLV2_ADDR,
	MPU6050_REG_I2C_SLV2_REG,
	MPU6050_REG_I2C_SLV2_CTRL,

	MPU6050_REG_I2C_SLV3_ADDR,
	MPU6050_REG_I2C_SLV3_REG,
	MPU6050_REG_I2C_SLV3_CTRL,

	MPU6050_REG_I2C_SLV4_ADDR,
	MPU6050_REG_I2C_SLV4_REG,
	MPU6050_REG_I2C_SLV4_DO,
	MPU6050_REG_I2C_SLV4_CTRL,
	MPU6050_REG_I2C_SLV4_DI,

	MPU6050_REG_I2C_MST_STATUS,


	MPU6050_REG_INT_PIN_CFG,
	MPU6050_REG_INT_ENABLE,
	MPU6050_REG_INT_STATUS = 0x3A,


	MPU6050_REG_A_X_H,
	MPU6050_REG_A_X_L,

	MPU6050_REG_A_Y_H,
	MPU6050_REG_A_Y_L,

	MPU6050_REG_A_Z_H,
	MPU6050_REG_A_Z_L,


	MPU6050_REG_TEMP_H,
	MPU6050_REG_TEMP_L,


	MPU6050_REG_G_X_H,
	MPU6050_REG_G_X_L,

	MPU6050_REG_G_Y_H,
	MPU6050_REG_G_Y_L,

	MPU6050_REG_G_Z_H,
	MPU6050_REG_G_Z_L,


	MPU6050_REG_EXT_SENS_DATA_00,
	MPU6050_REG_EXT_SENS_DATA_01,
	MPU6050_REG_EXT_SENS_DATA_02,
	MPU6050_REG_EXT_SENS_DATA_03,
	MPU6050_REG_EXT_SENS_DATA_04,
	MPU6050_REG_EXT_SENS_DATA_05,
	MPU6050_REG_EXT_SENS_DATA_06,
	MPU6050_REG_EXT_SENS_DATA_07,
	MPU6050_REG_EXT_SENS_DATA_08,
	MPU6050_REG_EXT_SENS_DATA_09,
	MPU6050_REG_EXT_SENS_DATA_10,
	MPU6050_REG_EXT_SENS_DATA_11,
	MPU6050_REG_EXT_SENS_DATA_12,
	MPU6050_REG_EXT_SENS_DATA_13,
	MPU6050_REG_EXT_SENS_DATA_14,
	MPU6050_REG_EXT_SENS_DATA_15,
	MPU6050_REG_EXT_SENS_DATA_16,
	MPU6050_REG_EXT_SENS_DATA_17,
	MPU6050_REG_EXT_SENS_DATA_18,
	MPU6050_REG_EXT_SENS_DATA_19,
	MPU6050_REG_EXT_SENS_DATA_20,
	MPU6050_REG_EXT_SENS_DATA_21,
	MPU6050_REG_EXT_SENS_DATA_22,
	MPU6050_REG_EXT_SENS_DATA_23,


	MPU6050_REG_I2C_SLV0_DO = 0x63,
	MPU6050_REG_I2C_SLV1_DO,
	MPU6050_REG_I2C_SLV2_DO,
	MPU6050_REG_I2C_SLV3_DO,


	MPU6050_REG_I2C_MST_DELAY_CTRL,


	MPU6050_REG_I2C_SIGNAL_PATH_RESET,

	MPU6050_REG_USER_CTRL = 0x6A,

	MPU6050_REG_PWR_MGMT_1,
	MPU6050_REG_PWR_MGMT_2,


	MPU6050_REG_FIFO_CNT_H = 0x72,
	MPU6050_REG_FIFO_CNT_L,

	MPU6050_REG_FIFO_DATA,


	MPU6050_REG_WHO_AM_I

} MPU6050_REG_ADDR_t;

// private variables

MPU6050_Descriptor_t * __Descriptor;
MPU6050_Data_t MPU6050_Data;
MPU6050_Flags_t Flags;
MPU6050_State_t state;
uint32_t error_count = 0;

// private functions

HAL_StatusTypeDef MPU6050_Read_Reg(MPU6050_REG_ADDR_t addr, uint8_t * dest)
{
	return HAL_I2C_Mem_Read(__Descriptor->hi2c, (__Descriptor->I2C_Addr)<<1|0x01, addr, 1, dest, 1, MPU6050_TIMEOUT);
}

HAL_StatusTypeDef MPU6050_Write_Reg(MPU6050_REG_ADDR_t addr, uint8_t value)
{
	return HAL_I2C_Mem_Write(__Descriptor->hi2c, __Descriptor->I2C_Addr<<1, addr, 1, &value, 1, MPU6050_TIMEOUT);
}

HAL_StatusTypeDef MPU6050_Read_Gyro(void)
{
	return HAL_I2C_Mem_Read(__Descriptor->hi2c, (__Descriptor->I2C_Addr)<<1|0x01, MPU6050_REG_G_Z_H, 1, MPU6050_Data.raw, 2, MPU6050_TIMEOUT);
}

HAL_StatusTypeDef MPU6050_Configure(void)
{
	HAL_StatusTypeDef error;
	uint8_t dtw;

	// clock configuration
	dtw = __Descriptor->Config->Clock_Config & 0x07;
	ASSERT_FUNC(MPU6050_Write_Reg(MPU6050_REG_PWR_MGMT_1, dtw))

	// sample rate divider
	dtw = __Descriptor->Config->SampleRateDivider;
	ASSERT_FUNC(MPU6050_Write_Reg(MPU6050_REG_SMPLRT_DIV, dtw))

	//general config
	dtw = __Descriptor->Config->DLPF_Frequency & 0x07;
	dtw |= __Descriptor->Config->Ext_Sync_Set << 3 & 0x38;
	ASSERT_FUNC(MPU6050_Write_Reg(MPU6050_REG_CONFIG, dtw))

	// gyro config
	dtw = __Descriptor->Config->Gyro_Sensitivity << 3 & 0x18;
	ASSERT_FUNC(MPU6050_Write_Reg(MPU6050_REG_GYRO_CONFIG, dtw))

	// FIFO enable
	dtw = __Descriptor->Config->Use_FIFO << 4 & 0x10;
	ASSERT_FUNC(MPU6050_Write_Reg(MPU6050_REG_FIFO_EN, dtw))

	// INT Pin config
	dtw = 0;
	dtw |= __Descriptor->Config->Interrupt_Config->FSYNC_en 		<< 2;
	dtw |= __Descriptor->Config->Interrupt_Config->FSYNC_level 	<< 3;
	dtw |= __Descriptor->Config->Interrupt_Config->clear_type		<< 4;
	dtw |= __Descriptor->Config->Interrupt_Config->latch_en 		<< 5;
	dtw |= __Descriptor->Config->Interrupt_Config->output_type	<< 6;
	dtw |= __Descriptor->Config->Interrupt_Config->level	 		<< 7;
	ASSERT_FUNC(MPU6050_Write_Reg(MPU6050_REG_INT_PIN_CFG, dtw))

	// INT Enable
	dtw = __Descriptor->Config->Interrupt_Config->Mask_DRDY;
	dtw |= __Descriptor->Config->Interrupt_Config->Mask_MST_INT << 3;
	dtw |= __Descriptor->Config->Interrupt_Config->Mask_FIFO << 4;
	return MPU6050_Write_Reg(MPU6050_REG_INT_ENABLE, dtw);
}

void MPU6050_FSM(void)
{
	HAL_StatusTypeDef error;

	switch(state)
	{
	case MPU6050_STATE_NOT_INIT :
		//NOP
		break;
	case MPU6050_STATE_INIT :
		error = MPU6050_Configure();
		error_count = 0;
		break;
	case MPU6050_STATE_READY :
		if(Flags.int_triggered)
		{
			error = MPU6050_Read_Gyro();

			if(error!=HAL_OK) error_count++;

			Flags.new_data = TRUE;

			Flags.int_triggered = FALSE;
		}
		break;
	case MPU6050_STATE_ERROR :
		//NOP
		break;
	default :
		//NOP
		break;
	}

	switch(state)
	{
	case MPU6050_STATE_NOT_INIT :
		//NOP
		break;
	case MPU6050_STATE_INIT :
		if(error==HAL_OK)
			state = MPU6050_STATE_READY;
		else
			state = MPU6050_STATE_ERROR;
		break;
	case MPU6050_STATE_READY :
		if(error_count>MPU6050_ERROR_LIMIT)
			state = MPU6050_STATE_ERROR;
		break;
	case MPU6050_STATE_ERROR :
		//NOP
		break;
	default :
		//NOP
		break;
	}
}


// public functions implementations

void MPU6050_Init(MPU6050_Descriptor_t * _Descriptor)
{
	Flags.int_triggered = 0;
	Flags.new_data = 0;

	__Descriptor = _Descriptor;

	state = MPU6050_STATE_INIT;
}

void MPU6050_Process(void)
{
	MPU6050_FSM();
}

void MPU6050_Interrupt_Routine(void)
{
	Flags.int_triggered = TRUE;
}

bool MPU6050_NewData(void)
{
	return Flags.new_data;
}

float MPU6050_GetData(void)
{
	float LSB_Scale;
	MPU6050_Data.unified = (int16_t)( (MPU6050_Data.raw[0] << 8) | MPU6050_Data.raw[1]);
	switch(__Descriptor->Config->Gyro_Sensitivity)
	{
	case MPU6050_GYRO_SENSITIVITY_250:
		LSB_Scale = 131.0f;
		break;
	case MPU6050_GYRO_SENSITIVITY_500:
		LSB_Scale = 131.0f;
		break;
	case MPU6050_GYRO_SENSITIVITY_1000:
		LSB_Scale = 131.0f;
		break;
	case MPU6050_GYRO_SENSITIVITY_2000:
		LSB_Scale = 131.0f;
		break;
	default :
		LSB_Scale = 131.0f;
		break;
	}
	MPU6050_Data.scaled = (float)(MPU6050_Data.unified) / LSB_Scale;
	return MPU6050_Data.scaled;
}

float MPU6050_GetData_CF(void)
{
	Flags.new_data = FALSE;
	return MPU6050_GetData();
}

float MPU6050_GetSampleRate(void)
{
	float SRD = (float)(__Descriptor->Config->SampleRateDivider);

	float GOR;

	if(__Descriptor->Config->DLPF_Frequency == MPU6050_DLPF_256Hz)
		GOR = MPU6050_BASE_SAMPLERATE_DLPF_OFF;
	else
		GOR = MPU6050_BASE_SAMPLERATE_DLPF_ON;

	return GOR/(1+SRD);
}
