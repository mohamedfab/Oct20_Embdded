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


#define TIMER0_TCCR0_REG			(*(u8*)0x53)
#define TIMER0_TCNT0_REG			(*(u8*)0x52)
#define TIMER0_OCR0_REG				(*(u8*)0x5C)
#define TIMER0_TIMSK_REG			(*(u8*)0x59)
#define TIMER0_TIFR_REG				(*(u8*)0x58)

ISR(TIMER0_OVF_vect)
{
	/*	Take Your Action	*/
	SSD_viddisplyNum(12);
	TIMER0_TCNT0_REG = 7;
	/* Re Set the preload value */

}

ISR(TIMER0_COMP_vect)
{

}

int main()
{
	SSD_vidinit();
	Led_vidledInit();
	Button_vidbuttonInit();
	GINT_vidEnableAllInterrupts();
	/*	Enable Overflow interrupt	*/
	SET_BIT(TIMER0_TIMSK_REG,0);
	/*	set preload	*/
	TIMER0_TCNT0_REG = 7;
	/*	Set Prescaler	*/
	TIMER0_TCCR0_REG|=3;

	while (1)
	{

	}
	return 0;
}
