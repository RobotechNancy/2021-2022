/*
 * defineMotor.h
 *
 *  Created on: May 2, 2022
 *      Author: lucie
 */

#ifndef INC_DEFINEMOTOR_H_
#define INC_DEFINEMOTOR_H_


#define CLK 16000000 //Hz
#define PRESCALER 16
#define FREQ_BASE 10000
//
//#define DIAMETRE_BASE 200
//#define RAYON_BASE 100
#define LENGTH_ARR_MAX 1105//1105

//taille de pas est [°/tr] / ( [step/pas] * [pas/tr] ) = [°/step]
//taille_pas = 360/(200*div_driver)

#define DIAMETRE_ROUE 60


//Motor 1
#define COEFF_DIAMETRE_1 1
#define DIV_DRIVER_1 2


//Motor 2
#define COEFF_DIAMETRE_2 1
#define DIV_DRIVER_2 2

//Motor 3
#define COEFF_DIAMETRE_3 1
#define DIV_DRIVER_3 2


#endif /* INC_DEFINEMOTOR_H_ */
