/*
 * can.h
 *
 *  Created on: 20 janv. 2022
 *      Author: Teoru
 */

#ifndef INC_CAN_H_
#define INC_CAN_H_
#include "stm32f0xx_hal.h"

int send_one(int adr, uint8_t data);
int send_can(int adr, uint8_t msg[], int msg_size);
CAN_HandleTypeDef hcan_p;
void CAN_Config(CAN_HandleTypeDef hcan, int adresse);
struct CanMsg;

#endif /* INC_CAN_H_ */
