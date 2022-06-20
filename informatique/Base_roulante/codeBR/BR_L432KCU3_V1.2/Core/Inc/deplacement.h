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

void prepare_deplacement(Trame_Moteur_t* trameMotor);

uint32_t calcul_acceleration(uint32_t a);
uint32_t calcul_deceleration(uint32_t a);


#endif /* INC_DEPLACEMENT_H_ */
