/*
 * motor.c
 *
 *  Created on: May 2, 2022
 *      Author: lucie
 *
 *  Fichiers hardware
 *  Gère les timers, DMA et état des pins
 *
 *  Si code fonction 2, enregistre le nombre de pas qui auront été effectués à la fin de la décélération (stepSaved)
 *  Renvoie une trameMoteur avec stepSaved
 *
 */


#include <stdbool.h>

#include "main.h"
#include "defineMotor.h"
#include "variable.h"
#include "deplacement.h"
#include "motor.h"
#include "can.h"

//Variables
extern TIM_HandleTypeDef htim1;

extern Motor_t motor1;
extern Motor_t motor2;
extern Motor_t motor3;
extern Trame_Moteur_t trameSaved;

//Fonctions
/*
 * @brief fonction interruption
 * @param condition htim==&htimX, où X est le numéro du timer utilisé
 * on avance d'un step informatiquement puis physiquement
 * fonction STM sans return
 * pour voir dans quelle phase on se trouve (arrêt, accélération, maintient ou décélération) on se réfère à la variable deplacementState
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if (htim==&htim1){ //condition d'interruption du timer X
//		motor_step puis avance ou avance puis motor_step
		count_steps();
		avance(&motor1);
		avance(&motor2);
		avance(&motor3);
		motor_step(&motor1);
		motor_step(&motor2);
		motor_step(&motor3);
		uint8_t data[1];
		if (get_steps() == get_length()){
			set_deplacement_state(MAINTIENT);
		}
		if(get_steps_left() <= 0)
		{
			HAL_TIM_Base_Stop_DMA(&htim1);
			HAL_TIM_OC_Stop(&htim1, TIM_CHANNEL_1);

			motor1.pinStepState = RESET;
			motor2.pinStepState = RESET;
			motor3.pinStepState = RESET;
			motor_step(&motor1);
			motor_step(&motor2);
			motor_step(&motor3);
		    motor1.cnt = 0;
		    motor2.cnt = 0;
		    motor3.cnt = 0;

			set_deplacement_state(ARRET);
			data[0] = 1;
			send(CAN_ADDR_RASPBERRY, REP_AVANCE, data, 1, true, 1, get_id_msg());
		}
		else if(get_target() < get_length() * 2)
		{
			if(get_steps() == get_steps_left())
			{
				uint32_t offsetAddr = LENGTH_ARR_MAX - (get_steps_left()-1);
				HAL_TIM_Base_Stop_DMA(&htim1);
				HAL_TIM_Base_Start_DMA(&htim1, (uint32_t *)&(get_r_arr()[offsetAddr]), get_steps_left()-1);
				set_deplacement_state(DECELERATION);
			}
		}
		else
		{
			if (get_length() == get_steps_left())
			{
				uint32_t offsetAddr = LENGTH_ARR_MAX - (get_length()-1);
				HAL_TIM_Base_Stop_DMA(&htim1);
				HAL_TIM_Base_Start_DMA(&htim1, (uint32_t *)&(get_r_arr()[offsetAddr]), get_length()-1);
				set_deplacement_state(DECELERATION);
			}
		}
	}
}

/*
 * @brief démarre les interruptions et le DMA (accélère)
 * @param None
 * @retval None
 */
void start_generate(void){
    HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_DMA(&htim1, (uint32_t *)&(get_arr()[0]), get_length());
    __HAL_TIM_ENABLE_IT(&htim1, TIM_IT_UPDATE);
    set_deplacement_state(ACCELERATION);
}

/*
 * @brief s'arrête en décélérant, enregistre le nombre de pas qui aura été effectué une fois le robot arrêté
 * @param None
 * @retval None
 */
void stop(void){
	set_step_saved(get_steps() + (LENGTH_ARR_MAX - (get_length()-1)));
	Trame_Moteur_t trameSaved;
	trameSaved.fields.nb_steps = get_step_saved();
	trameSaved.fields.div0 = motor1.diviseur;
	trameSaved.fields.div1 = motor2.diviseur;
	trameSaved.fields.div2 = motor3.diviseur;
	trameSaved.fields.dir0 = motor1.pinDirState;
	trameSaved.fields.dir1 = motor2.pinDirState;
	trameSaved.fields.dir2 = motor3.pinDirState;
	send(CAN_ADDR_RASPBERRY, REP_AVANCE, trameSaved.raw_data, 8, true, 8, 50);
	set_target(calcul_deceleration(get_tim_arr()));
	set_length(calcul_deceleration(get_tim_arr()));
	uint32_t offsetAddr = LENGTH_ARR_MAX - (get_length()-1);
	HAL_TIM_Base_Stop_DMA(&htim1);
	HAL_TIM_Base_Start_DMA(&htim1, (uint32_t *)&(get_r_arr()[offsetAddr]), (get_length()-1));
	reset_steps();
	set_deplacement_state(DECELERATION);
}

/*
 * @brief s'arrête net sans décélérer
 * @param None
 * @retval None
 */
void emergency_stop(void){
	HAL_TIM_Base_Stop_DMA(&htim1);
	HAL_TIM_OC_Stop(&htim1, TIM_CHANNEL_1);
	motor1.pinStepState = RESET;
	motor2.pinStepState = RESET;
	motor3.pinStepState = RESET;
	motor_step(&motor1);
	motor_step(&motor2);
	motor_step(&motor3);
    motor1.cnt = 0;
    motor2.cnt = 0;
    motor3.cnt = 0;
	set_deplacement_state(ARRET);
	uint8_t data[1];
	data[0] = 0;
	send(CAN_ADDR_RASPBERRY, REP_AVANCE, data, 1, true, 1, get_id_msg());
}

/*
 * @brief incrémente le compteur du moteur
 * @param &motor adresse du motor
 * @retval ARRET_MOTOR le moteur est à l'arrêt
 * @retval MARCHE_MOTOR le moteur peut avancer
 */
Motor_State_t avance(Motor_t *motor){
	Motor_State_t CR;
	if(motor->diviseur==0){
		motor->pinStepState = RESET;
		CR = ARRET_MOTOR;
	}
	else{
	    motor->cnt++;
	    motor->cnt %= motor->diviseur;
	    motor->pinStepState = motor->cnt == 0;
	    CR = MARCHE_MOTOR;
	}
    return CR;
}

/*
 * @brief ecris sur la pin step du motor
 * @param &motor adresse du motor
 * @retval None
 */
void motor_step(Motor_t *motor){
    HAL_GPIO_WritePin(motor->PIN_STEP_TYPE, motor->PIN_STEP, motor->pinStepState);
}

/*
 * @brief ecris sur la pin dir du motor
 * @param &motor adresse du motor
 * @retval None
 */
void motor_dir(Motor_t *motor){
    HAL_GPIO_WritePin(motor->PIN_DIR_TYPE, motor->PIN_DIR, motor->pinDirState);
}


/*
 * @brief écris sur la pin enable de chaque motor
 * @param SET moteurs non clampés
 * @param RESET moteurs clampés
 * @retval None
 */
void motor_en(GPIO_PinState state){
    HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, state);
}

/*
 * @brief configure la taille des steps (peut changer selon le driver utilisé, paramètres pour le TMC_2208)
 * @param RESET, RESET 8 microsteps
 * @param RESET, SET 4 microsteps (quarter speed)
 * @param SET, RESET 2 microsteps (half speed)
 * @param SET, SET 16 microsteps
 * @retval None
 */
void motor_micro_step(GPIO_PinState MS1state, GPIO_PinState MS2state){
    HAL_GPIO_WritePin(MS1_GPIO_Port, MS1_Pin, MS1state);
    HAL_GPIO_WritePin(MS2_GPIO_Port, MS2_Pin, MS2state);
}
