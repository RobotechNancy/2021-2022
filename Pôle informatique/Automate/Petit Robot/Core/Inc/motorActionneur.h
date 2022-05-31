/*
 * motor.h
 *
 *  Created on: May 2, 2022
 *      Author: lucie
 */

#ifndef INC_MOTORACTIONNEUR_H_
#define INC_MOTORACTIONNEUR_H_

#include "stm32f3xx_hal.h"


//fonctions
//void bus_can(int code_fct, int dir, int freq, int dist1, int dist2);
//void HAL_TIM_OC_DelayElapsedCallback(TIM_HandleTypeDef *htim);

void start_generate(void);
void stop(void);
void emergency_stop(void);

int avance(Motor_t *motor);
void motor_step(Motor_t *motor);
void motor_dir(Motor_t *motor);
void motor_en(GPIO_PinState state);


#endif /* INC_MOTORACTIONNEUR_H_ */

