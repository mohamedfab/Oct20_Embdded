/*
 * Dio.c
 *
 *  Created on: Aug 26, 2022
 *      Author: Eng_Fawzi
 */
#include "Dio.h"
#include "Bit_Math.h"


void Dio_vidClockEnable(dio_port_t port)
{
    switch(port)
    {
    case DIO_PORTA:
        SET_BIT(DIO_RCGC2_REG,0);
        break;

    case DIO_PORTB:
         SET_BIT(DIO_RCGC2_REG,1);
         break;

    case DIO_PORTC:
         SET_BIT(DIO_RCGC2_REG,2);
         break;

    case DIO_PORTD:
         SET_BIT(DIO_RCGC2_REG,3);
         break;

    case DIO_PORTE:
         SET_BIT(DIO_RCGC2_REG,4);
         break;

    case DIO_PORTF:
         SET_BIT(DIO_RCGC2_REG,5);
         break;

    }
}

void Dio_vidDigitalEnable(dio_port_t port, dio_pin_t pin)
{
    switch(port)
    {
        case DIO_PORTA:
            SET_BIT(DIO_GPIODEN_PORTA_REG,pin);
            break;

        case DIO_PORTB:
                SET_BIT(DIO_GPIODEN_PORTB_REG,pin);
                break;

        case DIO_PORTC:
                SET_BIT(DIO_GPIODEN_PORTC_REG,pin);
                break;

        case DIO_PORTD:
                SET_BIT(DIO_GPIODEN_PORTD_REG,pin);
                break;

        case DIO_PORTE:
                SET_BIT(DIO_GPIODEN_PORTE_REG,pin);
                break;

        case DIO_PORTF:
                SET_BIT(DIO_GPIODEN_PORTF_REG,pin);
                break;
    }
}


void Dio_vidConfigChanel(dio_port_t port, dio_pin_t pin,dio_dir_t dir)
{
	switch(port)
	{
	case DIO_PORTA:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DIO_GPIODIR_PORTA_REG,pin);
		}
		else
		{
			SET_BIT(DIO_GPIODIR_PORTA_REG,pin);
		}
		break;

	case DIO_PORTB:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DIO_GPIODIR_PORTB_REG,pin);
		}
		else
		{
			SET_BIT(DIO_GPIODIR_PORTB_REG,pin);
		}
		break;

	case DIO_PORTC:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DIO_GPIODIR_PORTC_REG,pin);
		}
		else
		{
			SET_BIT(DIO_GPIODIR_PORTC_REG,pin);
		}
		break;

	case DIO_PORTD:
		if (dir == DIO_INPUT)
		{
			CLEAR_BIT(DIO_GPIODIR_PORTD_REG,pin);
		}
		else
		{
			SET_BIT(DIO_GPIODIR_PORTD_REG,pin);
		}
		break;

    case DIO_PORTE:
        if (dir == DIO_INPUT)
        {
            CLEAR_BIT(DIO_GPIODIR_PORTE_REG,pin);
        }
        else
        {
            SET_BIT(DIO_GPIODIR_PORTE_REG,pin);
        }
        break;

    case DIO_PORTF:
        if (dir == DIO_INPUT)
        {
            CLEAR_BIT(DIO_GPIODIR_PORTF_REG,pin);
        }
        else
        {
            SET_BIT(DIO_GPIODIR_PORTF_REG,pin);
        }
        break;
	}
}

void Dio_vidWriteChanel(dio_port_t port, dio_pin_t pin,dio_level_t level)
{
	switch (port)
	{
	case DIO_PORTA:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_GPIODATA_PORTA_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_GPIODATA_PORTA_REG,pin);
		}
		break;

	case DIO_PORTB:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_GPIODATA_PORTB_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_GPIODATA_PORTB_REG,pin);
		}
		break;

	case DIO_PORTC:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_GPIODATA_PORTC_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_GPIODATA_PORTC_REG,pin);
		}
		break;

	case DIO_PORTD:
		if (level == DIO_HIGH)
		{
			SET_BIT(DIO_GPIODATA_PORTD_REG,pin);
		}
		else
		{
			CLEAR_BIT(DIO_GPIODATA_PORTD_REG,pin);
		}
		break;

    case DIO_PORTE:
        if (level == DIO_HIGH)
        {
            SET_BIT(DIO_GPIODATA_PORTE_REG,pin);
        }
        else
        {
            CLEAR_BIT(DIO_GPIODATA_PORTE_REG,pin);
        }
        break;

    case DIO_PORTF:
        if (level == DIO_HIGH)
        {
            SET_BIT(DIO_GPIODATA_PORTF_REG,pin);
        }
        else
        {
            CLEAR_BIT(DIO_GPIODATA_PORTF_REG,pin);
        }
        break;
	}
}


dio_level_t Dio_udtreadChanel(dio_port_t port, dio_pin_t pin)
{
	dio_level_t loc_result = DIO_LOW;

	switch (port)
	{
	case DIO_PORTA:
		if (CHECK_BIT(DIO_GPIODATA_PORTA_REG,pin) == 1)
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

	case DIO_PORTB:
		if (CHECK_BIT(DIO_GPIODATA_PORTB_REG,pin) == 1)
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

	case DIO_PORTC:
		if (CHECK_BIT(DIO_GPIODATA_PORTC_REG,pin) == 1)
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

	case DIO_PORTD:
		if (CHECK_BIT(DIO_GPIODATA_PORTD_REG,pin) == 1)
		{
			loc_result = DIO_HIGH;
		}
		else
		{
			loc_result = DIO_LOW;
		}
		break;

    case DIO_PORTE:
        if (CHECK_BIT(DIO_GPIODATA_PORTE_REG,pin) == 1)
        {
            loc_result = DIO_HIGH;
        }
        else
        {
            loc_result = DIO_LOW;
        }
        break;

    case DIO_PORTF:
           if (CHECK_BIT(DIO_GPIODATA_PORTF_REG,pin) == 1)
           {
               loc_result = DIO_HIGH;
           }
           else
           {
               loc_result = DIO_LOW;
           }
           break;
	}
	return loc_result;
}
