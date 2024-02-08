/*
 * Timer0_porting.h
 *
 * Created: 10/29/2023 11:04:38 AM
 *  Author: Belal
 */ 


#ifndef TIMER0_PORTING_H_
#define TIMER0_PORTING_H_
#include "Types.h"
// #define TIM0_TCCR0        *((volatile uint8*)(0x53))
// #define TIM0_TCNT0        *((volatile uint8*)(0x52))
// #define TIM0_OCR0        *((volatile uint8*)(0x5C))
// #define TIM0_TIMSK        *((volatile uint8*)(0x59))
// #define TIM0_TIFR        *((volatile uint8*)(0x58))
// 

#define TCCR0	*((volatile uint8*)0x53)
#define FOC0  7
#define WGM00 6
#define COM01 5
#define COM01 4
#define WGM01 3
#define CS02  2
#define CS01  1
#define CS00  0
#define TCNT0	*((volatile uint8*)0x52)
#define OCR0	*((volatile uint8*)0x5C)
#define TIMSK	*((volatile uint8*)0x59)
#define OCIE0 1
#define TOIE0 0
#define TIFR	*((volatile uint8*)0x58)
#define OCF0  1
#define TOV0  0
#define SREG     *((volatile uint8*)0x5F)


#endif /* TIMER0_PORTING_H_ */