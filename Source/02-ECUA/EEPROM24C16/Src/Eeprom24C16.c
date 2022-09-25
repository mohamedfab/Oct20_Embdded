 /**********************************************************************************************************************
 *  File		: Eeprom24C16.c
 *	Module		: Eeprom24C16
 *	Target		: General
 *	Author		: mFawzi
 *  Description	:      
 * 
 *********************************************************************************************************************/

#include <util/delay.h>
#include "Eeprom24C16.h"
#include "Lcd.h"
void Eeprom24C16_Init(void)
{
	I2C_MasterInit();
}

/*	addr = 0 to 2047	*/
void Eeprom24C16_WriteByte(u16 addr, u8 data)
{
	u8 loc_pageNo = (addr/256);
	u8 loc_byteNo = (addr%256);

	I2C_StartCondition();

	I2C_Send_SlaveAddressWriteOperation( 0x50 | loc_pageNo);
	I2C_WriteByte(loc_byteNo);
	I2C_WriteByte(data);
	I2C_StopCondition();
	_delay_ms(10);
}

/*	addr = 0 to 2047	*/
u8 Eeprom24C16_ReadByte(u16 addr)
{
	u8 loc_pageNo = (addr/256);
	u8 loc_byteNo = (addr%256);
	u8 loc_dataRead=0;
	I2C_StartCondition();
	I2C_Send_SlaveAddressWriteOperation( 0x50 | loc_pageNo);
	I2C_WriteByte(loc_byteNo);
	I2C_RepeatedStartCondition();
	I2C_Send_SlaveAddressReadOperation( 0x50 | loc_pageNo);
	loc_dataRead = I2C_ReadByte();
	I2C_StopCondition();
	return loc_dataRead;
}
/**********************************************************************************************************************
 *  END OF FILE: Eeprom24C16.c
 *********************************************************************************************************************/
