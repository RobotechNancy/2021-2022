/*
 * lidar.h
 *
 *  Created on: May 9, 2022
 *      Author: totog
 */

#ifndef SRC_LIDAR_H_
#define SRC_LIDAR_H_
#include "stm32l4xx_hal.h"

// error/success status returned by the translate function
typedef enum {
    TRANSLATION_SUCCESS = 0,
    TRANSLATION_ERROR_ID_MISMATCH,
    TRANSLATION_ERROR_SIZE_ZERO,
    TRANSLATION_ERROR_MESSAGE_INCOMPLETE,
    TRANSLATION_ERROR_UNKNOWN_TYPE_CODE,
    TRANSLATION_ERROR_UNKNOWN_PACKET_TYPE,
    TRANSLATION_ERROR_SCAN_PACKER_HEADER_MISMATCH,
    TRANLSATION_ERROR_CHECKSUM,
    TRANSLATION_ERROR
} LIDAR_Translation_Status_t;



LIDAR_Translation_Status_t LIDAR_Translation(uint8_t* data, uint16_t size);

int GetDistance(uint16_t *x1,uint16_t *x2);
void intersections(uint16_t distance_balise_1,uint16_t *position_balise_1,uint16_t distance_balise_2,uint16_t *position_balise_2);
char getPosition(uint16_t _x,uint16_t _y);
void initialisationGlobal(void);
void localisationBalises(void);
void urgencyStop(void);
void displayPosition(void);
uint8_t coherenceBalises(void);
void positionWith3Beacons(void);
void positionWith2Beacons(void);
char obstacleDetection(void);
void clearFarDistances(void); //fonction qui permet d'effacer les points en dehors du plateau de jeu sans connaitre la position du robot
void robotPosition(void);


#endif /* SRC_LIDAR_H_ */
