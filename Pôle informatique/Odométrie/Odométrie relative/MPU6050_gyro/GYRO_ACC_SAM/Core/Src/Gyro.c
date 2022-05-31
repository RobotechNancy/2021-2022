/*
 * Gyro.c
 *
 *  Created on: May 21, 2022
 *      Author: Samuel
 */

// private includes

#include "MPU6050.h"
#include "Gyro.h"

// private defines

// private macros

// private types

//typedef enum {
//	GYRO_NO_DATA = 0,
//	GYRO_DATA_AVAILABLE
//} Gyro_NewData_t;

typedef enum {
	GYRO_STATE_NOT_INIT = 0,
	GYRO_STATE_INIT,
	GYRO_STATE_CALIBRATION,
	GYRO_STATE_APPLY_CALIBRATION,
	GYRO_STATE_READY
} Gyro_State_t;

typedef struct {
	double accumulator;
	uint16_t counter;
	double offset;
	double datarate;
	double gyrorate;
	double integral;
} Gyro_Data_t;

// private variables

Gyro_Desciptor_t * Descriptor;

Gyro_Data_t Gyro_Data;

Gyro_State_t State = GYRO_STATE_NOT_INIT;

// private functions

void Gyro_Modulo(void)
{
	 while ( Gyro_Data.integral < 0.0f || Gyro_Data.integral > 360.0f ){
		 if(Gyro_Data.integral > 360.0f)
			 Gyro_Data.integral -= 360.0f;
		 else if (Gyro_Data.integral < 0.0f)
			 Gyro_Data.integral += 360.0f;
	 }
}

void Gyro_GetData(void)
{
	 Gyro_Data.gyrorate = MPU6050_GetData_CF() - Gyro_Data.offset;
}

Gyro_NewData_t Gyro_NewData(void)
{
	return (Gyro_NewData_t)MPU6050_NewData();
}

void Gyro_ResetAccumulator(void)
{
	 Gyro_Data.accumulator = 0.0;
	 Gyro_Data.counter = 0;
}

void Gyro_Accumulate(void)
{
	if(Gyro_NewData()==GYRO_DATA_AVAILABLE)
	{
		Gyro_GetData();
		Gyro_Data.accumulator += Gyro_Data.gyrorate;
		Gyro_Data.counter++;
	}
}

void Gyro_SetOffset(void)
{
	Gyro_Data.offset = Gyro_Data.accumulator / Gyro_Data.counter;
}

void Gyro_Estimate(void)
{
	if(Gyro_NewData()==GYRO_DATA_AVAILABLE)
	{
		 Gyro_GetData();
		 Gyro_Data.integral += Gyro_Data.gyrorate / Gyro_Data.datarate;
	}
}

void Gyro_FSM(void)
{
	// actions
	switch(State)
	{
	case GYRO_STATE_NOT_INIT :
		// NOP
		break;

	case GYRO_STATE_INIT :
		Gyro_ResetAccumulator();
		break;

	case GYRO_STATE_CALIBRATION :
		Gyro_Accumulate();
		break;

	case GYRO_STATE_APPLY_CALIBRATION :
		Gyro_SetOffset();
		break;

	case GYRO_STATE_READY:
		Gyro_Estimate();
		if( Descriptor->Config->use_modulo )
			Gyro_Modulo();
		break;

	default :
		break;
	}

	// transitions
	switch(State)
	{
	case GYRO_STATE_NOT_INIT :
		// NOP
		break;

	case GYRO_STATE_INIT :
		if( Descriptor->Config->skip_calibration )
			State = GYRO_STATE_READY;
		else
			State = GYRO_STATE_CALIBRATION;
		break;

	case GYRO_STATE_CALIBRATION :
		if( Gyro_Data.counter >= Descriptor->Config->mean_etimation_samples_number - 1 )
			State = GYRO_STATE_APPLY_CALIBRATION;
		break;

	case GYRO_STATE_APPLY_CALIBRATION :
		State = GYRO_STATE_READY;
		break;

	case GYRO_STATE_READY:
		// NOP
		break;

	default :
		break;
	}
}

// public functions implementations

void Gyro_Init(Gyro_Desciptor_t * _Descriptor)
{
	Descriptor = _Descriptor;
	Gyro_Data.datarate = MPU6050_GetSampleRate();
	Gyro_ResetAccumulator();
	Gyro_SetRot(0);
	State = GYRO_STATE_INIT;
}

void Gyro_Process(void)
{
	Gyro_FSM();
}

void Gyro_Calibrate(void){
	Gyro_ResetAccumulator();
	State = GYRO_STATE_CALIBRATION;
}

bool Gyro_isReady(void)
{
	return State == GYRO_STATE_READY;
}

float Gyro_GetRot(void)
{
	return Gyro_Data.integral;
}

void Gyro_SetRot(float newValue)
{
	 Gyro_Data.integral = newValue;
}

float Gyro_GetCalibrationAdvancement(void)
{
	return (float)(Gyro_Data.counter) * 100 / (float)(Descriptor->Config->mean_etimation_samples_number);
}
