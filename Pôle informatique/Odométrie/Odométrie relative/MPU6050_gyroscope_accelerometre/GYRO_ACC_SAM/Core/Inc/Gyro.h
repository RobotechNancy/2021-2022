/*
 * Gyro.h
 *
 *  Created on: Nov 9, 2021
 *      Author: François SULER
 */

#ifndef GYRO_H_
#define GYRO_H_

// public includes

// public defines

// public macros

// public types

typedef enum {
	GYRO_NO_MODULO = 0,
	GYRO_MODULO_360
} Gyro_Modulo_t;

typedef enum {
	GYRO_CALIBRATION_AT_STARTUP = 0,
	GYRO_SKIP_CALIBRATION
} Gyro_Calibration_t;

typedef struct {
	Gyro_Modulo_t use_modulo;
	uint16_t mean_etimation_samples_number;
	Gyro_Calibration_t skip_calibration;
	float offset;
	float scaler;
} Gyro_Config_t;

typedef struct {
	Gyro_Config_t * Config;
} Gyro_Desciptor_t;

// public functions

void Gyro_Init(Gyro_Desciptor_t * _Descriptor);

void Gyro_Process(void);

void Gyro_Calibrate(void);
_bool Gyro_isReady(void);

float Gyro_GetRot(void);
void Gyro_SetRot(float newValue);

float Gyro_GetCalibrationAdvancement(void);

#endif /* GYRO_H_ */
