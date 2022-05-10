/*
 * TOF_Types.h
 *
 *  Created on: May 8, 2022
 *      Author: Samuel
 */

#ifndef VL53L0X_PLATFORM_TOF_TYPES_H_
#define VL53L0X_PLATFORM_TOF_TYPES_H_

typedef enum {
	TOF_ABSENT = 0,
	TOF_PRESENT
} TOF_Presence_t;

typedef enum {
	TOF_NOT_READY = 0,
	TOF_READY
} TOF_Readiness_t;

typedef enum {
	TOF_DISABLED = 0,
	TOF_ENABLED
} TOF_Enableness_t;

typedef enum {
	LONG_RANGE = 0, 	/*!< Long range mode */
	HIGH_SPEED, 		/*!< High speed mode */
	HIGH_ACCURACY, 		/*!< High accuracy mode */
} TOF_Ranging_Config_t;

#endif /* VL53L0X_PLATFORM_TOF_TYPES_H_ */
