/*
 * I2C.c
 *
 * Created: 11/4/2023 1:37:40 PM
 *  Author: Belal
 */ 

#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "Bit_Math.h"
#include "Types.h"


void I2C_voidMasterInit(void)
{
	/* Set frequency 400 khz , prescalar value 0 */
	TWBR = 2;                
	/* Enable ACK *///Bit 6 – TWEA: TWI Enable Acknowledge Bit  in TWCR
	TWCR |= 1<<6;
	/* Enable I2C */ //• Bit 2 – TWEN: TWI Enable Bit in TWCR
	TWCR |= 1<<2;
}

void I2C_voidSlaveInit(uint8 Copy_u8SlaveAdd)
{
	/* Set Slave Address In TWAR */
	TWAR = Copy_u8SlaveAdd;
	/* Enable ACK */
	TWCR |= 1<<6;
	/* Enable I2C */
	TWCR |= 1<<2;
}

I2C_Error_States I2C_enuSendStartCondition(void)
{
	I2C_Error_States Local_enuState = I2C_Ok;

	/* set bit Start Condition */ //• Bit 5 – TWSTA: TWI START Condition Bit in TWCR
	TWCR |= 1<<5;
	/* Clear Flag */ //. The TWINT Flag must be cleared by software by writing a logic one to it  • Bit 7 – TWINT: TWI Interrupt Flag
	TWCR |= 1<<7;
	/* Polling On The Flag */
	while(!(TWCR&(1<<7)));
	
	/* Check Status code */ /*** note example to be used with the next function with different ack source */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_enuState = I2C_SC_Error;
	}
	else
	{

	}
	return Local_enuState;
}

I2C_Error_States I2C_enuSendReStartCondition(void)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Start Condition */
	TWCR |= 1<<5;

	/* Clear Flag */
	TWCR |= 1<<7;
	TWCR |= 1<<2;     //TWEN
	/* Polling On The Flag */
	while(!(TWCR&(1<<7)));

	/* Check Status code */
	/* Check Status code */ /*** note example to be used with the next function with different ack source */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_enuState = I2C_SC_Error;
	}
	else
	{

	}
	return Local_enuState;
}

I2C_Error_States I2C_enuSendSlaveAddWithWrite(uint8 Copy_u8SlaveAdd)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Write Slave Address */
	TWAR = Copy_u8SlaveAdd;
	/* Write W Bit */
	
	/* Clear Start Condition  */
	TWCR &=~ (1<<5);

	/* Clear Flag */
	TWCR |= 1<<7;
	TWCR |= 1<<2;     //TWEN
	TWCR |= 1<<6;      //TWEA

	/* Polling On the Flag */
	while(!(TWCR&(1<<7)));
	
	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_enuState = I2C_SC_Error;
	}
	else
	{

	}
	return Local_enuState;
}

I2C_Error_States I2C_enuSendSlaveAddWithRead(uint8 Copy_u8SlaveAdd)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Write Slave Address */
	TWAR = Copy_u8SlaveAdd;
	/* Write W Bit */
	
	/* Clear Start Condition  */
	TWCR &=~ (1<<5);

	/* Clear Flag */
	TWCR |= 1<<7;
	TWCR |= 1<<2;     //TWEN
	TWCR |= 1<<6;      //TWEA 
	
	/* Polling On the Flag */
	while(!(TWCR&(1<<7)));

	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_enuState = I2C_SC_Error;
	}
	else
	{

	}
	return Local_enuState;
}

I2C_Error_States I2C_enuMasterSendDataByte(uint8 Copy_u8Data)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Write Data on The Data register */
	TWDR = Copy_u8Data;		
	
	/* Clear Flag */
	TWCR |= 1<<7;
	TWCR |= 1<<6; //TWEN
	/* Polling On the Flag */
	while(!(TWCR&(1<<7)));

	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_enuState = I2C_SC_Error;
	}
	else
	{

	}
	return Local_enuState;

}

I2C_Error_States I2C_enuMasterReadDataByte(uint8 * Copy_pu8Data)
{
	I2C_Error_States Local_enuState = I2C_Ok;
	/* Clear flag */
	TWCR |= 1<<7;
	TWCR |= 1<<6; //TWEN
	/* Polling on the Flag */
	while(!(TWCR&(1<<7)));
	*Copy_pu8Data = TWDR;
	/* Check Status code */
	if((TWSR & I2C_STATUS_CODE_MASK) != I2C_MT_SC_ACK)
	{
		Local_enuState = I2C_SC_Error;
	}
	else
	{

	}
	return Local_enuState;
}

void I2C_voidSendStopCondition(void)
{
	/*Stop Condition*/ //Bit 4 – TWSTO: TWI STOP Condition Bit
	TWCR |=1<<4;      //stop

	/*Clear Flag*/
	TWCR |= 1<<7;
	TWCR |= 1<<2;  //TWEN
	
	while (TWCR & (1 << 4));
}
