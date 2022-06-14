/*
 * motor.h
 *
 *  Created on: Jan 21, 2022
 *      Author: lucie
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32f0xx_hal.h"

void stop(int s);
void change_dir(int dir);
void change_step(int f);




#endif /* INC_MOTOR_H_ */
