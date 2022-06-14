/*
 * servo.h
 *
 *  Created on: 9 mai 2022
 *      Author: thibault
 */

#ifndef INC_SERVO_H_
#define INC_SERVO_H_
#include "stm32f3xx_hal.h"
#include <stdbool.h>
/*
 * @brief enumeration de renvoie de la fonction tet_resistance()
 */
typedef enum {
    JAUNE = 0,
    VIOLET = 1,
    INTERDIT = 2,
    ERREUR = 3

}RESISTANCE_VALEUR;

/*
 * @brief implémente un delay pour replacer HAL_DELAY
 * @retval None
 */
void attendre(int);

/*
 * @brief demarre le pin du servo 3
 * @retval None
 */
void servo3Start();

/*
 * @brief eteint le pin du servo 3
 * @retval None
 */
void servo3Stop();

/*
 * @brief deplace le servomoteur du bras de la resistance en fonctioin d'un angle entré
 * @param int angle en degré
 * @retval uint8 pour savoir si l'action s'est effectué
 */
uint8_t deplacement_servo_resistance(int);

/*
 * @brief test la valeur de la resistance entre les 2 broches
 * @retval ENUMERATION pour savoir quelle est la couleur de la resistance
 */
RESISTANCE_VALEUR test_resistance();

/*
 * @brief allume l'électroaimant
 * @retval int renvoie 1 si l'action s'est effectué
 */
int aimant_on();

/*
 * @brief eteint l'électroaimant
 * @retval int renvoie 0 si l'action s'est effectué
 */
int aimant_off();

/*
 * @brief allume ou eteint l'électroaimant à l'aide des 2 fonctions précédentes
 * @param bool 1 pour allumer et 0 pour eteindre
 * @retval uint8 qui atteste que l'action est effectué
 */
uint8_t aimant(bool);

#endif /* INC_SERVO_H_ */
