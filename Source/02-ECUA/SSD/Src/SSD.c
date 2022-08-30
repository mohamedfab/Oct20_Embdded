/*
 * SSD.c
 *
 *  Created on: Aug 30, 2022
 *      Author: Eng_Fawzi
 */

#include "SSD.h"
#include "Dio.h"
#include <util/delay.h>

void SSD_vidinit(void)
{
	Dio_vidconfigChanel(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);

	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN5, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN6, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN7, DIO_OUTPUT);
}

void SSD_viddisplyNum(u8 num)
{
	u8 loc_secondDigit =  (num%10)<<4;
	u8 loc_firstDigit = (num/10)<<4;

	/* Enable SSD 1	-> EN1 = High	*/
	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN2, DIO_HIGH);
	/* Disable SSD 2 -> EN2 =Low	*/
	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN1, DIO_LOW);
	/* Write first digit */
	Dio_vidWriteChanelGroup(DIO_PORTA, loc_firstDigit, SSD_MASK);

	_delay_ms(1);

	/* Disable SSD 1	-> EN1 = Low	*/
	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN2, DIO_LOW);
	/* Enable SSD 2 -> EN2 = High	*/
	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN1, DIO_HIGH);
	/* Write second digit */
	Dio_vidWriteChanelGroup(DIO_PORTA, loc_secondDigit, SSD_MASK);

	_delay_ms(1);
}
