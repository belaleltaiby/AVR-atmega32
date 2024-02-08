/*
 * UART.c
 *
 * Created: 10/28/2023 1:01:53 PM
 *  Author: Belal
 */ 
#include "UART_INTERFACE.h"
#include "UART_porting.h"

//---------------------Global variables--------------------//
//USART_Typedef * Gp_USARTx = NULL;
// UART_config_t* Gp_UART_config =0;
// 
// void UART_INIT(UART_config_t* UART_config)
// {
// 	Gp_UART_config = UART_config;
// 	
// 	//select synch or asynch   //• Bit 6 in – UCSRC – UMSEL: USART Mode Select  
// 	UART_UCSRC |=UART_config->Type ; 
// 	
// 	//Baude Rate   • Bit 11:0 – UBRR11:0: USART Baud Rate Register
// 	//• Bit 15 – URSEL: Register Select must be zro to write to  BRRH
// 	UART_UBRRL = UART_config->Baudrate ;
// 	
// 	
// 	//parity mode    • Bit 5:4 – UPM1:0: Parity Mode   UCSRC
// 	UART_UCSRC  |= UART_config->parity ;
// 	
// 	
// 	//stop bits  • Bit 3 – USBS: Stop Bit Selec   UCSRC
// 	UART_UCSRC  |= UART_config ->stopBits ; 
// 	
// 	//data lenght  • Bit 2:1 – UCSZ1:0: Character Size  UCSRC
// 	UART_UCSRC |= UART_config->Payload_lenght;
// 	
// 	//enable Tx or Rx based on configuration
// 	//UART_UCSRB |= UART_config->Mode;
// 	
// 	//enable or disable interrupt
// 	UART_UCSRB |= UART_config->IRQ_Enable;
// }
// 
// void UART_TX(uint8_t data){
//  
// 	
// 	//check • Bit 5 – UDRE: USART Data Register Empty  UCSRA  //untill it become one
// 	UART_UCSRB |= 1<<3;  //enable tx
// // 	UART_UCSRB &=~ (1<<4);
// 	
// 	
// 	while(!(UART_UCSRA &(1<<5)));
// 		UART_UDR = data ;
// 
// }
// 	
// 	
// void UART_RX(uint16_t* pRxBuffer){
// 	 //Bit 7 – RXC: USART Receive Complete   UCSRA
// 	
// 	
// 	//This is 8bit data
// 	if (Gp_UART_config->parity ==parity_none)
// 	{
// 		//no parity So all 8bit are considered data
// 		while( !(UART_UCSRA & 1<<7 ));
// 		*((uint8_t*) pRxBuffer) =  UART_UDR   ;
// 		
// 
// 	}else
// 	{
// 		//Parity is used, so,7 bits will be of user data and 1 bit is parity
// 		*((uint8_t*) pRxBuffer) = ( UART_UDR  & (uint8_t)0X7F );
// 		while( !(UART_UCSRA & 1<<7 ));
// 
// 	}
// }



// 
// ISR(USART_TX_vect)
// {
// 	
// }
// 
#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 8000000UL  // Assuming an 8MHz clock frequency
#define BAUD_RATE 9600   // Desired baud rate

void (*ptr)();

void USART_Init() {
	// Set baud rate
	UBRRH = (unsigned char)(F_CPU / 16 / BAUD_RATE - 1) >> 8;
	UBRRL = (unsigned char)(F_CPU / 16 / BAUD_RATE - 1);

	// Enable receiver and transmitter
	UCSRB = (1 << RXEN) | (1 << TXEN);

	// Set frame format: 8 data, 1 stop bit
	UCSRC = (1 << URSEL) | (1 << UCSZ1) | (1 << UCSZ0);
}

void USART_Transmit(unsigned char data) {
	// Wait for the transmit buffer to be empty
	while (!(UCSRA & (1 << UDRE)))
	;

	// Put the data into the transmit buffer
	UDR = data;
}

unsigned char USART_Receive() {
	// Wait for data to be received
	while (!(UCSRA & (1 << RXC)));

	// Get and return received data from buffer
	return UDR;
}



