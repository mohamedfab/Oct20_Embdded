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


/*	Slave Code*/
int main()
{
	u8 loc_spiReceive = 0;
	Spi_vidSlaveInit();
	Led_vidledInit();

	while (1)
	{
		loc_spiReceive = Spi_u8SlaveRead();

		if (loc_spiReceive == 'a')
		{
			Led_vidledToggle(LED0);
		}
	}
	return 0;
}
