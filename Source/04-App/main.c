/***************************************
 * main.c
 *
 *  Created on: Aug 23, 2022
 *  Author: Eng_Fawzi
 ***************************************/

#include "Std_Types.h"
#include "Bit_Math.h"
#include <util/delay.h>
#include "Led.h"
#include "SSD.h"
#include "Lcd.h"
#include <stdio.h>
#include "Button.h"
#include "GINT.h"
#include <avr/interrupt.h>
#include "Uart.h"
#include "Eeprom24C16.h"

/*	Slave Code*/
int main()
{
	Lcd_vidinit();
	Eeprom24C16_Init();
	while (1)
	{

	}
	return 0;
}
