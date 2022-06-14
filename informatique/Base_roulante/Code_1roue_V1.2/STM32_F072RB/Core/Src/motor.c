/*
 * motor.c
 *
 *  Created on: Jan 21, 2022
 *      Author: lucie
 */


#include "motor.h"
#include "can.h"

//Variables
extern CAN_HandleTypeDef hcan;
extern TIM_HandleTypeDef htim1;

//User
extern int target;
extern int repetitions;

void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim==&htim1){
		if(repetitions>=target){
			motor_stop(0);
		}
		send_one(0x324, repetitions);
		repetitions++;
	}
}

void motor_stop(int s){
	if (s==1){
		HAL_TIM_PWM_Start_IT(&htim1, TIM_CHANNEL_3);
		send_one(0x324, 0xAA);
	}
	else{
		HAL_TIM_PWM_Stop_IT(&htim1, TIM_CHANNEL_3);
	}
}


void motor_dir(int dir){
	if (dir==0){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, RESET);
	}
	else if (dir==1){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, SET);
	}
}

void motor_step(int f){
	TIM1->ARR = f;
}

/*
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim==&htim1){
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, SET);
	}
}*/
/*
void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim){
	int repetition=0;
	if(repetition++>target){
		HAL_TIM_PWM_Stop_IT(htim, TIM_CHANNEL_3);
	}
}*/
