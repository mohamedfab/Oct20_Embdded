 /*********************************************
 *  File		: I2c.c
 *	Module		: I2C
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *
 ***********************************************/
#include "I2c.h"

void I2C_MasterInit(void)
{
    /* Bit Rate: 400 KHZ */
	I2C_TWBR_REG=0x0C;
    /* enable I2C Module	*/
	/* enable ACK check	*/
	I2C_TWCR_REG |=I2C_ENABLE|I2C_ENABLE_ACK;
}

void I2C_SlaveInit(u8 addr)
{
	/*	enable general call response in slave mode	*/
	SET_BIT(I2C_TWAR_REG,I2C_SLAVE_RESPONSE_BIT_NO);
    /* I2C Bus Slave Address	*/
	I2C_TWAR_REG |= (addr<<1);
    /* enable I2C Module	*/
	/*	enable ACK check	*/
	I2C_TWCR_REG |=I2C_ENABLE|I2C_ENABLE_ACK;
}
boolean I2C_StartCondition(void)
{
	/*	send start condition	*/
	I2C_TWCR_REG = I2C_ENABLE|I2C_INTERRUPT_FLAG|I2C_START_COND;
    /*	Wait until start condition sent successfully	*/
    while (CHECK_BIT(I2C_TWCR_REG,I2C_INTERRUPT_FLAG_BIT_NO)==0)
    {
    	/*Do Nothing */
    	   ;
    }

    if (I2C_ReadStatus() != I2C_START_ACK)
    {
    	return FALSE;
    }
    else
    {
    	/*	Do Nothing	*/
    }
    return TRUE;
}
boolean I2C_RepeatedStartCondition(void)
{
	/*	send start condition	*/
	I2C_TWCR_REG |= I2C_ENABLE|I2C_INTERRUPT_FLAG|I2C_START_COND;
    /*	Wait until start condition sent successfully	*/
    while (CHECK_BIT(I2C_TWCR_REG,I2C_INTERRUPT_FLAG_BIT_NO)==0)
    {
    	/*Do Nothing */
    	   ;
    }
    if (I2C_ReadStatus() != I2C_REP_START_ACK)
    {
    	return FALSE;
    }
    else
    {
    	/*	Do Nothing	*/
    }
    return TRUE;
}
void I2C_StopCondition(void)
{
	/*	send stop condition	*/
	I2C_TWCR_REG |= I2C_ENABLE|I2C_INTERRUPT_FLAG|I2C_STOP_COND;
	/*	Wait until start condition sent successfully	*/
    while (CHECK_BIT(I2C_TWCR_REG,I2C_INTERRUPT_FLAG_BIT_NO)==0)
    {
    	/*Do Nothing */
    	   ;
    }
}
void I2C_WriteByte(u8 data)
{
    /*	Put data On I2C data Register	*/
	I2C_TWDR_REG = data;

    /*	Send byte	*/
	I2C_TWCR_REG |= I2C_ENABLE|I2C_INTERRUPT_FLAG;



	/*	Wait until data sent successfully	*/
    while (CHECK_BIT(I2C_TWCR_REG,I2C_INTERRUPT_FLAG_BIT_NO)==0)
    {
    	/*Do Nothing */
    	   ;
    }
}
boolean I2C_Send_SlaveAddressWriteOperation(u8 addr)
{
	u8 loc_addrWrite=0;
	loc_addrWrite=(addr<<1);
	I2C_WriteByte(loc_addrWrite);
    if (I2C_ReadStatus() != I2C_SLA_W_ACK)
    {
    	return FALSE;
    }
    else
    {
    	/*	Do Nothing	*/
    }
    return TRUE;

}
boolean I2C_Send_SlaveAddressReadOperation(u8 addr)
{
	u8 loc_addrWrite=0;
	loc_addrWrite=(addr<<1)|(0x01);
	I2C_WriteByte(loc_addrWrite);
    if (I2C_ReadStatus() != I2C_SLA_R_ACK)
    {
    	return FALSE;
    }
    else
    {
    	/*	Do Nothing	*/
    }
    return TRUE;
}
u8 I2C_ReadByte(void)
{
	I2C_TWCR_REG |= I2C_ENABLE|I2C_INTERRUPT_FLAG;
	/*	Wait until data sent successfully	*/
    while (!(CHECK_BIT(I2C_TWCR_REG,I2C_INTERRUPT_FLAG_BIT_NO)))
    {
    	/*Do Nothing */
    	   ;
    }
    return I2C_TWDR_REG;
}
u8 I2C_ReadStatus(void)
{
    u8 status;
    status = I2C_TWSR_REG & 0xF8; // 1111 1000
    return status;
}
