/*
 * motor.c
 *
 *  Created on: May 2, 2022
 *      Author: lucie
 */


//#include <stdio.h>
//#include <string.h>
#include <stdbool.h>
//#define _USE_MATH_DEFINES // for C
//#include <math.h>

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

//Fonctions
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
			send(CAN_ADDR_RASPBERRY, REP_AVANCE, 1, 1, true, 1, get_id_msg());
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


void start_generate(void){
    HAL_TIM_OC_Start(&htim1, TIM_CHANNEL_1);
    HAL_TIM_Base_Start_DMA(&htim1, (uint32_t *)&(get_arr()[0]), get_length());
    __HAL_TIM_ENABLE_IT(&htim1, TIM_IT_UPDATE);
    set_deplacement_state(ACCELERATION);
}

void stop(void){
	set_target(calcul_deceleration(get_tim_arr()));
	set_length(calcul_deceleration(get_tim_arr()));
	uint32_t offsetAddr = LENGTH_ARR_MAX - (get_length()-1);
	HAL_TIM_Base_Stop_DMA(&htim1);
	HAL_TIM_Base_Start_DMA(&htim1, (uint32_t *)&(get_r_arr()[offsetAddr]), (get_length()-1));
	reset_steps();
	set_deplacement_state(DECELERATION);
}

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
	send(CAN_ADDR_RASPBERRY, REP_AVANCE, 1, 1, true, 1, get_id_msg());
}

int avance(Motor_t *motor){
	int err;
	if(motor->diviseur==0){
		motor->pinStepState = RESET;
		err = 0;
	}
	else{
	    motor->cnt++;
	    motor->cnt %= motor->diviseur;
	    motor->pinStepState = motor->cnt == 0;
	    err = 1;
	}
    return err;
}

void motor_step(Motor_t *motor){
    HAL_GPIO_WritePin(motor->PIN_STEP_TYPE, motor->PIN_STEP, motor->pinStepState);
}

void motor_dir(Motor_t *motor){
    HAL_GPIO_WritePin(motor->PIN_DIR_TYPE, motor->PIN_DIR, motor->pinDirState);
}

void motor_en(GPIO_PinState state){
    HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, state);
}

void motor_micro_step(GPIO_PinState MS1state, GPIO_PinState MS2state){
    HAL_GPIO_WritePin(MS1_GPIO_Port, MS1_Pin, MS1state);
    HAL_GPIO_WritePin(MS2_GPIO_Port, MS2_Pin, MS2state);
}
