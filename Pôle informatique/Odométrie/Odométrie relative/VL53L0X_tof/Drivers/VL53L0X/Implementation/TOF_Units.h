/*
 * TOF_Units.h
 *
 *  Created on: May 8, 2022
 *      Author: Samuel
 */

#ifndef IMPLEMENTATION_TOF_UNITS_H_
#define IMPLEMENTATION_TOF_UNITS_H_

#include "../Platform/TOF_Types.h"

// Manufacturer I2C adress
#define TOF_BASE_I2C_ADDRESS 0x52

// Manufacturer Model ID
#define TOF_BASE_ID 0xEEAA

// Polarity of XSHUT pin
#define TOF_XSHUT_SET 	GPIO_PIN_SET
#define TOF_XSHUT_RESET GPIO_PIN_RESET

// Ranging mode (see modes in TOF_Types.h)
#define TOF_RANGING_MODE HIGH_ACCURACY

// Lists of TOF Units
// Names are completely free
typedef enum {
	TOF_UNIT_0 = 0,

	TOF_UNIT_COUNT // Let this enum value !!!! Mandatory for the driver operations
} TOF_Units_t;

#endif /* IMPLEMENTATION_TOF_UNITS_H_ */
