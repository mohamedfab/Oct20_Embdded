/*
 * Uart.h
 *
 *  Created on: Sep 17, 2022
 *      Author: Eng_Fawzi
 */

#ifndef SOURCE_01_MCAL_UART_INC_UART_H_
#define SOURCE_01_MCAL_UART_INC_UART_H_
#include "Std_Types.h"
#include "Uart_Reg.h"

#define F_OSC			16000000


#define UART_UDRE_BIT		(5)
#define UART_RXC_BIT		(7)
#define UART_RXEN_BIT		(4)
#define UART_TXEN_BIT		(3)
#define UART_URSEL_BIT		(7)
#define UART_USBS_BIT		(3)
#define UART_UCSZ0_BIT		(1)
#define UART_RXC_INT_BIT	(7)

void USART_Init(u32 baud);
void USART_TransmitChr(u8 data);
void USART_TransmitStr(u8 *str);
u8 USART_Receive_Block(void);
u8 USART_Receive_NonBlock(void);
void USART_ReceiveInterruptEnable(void);

#endif /* SOURCE_01_MCAL_UART_INC_UART_H_ */
