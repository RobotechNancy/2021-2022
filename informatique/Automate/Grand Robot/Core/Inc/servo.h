/*
 * servo.h
 *
 *  Created on: May 10, 2022
 *      Author: thibault
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_

#include "stm32f3xx_hal.h"
#include <stdbool.h>

int pompe_on();
int pompe_off();

uint8_t pompe(bool);

/*
 * @brief implémente un delay pour replacer HAL_DELAY
 * @retval None
 */
void attendre(int);

/*
 * @brief demarre le pin du servo 1
 * @retval None
 */
void servo1Start();

/*
 * @brief eteint le pin du servo 1
 * @retval None
 */
void servo1Stop();

/*
 * @brief demarre le pin du servo 2
 * @retval None
 */
void servo2Start();

/*
 * @brief eteint le pin du servo 2
 * @retval None
 */
void servo2Stop();

/*
 * @brief deplace le servomoteur du bras de la resistance en fonctioin d'un angle entré
 * @param int angle en degré
 * @retval uint8 pour savoir si l'action s'est effectué
 */
int deplacement_servo_ventouse(int);

/*
 * @brief deplace le servomoteur du bras de la resistance en fonctioin d'un angle entré
 * @param int angle en degré
 * @retval uint8 pour savoir si l'action s'est effectué
 */
int deplacement_servo_courroie(int);

#endif /* INC_SERVO_H_ */
