/*
 * kEYPAD.h
 *
 * Created: 10/23/2023 10:36:29 AM
 *  Author: Belal
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include "DIO_private.h"
#include "Bit_Math.h"
//ROWS PORTS and PINS
#define  ROW1_PORT        PORTC
#define  ROW1_PIN         5

#define  ROW2_PORT        PORTC
#define  ROW2_PIN         4

#define  ROW3_PORT        PORTC
#define  ROW3_PIN         3

#define  ROW4_PORT        PORTC
#define  ROW4_PIN         2

//coloumn PORTS and PINS
#define  COL1_PORT        PORTD
#define  COL1_PIN         7

#define  COL2_PORT        PORTD
#define  COL2_PIN         6

#define  COL3_PORT        PORTD
#define  COL3_PIN         5

#define  COL4_PORT        PORTD
#define  COL4_PIN         3



//basma
#define KEYPAD_R1(x)		if (x == 1) setBit(PORTC, 5); else clearBit(PORTC, 5)
#define KEYPAD_R2(x)		if (x == 1)	setBit(PORTC, 4); else clearBit(PORTC, 4)
#define KEYPAD_R3(x)		if (x == 1) setBit(PORTC, 3); else clearBit(PORTC, 3)
#define KEYPAD_R4(x)		if (x == 1) setBit(PORTC, 2); else clearBit(PORTC, 2)
#define KEYPAD_C1			getbit(PIND, 7)
#define KEYPAD_C2			getbit(PIND, 6)
#define KEYPAD_C3			getbit(PIND, 5)
#define KEYPAD_C4			getbit(PIND, 3)

void KeyPad_init();
unsigned char KEYPAD_READ();
#endif /* KEYPAD_H_ */