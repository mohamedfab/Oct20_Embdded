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


int main()
{
	Led_vidledInit();
	while (1)
	{
		Led_vidledOn(LED0);
		_delay_ms(500);			/*	wait	*/
		Led_vidledOff(LED0);
		_delay_ms(500);			/*	wait	*/
	}
	return 0;
}
