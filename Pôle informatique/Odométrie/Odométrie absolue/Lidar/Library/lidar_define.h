/*
 * lidar_define.h
 *
 *  Created on: 9 mai 2022
 *      Author: totog
 */

#ifndef INC_LIDAR_DEFINE_H_
#define INC_LIDAR_DEFINE_H_

//Départ à gauche ou à droite
#define START_LEFT  1 // le robot est à droite en début de compétition
#define START_RIGHT 0 // le robot est à gauche en début de compétition

//Angles des balises en fonction de l'endroit du départ
#define ANGLE_BALISE_GAUCHE_BASSE   65 //balise du bas côté robot quand on commmence à gauche
#define ANGLE_BALISE_GAUCHE_HAUTE   120   //balise du haut côté robot quand on commence à gauche
#define ANGLE_BALISE_GAUCHE_OPPOSEE 290 //balise opposée au robot quand on commence à gauche

#define ANGLE_BALISE_DROITE_BASSE   0 //balise du bas côté robot quand on commmence à droite
#define ANGLE_BALISE_DROITE_HAUTE   0 //balise du haut côté robot quand on commence à droite
#define ANGLE_BALISE_DROITE_OPPOSEE 0 //balise opposée au robot quand on commence à droite

//Coordonées des balises avec départ à gauche
#define X_BALISE_GAUCHE_BASSE       1000//position en x de la balise basse quand on commence à gauche
#define Y_BALISE_GAUCHE_BASSE       50 //position en y de la balise basse quand on commence à gauche

#define X_BALISE_GAUCHE_HAUTE       1000 //position en x de la balise haute quand on commence à gauche
#define Y_BALISE_GAUCHE_HAUTE       1000 //position en y de la balise haute quand on commence à gauche

#define X_BALISE_GAUCHE_OPPOSEE     3000 //position en x de la balise opposée quand on commence à gauche
#define Y_BALISE_GAUCHE_OPPOSEE     500 //position en y de la balise opposée quand on commence à gauche

//Coodronées des balises avec départ à droite
#define X_BALISE_DROITE_BASSE       5//position en x de la balise basse quand on commence à droite
#define Y_BALISE_DROITE_BASSE       50 //position en y de la balise basse quand on commence à droite

#define X_BALISE_DROITE_HAUTE 5 //position en x de la balise haute quand on commence à droite
#define Y_BALISE_DROITE_HAUTE 1950 //position en y de la balise haute quand on commence à droite

#define X_BALISE_DROITE_OPPOSEE 2995 //position en x de la balise opposée quand on commence à droite
#define Y_BALISE_DROITE_OPPOSEE 1000 //position en y de la balise opposée quand on commence à droite

#define TOUR_COMPLET 360 //nombre de degrés dans un tour complet
#define DISTANCE_MINIMUM 120 //distance minimum captée par le lidar
#define DISTANCE_MAXIMUM 16000 //distance maximum captée par le lidar
#define DISTANCE_OBSTACLE 300 //distance à partir de laquelle on considère un objet comme obstacle
#define OBSTACLE_DETECTION_MINIMUM 3 //nombre d'obstacles à partir duquel on déclenche l'anti-collision

#define SMALL_RANGE 20 //utilisée pour l'initialisation et le repérage des balises
#define LARGE_RANGE 25 //utilisée pour le repérage du robot allié
#define RAYON_BALISE 30
#define TOLERANCE_INTERSECTION 500 //tolérance pour comparer les points des intersections

//erreurs et retours de fonction :
#define ANGLE_OUT_OF_BOUNDS -1 //code erreur si un angle dépasse 360 degrés
#define NO_COLLISION 0 //pas d'anti-collision activée
#define COLLISION 1 //anti-collision activée
#define DISTANCE_MAX 3200

#endif /* INC_LIDAR_DEFINE_H_ */
