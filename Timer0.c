/*
 * Timer0.c
 *
 * Created: 10/29/2023 11:04:21 AM
 *  Author: Belal
 */ 
#include "Timer0.h"
#include "Bit_Math.h"
#include "Timer0_porting.h"
#include "Types.h"
#include "DIO.h"
#include "avr/interrupt.h"
#define  NULL   0



void (*callback)(void);
int counter = 0;
void TIMER0_init(){
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	SET_BIT(TIMSK,TOIE0);
	TCNT0 = 0;
}
void  TIMER0_start(){

	TCCR0 &= 0xf8;  //0b1111 1000
	TCCR0 |= 0x05; //0b0000 0101
}

void TIMER0_voidSetCallBackInterrupt( void (*cb)(void))
{
	callback = cb;
}
ISR(TIMER0_OVF_vect){		counter++;
		if(counter == 1830){
			callback();
			counter = 0;
		}
		}