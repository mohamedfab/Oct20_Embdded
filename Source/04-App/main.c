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

int main()
{
	Led_vidledInit();
	SSD_vidinit();
	while (1)
	{
		SSD_viddisplyNum(85);
	}
	return 0;
}
