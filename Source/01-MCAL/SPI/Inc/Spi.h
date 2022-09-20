 /*************************************************
 *  File		: Spi.h
 *	Module		: SPI
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 **************************************************/
#ifndef SPI_H
#define SPI_H

#include "Spi_Reg.h"
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Dio.h"

#define SPI_SCK_FREQ_FCPU_DIV_4			(0<<0)
#define SPI_SCK_FREQ_FCPU_DIV_16		(1<<0)
#define SPI_SCK_FREQ_FCPU_DIV_64		(2<<0)
#define SPI_SCK_FREQ_FCPU_DIV_128		(3<<0)

#define SPI_SPE_BIT_NO           	(6)
#define SPI_MSTR_BIT_NO				(4)
#define SPI_SPIF_BIT_NO				(7)

void Spi_vidMasterInit(void);
void Spi_vidSlaveInit(void);
void Spi_MasterWrite(u8 data);
u8 Spi_u8MasterRead(void);
u8 Spi_u8MasterTranseve(u8 data);

u8 Spi_u8SlaveRead(void);
void Spi_vidSlaveWrite(u8 data);
#endif  /* UART_H */
