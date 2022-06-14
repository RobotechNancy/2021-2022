/*
 * servo.c
 *
 *  Created on: 9 mai 2022
 *      Author: thibault rey  thibault.rey6@etu.univ-lorraine.fr
 */


#include "servo.h"
#include "actionneurs_define.h"
#include "main.h"

extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim6;
extern ADC_HandleTypeDef hadc1;

/*
 * @brief démarre le servomoteur (l'axe est éteint et relaché par défaut)
 * @retval None
 */
void servo3Start() {
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
}
/*
 * @brief éteint le servomoteur
 * @retval None
 */
void servo3Stop() {
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_4);
}

/*
 * @brief deplace le servo moteur à l'angle indiqué
 * @param angle en entier et en degré que l'ont veut déplacer le servomoteur
 * @retval renvoie un entier 1 pour valider le deplacement du  servomoteur
 */
uint8_t deplacement_servo_resistance(int angle) {


	TIM3-> CCR4=ANGLE_RESISTANCE_REFERENCE+angle*PAS_SERVO_RESISTANCE;
	servo3Start();
	attendre(TEMPS_ACTION_RESISTANCE);
	servo3Stop();
	return 1;
}

/*
 * @brief renvoie la valeur de la resistance
 * @retval enum representant la couleur de l'équipe en fonctione de la valeur de la resistance
 */
RESISTANCE_VALEUR test_resistance() {

	HAL_ADC_Start(&hadc1); // definit les port et les informations dont STM à besoin
	HAL_ADC_PollForConversion(&hadc1, TIMEOUT_HADC);

	float raw = HAL_ADC_GetValue(&hadc1); //récupère la valeur en bit, valeur comprise entre 0 et 4096
	float vin = raw*(VIN_TENSION/VIN_DIVISEUR); //passe la valeur récupéré précédemment en  tension
	float resistance_a_tester = vin*RESISTANCE_REF/(RESISTANCE_MAX-vin); // calcul la valeur de la résistance testée grâce à un pont diviseur de tension

	if (resistance_a_tester > RESISTANCE_JAUNE_MIN && resistance_a_tester < RESISTANCE_JAUNE_MAX){   //renvoie une énum qui est soit JAUNE,VIOLET ou INTERDIT en fonction de la valeur de la resistance mesurée
		return JAUNE;
	}
	else if (resistance_a_tester > RESISTANCE_VIOLET_MIN && resistance_a_tester < RESISTANCE_VIOLET_MAX) {
		return VIOLET;
	}
	else if (resistance_a_tester >RESISTANCE_INTERDIT_MIN && resistance_a_tester < RESISTANCE_INTERDIT_MAX){
		return INTERDIT;
	}
	else {
		return ERREUR;
	}

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
 * @brief active l'électroaimant
 * @retval 0 lorsque l'action est terminée et que l'aimant est activé
 */
int aimant_on() {
	HAL_GPIO_WritePin(aimant_GPIO_Port, aimant_Pin, SET);  // modifie la valeur du pin a 1 pour activer l'aimant
	return 1;
}

/*
 * @brief désactive l'électroaimant
 * @retval 0 lorsque l'action est terminée et que l'aimant est désactivé
 */
int aimant_off() {
	HAL_GPIO_WritePin(aimant_GPIO_Port, aimant_Pin, RESET); //modifie la valeur du pin a 0 pour désactiver l'aimant
	return 0;
}


/*
 * @brief regroupe les 2 fonctione précedente pour activer/désactiver l'aimant
 * @param bool 1 allume l'aimant et 0 éteint l'aimant
 * @retval bool 0 si l'aimant à bien été eteint, 1 si l'aimant à bien été allumé
 */
uint8_t aimant(bool ordre) {
	if (ordre==1) {
		aimant_on();
		return 1;
	}
	else if (ordre==0) {
		aimant_off();
		return 0;
	}
	else {
		return 2;
	}
}
