/*
 * defineMotor.h
 *
 *  Created on: May 2, 2022
 *      Author: lucie
 */

#ifndef INC_DEFINEACTIONNEUR_H_
#define INC_DEFINEACTIONNEUR_H_

#define CLK 16000000
#define PRESCALER 16

//distance NEUTRE-STATUETTE = +- 62mm = -+16258pas
//distance NEUTRE-AIMANT = +- 13mm = -+3409pas
#define NB_STEPS_STATUETTE 16258
#define NB_STEPS_AIMANT 3409

#define LENGTH_ARR_MAX 1105

#define DIAMETRE_PIGNON 14
#define DIV_DRIVER 2



#endif /* INC_DEFINEACTIONNEUR_H_ */
