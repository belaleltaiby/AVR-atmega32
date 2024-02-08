/*
 * EXTI_Private.h
 *
 * Created: 11/1/2023 9:01:51 PM
 *  Author: Belal
 */ 


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

/**********Initializing INT0, INT1 and INT2 Using Pre-build configuration**********/
// INT0 PIE States
#define INT0_ENABLE			1
#define INT0_DISABLE		2
// INT0 Sense Control
#define INT0_LOW_LEVEL 		3
#define INT0_ON_CHANGE		4
#define INT0_FALLING_EDGE	5
#define INT0_RISING_EDGE	6

// ================================

// INT0 PIE States
#define INT1_ENABLE			7
#define INT1_DISABLE		8
// INT0 Sense Control
#define INT1_LOW_LEVEL 		9
#define INT1_ON_CHANGE		10
#define INT1_FALLING_EDGE	11
#define INT1_RISING_EDGE	12

// ================================

// INT2 PIE States
#define INT2_ENABLE			13
#define INT2_DISABLE		14
// INT2 Sense Control
#define INT2_FALLING_EDGE	15
#define INT2_RISING_EDGE	16





#endif /* EXTI_PRIVATE_H_ */