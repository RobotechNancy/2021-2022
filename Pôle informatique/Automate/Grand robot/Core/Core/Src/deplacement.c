/*
 * deplcament.c
 *
 *  Created on: May 12, 2022
 *      Author: thibault
 */
#include "math.h"
#include "deplacement.h"
#include "deplacement_define.h"

double compteur_angle=0;

float deplacement(float *pointx1, float *pointy1, int dx, int dy, float angle,float x0 , float y0) {

	compteur_angle+=angle;

	*pointx1 += x0 + dx * cos(compteur_angle*PI/180) - dy * sin(compteur_angle*PI/180);
	*pointy1 += y0 + dx * sin(compteur_angle*PI/180) + dy * cos(compteur_angle*PI/180);

	return 0;

}
