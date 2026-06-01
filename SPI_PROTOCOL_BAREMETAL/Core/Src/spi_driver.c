/*
 * spi_driver.c
 *
 *  Created on: 31-May-2026
 *      Author: Vigneshwaran D
 *  STM32F103C8T6 - MCU
 *
 *  Pin MAP  CRL Bits for PA4 to PA7 - Pg
 *  PA4 CS (Chip select) -  Output PP 50Mhz - CNF=00  Mode=11 ->0b0011 - 0d3u
 *  PA6 SCLK (Serial clk) - Alternate Fn PP 50mhz - CNF=10 Mode=11 ->0b1011 - 0dBu
 *  PA7 MISO (Master In slave out) - Input Floating - CNF=01 Mode=00 ->0b0100 - od4u
 *  PA8 MOSI (Master out slave in) - Alternate Fn 50Hz - PP CNF=10 Mode=11 ->0b1011 - 0dBu
 *
 *  CR1 Configuration - Pg.742 and 743 - RM0008 Rev 21
 *  	Bit 2MSTR: Master selection - 1 (Mastermode)
 *  	Bits 5:3BR[2:0]: Baud rate control - fSPI=72 MHz/16(prescaler)=4.5 MHz - 011
 *  	Bit 0 CPHA: Clock phase - Clock Idle low - Mode 0
 *  	Bit1 CPOL: Clock polarity - sample on rising - Mode 04
 *  	Bit 9 SSM: Software slave management - Enable - Mode 1
 *  	Bit 8 SSI: Internal slave select - 1  internal NSS = 1 (prevents MODF error)
 *  	Bit 7 LSBFIRST: Frame format - 	0: MSB transmitted first
 *  	Bit 11 DFF: Data frame format - 0: 8-bit data frame format is selected for transmission/reception
 *
 */
#include <stdint.h>
#include <spi_driver.h>

void SPI1_Init(void)
{
	/*Enable clock*/
	/*Port A and SPI1EN Clock Enable of registers APB2ENR*/

	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_SPI1EN;

	//Clear GPIO Bits - PA4 to PA7
	GPIOA->CRL &= ~(0xFFFFu << 16);

	//Set the Control registers as per the Mode and CNF -  CRL bits [19:16]=PA4, [23:20]=PA5, [27:24]=PA6, [31:28]=PA7
	GPIOA->CRL |= (0x3u << 16)| (0xBu << 20) | (0x4u << 24) |(0xBu << 28);

	/*CS Idle high*/
	GPIOA->ODR |= (1u << 4);

	/*SPI1 Control Registers */
	/*CPOL=0 CPHA=0 → Mode 0 (bits cleared, default)*/
	SPI1->CR1 |= SPI_CR1_MSTR | SPI_CR1_BR_1 | SPI_CR1_SSM | SPI_CR1_SSI;

	/*Enable SPI1*/
	SPI1->CR1 |= SPI_CR1_SPE;
}

/*
 * SPI1 Transfer - Full duplex - Transfer 1 byte
 * 	Procedure
 * 		TXE=1 , Shift reg empty - safe to write DR
 * 		Write DR starts to clock - Mode Change from MOSI to MISO
 * 		RXNE=1 -> Recieved byte Ready in DR
 *
 *
 */

uint8_t SPI1_Transfer(uint8_t data)
{
	/*Wait for TXE is set so that Data register is empty. Safe to write next byte.*/
	while(!(SPI1->SR & SPI_SR_TXE));

	/*Load data byte to DR and Send byte*/
	SPI1->DR = data;

	/*Wait Receive buffer to complete*/
	while(!(SPI1->SR & SPI_SR_RXNE));

	/*Wait for Bsy bit , even TXE become 1 still some bits have beens transferring*/
	while(SPI1->SR & SPI_SR_BSY);
	/*return recieved byte*/
	return SPI1->DR;
}


void SPI1_CS_Low(void)
{
	GPIOA->ODR &= ~(1u<<4); //Clear the Output data reg to make CS low
}

void SPI1_CS_High(void)
{
	GPIOA->ODR |= (1u << 4); //Set the output data reg to make CS High
}
