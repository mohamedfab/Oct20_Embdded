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

		/*	ADC Registers	*/
#define ADC_ADMUX_REG       (*(volatile u8*)0x27)
#define ADC_ADCSRA_REG		(*(volatile u8*)0x26)
#define ADC_ADCH_REG		(*(volatile u8*)0x25)
#define ADC_ADCL_REG		(*(volatile u8*)0x24)

//
//ISR(INT0_vect)
//{
//	/*	Toggle LED1	*/
//	Led_vidledToggle(LED1);
//}


int main()
{
	u16 result;

	/*	Enable ADC	*/
	SET_BIT(ADC_ADCSRA_REG, 7);
	/*	Configure ADC prescaler	*/
	ADC_ADCSRA_REG |= 7;
	/*	Select Vref +	AVCC	*/
	SET_BIT(ADC_ADMUX_REG,6);
	/*	select ADC channel	*/
	 ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|3;
	/*	Start ADC conversion	*/
	 SET_BIT(ADC_ADCSRA_REG,6);
	/*	wait until ADIF flag become 1 */
	 	while(CHK_BIT(ADC_ADCSRA_REG,4) !=1)
	 		  {
	 		  	  /*	Do Nothing	*/
	 		  }
	 /*	clear ADIF by writing 1 	*/
	 SET_BIT(ADC_ADCSRA_REG,4);
	/*	read ADC result form ADCL, ADCH	*/
	 result=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));

	while (1)
	{

	}
	return 0;
}
