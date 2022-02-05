/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    motor.c
  * @brief   Fonctions moteur
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  *  Created on: Jan 21, 2022
  *      Author: lucie
  ******************************************************************************
  */


#include "main.h" /*!< Permet d'inclure les initialisations effectuées dans le main */
#include "motor.h" /*!< Fonctions des moteurs */
#include "can.h" /*!< Fonctions du bus CAN */

//Variables
extern CAN_HandleTypeDef hcan;
extern TIM_HandleTypeDef htim1;

//User
extern int target; /*!< Nombre de pas à effectuer, initialiser à -1 pour ne pas faire de pas */
extern int repetitions; /*!< Compte le nombre de pas effectué, jusqu'à atteindre target */

/*
 * @brief Fonction d'interruption de STM
 * Pour le Timer 1, chaque interruption génère une impultion sur la pin 10
 * Et à chaque interruption on incrémente repetition de 1
 * Lorsque le nombres de pas effectué est supérieur ou égal au nombre de pas cible alros on arrête le moteur
 */
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim==&htim1){
		if(repetitions>=target){
			motorStop(0);
		}
		send_one(0x324, repetitions);
		repetitions++;
	}
}

/*
 * @brief Active ou désactive les interruptions donc active ou désactive le moteur
 * @param variable stop, prend 0 ou 1 en valeur pour définir l'état du moteur, sinon l'état est indéfini
 * return 0 moteur à l'arrêt
 * return 1 moteur en marche
 * return -1 état indéfini
 */
int motorStop(int stop){
	int error;
	if (stop==1){
		HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_3);
		error=1;
	}
	else if (stop==0){
		HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_3);
				error=0;
	}
	else{
		error=-1;
	}
	return error;
}

/*
 * @brief Fait tourner le moteur dans une direction
 * @param variable direction, prend 0 ou 1 en valeur pour définir le sens de rotation, sinon le sens est indéfini
 * return 0 moteur dans le sens 1
 * return 1 moteur dans le sens 2
 * return -1 sens indéfini
 */
int motorDirection(int direction){
	int error;
	if (direction==0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
		error = 0;
	}
	else if (direction==1){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
		error = 1;
	}
	else{
		error = -1;
	}
	return error;
}

/*
 * @brief Change la fréquence donc la vitesse de rotation de la roue
 * @param variable frequence
 * return TIM1->ARR
 */
int motorStep(int frequence){
	TIM1->ARR = frequence;
	return TIM1->ARR;
}
