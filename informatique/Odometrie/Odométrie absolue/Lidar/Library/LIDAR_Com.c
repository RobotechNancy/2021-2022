/*
 * LIDAR_Com.c
 *
 *  Created on: May 11, 2022
 *      Author: totog
 */
#include "LIDAR_Com.h"

#include <string.h>
#include "lidar.h"

#define RX_BUFFER_SIZE 2048
#define TX_BUFFER_SIZE 2
#define COMMAND_START 0xA5


extern UART_HandleTypeDef huart2;

typedef struct {
	LIDAR_Flag_New_Message_t new_msg_1;
	LIDAR_Flag_New_Message_t new_msg_2;
}LIDAR_Flags_t;

uint8_t LIDAR_rx_buffer[RX_BUFFER_SIZE];
uint8_t LIDAR_tx_buffer[TX_BUFFER_SIZE];
uint8_t LIDAR_rx_msg_1[RX_BUFFER_SIZE];
uint16_t LIDAR_rx_msg_1_len;
uint8_t LIDAR_rx_msg_2[RX_BUFFER_SIZE];
uint16_t LIDAR_rx_msg_2_len;


LIDAR_Descriptor_t *Descriptor;
LIDAR_Flags_t Flags;
LIDAR_Translation_Status_t LIDAR_Status;


LIDAR_Status_t LIDAR_uart_send(LIDAR_Command_t cmd){
	HAL_StatusTypeDef HAL_Status;

	LIDAR_tx_buffer[0]= COMMAND_START;
	LIDAR_tx_buffer[1]= (uint8_t)cmd;

	HAL_Status=HAL_UART_Transmit_DMA(Descriptor->huart, LIDAR_tx_buffer, TX_BUFFER_SIZE);
	if(HAL_Status!=HAL_OK) return LIDAR_ERROR_UART;
	return LIDAR_SUCCESS;

}

void LIDAR_start_uart_receive(void){
	HAL_UARTEx_ReceiveToIdle_DMA(Descriptor->huart, LIDAR_rx_buffer, RX_BUFFER_SIZE);

	__HAL_DMA_DISABLE_IT(Descriptor->hdma_usart_rx,DMA_IT_HT);
}

void LIDAR_uart_rx_interrupt_routine(UART_HandleTypeDef *huart, uint16_t Size){ //size = nombre de données reçues
	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10);
	if (huart != Descriptor->huart) return ;

	NewMessage(LIDAR_rx_buffer, Size);

	LIDAR_start_uart_receive();
//	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_10);
}

void NewMessage(uint8_t *msg , uint16_t _Size){
	//if (_Size < 5) return;
	if (Flags.new_msg_1 == LIDAR_NO_MESSAGE){
		memcpy(LIDAR_rx_msg_1, msg, _Size);
		LIDAR_rx_msg_1_len = _Size;
		Flags.new_msg_1 = LIDAR_NEW_MESSAGE;
	} else if (Flags.new_msg_2 == LIDAR_NO_MESSAGE){
		memcpy(LIDAR_rx_msg_2, msg, _Size);
		LIDAR_rx_msg_2_len = _Size;
		Flags.new_msg_2 = LIDAR_NEW_MESSAGE;
	}
	else {
		//message perdu
	}
}

void ProcessingQueue(){
	if (Flags.new_msg_1 == LIDAR_NEW_MESSAGE){
		Flags.new_msg_1 = LIDAR_NO_MESSAGE;
		Processing(LIDAR_rx_msg_1, LIDAR_rx_msg_1_len);
	} else if (Flags.new_msg_2 == LIDAR_NEW_MESSAGE){
		Flags.new_msg_2 = LIDAR_NO_MESSAGE;
		Processing(LIDAR_rx_msg_2, LIDAR_rx_msg_2_len);
	} else {
		//aucun message à traiter
	}
}

void Processing(uint8_t msg [], uint16_t len){
//	uint8_t Buf [150];
//	uint16_t Len;
//	LIDAR_get_message(Buf,&Len,msg,len);
	LIDAR_Status = LIDAR_Translation(msg,len);
	//robotPosition();
	//initialisationGlobal();
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size){
	LIDAR_uart_rx_interrupt_routine(huart,Size);
}

void LIDAR_Init(LIDAR_Descriptor_t * _Descriptor){
	Descriptor = _Descriptor;
	Flags.new_msg_1 = LIDAR_NO_MESSAGE;
	Flags.new_msg_2 = LIDAR_NO_MESSAGE;
}


/*LIDAR_Flag_New_Message_t LIDAR_is_new_message(void){
	return Flags.new_msg;
}*/

void LIDAR_get_message(uint8_t * dest, uint16_t *Size, uint8_t _msg[], uint16_t _len){
	memcpy(dest,_msg,_len);
	*Size = _len;
}




