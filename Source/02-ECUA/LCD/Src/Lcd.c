/*
 * Lcd.c
 *
 *  Created on: Aug 31, 2022
 *      Author: Eng_Fawzi
 */

#include "Lcd.h"
#include "Dio.h"
#include "util/delay.h"
#include <stdio.h>


void Lcd_vidinit(void)
{
	/*	configure control pins as output	*/
	Dio_vidconfigChanel(DIO_PORTB, DIO_PIN1, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTB, DIO_PIN2, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTB, DIO_PIN3, DIO_OUTPUT);

	/*	configure data pins as output	*/
	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN4, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN5, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN6, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTA, DIO_PIN7, DIO_OUTPUT);

	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN2, DIO_LOW);

	_delay_ms(15);

	Lcd_vidCmd(0x03);
	_delay_ms(5);
	Lcd_vidCmd(0x03);
	_delay_us(100);
	Lcd_vidCmd(0x03);
	Lcd_vidCmd(0x02);
	Lcd_vidCmd(_LCD_4BIT_MODE);
}

static void Lcd_videnablePulse(void)
{
	//send Enable pulse
	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN3, DIO_HIGH);
	_delay_us(1);
	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN3, DIO_LOW);
	_delay_ms(2);
}
void Lcd_vidDisplayChar(u8 chr)
{
	/*
	  MSB    LSB
	0b1101  1001

	1101   0000
	1001   0000
*/
	u8 loc_MSB = (chr & ~LCD_MASK);
	u8 loc_LSB = (chr<<4);
	//RS->1
	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN1, DIO_HIGH);

	//write data MSB to LCD
	Dio_vidWriteChanelGroup(DIO_PORTA, loc_MSB, LCD_MASK);
	//send Enable pulse
	Lcd_videnablePulse();

	//write data LSB to LCD
	Dio_vidWriteChanelGroup(DIO_PORTA, loc_LSB, LCD_MASK);
	//send Enable pulse
	Lcd_videnablePulse();
}
void Lcd_vidCmd(lcd_Cmd_t cmd)
{
	u8 loc_MSB = cmd & ~LCD_MASK;
	u8 loc_LSB = cmd<<4;
	//RS->0
	Dio_vidwriteChanel(DIO_PORTB, DIO_PIN1, DIO_LOW);

	//write data MSB to LCD
	Dio_vidWriteChanelGroup(DIO_PORTA, loc_MSB, LCD_MASK);
	//send Enable pulse
	Lcd_videnablePulse();

	//write data LSB to LCD
	Dio_vidWriteChanelGroup(DIO_PORTA, loc_LSB, LCD_MASK);
	//send Enable pulse
	Lcd_videnablePulse();
}

void Lcd_vidRowColumn(u8 row, u8 col)
{
	switch (row)
	{
	case 0:
		Lcd_vidCmd(0x80 + col);
		break;

	case 1:
		Lcd_vidCmd(0xC0 + col);
		break;
	}
}
void Lcd_vidDisplyStr(u8* str)
{
	while (*str != '\0')
	{
		Lcd_vidDisplayChar(*str);
		str++;
	}
}

void Lcd_vidDisplyInt(u32 num)
{
	u8 buffer[5];
	sprintf(buffer,"%d",num);
	Lcd_vidDisplyStr(buffer);
}
