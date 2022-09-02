/*
 * Keypad.c
 *
 *  Created on: Sep 2, 2022
 *      Author: Eng_Fawzi
 */

#include "Keypad_Types.h"
#include "Keypad.h"
#include "Dio.h"

#include "Std_Types.h"


u8 Keypad_Layout[4][4] ={
		{'1','2','3','A'},
		{'4','5','6','B'},
		{'7','8','9','C'},
		{'*','0','#','D'}
};

void Keypad_vidinit(void)
{
	/*	Configure Rows Pins as input	*/
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN0, DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN1, DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN2, DIO_INPUT);
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN3, DIO_INPUT);

	/*	Configure Columns Pins as output	*/
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN4, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN5, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN6, DIO_OUTPUT);
	Dio_vidconfigChanel(DIO_PORTC, DIO_PIN7, DIO_OUTPUT);

	/*	initialize output columns with high	*/
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_HIGH);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_HIGH);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_HIGH);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_HIGH);
}

boolean Keypad_udtIsPressed()
{
	if (
			(Dio_udtreadChanel(DIO_PORTC, DIO_PIN0) == DIO_HIGH)||
			(Dio_udtreadChanel(DIO_PORTC, DIO_PIN1) == DIO_HIGH)||
			(Dio_udtreadChanel(DIO_PORTC, DIO_PIN2) == DIO_HIGH)||
			(Dio_udtreadChanel(DIO_PORTC, DIO_PIN3) == DIO_HIGH)
	)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

kp_row_t Keypad_udtgetRow(void)
{
	kp_row_t loc_row = KP_NOROW;

	if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN0) == DIO_HIGH)
	{
		loc_row=KP_ROW0;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN1) == DIO_HIGH)
	{
		loc_row=KP_ROW1;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN2) == DIO_HIGH)
	{
		loc_row=KP_ROW2;
	}
	else if (Dio_udtreadChanel(DIO_PORTC, DIO_PIN3) == DIO_HIGH)
	{
		loc_row=KP_ROW3;
	}
	else
	{
		loc_row = KP_NOROW;
	}
	return loc_row;
}

kp_col_t Keypad_udtgetCol(kp_row_t current_row)
{
	kp_col_t loc_column = KP_NOCOL;

	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_HIGH);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_LOW);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_LOW);
	Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_LOW);

	if (Keypad_udtgetRow() == current_row)
	{
		loc_column = KP_COL0;
	}
	else
	{
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_LOW);
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_HIGH);
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_LOW);
		Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_LOW);

		if (Keypad_udtgetRow() == current_row)
		{
			loc_column = KP_COL1;
		}
		else
		{
			Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_LOW);
			Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_LOW);
			Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_HIGH);
			Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_LOW);

			if (Keypad_udtgetRow() == current_row)
			{
				loc_column = KP_COL2;
			}
			else
			{
				Dio_vidwriteChanel(DIO_PORTC, DIO_PIN4, DIO_LOW);
				Dio_vidwriteChanel(DIO_PORTC, DIO_PIN5, DIO_LOW);
				Dio_vidwriteChanel(DIO_PORTC, DIO_PIN6, DIO_LOW);
				Dio_vidwriteChanel(DIO_PORTC, DIO_PIN7, DIO_HIGH);

				if (Keypad_udtgetRow() == current_row)
				{
					loc_column = KP_COL3;
				}
				else
				{

				}
			}
		}
	}
	return loc_column;
}

u8 Keypad_u8GetButton(void)
{
	kp_row_t loc_row = KP_NOROW;
	kp_col_t loc_col = KP_NOCOL;
	u8 loc_button = 0xFF;

	Keypad_vidinit();

	if (Keypad_udtIsPressed() == TRUE)
	{
		loc_row = Keypad_udtgetRow();
		loc_col = Keypad_udtgetCol(loc_row);
		loc_button = Keypad_Layout[loc_row][loc_col];
	}
	else
	{

	}
	return loc_button;
}
