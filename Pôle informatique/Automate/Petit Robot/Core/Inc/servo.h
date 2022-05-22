/*
 * servo.h
 *
 *  Created on: 9 mai 2022
 *      Author: thibault
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_
#include "stm32f3xx_hal.h"
#include <stdbool.h>

void attendre(int);

void servo3Start();
void servo3Stop();

void deplacement_servo_resistance(int);
int test_resistance();



int aimant_on();
int aimant_off();

void aimant(bool);

#endif /* INC_SERVO_H_ */
