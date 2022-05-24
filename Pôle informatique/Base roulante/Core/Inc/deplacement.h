/*
 * deplacement.h
 *
 *  Created on: 8 mai 2022
 *      Author: lucie
 */

#ifndef INC_DEPLACEMENT_H_
#define INC_DEPLACEMENT_H_

#include "stm32l4xx_hal.h"

void triangle(void);

void calcul_diviseur();

void prepare_deplacement(Trame_Moteur_t* trameMotor);
//int calcul_deplacement(int dir, float vit, float dist);
//void calcul_target(uint32_t distance);
//uint32_t calcul_arc(float angle);
//float calcul_vecteur(float distance);

uint32_t calcul_acceleration(uint32_t a);
uint32_t calcul_deceleration(uint32_t a);

int freq_to_period(Motor_t *motor);
int period_to_freq(Motor_t *motor);

#endif /* INC_DEPLACEMENT_H_ */
