/*
 * deplacement.c
 *
 *  Created on: 20 mai 2022
 *      Author: thibault
 */

#ifndef SRC_DEPLACEMENT_C_
#define SRC_DEPLACEMENT_C_

#include "math.h"
#include "deplacement.h"
#include "deplacement_define.h"

double compteur_angle=0;

/*
 * @brief fonction qui permet de calculer la position theorique où le robot se trouve après un déplacement ordonnée par une rotation et un deplacement en x,y
 * @param 2 pointeurs x1 et y1 qui sont la position du robot finale par rapport au plateau
 * @param int dx et dy le depalcement en x et y mesuré par le capteur optique (dans le referentiel de ce dernier)
 * @param float angle de rotation donné par le giroscope à coupler avec le capteur optique
 * @param float x0 et y0 qui sont les position initiale du robot dans le referentiel du plateau
 */
float deplacement(float *pointx1, float *pointy1, int dx, int dy, float angle,float x0 , float y0) {

	compteur_angle+=angle;

	*pointx1 += x0 + dx * cos(compteur_angle*PI/180) - dy * sin(compteur_angle*PI/180);
	*pointy1 += y0 + dx * sin(compteur_angle*PI/180) + dy * cos(compteur_angle*PI/180);

	return 0;

}


#endif /* SRC_DEPLACEMENT_C_ */
