/*
 * EEPROM.c
 *
 * Created: 11/4/2023 6:59:08 PM
 *  Author: Belal
 */ 

#include "EEPROM_Interface.h"
#include "EEPROM_Private.h"
#include "I2C_Interface.h"

uint8	EEPROM_u8WriteByte(uint16 Add , uint8 Data)
{
	
	/*	Start Condition						*/
	I2C_enuSendStartCondition();
	/*	Send Slave Add with write 1010->  address of EPPROM	(1010(A2)(A1)(A0))	*/
	I2C_enuSendSlaveAddWithWrite(0b10100000);
	/*	Send Byte Add by func send data 						*/
	I2C_enuMasterSendDataByte(Add);
	/*	Send Data Byte						*/
	I2C_enuMasterSendDataByte(Data);
	/*	Stop Condition						*/
	I2C_voidSendStopCondition();
}
//uint8 * Copy_pu8Data;
uint8 EEPROM_u8ReadByte(uint16 Add , uint8 * Data)
{
	
	/*	Start Condition						*/
	I2C_enuSendStartCondition();
	/*	Send Slave Add	(1010(A2)(A1)(A0))	*/
	I2C_enuSendSlaveAddWithWrite(0b10100000);
	/*	Send Byte Add						*/
	I2C_enuMasterSendDataByte(Add);
	
	/*	Repeated Start Condition			*/
	I2C_enuSendReStartCondition();
	/*	Send Slave Add	(1010(A2)(A1)(A0))	*/
	I2C_enuSendSlaveAddWithRead(0b10100001);
	/*	Read Data Byte						*/
	I2C_enuMasterReadDataByte(&Data);
	
	/*	Stop Condition						*/
	I2C_voidSendStopCondition();
}