/*
 * PMW3091.h
 *
 *  Created on: May 9, 2022
 *      Author: ncm69
 */

#ifndef INC_PMW3091_H_
#define INC_PMW3091_H_

#include <stdbool.h>
#include "stm32f3xx_hal.h"

typedef struct {
	SPI_HandleTypeDef *hspi;
	GPIO_TypeDef *CS_Port;
	uint16_t CS_Pin;
} PMW3901_Descriptor_t;

typedef enum {
	PMW3901_SUCCESS = 0, // TOUT BON
	PMW3901_ERROR_UNKNOWN_ID, // Product_ID pas bon
	PMW3901_ERROR_SPI, //
}PMW3901_Status_t;



PMW3901_Status_t PMW3901_Init(PMW3901_Descriptor_t *_Descriptor);

PMW3901_Status_t PMW3901_Read_Variation(int16_t *x, int16_t *y);

PMW3901_Status_t setLed(void);

PMW3901_Status_t Pmw3091_Init(void);

#endif /* INC_PMW3091_H_ */
