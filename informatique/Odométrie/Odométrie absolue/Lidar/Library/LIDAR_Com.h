/*
 * LIDAR_Com.h
 *
 *  Created on: May 11, 2022
 *      Author: totog
 */

#ifndef LIDAR_COM_H_
#define LIDAR_COM_H_

#define TRUE 1
#define FALSE 1

#include "stm32l4xx_hal.h"



typedef struct {
	UART_HandleTypeDef *huart;
	DMA_HandleTypeDef *hdma_usart_rx;
}LIDAR_Descriptor_t;


typedef enum {
	LIDAR_SUCCESS = 0,
	LIDAR_ERROR_UART //ne rien mettre ici fait que ça vaut 1
}LIDAR_Status_t;

typedef enum {
	LIDAR_NO_MESSAGE = 0,
	LIDAR_NEW_MESSAGE
}LIDAR_Flag_New_Message_t;


typedef enum {
	LIDAR_COMMAND_START_SCANNING = 0x60,
	LIDAR_COMMAND_STOP_SCANNING = 0x65,
	LIDAR_COMMAND_GET_DEV_INFO = 0x90,
	LIDAR_COMMAND_GET_HEALTH_STATUS = 0x92,
	LIDAR_COMMAND_SCAN_FREQ_INC_1dHz = 0x09,
	LIDAR_COMMAND_SCAN_FREQ_DEC_1dHz = 0x0A,
	LIDAR_COMMAND_SCAN_FREQ_INC_1Hz = 0x0B,
	LIDAR_COMMAND_SCAN_FREQ_DEC_1Hz = 0x0C,
	LIDAR_COMMAND_GET_SCAN_FREQ = 0x0D,
	LIDAR_COMMAND_GET_RANGE_FREQ = 0xD1,
	LIDAR_COMMAND_PDN_PROTECTION_MODE = 0xD9,
	LIDAR_COMMAND_SOFT_RESTART = 0x40
}LIDAR_Command_t;

void LIDAR_Init(LIDAR_Descriptor_t * _Descriptor);
LIDAR_Status_t LIDAR_uart_send(LIDAR_Command_t cmd);
LIDAR_Flag_New_Message_t LIDAR_is_new_message(void);
void LIDAR_get_message(uint8_t * dest, uint16_t *Size, uint8_t _msg[], uint16_t _len);
void LIDAR_start_uart_receive(void);
void NewMessage(uint8_t msg [],uint16_t _Size);
void Processing(uint8_t msg [], uint16_t len);
void ProcessingQueue();






#endif /* LIDAR_COM_H_ */
