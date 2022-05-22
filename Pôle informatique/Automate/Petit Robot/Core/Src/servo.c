/*
 * servo.c
 *
 *  Created on: 9 mai 2022
 *      Author: thibault
 */


#include "servo.h"
#include "actionneurs_define.h"
#include "main.h"

extern TIM_HandleTypeDef htim3;
extern ADC_HandleTypeDef hadc1;


void servo3Start() {
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
}
void servo3Stop() {
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
}

void deplacement_servo_resistance(int angle) {
	servo3Start();

	TIM3-> CCR4=ANGLE_RESISTANCE_REFERENCE+angle*PAS_SERVO_RESISTANCE;
	attendre(TEMPS_ACTION_RESISTANCE);
	servo3Stop();
}



int test_resistance() {

	deplacement_servo_resistance(90);

	HAL_ADC_Start(&hadc1); // definit les port et les informations dont STM à besoin
	HAL_ADC_PollForConversion(&hadc1, 300);

	float raw = HAL_ADC_GetValue(&hadc1); //récupère la valeur en bit, valeur comprise entre 0 et 4096
	float vin = raw*(3.3/4096); //passe la valeur récupéré précédemment en  tension
	float resistance_a_tester = vin*RESISTANCE_REF/(RESISTANCE_MAX-vin); // calcul la valeur de la résistance testée grâce à un pont diviseur de tension

	if (resistance_a_tester > 300 && resistance_a_tester < 640){   // en fonction de la valeur obtenue, renvoie différente valeur
		return 0;
	}
	else if (resistance_a_tester > 640 && resistance_a_tester < 1360) {
		return 1;
	}
	else if (resistance_a_tester >3000 && resistance_a_tester < 6400){
		return 2;
	}
	else {
		return -1;
	}

}


void attendre(int temps){ //temps en ms durant lequel la commande reste active
	uint32_t start=HAL_GetTick();

	while((HAL_GetTick()-start)<temps) {
		}
}

int aimant_on() {
	HAL_GPIO_WritePin(aimant_GPIO_Port, aimant_Pin, RESET); //modifie la valeur du pin a 0 pour activer l'aimant
	return 0;
}

int aimant_off() {
	HAL_GPIO_WritePin(aimant_GPIO_Port, aimant_Pin, SET);  // modifie la valeur du pin a 1 pour activer l'aimant
	return 0;
}

void aimant(bool ordre) {
	if (ordre==ON) {
		aimant_on();
	}
	else if(ordre==OFF) {
		aimant_off();
	}
	else {

	}
}
