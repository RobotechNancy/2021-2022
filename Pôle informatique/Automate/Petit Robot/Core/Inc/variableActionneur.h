/*
 * variable.h
 *
 *  Created on: 8 mai 2022
 *      Author: lucie
 */

#ifndef INC_VARIABLEACTIONNEUR_H_
#define INC_VARIABLEACTIONNEUR_H_

//#include "main.h"
#include "stm32f3xx_hal.h"

typedef enum {
	ARRET = 0,
	ACCELERATION = 1,
	MAINTIENT,
	DECELERATION
} Deplacement_State_t;

typedef enum{
	INCONNUE = 0,
	STATUETTE = 1,
	AIMANT = 2
} Position_t;

typedef struct{
    int diviseur; //= freq_timer / freq_voulue, si =0 n'avance pas
    int cnt;

    uint16_t PIN_STEP; //STEP_Mx
    uint16_t PIN_DIR; //DIR_Mx
    uint16_t PIN_EN; //EN_Mx
    GPIO_TypeDef* PIN_STEP_TYPE; //GPIOx
    GPIO_TypeDef* PIN_DIR_TYPE; //GPIOx
    GPIO_TypeDef* PIN_EN_TYPE; //GPIOx
    int pinStepState;
    int pinDirState;
    int pinEnState;

} Motor_t;

//Fonctions
uint32_t get_length(void);
void set_length(uint32_t l);
uint32_t* get_arr(void);
uint32_t* get_r_arr(void);
uint32_t get_tim_arr(void);
Deplacement_State_t get_deplacement_state(void);
void set_deplacement_state(Deplacement_State_t state);
Position_t get_position(void);
void set_position(Deplacement_State_t pos);
Position_t get_next_position(void);
void set_next_position(Deplacement_State_t pos);
uint32_t get_target(void);
void set_target(uint32_t t);
void reset_steps(void);
void count_steps(void);
uint32_t get_steps(void);
uint32_t get_steps_left(void);
uint32_t get_freq(void);
float time_left(void);
void set_fin(bool f);
bool get_fin(void);


#endif /* INC_VARIABLEACTIONNEUR_H_ */
