/*
 * servo.h
 *
 *  Created on: May 10, 2022
 *      Author: thibault
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "stm32f3xx_hal.h"

void attendre(int);

void servo1Start();
void servo1Stop();

void servo2Start();
void servo2Stop();

void deplacement_servo_ventouse(int);

void deplacement_servo_courroie(int);

#endif /* INC_SERVO_H_ */
