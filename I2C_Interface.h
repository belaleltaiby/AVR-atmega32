/*
 * I2C_Interface.h
 *
 * Created: 11/4/2023 1:38:16 PM
 *  Author: Belal
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_
#include "Types.h"

typedef enum
{
	I2C_Ok,
	I2C_SC_Error,
	I2C_RSC_Error,
	I2C_SLA_W_Error,
	I2C_SLA_R_Error,
	I2C_DATA_Error,
	I2C_MR_DATA_Error

}I2C_Error_States;


void I2C_voidMasterInit(void);

void I2C_voidSlaveInit(uint8 Copy_u8SlaveAdd);

I2C_Error_States I2C_enuSendStartCondition(void);

I2C_Error_States I2C_enuSendReStartCondition(void);

I2C_Error_States I2C_enuSendSlaveAddWithWrite(uint8 Copy_u8SlaveAdd);

I2C_Error_States I2C_enuSendSlaveAddWithRead(uint8 Copy_u8SlaveAdd);

I2C_Error_States I2C_enuMasterSendDataByte(uint8 Copy_u8Data);

I2C_Error_States I2C_enuMasterReadDataByte(uint8 * Copy_pu8Data);


void I2C_voidSendStopCondition(void);





#endif /* I2C_INTERFACE_H_ */