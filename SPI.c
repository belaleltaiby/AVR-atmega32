/*
 * SPI.c
 *
 * Created: 11/3/2023 10:53:23 AM
 *  Author: Belal
 */ 

#include "SPI_Interface.h"
#include "SPI_Porting.h"
#include "SPI_Config.h"
#include "DIO.h"
#include "DIO_private.h"
#include "Types.h"
#include "avr//delay.h"
void (*SPI_CallBackFunc)(void);

void SPI_Master_voidInit()
{
	/*
	 1- Data order
	 2- Master/Slave
	 3- Clock Polarity
	 4- Clock phase
	 5- Enable SPI
	 */
	SETPINDIrection(portB,PIN5,OUTPUT);
	//SETPINDIrection(portB,PIN6,INPUT);
	SETPINDIrection(portB,PIN7,OUTPUT);
	//Bit 5 – DORD: Data Order  SPCR
	SPCR |= 1<<5 ;	   //LSB
	
	// Bit 4 – MSTR: Master/Slave Selec SPCR
	SPCR |= (1<<4);       //select master 
	
	//Bit 3 – CPOL: Clock Polarity
	SPCR &=~ (1<<3) ;         //clkPol zero
	
	//Bit 2 – CPHA: Clock Phase
	SPCR &=~ (1<<2) ;   // clockphase  zero
	
	//• Bit 6 – SPE: SPI Enable
	SPCR |= 1<<6;            
	
}

void SPI_Slave_voidInit()
{
	/*
	 1- Data order
	 2- Master/Slave
	 3- Clock Polarity
	 4- Clock phase
	 5- Enable SPI
	 */
	//SETPINDIrection(portB,PIN5,INPUT);
	SETPINDIrection(portB,PIN6,OUTPUT);
	//SETPINDIrection(portB,PIN7,INPUT);
	//Bit 5 – DORD: Data Order  SPCR
	SPCR |= 1<<5 ;	   //LSB
	
	// Bit 4 – MSTR: Master/Slave Selec SPCR
	SPCR &=~ (1<<4);       //select master 
	
	//Bit 3 – CPOL: Clock Polarity
	SPCR &=~ (1<<3) ;         //clkPol zero
	
	//Bit 2 – CPHA: Clock Phase
	SPCR &=~ (1<<2) ;   // clockphase  zero
	
	//• Bit 6 – SPE: SPI Enable
	SPCR |= 1<<6;            
	
}
void SPI_voidINTEnable()
{
	Enable_Ginterrupt;
	//• Bit 7 – SPIE: SPI Interrupt Enable
	SPCR |= (1<<7);
}
void SPI_voidINTDisable()
{
	//• Bit 7 – SPIE: SPI Interrupt Enable
	SPCR &=~ (1<<7) ;	
}

void SPI_u8SendByteSynch(uint8 Data)
{
	/* timeout mechanism with the flag */
	
	SPDR = Data ;
	while(((SPSR&0b10000000)>>7) ==0 );
}

void SPI_u8ReceiveByteSynch(uint8 *Data)
{
	  /* send dummy byte to recieve and wait flag and timeout mechanism */ 
	  //Bit 7 – SPIF: SPI Interrupt Flag .......When a serial transfer is complete, the SPIF Flag is set  in SPSR
	  while(((SPSR&0b10000000)>>7) ==0 );
	  *Data = SPDR ; 
	  
}
uint8* rec=8;
void SPI_u8SendReceiveBufferASynch(uint8 *data_S,uint8 *data_R,uint8 BufferSize,void(*NotificationFuction)(void))
{	
	SPI_CallBackFunc= NotificationFuction;
	
	SPDR = *data_S ;		
	rec = data_R;
	
}


void __vector_12 (void)
{

	*rec =SPDR;   //display rec value
	PORTD = 8;
	SPI_CallBackFunc();
}