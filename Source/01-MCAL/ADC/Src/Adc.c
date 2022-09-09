/*
 * Adc.c
 *
 *  Created on: Sep 9, 2022
 *      Author: Eng_Fawzi
 */
#include "Adc.h"
#include "Adc_Reg.h"
#include "Adc_Types.h"
#include "Bit_Math.h"

void Adc_vidInit(void)
{

	/*	Enable ADC	*/
	SET_BIT(ADC_ADCSRA_REG, 7);
	/*	Configure ADC prescaler	 /128	*/
	ADC_ADCSRA_REG |= 7 /*0000 0111*/;
	/*	Select Vref +	AVCC	*/
	SET_BIT(ADC_ADMUX_REG,6);
}

f64 Adc_u16AdcRead(adc_channlId_t channel)
{
	u16 loc_adcResult = 0;
	f64 loc_volt =0;
	/*	select ADC channel	*/
	ADC_ADMUX_REG =  (ADC_ADMUX_REG & 0xF8)| channel;
	/*	Start ADC conversion	*/
	SET_BIT(ADC_ADCSRA_REG,6);

	/*	wait until ADIF flag become 1 */
	while(CHECK_BIT(ADC_ADCSRA_REG,4) !=1)
	{
		/*	Do Nothing	*/
	}

	/*	clear ADIF by writing 1 	*/
	SET_BIT(ADC_ADCSRA_REG,4);

	/*	read ADC result form ADCL, ADCH	*/
	loc_adcResult=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));

	loc_volt = loc_adcResult * ADC_STEP;
	return loc_volt;
}
