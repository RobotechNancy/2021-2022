/*
 * MPU6050.h
 *
 *  Created on: Nov 6, 2021
 *      Author: François SULER
 */

#ifndef MPU6050_H_
#define MPU6050_H_

// public includes

#include "stm32l4xx_hal.h"

// public defines

// public macros

// public types

typedef enum {
	FALSE = 0,
	TRUE,
} _bool;

typedef enum {
	MPU6050_DLPF_256Hz = 0,
	MPU6050_DLPF_188Hz,
	MPU6050_DLPF_98Hz,
	MPU6050_DLPF_42Hz,
	MPU6050_DLPF_20Hz,
	MPU6050_DLPF_10Hz,
	MPU6050_DLPF_5Hz
} MPU6050_DLPF_t;

typedef enum {
	MPU6050_EXT_SYNC_DISABLED = 0,
	MPU6050_EXT_SYNC_TEMP,
	MPU6050_EXT_SYNC_GX,
	MPU6050_EXT_SYNC_GY,
	MPU6050_EXT_SYNC_GZ,
	MPU6050_EXT_SYNC_AX,
	MPU6050_EXT_SYNC_AY,
	MPU6050_EXT_SYNC_AZ
} MPU6050_External_Sync_t;

typedef enum {
	MPU6050_GYRO_SENSITIVITY_250 = 0,
	MPU6050_GYRO_SENSITIVITY_500,
	MPU6050_GYRO_SENSITIVITY_1000,
	MPU6050_GYRO_SENSITIVITY_2000
} MPU6050_Gyro_Senstivity_t;

typedef enum {
	MPU6050_INT_ACTIVE_HIGH = 0,
	MPU6050_INT_ACTIVE_LOW
} MPU6050_Interrupt_level_t;

typedef enum {
	MPU6050_INT_PUSH_PULL = 0,
	MPU6050_INT_OPEN_DRAIN,
} MPU6050_Interrupt_Output_Type_t;

typedef enum {
	MPU6050_INT_LATCH_50US_PULSE = 0,
	MPU6050_INT_LATCH_HELD_UNTIL_NOT_CLEARED
} MPU6050_Interrupt_Latch_t;

typedef enum {
	MPU6050_INT_CLEAR_BY_READING_STATUS = 0,
	MPU6050_INT_CLEAR_ON_ANY_READ
} MPU6050_Interrupt_Clear_t;

typedef enum {
	MPU6050_FSYNC_ACTIVE_HIGH = 0,
	MPU6050_FSYNC_ACTIVE_LOW
} MPU6050_FSYNC_level_t;

typedef enum {
	MPU6050_FSYNC_INT_DISABLE = 0,
	MPU6050_FSYNC_INT_ENABLE
} MPU6050_FSYNC_Enable_t;

typedef enum {
	MPU6050_FIFO_OVF_DISABLE = 0,
	MPU6050_FIFO_OVF_ENABLE
} MPU6050_Interrupt_Mask_FIFO_t;

typedef enum {
	MPU6050_MST_INT_DISABLE = 0,
	MPU6050_MST_INT_ENABLE
} MPU6050_Interrupt_Mask_MST_INT_t;

typedef enum {
	MPU6050_DRDY_DISABLE = 0,
	MPU6050_DRDY_ENABLE
} MPU6050_Interrupt_Mask_DRDY_t;

typedef enum {
	MPU6050_Z_FIFO_DISABLE = 0,
	MPU6050_Z_FIFO_ENABLE
} MPU6050_Zaxis_FIFO_Enable_t;

typedef enum {
	MPU6050_CLOCK_INTERNAL_8MHz = 0,
	MPU6050_CLOCK_PLL_X_GYRO,
	MPU6050_CLOCK_PLL_Y_GYRO,
	MPU6050_CLOCK_PLL_Z_GYRO,
	MPU6050_CLOCK_PLL_EXT_32kHz,
	MPU6050_CLOCK_PLL_EXT_19MHz,
	MPU6050_CLOCK_RESERVED,
	MPU6050_CLOCK_STOP
} MPU6050_Clock_Config_t;

typedef struct {
	MPU6050_Interrupt_level_t level;
	MPU6050_Interrupt_Output_Type_t output_type;
	MPU6050_Interrupt_Latch_t latch_en;
	MPU6050_Interrupt_Clear_t clear_type;
	MPU6050_FSYNC_level_t FSYNC_level;
	MPU6050_FSYNC_Enable_t FSYNC_en;
	MPU6050_Interrupt_Mask_FIFO_t Mask_FIFO;
	MPU6050_Interrupt_Mask_MST_INT_t Mask_MST_INT;
	MPU6050_Interrupt_Mask_DRDY_t Mask_DRDY;
} MPU6050_Interrupt_Config_t;

typedef struct {
	uint8_t SampleRateDivider;
	MPU6050_DLPF_t DLPF_Frequency;
	MPU6050_External_Sync_t Ext_Sync_Set;
	MPU6050_Gyro_Senstivity_t Gyro_Sensitivity;
	MPU6050_Zaxis_FIFO_Enable_t Use_FIFO;
	MPU6050_Clock_Config_t Clock_Config;
	MPU6050_Interrupt_Config_t * Interrupt_Config;
} MPU6050_Config_t;

typedef struct {
	I2C_HandleTypeDef * hi2c;
	uint8_t I2C_Addr;
	//GPIO_TypeDef * INT_Port;
	//uint16_t INT_Pin;
	MPU6050_Config_t * Config;
} MPU6050_Descriptor_t;

// public functions

void MPU6050_Init(MPU6050_Descriptor_t * _Descriptor);

void MPU6050_Process(void);

void MPU6050_Interrupt_Routine(void);

_bool MPU6050_NewData(void);

int16_t MPU6050_GetData(void);
int16_t MPU6050_GetData_CF(void);

float MPU6050_GetSampleRate(void);


#endif /* MPU6050_H_ */
