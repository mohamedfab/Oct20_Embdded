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

int main()
{
	u16 result;
	f64 volt=0;
	u8 voltDisply = 0;

	Lcd_vidinit();
	Lcd_vidCmd(_LCD_CURSOR_OFF);

	/*	Enable ADC	*/
	SET_BIT(ADC_ADCSRA_REG, 7);

	/*	Configure ADC prescaler	 /128*/
	ADC_ADCSRA_REG |= 7	/**/;

	/*	Select Vref +	AVCC	*/
	SET_BIT(ADC_ADMUX_REG,6);

	/*	select ADC channel	*/
//	 ADC_ADMUX_REG = (ADC_ADMUX_REG & 0xF8)|1;
	 ADC_ADMUX_REG |= 1;

	while (1)
	{
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
			 result=(ADC_ADCL_REG|(ADC_ADCH_REG<<8));

			 volt = result * 4.8;  /*mv*/
			 volt = volt/1000;		/*	v	*/
			 voltDisply = volt *10;
			// volt = 23;

		 Lcd_vidRowColumn(0, 0);
		 Lcd_vidDisplyStr("Volt=    ");
		 Lcd_vidRowColumn(0, 5);

		 Lcd_vidDisplyInt(voltDisply/10);
		 Lcd_vidDisplayChar('.');
		 Lcd_vidDisplyInt(voltDisply%10);

		 _delay_ms(500);
	}
	return 0;
}
