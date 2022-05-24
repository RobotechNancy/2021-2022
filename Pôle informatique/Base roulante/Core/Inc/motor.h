/*
 * motor.h
 *
 *  Created on: May 2, 2022
 *      Author: lucie
 */

#ifndef INC_MOTOR_H_
#define INC_MOTOR_H_

#include "stm32l4xx_hal.h"


//fonctions
//void bus_can(int code_fct, int dir, int freq, int dist1, int dist2);
//void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);

void start_generate(void);
void stop(void);
void emergency_stop(void);

int avance(Motor_t *motor);
int move_to_target(void);
void motor_step(Motor_t *motor);
void motor_dir(Motor_t *motor);
void motor_en(GPIO_PinState state);
void motor_micro_step(GPIO_PinState M1state, GPIO_PinState M2state);


#endif /* INC_MOTOR_H_ */

