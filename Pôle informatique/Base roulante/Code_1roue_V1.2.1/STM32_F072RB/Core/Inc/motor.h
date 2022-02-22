/*
 * motor.h
 *
 *  Created on: Jan 21, 2022
 *      Author: lucie
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f0xx_hal.h"

int motorStop(int stop);
int motorDirection(int direction);
int motorStep(int frequence);




#endif /* INC_MOTOR_H_ */
