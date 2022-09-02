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
	u8 counter = 0;
	u16 delay = 0;
	SSD_vidinit();
	while (1)
	{
	 SSD_viddisplyNum(counter);

	 for (delay=0; delay<1000;delay++)
	 {
		 _delay_ms(1);
		 SSD_viddisplyNum(counter);
	 }

//	 _delay_ms(1000);

	 counter++;

	 if (counter == 100)
	 {
		 counter = 00;
	 }


	}
	return 0;
}
