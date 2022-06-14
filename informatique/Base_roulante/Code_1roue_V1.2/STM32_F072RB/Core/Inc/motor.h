/*
 * motor.h
 *
 *  Created on: Jan 21, 2022
 *      Author: lucie
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f0xx_hal.h"

void motor_stop(int s);
void motor_dir(int dir);
void motor_step(int f);




#endif /* INC_MOTOR_H_ */
