/*
 * lidar.c
 *
 *  Created on: May 9, 2022
 *      Author: totog
 */
#include "lidar.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "lidar_define.h"

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;

extern uint16_t array_distances[360];
extern uint8_t objects[10];
extern uint8_t start;

uint16_t angle_balise_haute;
uint16_t angle_balise_basse;
uint16_t angle_balise_opposee;
uint16_t angle_co_robot;

uint16_t distance_balise_haute;
uint16_t distance_balise_basse;
uint16_t distance_balise_opposee;
uint16_t distance_co_robot;

uint16_t coherence_balise_basse;
uint16_t coherence_balise_haute;
uint16_t coherence_balise_opposee;


uint16_t ancienne_distance_balise_haute;
uint16_t ancienne_distance_balise_basse;
uint16_t ancienne_distance_balise_opposee;

uint16_t position_balise_haute [2]={0};
uint16_t position_balise_basse [2]={0};
uint16_t position_balise_opposee [2]={0};



uint16_t x_robot;
uint16_t y_robot;

int16_t points_intersection[4]; //Les deux premiers éléments sont 1 point, les deux autres le second point



// transform a array of 2 uint8_t into a uint16_t (the reverse too)
typedef union {
    uint8_t u8[2];
    uint16_t u16;
} LIDAR_u8_to_u16_t;

// transform a array of 4 uint8_t into a uint32_t (the reverse too)
typedef union {
    uint8_t u8[4];
    uint32_t u32;
} LIDAR_u8_to_u32_t;

// transform a array of 8 uint8_t into a uint64_t (the reverse too)
typedef union {
    uint8_t u8[8];
    uint64_t u64;
} LIDAR_u8_to_u64_t;



LIDAR_Translation_Status_t LIDAR_Translation(uint8_t* data, uint16_t size)
/*
 * @param uint8_t* data : pointer to the message buffer
 * @param uint16_t size : size of the message
 *
 * @return LIDAR_Translation_Status_t : status (success or error)
 *
 * @brief This function performs the decoding of the dataframes recieved by te MCU
 */
{
    LIDAR_u8_to_u16_t u8_to_u16;
    LIDAR_u8_to_u32_t u8_to_u32;
    LIDAR_u8_to_u64_t u8_to_u64;

    uint16_t id;
    uint32_t length_mode;
    uint32_t length;
    uint8_t mode;
    uint8_t type_code;

    //Pour le scan mode
    uint16_t PH, FSA, LSA, CS,angle_FSA,angle_LSA; // system header
    uint8_t CT, LS;

    uint32_t distance_intensity; //sample data

    uint16_t i, j;
    uint16_t computed_CS;
    uint8_t scanning_frequency, package_type, sample_quantity;
    uint16_t distance, intensity;

    float angle_offset, angle_scale, angle;


//
//    if ( size <= 10 ) return TRANSLATION_ERROR_SIZE_ZERO;
//
//    u8_to_u16.u8[0] = data[0];
//    u8_to_u16.u8[1] = data[1];
//    id = u8_to_u16.u16;
//
//    if ( id != 0x55AA ) return TRANSLATION_ERROR_ID_MISMATCH;
//
//
//    u8_to_u32.u8[0] = data[2];
//    u8_to_u32.u8[1] = data[3];
//    u8_to_u32.u8[2] = data[4];
//    u8_to_u32.u8[3] = data[5];
//    length_mode = u8_to_u32.u32;
//
//    length = length_mode & 0x3FFFFFFF;
//    mode = (uint8_t)(length_mode >> 30) & 0x03 ;

//    type_code = data[6];

    if ( type_code == 0x81 || 1)
    /*
     * SCAN RETURN
     */
    {


        if ( size < 19 ) return TRANSLATION_ERROR_MESSAGE_INCOMPLETE;

        // Packet Header
        u8_to_u16.u8[0] = data[0];
        u8_to_u16.u8[1] = data[1];
        PH = u8_to_u16.u16;
        if ( PH != 0x55AA ) return TRANSLATION_ERROR_SCAN_PACKER_HEADER_MISMATCH;

        // scanning frequency and packet type
        CT = data[2];
        scanning_frequency = CT >> 1 & 0x7F; // take the 7 MSB of the CS register
        package_type = CT & 0x03;
//        if(package_type > 1) return TRANSLATION_ERROR_UNKNOWN_PACKET_TYPE;

        LS = data[3];
        sample_quantity = LS;

        u8_to_u16.u8[0] = data[4];
        u8_to_u16.u8[1] = data[5];
        FSA = u8_to_u16.u16;

        u8_to_u16.u8[0] = data[6];
        u8_to_u16.u8[1] = data[7];
        LSA = u8_to_u16.u16;

        angle_FSA = (FSA >> 1)/64;
        angle_LSA = (LSA >> 1)/64;
        angle_offset = (float)     angle_FSA               ;
        angle_scale  = (float)(angle_LSA-angle_FSA)/((float)(LS));


        /* CHECKSUM BEGIN 1*/
        u8_to_u16.u8[0] = data[8];
        u8_to_u16.u8[1] = data[9];
        CS = u8_to_u16.u16;

        computed_CS  = PH;
        computed_CS ^= FSA;
        /* CHECKSUM END   1*/

        i = 10; // start at the 18th byte (17th index)
        for(j=0;j<sample_quantity;j++)
        {
            // if the last byte to be read in this loop is out of bound (index+1>size), return an error, the packet is incomplete
            if( i+3 > size ) return TRANSLATION_ERROR_MESSAGE_INCOMPLETE;

            /* CHECKSUM BEGIN 2*/

            // perform the checksum for the sampling data
            u8_to_u16.u8[0] = data[i+2];
            u8_to_u16.u8[1] =      0x00;
            computed_CS ^= u8_to_u16.u16;

            u8_to_u16.u8[0] = data[i+0];
            u8_to_u16.u8[1] = data[i+1];
            computed_CS ^= u8_to_u16.u16;
            /* CHECKSUM END   2*/

            // get the entire sampling data
            u8_to_u32.u8[0] = data[i+0];
            u8_to_u32.u8[1] = data[i+1];
            u8_to_u32.u8[2] = data[i+2];
            u8_to_u32.u8[3] =      0x00;
            distance_intensity = u8_to_u32.u32;

            // convert the sampling data into usefull data
            intensity = (uint16_t)(   distance_intensity         & 0x000001FF ); // get the 9 LSB
            distance  = (uint16_t)( ( distance_intensity >> 10 ) & 0x00007FFF ); // get the 15 MSB
            angle = angle_offset + angle_scale * j;

            // increment i by 3 (3 bytes read)
            i+=3;

            /* USE MEASUREMENT BEGIN */
            // Call an iterative function to perform the calculations
            array_distances[((uint16_t)angle)%TOUR_COMPLET] = distance;

            uint8_t b[64],l;
            l = sprintf((char*)b,"%d\t%d\t%d\r\n",(uint16_t)angle,distance,intensity);
            HAL_UART_Transmit(&huart2, b, l, 6);
            /* USE MEASUREMENT END   */
        }

        /* CHECKSUM BEGIN 3*/
        // perform the checksum for the 3 last data fields
        u8_to_u16.u8[0] = CT;
        u8_to_u16.u8[1] = LS;
        computed_CS ^= u8_to_u16.u16;

        computed_CS ^= LSA;

        // if the checksum does not correspond, raise an error
        if ( computed_CS != CS ) return TRANLSATION_ERROR_CHECKSUM;
        /* CHECKSUM END   3*/
    }
    else
        // if there is no case to process the data for a given type code
        return TRANSLATION_ERROR_UNKNOWN_TYPE_CODE;

//    __UNUSED(length);
//    __UNUSED(mode);
//    __UNUSED(u8_to_u64);
//    __UNUSED(scanning_frequency);
//    __UNUSED(package_type);
//    __UNUSED(intensity);
    // if nothing bad append, return success

    return TRANSLATION_SUCCESS;
}

void localisationBalises(){ //permet de connaitre l'angle et la distance des 3 balises
	uint16_t distance_minimum = DISTANCE_MAXIMUM; //on début la valeur minimum avec la plus grande valeur possible pour ne pas avoir de problèmes
	for (int i=(angle_balise_basse-SMALL_RANGE)%TOUR_COMPLET;i<(angle_balise_basse+SMALL_RANGE)%TOUR_COMPLET;i++){ //repérage de la première balise
		if (array_distances[i]<distance_minimum && array_distances[i]>DISTANCE_MINIMUM){ //on cherche la plus petite distance en évitant les données incohérentes
			distance_minimum = array_distances[i]; //on note la plus petite distance
			angle_balise_basse = i; //on note l'angle de la balise
		}
	}
	distance_balise_basse = distance_minimum; //on note la distance à la balise

	//char aBalise[3] ={0};
	//char dBalise[5]={0};
	/*(angle_balise_basse,aBalise,10);
	itoa(distance_balise_basse,dBalise,10);
	HAL_UART_Transmit(&huart2,  (uint8_t *)"Angle balise : ", sizeof("Angle balise : "), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)aBalise, sizeof(aBalise), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)" distance balise : ", sizeof(" distance balise : "), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)dBalise, sizeof(dBalise), 50);*/


	distance_minimum = DISTANCE_MAXIMUM;
	for (int i=(angle_balise_haute-SMALL_RANGE)%TOUR_COMPLET;i<(angle_balise_haute+SMALL_RANGE)%TOUR_COMPLET;i++){ //repérage de la première balise
		if (array_distances[i]<distance_minimum && array_distances[i]>DISTANCE_MINIMUM){ //on cherche la plus petite distance en évitant les données incohérentes
			distance_minimum = array_distances[i]; //on note la plus petite distance
			angle_balise_haute = i; //on note l'angle de la balise
		}
	}
	distance_balise_haute = distance_minimum; //on note la distance à la balise

	/*itoa(angle_balise_haute,aBalise,10);
	itoa(distance_balise_haute,dBalise,10);
	HAL_UART_Transmit(&huart2,  (uint8_t *)" Angle balise : ", sizeof(" Angle balise : "), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)aBalise, sizeof(aBalise), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)" distance balise : ", sizeof(" distance balise : "), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)dBalise, sizeof(dBalise), 50);*/

	distance_minimum = DISTANCE_MAXIMUM;
	for (int i=(angle_balise_opposee-SMALL_RANGE)%TOUR_COMPLET;i<(angle_balise_opposee+SMALL_RANGE)%TOUR_COMPLET;i++){ //repérage de la première balise
		if (array_distances[i]<distance_minimum && array_distances[i]>DISTANCE_MINIMUM){ //on cherche la plus petite distance en évitant les données incohérentes
			distance_minimum = array_distances[i]; //on note la plus petite distance
			angle_balise_opposee = i; //on note l'angle de la balise
		}
	}
	distance_balise_opposee = distance_minimum; //on note la distance à la balise

	/*itoa(angle_balise_opposee,aBalise,10);
	itoa(distance_balise_opposee,dBalise,10);
	HAL_UART_Transmit(&huart2,  (uint8_t *)" Angle balise : ", sizeof(" Angle balise : "), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)aBalise, sizeof(aBalise), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)" distance balise : ", sizeof(" distance balise : "), 50);
	HAL_UART_Transmit(&huart2,  (uint8_t *)dBalise, sizeof(dBalise), 50);*/
}

void initialisationGlobal(){

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
	if (start == START_LEFT){ //on initialise les balises pour un départ à gauche
		angle_balise_haute = ANGLE_BALISE_GAUCHE_HAUTE; //à modifier avec les angles des balises par rapport au début
		angle_balise_basse = ANGLE_BALISE_GAUCHE_BASSE;
		angle_balise_opposee = ANGLE_BALISE_GAUCHE_OPPOSEE;
		position_balise_haute[0] =X_BALISE_GAUCHE_HAUTE;
		position_balise_basse[0] =X_BALISE_GAUCHE_BASSE;
		position_balise_opposee[0] =X_BALISE_GAUCHE_OPPOSEE;
		position_balise_haute[1] =Y_BALISE_GAUCHE_HAUTE;
		position_balise_basse[1] =Y_BALISE_GAUCHE_BASSE;
		position_balise_opposee[1] =Y_BALISE_GAUCHE_OPPOSEE;
	} else if (start == START_RIGHT){ //on initialise les balises pour un départ à droite
		angle_balise_haute = ANGLE_BALISE_DROITE_HAUTE; //à modifier avec les angles des balises par rapport au début
		angle_balise_basse = ANGLE_BALISE_DROITE_BASSE;
		angle_balise_opposee = ANGLE_BALISE_DROITE_OPPOSEE;
		position_balise_haute[0] =0;
		position_balise_basse[0] =0;
		position_balise_opposee[0] =0;
		position_balise_haute[1] =0;
		position_balise_basse[1] =0;
		position_balise_opposee[1] =0;
	}

	localisationBalises(); //on repère les 3 balises

	distance_balise_basse = 300;
	distance_balise_haute = 400;  //tests pour le calcul de position
	distance_balise_opposee = 122;
	positionWith3Beacons();

	//char CR = getPosition(x_robot,y_robot);
	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_8);
}

char getPosition(uint16_t _x,uint16_t _y){ //permet de tester la cohérence d'une position
	if (_x>0 && _x<3000 && _y>0 && _y<2000){
		return 0; //tout va bien
	} else{
		return -1; //position incohérente
	}
}

void robotPosition(){ //calcul la position du robot
	ancienne_distance_balise_haute = distance_balise_haute;
	ancienne_distance_balise_basse = distance_balise_basse;
	ancienne_distance_balise_opposee = distance_balise_opposee;
	localisationBalises(); //on cherche les balises
	uint8_t nombre_de_balises = coherenceBalises(); //on regarde combien sont utilisables

	if (nombre_de_balises == 3){ //si 3 balises sont cohérentes
		positionWith3Beacons();
	} else if (nombre_de_balises == 2){ //si 2 balises sont cohérentes
		positionWith2Beacons();
	}


}

void positionWith2Beacons(){
	memset(points_intersection,0,sizeof(points_intersection)); //on s'assure ne pas avoir de points d'intersection déjà établis

	coherence_balise_basse = 0;
	coherence_balise_haute = 1;
	coherence_balise_opposee = 1;
	distance_balise_haute = 200;
	distance_balise_opposee = 500;
	x_robot =200;
	y_robot =200;


	if (coherence_balise_basse == 0){ //balise basse inutilisable
		intersections(distance_balise_haute, position_balise_haute, distance_balise_opposee, position_balise_opposee);
	} else if (coherence_balise_haute == 0){ //balise haut inutilisable
		intersections(distance_balise_basse, position_balise_basse, distance_balise_opposee, position_balise_opposee);
	} else { //balise oppposée inutilisable
		intersections(distance_balise_haute, position_balise_haute, distance_balise_basse, position_balise_basse);
	}

	uint16_t point1[2] = {points_intersection[0],points_intersection[1]}; //premier point d'intersection
	uint16_t point2[2] = {points_intersection[2],points_intersection[3]}; //second point d'intersection

	uint16_t distance_point1 = abs(x_robot - point1[0]) + abs(y_robot - point1[1]); //différence entre la position du premier point d'intersection de la position précédente
	uint16_t distance_point2 = abs(x_robot - point2[0]) + abs(y_robot - point2[1]); //différence entre la position du second point d'intersection de la position précédente

	if (distance_point1 < distance_point2 && distance_point1 < 10000){
		x_robot = point1[0];
		y_robot = point1[1];
	} else if (distance_point2 <= distance_point1 && distance_point2 < 10000){
		x_robot = point2[0];
		y_robot = point2[1];
	} else {
		x_robot = 10000;
		y_robot = 10000;
	}
	distance_point1 = 0;
	distance_point2 = 0;
}

void positionWith3Beacons(){
	//memset(points_intersection,0,sizeof(points_intersection)); //on s'assure ne pas avoir de points d'intersection déjà établis
	intersections(distance_balise_basse, position_balise_basse, distance_balise_haute, position_balise_haute);
	int16_t point1[2];
	int16_t point2[2];
	point1[0] = points_intersection[0]; //premier point d'intersection
	point1[1] = points_intersection[1];
	point2[0] = points_intersection[2]; //second point d'intersection
	point2[1] = points_intersection[3];

	//memset(points_intersection,0,sizeof(points_intersection)); //on remet les points d'intersection à 0
	intersections(distance_balise_basse, position_balise_basse, distance_balise_opposee, position_balise_opposee);
	int16_t point3[2] = {points_intersection[0],points_intersection[1]}; //troisième point d'intersection
	int16_t point4[2] = {points_intersection[2],points_intersection[3]}; //quatrième point d'intersection

	//on cherche le point d'intersection présent deux fois pour déterminer la position du robot
	if ((point3[0] - TOLERANCE_INTERSECTION < point1[0]  && point1[0]< point3[0] + TOLERANCE_INTERSECTION) || (point4[0] - TOLERANCE_INTERSECTION < point1[0] && point1[0] < point4[0] + TOLERANCE_INTERSECTION)){
		if ((point3[1] - TOLERANCE_INTERSECTION < point1[1] && point1[1] < point3[1] + TOLERANCE_INTERSECTION) || (point4[1] - TOLERANCE_INTERSECTION < point1[1] && point1[1] < point4[1] + TOLERANCE_INTERSECTION)){
			x_robot = point1[0]; //le robot est à l'endroit du point 1
			y_robot = point1[1];
		} else {
			x_robot = 10000; //l'initialisation est ratée
			y_robot = 10000;
		}
	} else if ((point3[0] - TOLERANCE_INTERSECTION < point2[0] && point2[0] < point3[0] + TOLERANCE_INTERSECTION) || (point4[0] - TOLERANCE_INTERSECTION < point2[0] && point2[0] < point4[0] + TOLERANCE_INTERSECTION)){
		if ((point3[1] - TOLERANCE_INTERSECTION < point2[1] && point2[1] < point3[1] + TOLERANCE_INTERSECTION) || (point4[1] - TOLERANCE_INTERSECTION < point2[1] && point2[1] < point4[1] + TOLERANCE_INTERSECTION)){
			x_robot = point2[0]; //le robot est à l'endroit du point 2
			y_robot = point2[1];
		} else {
			x_robot = 10000; //l'initialisation est ratée
			y_robot = 10000;
		}
	} else {
		x_robot = 10000; //l'initialisation est ratée
		y_robot = 10000;
	}
}

uint8_t coherenceBalises(){
	uint8_t indice_de_confiance = 0;
	coherence_balise_basse = 0;
	coherence_balise_haute = 0;
	coherence_balise_opposee = 0;

	if (abs(ancienne_distance_balise_basse - distance_balise_basse) < 300){
		indice_de_confiance++;
		coherence_balise_basse = 1;
	}
	if (abs(ancienne_distance_balise_haute - distance_balise_haute) < 300){
		indice_de_confiance++;
		coherence_balise_haute = 1;
	}
	if (abs(ancienne_distance_balise_opposee - distance_balise_opposee) < 300){
		indice_de_confiance++;
		coherence_balise_opposee = 1;
	}
	return indice_de_confiance;
}

void positionOfCoRobot(){
	uint16_t distance_minimum = DISTANCE_MAXIMUM;
	for (int i = (angle_co_robot - LARGE_RANGE)%TOUR_COMPLET; i< (angle_co_robot + LARGE_RANGE)%TOUR_COMPLET; i++){
		if (array_distances[i] < distance_minimum){
			distance_minimum = array_distances[i];
			angle_co_robot = i;
		}
	}
	distance_co_robot = distance_minimum;
}



void urgencyStop(){
	char buffer[2];
	buffer[0] = 0xA5;
	buffer[1] = 0x65;

	HAL_UART_Transmit(&huart1, (uint8_t *)buffer, sizeof(buffer), 200); //arret de la fonction
}

char obstacleDetection(){
	uint8_t obstacles = 0;
	for (int i = 0;i<TOUR_COMPLET;i++){
		if (array_distances[i]<DISTANCE_OBSTACLE && array_distances[i]>DISTANCE_MINIMUM) obstacles++;
	}
	if (obstacles > OBSTACLE_DETECTION_MINIMUM) return COLLISION; //présence d'obstacle
	else return NO_COLLISION; //pas d'obstacle
}



void clearFarDistances(){
	for (int i = 0; i< 360; i++){
		if (array_distances[i]>DISTANCE_MAX) array_distances[i]=0;
	}
}

void displayPosition(){
	char _x[5]={0};
	char _y[5]={0};
	itoa(x_robot,_x,10);
	itoa(y_robot,_y,10);
	HAL_UART_Transmit(&huart2, (uint8_t *)"\r\n x = ", sizeof("\t\n x = "), 200);
	HAL_UART_Transmit(&huart2, (uint8_t *)_x, sizeof(_x), 200);
	HAL_UART_Transmit(&huart2, (uint8_t *)"   y = ", sizeof("   y = "), 200);
	HAL_UART_Transmit(&huart2, (uint8_t *)_y, sizeof(_y), 200);

}






int GetDistance(uint16_t *x1,uint16_t *x2){ //Permet d'obtenir la distance entre 2 points


	return(pow(((pow(x2[0]-x1[0],2))+pow(x2[1]-x1[1],2)),0.5));

}

void intersections(uint16_t distance_balise_1,uint16_t position_balise_1[2],uint16_t distance_balise_2,uint16_t position_balise_2[2]){ // Permet d'obtenir les coordonnées des points d'intersection entre 2 cercles de centre pos1, pos2 de rayon R0, R1

	//dans le cas des vraies balises il faut penser à retirer le rayon de la balise à la distance
 float  x1=position_balise_1[0]; //coordonée en x de la première balise
 float  y1=position_balise_1[1]; //coordonée en y de la première balise
 float  x2=position_balise_2[0]; //coordonée en x de la deuxième balise
 float  y2=position_balise_2[1]; //coordonée en y de la deuxième balise
 distance_balise_1 += RAYON_BALISE;
 distance_balise_2 += RAYON_BALISE;

 float C1 =(pow(distance_balise_2,2)-pow(distance_balise_1,2)-pow(x2,2)+pow(x1,2)-pow(y2,2)+pow(y1,2))/(2*(y1-y2)); //constante 1
 float C2 = (x1 - x2 )/( y1 - y2 ); //constante 2
 float A = pow(C2,2)+1;
 float B =2*y1*C2 -2*C1*C2-2*x1;
 float C= pow(x1,2)+pow(y1,2)+pow(C1,2)-pow(distance_balise_1,2)-2*y1*C1;
 float d = pow(B,2) - 4 * A * C; //déterminant

 if (d > 0){
     float D= sqrt(d);
     int xa =(-B+D)/(2*A);
     int ya = (C1-xa*C2);

     int xb = (-B-D)/(2*A);
     int yb = (C1-xb*C2);

     points_intersection[0]=xa;
     points_intersection[1]=ya;
     points_intersection[2]=xb;
     points_intersection[3]=yb;
 }
 else if (d == 0 ){

     int x = (- B / ( 2 * A ));
     int y = (C1 - x * C2);

     points_intersection[0]=x;
     points_intersection[1]=y;
     points_intersection[2]=x;
     points_intersection[3]=y;

 } else {
	 points_intersection[0]=0;
	 points_intersection[1]=0;
	 points_intersection[2]=0;
	 points_intersection[3]=0;

 }

}
