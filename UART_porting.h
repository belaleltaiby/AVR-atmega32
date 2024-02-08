/*
 * UART_porting.h
 *
 * Created: 10/28/2023 1:01:15 PM
 *  Author: Belal
 */ 


#ifndef UART_PORTING_H_
#define UART_PORTING_H_


#define UART_UDR           *((volatile uint8*)(0x2C))
#define UART_UCSRA         *((volatile uint8*)(0x2B))
#define UART_UCSRB         *((volatile uint8*)(0x2A))
#define UART_UCSRC         *((volatile uint8*)(0x40))
#define UART_UBRRL         *((volatile uint8*)(0x29))
#define UART_UBRRH         *((volatile uint8*)(0x40))

#endif /* UART_PORTING_H_ */