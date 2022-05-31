/*
 * deplacement.c
 *
 *  Created on: 8 mai 2022
 *      Author: lucie
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>

#include "defineActionneur.h"
#include "variableActionneur.h"
#include "deplacementActionneur.h"
#include "motorActionneur.h"

extern Motor_t motor;

void go_position(Position_t pos){
	if (get_deplacement_state() == ARRET){
		if (get_position() != pos){
			reset_steps();
			switch(get_position()){
			case STATUETTE:
				motor.pinDirState = 0;
				motor_dir(&motor);
				set_target(NB_STEPS);
				set_fin(0);
				break;
			case AIMANT:
				motor.pinDirState = 1;
				motor_dir(&motor);
				set_target(NB_STEPS);
				set_fin(0);
				break;
			default:
			break;
			}
		}
		set_next_position(pos);
		motor.diviseur = 40;

	}
}

uint32_t calcul_acceleration(uint32_t a){
    uint32_t indice = 0;
    while (get_arr()[indice] >= a){
        indice++;
    }
    set_length(indice);
	return get_length();
}

uint32_t calcul_deceleration(uint32_t a){
	uint32_t indice = 0;
    while (get_r_arr()[indice] >= a){
        indice++;
    }
    set_length(indice);
	return get_length();
}
