/*
 * EXTI_Interface.h
 *
 * Created: 11/1/2023 9:02:44 PM
 *  Author: Belal
 */ 


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
#include "Types.h"
/**************Initializing INT0, INT1 and INT2 Using Pre-build configuration**************/
// INT0 initialization
void EXTI_voidINT0Init(void);
// INT1 initialization
void EXTI_voidINT1Init(void);
// INT2 initialization
void EXTI_voidINT2Init(void);


/**************Initializing INT0, INT1 and INT2 Using Post-build configuration*************/
// INT0 initialization
uint8 EXTI_u8INT0Init(uint8 copy_u8SenseControl);
// INT1 initialization
uint8 EXTI_u8INT1Init(uint8 copy_u8SenseControl);
// INT2 initialization
uint8 EXTI_u8INT2Init(uint8 copy_u8SenseControl);



/****************************Enable of Disable Interrupt (GIE)*****************************/
// Global Interrupt Enable (GIE)
// Enable GIE
void GIE_voidEnable(void);
// Disable GIE
void GIE_voidDisable(void);



/***********************************Set Callback Function***********************************/

/*return: the error code, if return 1, means no errors
 	 	 	 	 	 	  if return 2, NULL user function
 * Parameters: pointer to function (address of a function
 */
void EXTI_voidSetCallBackINT0(void (*copy_pvUserFunc0)(void));
void EXTI_u8SetCallBackINT1(void (*copy_pvUserFunc1)(void));




/*******Sense Control Options for INT0, INT1 and INT2 Using Post-build configuration*******/
// INT0 Sense Control
#define INT0_LOW_LEVEL 		3
#define INT0_ON_CHANGE		4
#define INT0_FALLING_EDGE	5
#define INT0_RISING_EDGE	6

// ================================
// INT0 Sense Control
#define INT1_LOW_LEVEL 		9
#define INT1_ON_CHANGE		10
#define INT1_FALLING_EDGE	11
#define INT1_RISING_EDGE	12

// ================================
// INT2 Sense Control
#define INT2_FALLING_EDGE	15
#define INT2_RISING_EDGE	16





#endif /* EXTI_INTERFACE_H_ */