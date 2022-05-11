/*
 * TOF.c
 *
 *  Created on: May 7, 2022
 *      Author: Samuel
 */

#include "TOF.h"


#define TOF_ASSERT(func) status = func; if(status) return status;
#define TOF_ASSERT_BREAK(func) status = func; if(status) break;
#define TOF_DEV TOF_Devices[unit]
#define TOF_PDEV &(TOF_Devices[unit])

extern VL53L0X_Dev_t TOF_Devices[TOF_UNIT_COUNT];

void TOF_XSHUT_Write(TOF_Units_t unit, GPIO_PinState state)
{
	HAL_GPIO_WritePin(TOF_DEV.XSHUT_Port, TOF_DEV.XSHUT_Pin, state);
}

TOF_Status_t TOF_Init_I2C_Adresses(uint8_t *detectedDevices)
{
	VL53L0X_Dev_t *Dev;
	TOF_Status_t status;

	uint16_t Id;
	uint8_t FinalAddress;

	TOF_Units_t unit;

	uint8_t deviceCount = 0;

	// Shutdown every units
	for(unit=0;unit<TOF_UNIT_COUNT;unit++)
		TOF_XSHUT_Write(unit, TOF_XSHUT_RESET);

	for(unit=0;unit<TOF_UNIT_COUNT;unit++)
	{
		Dev = &(TOF_Devices[unit]);
		Dev->I2cDevAddr = TOF_BASE_I2C_ADDRESS;
		Dev->Present = TOF_ABSENT;
		FinalAddress = TOF_BASE_I2C_ADDRESS + (unit+1)*2;

		// Wake up one unit
		TOF_XSHUT_Write(unit, TOF_XSHUT_SET);

		/* Set I2C standard mode (400 KHz) before doing the first register access */
		if (status == VL53L0X_ERROR_NONE) status = VL53L0X_WrByte(Dev, 0x88, 0x00);

		do{

			// Try to get the model ID of the device
			TOF_ASSERT_BREAK(VL53L0X_RdWord(Dev, VL53L0X_REG_IDENTIFICATION_MODEL_ID, &Id))

			// The device is a VL53L0X
			if(Id==TOF_BASE_ID)
			{
				// Set the new address
				TOF_ASSERT_BREAK(VL53L0X_SetDeviceAddress(Dev,FinalAddress))

				// change the address of the device to the new one
				Dev->I2cDevAddr = FinalAddress;

				// try to get the model id to verify the address change
				TOF_ASSERT_BREAK(VL53L0X_RdWord(Dev, VL53L0X_REG_IDENTIFICATION_MODEL_ID, &Id))

				// try to initialize the device data model
				status = VL53L0X_DataInit(Dev);
				if(status) 	break;

				Dev->Present = TOF_PRESENT;
				deviceCount++;
			}

		} while(0); // while loop to be able to exit with a simple break command. (no repetitions, just a coding trick)

		// if there is a fail, shutdown the sensor to be sure
		if(status) TOF_XSHUT_Write(unit, TOF_XSHUT_RESET);

	}

	for(unit=0;unit<TOF_UNIT_COUNT;unit++)
		TOF_XSHUT_Write(unit, TOF_XSHUT_SET);

	*detectedDevices = deviceCount;

	return status;
}

TOF_Status_t TOF_Init_Item(TOF_Units_t unit)
{
	VL53L0X_Dev_t *Dev = &(TOF_Devices[unit]);
	TOF_Status_t status;

    uint8_t VhvSettings;
    uint8_t PhaseCal;
    uint32_t refSpadCount;
	uint8_t isApertureSpads;
	FixPoint1616_t signalLimit = (FixPoint1616_t)(0.25*65536);
	FixPoint1616_t sigmaLimit = (FixPoint1616_t)(18*65536);
	uint32_t timingBudget = 33000;
	uint8_t preRangeVcselPeriod = 14;
	uint8_t finalRangeVcselPeriod = 10;

	TOF_ASSERT(VL53L0X_DataInit(Dev))
	TOF_ASSERT(VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal))
	TOF_ASSERT(VL53L0X_PerformRefSpadManagement(Dev, &refSpadCount, &isApertureSpads))
	TOF_ASSERT(VL53L0X_SetDeviceMode(Dev, VL53L0X_DEVICEMODE_SINGLE_RANGING))
	TOF_ASSERT(VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, 1))
	TOF_ASSERT(VL53L0X_SetLimitCheckEnable(Dev, VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, 1))

	switch(TOF_RANGING_MODE) {
	case LONG_RANGE:
		signalLimit = (FixPoint1616_t)(0.1*65536);
		sigmaLimit = (FixPoint1616_t)(60*65536);
		timingBudget = 33000;
		preRangeVcselPeriod = 18;
		finalRangeVcselPeriod = 14;
		break;
	case HIGH_ACCURACY:
		signalLimit = (FixPoint1616_t)(0.25*65536);
		sigmaLimit = (FixPoint1616_t)(18*65536);
		timingBudget = 200000;
		preRangeVcselPeriod = 14;
		finalRangeVcselPeriod = 10;
		break;
	case HIGH_SPEED:
		signalLimit = (FixPoint1616_t)(0.25*65536);
		sigmaLimit = (FixPoint1616_t)(32*65536);
		timingBudget = 20000;
		preRangeVcselPeriod = 14;
		finalRangeVcselPeriod = 10;
		break;
	default:
		return TOF_STATUS_CONFIG_UNKNOWN_RANGING_MODE;
	}
	status = TOF_STATUS_SUCESS;

	TOF_ASSERT(VL53L0X_SetLimitCheckValue(Dev,  VL53L0X_CHECKENABLE_SIGNAL_RATE_FINAL_RANGE, signalLimit))
	TOF_ASSERT(VL53L0X_SetLimitCheckValue(Dev,  VL53L0X_CHECKENABLE_SIGMA_FINAL_RANGE, sigmaLimit))
	TOF_ASSERT(VL53L0X_SetMeasurementTimingBudgetMicroSeconds(Dev,  timingBudget))
	TOF_ASSERT(VL53L0X_SetVcselPulsePeriod(Dev,  VL53L0X_VCSEL_PERIOD_PRE_RANGE, preRangeVcselPeriod))
	TOF_ASSERT(VL53L0X_SetVcselPulsePeriod(Dev,  VL53L0X_VCSEL_PERIOD_FINAL_RANGE, finalRangeVcselPeriod))
	TOF_ASSERT(VL53L0X_PerformRefCalibration(Dev, &VhvSettings, &PhaseCal))

	Dev->LeakyFirst = 1;

	return status;
}

/*
 * Initialize all the TOFs sensors
 * @param None
 * @return TOF_Status_t error_code
 */
TOF_Status_t TOF_Init(void)
{
	TOF_Status_t status;
	TOF_Units_t unit;
	uint8_t devicesDetected;

	TOF_ASSERT(TOF_Init_I2C_Adresses(&devicesDetected))

	if(devicesDetected<TOF_UNIT_COUNT) return TOF_STATUS_SENSORS_MISSING;

	for (unit = 0; unit<TOF_UNIT_COUNT; unit++)
	{
		TOF_ASSERT(TOF_Init_Item(unit))
	}

	return status;
}

/*
 * Initialize all the TOFs sensors
 * @param TOF_Units_t unit : unit selected (see enum names)
 * @param uint16_t max_retries : maximum retries for the measure
 * @param uint16_t *range_milimeters : pointer to the range variable
 * @param uint8_t *range_status : pointer to the status range variable
 *										0 : unknown error
 *										1 : good measure
 *										2 : out of range
 *										3 : minimal value
 *										5 : communication interrupted
 * @return TOF_Status_t error_code
 */
TOF_Status_t TOF_Get_Range(TOF_Units_t unit, uint16_t max_retries, uint16_t *range_milimeters, uint8_t *range_status)
{
	TOF_Status_t status;
	VL53L0X_RangingMeasurementData_t data;
	uint16_t retries;

	for(retries=0; retries<max_retries; retries++)
	{
		TOF_ASSERT(VL53L0X_PerformSingleRangingMeasurement(TOF_PDEV, &data))
		if(data.RangeStatus==1) break;
	}

	*range_milimeters = data.RangeMilliMeter;
	*range_status = data.RangeStatus;

	return status;
}
