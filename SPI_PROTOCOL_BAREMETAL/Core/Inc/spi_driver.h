/*
 * spi_driver.h
 *
 *  Created on: 31-May-2026
 *      Author: Anusiya
 */

#ifndef INC_SPI_DRIVER_H_
#define INC_SPI_DRIVER_H_

#include "stm32f1xx.h"
#include <stdint.h>

void SPI1_Init(void);

uint8_t SPI1_Transfer(uint8_t data); //Full duplex , sends+recieves 1 byte

void SPI1_CS_Low(void);

void SPI1_CS_High(void);

#endif /* INC_SPI_DRIVER_H_ */
