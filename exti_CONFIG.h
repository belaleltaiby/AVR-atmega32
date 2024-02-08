/*
 * exti_CONFIG.h
 *
 * Created: 11/1/2023 9:05:33 PM
 *  Author: Belal
 */ 


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_


/**********Initializing INT0, INT1 and INT2 Using Pre-build configuration**********/

/* INT0 Options:
 * 1- INT0_ENABLE
 * 2- INT0_DISABLE
 */
#define INT0_EN_STATE			INT0_ENABLE

/*INT0 Sense Control Options
 * 1- INT0_LOW_LEVEL
 * 2- INT0_ON_CHANGE
 * 3- INT0_FALLING_EDGE
 * 4- INT0_RISING_EDGE
 */
#define INT0_SENSE_CONTROL		INT0_FALLING_EDGE

// =======================================================

/* INT1 Options:
 * 1- INT1_ENABLE
 * 2- INT1_DISABLE
 */
#define INT1_EN_STATE			INT1_ENABLE

/*INT0 Sense Control Options
 * 1- INT1_LOW_LEVEL
 * 2- INT1_ON_CHANGE
 * 3- INT1_FALLING_EDGE
 * 4- INT1_RISING_EDGE
 */
#define INT1_SENSE_CONTROL		INT1_FALLING_EDGE

// =======================================================

/* INT2 Options:
 * 1- INT2_ENABLE
 * 2- INT2_DISABLE
 */
#define INT2_EN_STATE			INT2_ENABLE

/*INT2 Sense Control Options
 * 1- INT2_FALLING_EDGE
 * 2- INT2_RISING_EDGE
 */
#define INT2_SENSE_CONTROL		INT2_FALLING_EDGE




#endif /* EXTI_CONFIG_H_ */