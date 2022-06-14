/*
 * tor.c
 *
 *  Created on: May 10, 2022
 *      Author: thibault
 */

#include "tor.h"
#include "actionneurs_define.h"
#include "main.h"

int pompe_on() {
	HAL_GPIO_WritePin(pompe_GPIO_Port, pompe_Pin, RESET); //modifie la valeur du pin a 0 pour activer la pompe
	return 0;
}

int pompe_off() {
	HAL_GPIO_WritePin(pompe_GPIO_Port, pompe_Pin, SET);  //modifie la valeur du pin a 1 pour activer la pompe
	return 0;
}


void pompe(bool ordre) {
	if (ordre==ON) {
		pompe_on();
	}
	else if (ordre==OFF) {
		pompe_off();
	}
	else {

	}
}
