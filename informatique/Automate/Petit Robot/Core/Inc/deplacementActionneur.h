/*
 * deplacement.h
 *
 *  Created on: 8 mai 2022
 *      Author: lucie
 */

#ifndef INC_DEPLACEMENTACTIONNEUR_H_
#define INC_DEPLACEMENTACTIONNEUR_H_

#include "stm32f3xx_hal.h"

void go_position(Position_t pos);
int calcul_trajet(int dir, float vit, float dist);
uint32_t calcul_nb_step(float distance);
float calcul_arc(float angle);
float calcul_vecteur(float distance);

uint32_t calcul_acceleration(uint32_t a);
uint32_t calcul_deceleration(uint32_t a);

int freq_to_period(Motor_t *motor);
int period_to_freq(Motor_t *motor);

#endif /* INC_DEPLACEMENTACTIONNEUR_H_ */
