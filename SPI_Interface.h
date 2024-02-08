/*
 * SPI_Interface.h
 *
 * Created: 11/3/2023 10:53:42 AM
 *  Author: Belal
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
#include "Types.h"
#include "Bit_Math.h"
typedef enum{
	SPI_error,
	SPI_NoError
	}ErrorStatus;


void SPI_voidINTEnable();
void SPI_voidINTDisable();
void SPI_u8SendByteSynch(uint8 Data);
void SPI_u8ReceiveByteSynch(uint8 *Data);
void SPI_u8_Send_Receive_ByteSynch(uint8 Data_S,uint8 *Data_R);

void SPI_u8SendReceiveBufferASynch(uint8 *Data_S,uint8 *Data_R,uint8 BufferSize,void(*NotificationFuction)(void));

void SPI_Slave_voidInit(void);
void SPI_Master_voidInit(void);
void SPI_u8ReceiveByteSynch(uint8 *Data);
void SPI_u8SendByteSynch(uint8 Data);


#endif /* SPI_INTERFACE_H_ */