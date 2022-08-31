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

int main()
{
	u8 cntr =0;
	u8 customChar[] = {
	  0b01110,
	  0b11111,
	  0b10001,
	  0b10001,
	  0b10001,
	  0b10001,
	  0b10001,
	  0b11111
	};


	Lcd_vidinit();
	for (cntr=0; cntr<8; cntr++)
	{
		Lcd_vidCmd(0x40+cntr); /* */
		Lcd_vidDisplayChar(customChar[cntr]);
	}

	Lcd_vidRowColumn(0, 0);  /*DDRAM*/
	Lcd_vidDisplayChar(0);

	Led_vidledInit();
	SSD_vidinit();
	Lcd_vidRowColumn(0, 0);
	Lcd_vidDisplyStr("    ");
	Lcd_vidRowColumn(0, 0);

	while (1)
	{

	}
	return 0;
}
