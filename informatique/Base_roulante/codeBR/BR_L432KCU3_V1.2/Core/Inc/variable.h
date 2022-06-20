/*
 * variable.h
 *
 *  Created on: 8 mai 2022
 *      Author: lucie
 *
 *  Création des structures et des enum
 *
 *
 */

#ifndef INC_VARIABLE_H_
#define INC_VARIABLE_H_

//#include "main.h"
#include "stm32l4xx_hal.h"

/*
 * @brief structure moteur
 */
typedef struct{
    int cnt;
    uint8_t diviseur; //= freq_timer / freq_voulue, si =0 n'avance pas
    const float DIAMETRE;
    const float STEP_SIZE;

    uint16_t PIN_STEP; //STEP_Mx
    uint16_t PIN_DIR; //DIR_Mx
    GPIO_TypeDef* PIN_STEP_TYPE; //GPIOx
    GPIO_TypeDef* PIN_DIR_TYPE; //GPIOx
    GPIO_PinState pinStepState;
    GPIO_PinState pinDirState;
} Motor_t;


/*
 * @brief enum des différentes phases de déplacement
 */
typedef enum {
	ARRET = 0,
	ACCELERATION = 1,
	MAINTIENT,
	DECELERATION
} Deplacement_State_t;

/*
 * @brief enum des différentes états du moteur
 */
typedef enum {
	ARRET_MOTOR = 0,
	MARCHE_MOTOR = 1,
} Motor_State_t;


/*
 * @brief union utilisé dans le bus CAN pour envoyer les données
 */
typedef union {
    struct {
        uint32_t nb_steps : 32;
        uint8_t div0 : 8;
        uint8_t div1 : 8;
        uint8_t div2 : 8;
        bool dir0 : 1;
        bool dir1 : 1;
        bool dir2 : 1;
    } fields;
    uint64_t unified;
    uint8_t raw_data[8];
} Trame_Moteur_t;



//Fonctions
uint8_t get_id_msg(void);
void set_id_msg(uint8_t id);
uint32_t get_length(void);
void set_length(uint32_t l);
uint32_t* get_arr(void);
uint32_t* get_r_arr(void);
uint32_t get_tim_arr(void);
Deplacement_State_t get_deplacement_state(void);
void set_deplacement_state(Deplacement_State_t state);
uint32_t get_target(void);
void set_target(uint32_t t);
void reset_steps(void);
void count_steps(void);
uint32_t get_steps(void);
uint32_t get_steps_left(void);
uint32_t get_step_saved(void);
void set_step_saved(uint32_t t);
uint32_t get_freq(void);
float time_left(void);

#endif /* INC_VARIABLE_H_ */
