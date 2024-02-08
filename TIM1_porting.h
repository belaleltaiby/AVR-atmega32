/*
 * TIM1_porting.h
 *
 * Created: 10/30/2023 12:22:13 PM
 *  Author: Belal
 */ 


#ifndef TIM1_PORTING_H_
#define TIM1_PORTING_H_

#define  TIM1_TCCR1A      *((volatile uint8*)(0x4F))
#define  TIM1_TCCR1B      *((volatile uint8*)(0x4E))
#define  TIM1_TIMSK        *((volatile uint8*)(0x59))
#define  TIM1_OCR1AL       *((volatile uint8*)(0x4A))
#define  TIM1_OCR1AH        *((volatile uint8*)(0x4B)) 

#endif /* TIM1_PORTING_H_ */