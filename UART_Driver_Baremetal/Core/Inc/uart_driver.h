/*
 * uart_driver.h
 *
 *  Created on: 03-Jun-2026
 *      Author: Vigneshwaran D
 */

#ifndef INC_UART_DRIVER_H_
#define INC_UART_DRIVER_H_

#include "stm32f1xx.h"
#include <stdint.h>

void UART_Init(void);

void UART_Sendbyte(uint8_t byte);

void  UART_Sendstring(const char *str);

uint8_t UART_Read(void);

uint8_t UART_DataAvailable(void);

#endif /* INC_UART_DRIVER_H_ */
