 /**********************************************************************************************************************
 *  File		: Eeprom.c
 *	Module		: EEPROM
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 *********************************************************************************************************************/
#include <Eeprom.h>

void EEPROM_Write(u16 address,u8 data)
{
	/* Wait for completion of previous write */
	while(EEPROM_CR_REG & (1<<EEWE))
		/*	Do Nothing	*/		;
	/* Set up address and data registers */
	EEPROM_ARL_REG=address;
	EEPROM_ARH_REG = address>>8;
	EEPROM_DR_REG = data;
	/* Write logical one to EEMWE */
	EEPROM_CR_REG |= (1<<EEMWE);
	/* Start eeprom write by setting EEWE */
	EEPROM_CR_REG |= (1<<EEWE);
}

u8 EEPROM_Read(u16 address)
{
	/* Wait for completion of previous write */
	while(EEPROM_CR_REG & (1<<EEWE))
			;
	/* Set up address register */
	EEPROM_ARL_REG	=address;
	EEPROM_ARH_REG = address>>8;
	/* Start eeprom read by writing EERE */
	EEPROM_CR_REG |= (1<<EERE);
	/* Return data from data register */
	return EEPROM_DR_REG;
}
/**********************************************************************************************************************
 *  END OF FILE: Eeprom.c
 *********************************************************************************************************************/
