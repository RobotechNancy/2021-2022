/*
 * TOF.h
 *
 *  Created on: May 7, 2022
 *      Author: Samuel
 */

#ifndef IMPLEMENTATION_TOF_H_
#define IMPLEMENTATION_TOF_H_

#include "../Inc/vl53l0x_api.h"
#include "../Implementation/TOF_Units.h"
#include "TOF_Errors.h"

TOF_Status_t TOF_Init(void);
TOF_Status_t TOF_Get_Range(TOF_Units_t unit, uint16_t max_retries, uint16_t *range_milimeters, uint8_t *range_status);

#endif /* IMPLEMENTATION_TOF_H_ */
