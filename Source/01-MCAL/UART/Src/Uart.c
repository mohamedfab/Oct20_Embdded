/*
 * Uart.c
 *
 *  Created on: Sep 17, 2022
 *      Author: Eng_Fawzi
 */

#include "Uart_Reg.h"
#include "Uart.h"
#include "Std_Types.h"
#include "Bit_Math.h"

void USART_Init(u32 baud)
{
	u32 loc_UBBR_val = ((F_OSC/(16*baud))-1);
	/* Set baud rate */
	UART_UBRRH_REG = loc_UBBR_val>>8;
	UART_UBRRL_REG = loc_UBBR_val;
	/* Enable receiver and transmitter */
	UART_UCSRB_REG = (1<<UART_RXEN_BIT)|(1<<UART_TXEN_BIT);
	/* Set frame format: 8data, 2stop bit */
	UART_UCSRC_REG = (1<<UART_URSEL_BIT)|(1<<UART_USBS_BIT)|(3<<UART_UCSZ0_BIT);
}

void USART_TransmitChar(u8 data)
{
	/* Wait for empty transmit buffer */
	while (CHECK_BIT(UART_UCSRA_REG,UART_UDRE_BIT) == 0)
	{
		;
	}
		/* Put data into buffer, sends the data */
	UART_UDR_REG = data;
}

/*	it shall be called periodically	*/
u8 USART_Receive_NonBlock(void)
{
	/* Wait for data to be received */
	if (CHECK_BIT(UART_UCSRA_REG,UART_RXC_BIT) == 1)
	{
		/* Get and return received data from buffer */
		return UART_UDR_REG;
	}
	else
	{
		return 0;
	}
}

u8 USART_Receive_Block(void)
{
	/* Wait for data to be received */
	while(CHECK_BIT(UART_UCSRA_REG,UART_RXC_BIT) == 0)
	{
		;
	}
	/* Get and return received data from buffer */
	return UART_UDR_REG;
}

void USART_TransmitStr(u8 *str)
{
	while (*str != '\0')
	{
		USART_TransmitChar(*str);
		str++;
	}
}

void USART_ReceiveInterruptEnable(void)
{
	SET_BIT(UART_UCSRB_REG,UART_RXC_INT_BIT);
}

