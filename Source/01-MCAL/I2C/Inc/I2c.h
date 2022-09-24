 /***********************************************
 *  File		: I2c.h
 *	Module		: I2C
 *	Target		: ATMEGA32
 *	Author		: mFawzi
 *  Description	:
 *************************************************/
#ifndef I2C_H
#define I2C_H

#include <I2c_Reg.h>
#include "Std_Types.h"
#include "Bit_Math.h"
#include "Dio.h"

#define I2C_MT_ARB_LOST   		0x38
#define I2C_MR_ARB_LOST   		0x38
#define I2C_START_ACK     		0x08
#define I2C_REP_START_ACK    	0x10
#define I2C_SLA_W_ACK    		0x18
#define I2C_SLA_R_ACK    		0x40
#define I2C_MT_DATA_ACK   		0x28
#define I2C_MR_DATA_NACK  		0x58
#define I2C_MR_SLA_NACK   		0x48
#define I2C_MT_SLA_NACK   		0x20
#define I2C_MT_DATA_NACK  		0x30
#define I2C_MR_DATA_ACK   		0x50


#define SLAVE_ADDRESS  (0x01)

#define I2C_PRESCALER_1  (0<<0)
#define I2C_PRESCALER_4  (1<<0)
#define I2C_PRESCALER_61  (2<<0)
#define I2C_PRESCALER_64  (3<<0)


void I2C_MasterInit(void);
void I2C_SlaveInit(u8 addr);
boolean I2C_StartCondition(void);
boolean I2C_RepeatedStartCondition(void);
void I2C_StopCondition(void);
void I2C_WriteByte(u8 data);
boolean I2C_Send_SlaveAddressWriteOperation(u8 addr);
boolean I2C_Send_SlaveAddressReadOperation(u8 addr);
u8 I2C_ReadByte(void);
u8 I2C_ReadStatus(void);
#endif  /* I2C_H */

/**********************************************************************************************************************
 *  END OF FILE: I2c.h
 *********************************************************************************************************************/
