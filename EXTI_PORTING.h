/*
 * EXTI_PORTING.h
 *
 * Created: 10/27/2023 2:46:38 PM
 *  Author: Belal
 */ 


#ifndef EXTI_PORTING_H_
#define EXTI_PORTING_H_

#define  EXTI_MCUCR               *((volatile uint8*)(0x55))           
#define  EXTI_MCUCSR              *((volatile uint8*)(0x54))
#define  EXTI_GICR                *((volatile uint8*)(0x5B))
#define  EXTI_GIFR                *((volatile uint8*)(0x5A))

void __vector_1(void) __attribute__((signal , used));

#endif /* EXTI_PORTING_H_ */