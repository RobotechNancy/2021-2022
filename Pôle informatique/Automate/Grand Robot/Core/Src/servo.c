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
extern TIM_HandleTypeDef htim6;

/*
 * @brief démarre le servomoteur (l'axe est éteint et relaché par défaut)
 * @retval None
 */
void servo1Start() {
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
}

/*
 * @brief éteint le servomoteur
 * @retval None
 */
void servo1Stop() {
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
}

/*
 * @brief démarre le servomoteur (l'axe est éteint et relaché par défaut)
 * @retval None
 */
void servo2Start() {
	HAL_TIMEx_PWMN_Start(&htim1, TIM_CHANNEL_3);
}

/*
 * @brief éteint le servomoteur
 * @retval None
 */
void servo2Stop() {
	HAL_TIMEx_PWMN_Stop(&htim1, TIM_CHANNEL_3);

}

/*
 * @brief deplace le servo moteur à l'angle indiqué
 * @param angle en entier et en degré que l'ont veut déplacer le servomoteur
 * @retval renvoie un entier 1 pour valider le deplacement du  servomoteur
 */
int deplacement_servo_ventouse(int angle) {
	servo1Start();

	TIM3-> CCR4=ANGLE_VENTOUSE_REFERENCE-angle*PAS_SERVO_VENTOUSE;
	attendre(TEMPS_ACTION_VENTOUSE);
	servo1Stop();
	return 1;
}

/*
 * @brief deplace le servo moteur à l'angle indiqué
 * @param angle en entier et en degré que l'ont veut déplacer le servomoteur
 * @retval renvoie un entier 1 pour valider le deplacement du  servomoteur
 */
int deplacement_servo_courroie(int angle) {
	servo2Start();

	TIM1-> CCR3=ANGLE_COURROIE_REFERENCE-angle*PAS_SERVO_COURROIE;
	attendre(TEMPS_ACTION_COURROIE);
	servo2Stop();
	return 1;
}

/*
 * @brief implémente un delay sans utiliser la fonctione HAL_DELAY de stm qu'il ne faut pas utiliser
 * @retval None
 */
void attendre(int temps){ //temps en ms durant lequel la commande reste active
	HAL_TIM_Base_Start(&htim6);
	uint32_t start = __HAL_TIM_GET_COUNTER(&htim6);
	//uint32_t start=HAL_GetTick();

	while((__HAL_TIM_GET_COUNTER(&htim6)-start)<temps) {
	//	while((HAL_GetTick()-start)<temps) {
		}
}

/*
 * @brief active la pompe
 * @retval 0 lorsque l'action est terminée et que la pompe est activé
 */
int pompe_on() {
	HAL_GPIO_WritePin(pompe_GPIO_Port, pompe_Pin, RESET); //modifie la valeur du pin a 0 pour activer la pompe
	return 0;
}

/*
 * @brief désactive la pompe
 * @retval 0 lorsque l'action est terminée et que la pompe est désactivé
 */
int pompe_off() {
	HAL_GPIO_WritePin(pompe_GPIO_Port, pompe_Pin, SET);  //modifie la valeur du pin a 1 pour activer la pompe
	return 0;
}

/*
 * @brief regroupe les 2 fonctione précedente pour activer/désactiver la pompe
 * @param bool 1 allume la pompe et 0 éteint la pompe
 * @retval bool 0 si la pompe à bien été eteint, 1 si la pompe à bien été allumé
 */
uint8_t pompe(bool ordre) {
	if (ordre==ON) {
		pompe_on();
		return 1;
	}
	else if (ordre==OFF) {
		pompe_off();
		return 0;
	}
	else {

	}
}

