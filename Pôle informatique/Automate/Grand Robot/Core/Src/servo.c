/*
 * servo.c
 *
 *  Created on: May 10, 2022
 *      Author: thibault
 */

#include "servo.h"
#include "actionneurs_define.h"
extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim3;

void servo1Start() {
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
}
void servo1Stop() {
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
}
void servo2Start() {
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
}
void servo2Stop() {
	HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);

}

void deplacement_servo_ventouse(int angle) {
	servo1Start();

	TIM3-> CCR4=ANGLE_VENTOUSE_REFERENCE-angle*PAS_SERVO_VENTOUSE;
	attendre(TEMPS_ACTION_VENTOUSE);
	servo1Stop();
}

void deplacement_servo_courroie(int angle) {
	servo2Start();

	TIM1-> CCR3=ANGLE_COURROIE_REFERENCE-angle*PAS_SERVO_COURROIE;
	attendre(TEMPS_ACTION_COURROIE);
	servo2Stop();
	//pas plus de 140
}


void attendre(int temps){ //temps en ms durant lequel la commande reste active
	HAL_ResumeTick();
	uint32_t start=HAL_GetTick();

	while((HAL_GetTick()-start)<temps) {
		uint32_t sto = HAL_GetTick()-start;
		}
}
