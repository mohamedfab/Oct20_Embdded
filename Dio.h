/*
 * Dio.h
 *
 *  Created on: Aug 26, 2022
 *      Author: Eng_Fawzi
 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"

#define DIO_DDRA_REG    		 (*(u8*)0x3A)
#define DIO_PORTA_REG	 		 (*(u8*)0x3B)
#define DIO_PINA_REG			 (*(u8*)0x39)

#define DIO_DDRB_REG			 (*(u8*)0x37)
#define DIO_PORTB_REG			 (*(u8*)0x38)
#define DIO_PINB_REG			 (*(u8*)0x36)

#define DIO_DDRC_REG	 		 (*(u8*)0x34)
#define DIO_PORTC_REG	 		 (*(u8*)0x35)
#define DIO_PINC_REG	         (*(u8*)0x33)

#define DIO_DDRD_REG	 		 (*(u8*)0x31)
#define DIO_PORTD_REG	 		 (*(u8*)0x32)
#define DIO_PIND_REG	         (*(u8*)0x30)


typedef enum
{
	DIO_PORTA,
	DIO_PORTB,
	DIO_PORTC,
	DIO_PORTD
}dio_port_t;

typedef enum
{
	DIO_PIN0,
	DIO_PIN1,
	DIO_PIN2,
	DIO_PIN3,
	DIO_PIN4,
	DIO_PIN5,
	DIO_PIN6,
	DIO_PIN7
}dio_pin_t;

typedef enum
{
	DIO_INPUT,
	DIO_OUTPUT
}dio_dir_t;

typedef enum
{
	DIO_LOW,
	DIO_HIGH
}dio_level_t;

void Dio_vidconfigChanel(dio_port_t port, dio_pin_t pin, dio_dir_t dir);
void Dio_vidwriteChanel(dio_port_t port, dio_pin_t pin, dio_level_t level);
dio_level_t Dio_udtreadChanel(dio_port_t port, dio_pin_t pin);



#endif /* DIO_H_ */
