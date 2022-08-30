/*
 * Button.c
 *
 *  Created on: Aug 27, 2022
 *      Author: Eng_Fawzi
 */
#include "Button.h"
#include "Dio.h"
void Button_vidbuttonInit(void)
{
	Dio_vidconfigChanel(DIO_PORTB,DIO_PIN0,DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTB,DIO_PIN4,DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTD,DIO_PIN2,DIO_INPUT);
}

button_butStatus_t Button_udtbuttonStatus(button_buttonId_t butnId)
{
	button_butStatus_t loc_btnStatus = RELEASED;

	switch (butnId)
	{
	case BUTTON0:
		if (Dio_udtreadChanel(DIO_PORTB, DIO_PIN0) == DIO_HIGH)
		{
			loc_btnStatus = PRESSED;
		}
		else
		{
			loc_btnStatus = RELEASED;
		}
		break;

	case BUTTON1:
		if (Dio_udtreadChanel(DIO_PORTB, DIO_PIN4) == DIO_HIGH)
		{
			loc_btnStatus = PRESSED;
		}
		else
		{
			loc_btnStatus = RELEASED;
		}
		break;

	case BUTTON2:
		if (Dio_udtreadChanel(DIO_PORTD, DIO_PIN2) == DIO_HIGH)
		{
			loc_btnStatus = PRESSED;
		}
		else
		{
			loc_btnStatus = RELEASED;
		}
		break;
	}
	return loc_btnStatus;
}

