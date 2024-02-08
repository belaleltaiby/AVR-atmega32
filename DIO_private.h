/*
 * DIO_private.h
 *
 * Created: 10/20/2023 2:21:19 PM
 *  Author: Belal
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_
#include "Types.h"


/* DIO_Registers */
#define PORTA  (*(volatile unsigned char*)0x3B)
#define DDRA   (*(volatile unsigned char*)0X3A)
#define PINA   (*(volatile unsigned char*)0x39)

#define PORTB  (*(volatile unsigned char*)0x38)
#define DDRB   (*(volatile unsigned char*)0X37)
#define PINB   (*(volatile unsigned char*)0x36)

#define PORTC  (*(volatile unsigned char*)0x35)
#define DDRC   (*(volatile unsigned char*)0X34)
#define PINC   (*(volatile unsigned char*)0x33)

#define PORTD  (*(volatile unsigned char*)0x32)
#define DDRD   (*(volatile unsigned char*)0X31)
#define PIND   (*(volatile unsigned char*)0x30)



#endif /* DIO_PRIVATE_H_ */