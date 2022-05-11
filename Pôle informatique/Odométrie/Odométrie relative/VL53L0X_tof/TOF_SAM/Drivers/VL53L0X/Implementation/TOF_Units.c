/*
 * TOF_Units.c
 *
 *  Created on: May 8, 2022
 *      Author: Samuel
 */

#include "../Platform/TOF.h"
#include "TOF_Units.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

VL53L0X_Dev_t TOF_Devices[] = {
		{
				.Id = TOF_UNIT_0,
				.I2cHandle = &hi2c1,
				.XSHUT_Port = TOF0_XSHUT_GPIO_Port,
				.XSHUT_Pin = TOF0_XSHUT_Pin
		}
};


