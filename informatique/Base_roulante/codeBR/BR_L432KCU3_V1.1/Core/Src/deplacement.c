/*
 * deplacement.c
 *
 *  Created on: 8 mai 2022
 *      Author: lucie
 */


#include <stdbool.h>
#define _USE_MATH_DEFINES // for C
#include <math.h>

#include "defineMotor.h"
#include "variable.h"
#include "deplacement.h"
#include "motor.h"

extern Motor_t motor1;
extern Motor_t motor2;
extern Motor_t motor3;

/*
 * @brief effectue un triangle
 * @param None
 * @retval None
 */
void triangle(void){
	set_target(24504);
	motor1.diviseur = 20;
	motor2.diviseur = 20;
	motor3.diviseur = 0;
	motor1.pinDirState = 1;
	motor2.pinDirState = 0;
	motor3.pinDirState = 0;
	motor_dir(&motor1);
	motor_dir(&motor2);
	motor_dir(&motor3);
	reset_steps();
	start_generate();
	while(get_steps_left()!=0){
		int a = 1;
	}
	motor1.diviseur = 20;
	motor2.diviseur = 0;
	motor3.diviseur = 20;
	motor1.pinDirState = 0;
	motor2.pinDirState = 0;
	motor3.pinDirState = 1;
	motor_dir(&motor1);
	motor_dir(&motor2);
	motor_dir(&motor3);
	reset_steps();
	start_generate();
	while(get_steps_left()!=0){
		int a = 1;
	}
	motor1.diviseur = 0;
	motor2.diviseur = 20;
	motor3.diviseur = 20;
	motor1.pinDirState = 0;
	motor2.pinDirState = 1;
	motor3.pinDirState = 0;
	motor_dir(&motor1);
	motor_dir(&motor2);
	motor_dir(&motor3);
	reset_steps();
	start_generate();
	while(get_steps_left()!=0){
		int a = 1;
	}
}



/*préparer des codes sur raspy envoyer a BR -> un NB de STEP en 32byte | 3 diviseur en 8 byte | 3 dir en 1 bit -> 64
	00 32 -> step
	32 40 -> div0
	40 48 -> div1
	48 56 -> div2
	56 59 -> 3 dir
 */
/*
 * @brief enregistre les valeurs des variables CAN dans les variables moteur et applique le nouveau sens de rotation des moteurs
 * @param &trameMotor adresse de la trameMotor
 * @retval None
 */
void prepare_deplacement(Trame_Moteur_t* trameMotor){
	set_target(trameMotor->fields.nb_steps);
	motor1.diviseur = trameMotor->fields.div0;
	motor2.diviseur = trameMotor->fields.div1;
	motor3.diviseur = trameMotor->fields.div2;
	motor1.pinDirState = trameMotor->fields.dir0;
	motor2.pinDirState = trameMotor->fields.dir1;
	motor3.pinDirState = trameMotor->fields.dir2;
	motor_dir(&motor1);
	motor_dir(&motor2);
	motor_dir(&motor3);
}

/*
 * @brief calcul la longueur de l'accélération, nombre de case à parcourrir dans le tableau arr
 * @param a, la valeur de l'ARR que laquelle on souhaite arriver
 * @retval length, la longueur
 */
uint32_t calcul_acceleration(uint32_t a){
    uint32_t indice = 0;
    while (get_arr()[indice] >= a){
        indice++;
    }
    set_length(indice);
	return get_length();
}

/*
 * @brief calcul la longueur de la décélération, nombre de case à parcourrir dans le tableau rArr
 * @param a, la valeur de l'ARR que laquelle on souhaite arriver
 * @retval length, la longueur
 */
uint32_t calcul_deceleration(uint32_t a){
	uint32_t indice = 0;
    while (get_r_arr()[indice] >= a){
        indice++;
    }
    set_length(indice);
	return get_length();
}

