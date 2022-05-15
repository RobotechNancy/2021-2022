/*
 * PollingRoutines.h
 *
 *  Created on: 5 mai 2022
 *      Author: Samuel
 */

#ifndef INC_POLLINGROUTINES_H_
#define INC_POLLINGROUTINES_H_

#ifdef _cplusplus
extern "C" {
#endif

#define UART_BUF_SIZE 16

void PollingInit();
void PollingRoutine();

#ifdef _cplusplus
}
#endif

#endif /* INC_POLLINGROUTINES_H_ */
