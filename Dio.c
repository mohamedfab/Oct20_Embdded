/*
 * Dio.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Eng_Fawzi
 */
#include "Dio.h"
#include "Bit_Math.h"

void Dio_vidconfigChanel(dio_port_t port, dio_pin_t pin, dio_dir_t dir)
{
	switch (port)
	{
	case DIO_PORTA:
		{
			if (dir == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRA_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRA_REG,pin);
			}
			break;
		}

	case DIO_PORTB:
		{
			if (dir == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRB_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRB_REG,pin);
			}
			break;
		}

	case DIO_PORTC:
		{
			if (dir == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRC_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRC_REG,pin);
			}
			break;
		}

	case DIO_PORTD:
		{
			if (dir == DIO_INPUT)
			{
				CLEAR_BIT(DIO_DDRD_REG,pin);
			}
			else
			{
				SET_BIT(DIO_DDRD_REG,pin);
			}
			break;
		}
	}
}

void Dio_vidwriteChanel(dio_port_t port, dio_pin_t pin, dio_level_t level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTA_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTA_REG,pin);
		}
		break;

	case DIO_PORTB:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTB_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTB_REG,pin);
		}
		break;

	case DIO_PORTC:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTC_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTC_REG,pin);
		}
		break;

	case DIO_PORTD:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_PORTD_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_PORTD_REG,pin);
		}
		break;
	}
}
