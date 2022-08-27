/*
 * Dio_reg.h
 *
 *  Created on: Aug 27, 2022
 *      Author: Eng_Fawzi
 */

#ifndef DIO_REG_H_
#define DIO_REG_H_

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


#endif /* DIO_REG_H_ */
