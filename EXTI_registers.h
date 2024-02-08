/*
 * EXTI_registers.h
 *
 * Created: 11/1/2023 9:03:52 PM
 *  Author: Belal
 */ 


#ifndef EXTI_REGISTERS_H_
#define EXTI_REGISTERS_H_



//INT0, INT1 Sense Control Register
#define MCUCR			*((volatile u8*) 0x55)
// INT0 Sense Control Bits
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
// INT1 Sense Control Bits
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

//INT2 Sense Control Register
#define MCUCSR			*((volatile u8*) 0x54)
// INT2 Sense Control Bit
#define MCUCSR_ISC2		6


// Peripheral Interrupt Enable (PIE)
#define GICR			*((volatile u8*) 0x5B)
// PIE bit number
#define GICR_INT0		6
#define GICR_INT1		7
#define GICR_INT2		5


// Peripheral Interrupt Flag (PIF)
#define GIFR			*((volatile u8*) 0x5A)
// PIF bit number
#define GIFR_INT0		6
#define GIFR_INT1		7
#define GIFR_INT2		5

// Global Interrupt Enable (GIE)
#define SREG			*((volatile u8*) 0x5F)
#define SREG_I			7



#endif /* EXTI_REGISTERS_H_ */