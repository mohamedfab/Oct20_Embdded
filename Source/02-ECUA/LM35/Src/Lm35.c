/*
 * Lm35.c
 *
 *  Created on: Sep 9, 2022
 *      Author: Eng_Fawzi
 */

#include "Std_Types.h"
#include "Adc.h"

void Lm35_vidInit(void)
{
	Adc_vidInit();
}
u16 Lm35_u8TempRead(void)
{
	f64 loc_adcRead = 0;
	u16 loc_temp = 0;

	loc_adcRead = Adc_u16AdcRead(ADC_CHANNEL1);
	loc_temp = loc_adcRead/10;

	return loc_temp;
}
