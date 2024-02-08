/*
 * EXTI.c
 *
 * Created: 11/1/2023 9:01:12 PM
 *  Author: Belal
 */ 
// Libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// MCAL
#include "EXTI_config.h"
#include "EXTI_registers.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"



// Global pointer to function to be used in callback
void (*EXTI_INT0PtrToFunc)(void) = NULL;
void (*EXTI_INT1PtrToFunc)(void) = NULL;

/*******************Initializing INT0, INT1 and INT2 Using Pre-build configurations*******************/

// ============================================================
// INT0 initialization
// ============================================================
void EXTI_voidINT0Init(void)
{
	/* INT0 PIE Setting*/
#if INT0_EN_STATE == INT0_ENABLE
	// Enable INT0 (PIE)
	SET_BIT(GICR, GICR_INT0);

#elif INT0_EN_STATE == INT0_DISABLE
	// Disable INT0 (PIE)
	CLR_BIT(GICR, GICR_INT0);

#else
#error "Invalid INT0 Enable State (PIE)"
#endif

	/* INT0 Sense Control Setting */
#if INT0_SENSE_CONTROL == INT0_LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE_CONTROL == INT0_ON_CHANGE
	SET_BIT(MCUCR, MCUCR_ISC00);
	CLR_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE_CONTROL == INT0_FALLING_EDGE
	CLR_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);

#elif INT0_SENSE_CONTROL == INT0_RISING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC00);
	SET_BIT(MCUCR, MCUCR_ISC01);

#else
#error "Invalid INT0 Sense Control"
#endif
}

// ============================================================
// INT1 initialization
// ============================================================
void EXTI_voidINT1Init(void)
{
	/* INT1 PIE Setting*/
#if INT1_EN_STATE == INT1_ENABLE
	// Enable INT1 (PIE)
	SET_BIT(GICR, GICR_INT1);

#elif INT1_EN_STATE == INT1_DISABLE
	// Disable INT1 (PIE)
	CLR_BIT(GICR, GICR_INT1);

#else
#error "Invalid INT1 Enable State (PIE)"
#endif

	/* INT1 Sense Control Setting */
#if INT1_SENSE_CONTROL == INT1_LOW_LEVEL
	CLR_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);

#elif INT1_SENSE_CONTROL == INT1_ON_CHANGE
	SET_BIT(MCUCR, MCUCR_ISC10);
	CLR_BIT(MCUCR, MCUCR_ISC11);

#elif INT1_SENSE_CONTROL == INT1_FALLING_EDGE
	CLR_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);

#elif INT1_SENSE_CONTROL == INT1_RISING_EDGE
	SET_BIT(MCUCR, MCUCR_ISC10);
	SET_BIT(MCUCR, MCUCR_ISC11);

#else
#error "Invalid INT1 Sense Control"
#endif
}

// ============================================================
// INT2 initialization
// ============================================================
void EXTI_voidINT2Init(void)
{
	/* INT2 PIE Setting*/
#if INT2_EN_STATE == INT2_ENABLE
	// Enable INT2 (PIE)
	SET_BIT(GICR, GICR_INT2);

#elif INT2_EN_STATE == INT2_DISABLE
	// Disable INT2 (PIE)
	CLR_BIT(GICR, GICR_INT2);

#else
#error "Invalid INT2 Enable State (PIE)"
#endif

	/* INT2 Sense Control Setting */
#if INT2_SENSE_CONTROL == INT2_FALLING_EDGE
	CLR_BIT(MCUCSR, MCUCSR_ISC2);

#elif INT2_SENSE_CONTROL == INT2_RISING_EDGE
	SET_BIT(MCUCSR, MCUCSR_ISC2);

#else
#error "Invalid INT2 Sense Control"
#endif
}

/*******************Initializing INT0, INT1 and INT2 Using Post-build configurations*******************/

// ============================================================
// INT0 initialization
// ============================================================
u8 EXTI_u8INT0Init(u8 copy_u8SenseControl)
{
	u8 local_u8ErrorCode = 0;
	
	switch(copy_u8SenseControl)
	{
	case INT0_LOW_LEVEL:
		CLR_BIT(MCUCR, MCUCR_ISC00);
		CLR_BIT(MCUCR, MCUCR_ISC01);
		break;

	case INT0_ON_CHANGE:
		SET_BIT(MCUCR, MCUCR_ISC00);
		CLR_BIT(MCUCR, MCUCR_ISC01);
		break;

	case INT0_FALLING_EDGE:
		CLR_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
		break;

	case INT0_RISING_EDGE:
		SET_BIT(MCUCR, MCUCR_ISC00);
		SET_BIT(MCUCR, MCUCR_ISC01);
		break;

	default:
		local_u8ErrorCode = 1;
		break;
	}

	// Enable INT0 (PIE)
	SET_BIT(GICR, GICR_INT0);
	
	return local_u8ErrorCode;
}


// ============================================================
// INT1 initialization
// ============================================================
u8 EXTI_u8INT1Init(u8 copy_u8SenseControl)
{
	u8 local_u8ErrorCode = 0;
	

	switch(copy_u8SenseControl)
	{
	case INT1_LOW_LEVEL:
		CLR_BIT(MCUCR, MCUCR_ISC10);
		CLR_BIT(MCUCR, MCUCR_ISC11);
		break;

	case INT1_ON_CHANGE:
		SET_BIT(MCUCR, MCUCR_ISC10);
		CLR_BIT(MCUCR, MCUCR_ISC11);
		break;

	case INT1_FALLING_EDGE:
		CLR_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
		break;

	case INT1_RISING_EDGE:
		SET_BIT(MCUCR, MCUCR_ISC10);
		SET_BIT(MCUCR, MCUCR_ISC11);
		break;

	default:
		local_u8ErrorCode = 1;
		break;
	}
	
	// Enable INT1 (PIE)
	SET_BIT(GICR, GICR_INT1);
	
	return local_u8ErrorCode;
}


// ============================================================
// INT2 initialization
// ============================================================
u8 EXTI_u8INT2Init(u8 copy_u8SenseControl)
{
	u8 local_u8ErrorCode = 0;
	// Enable INT2 (PIE)
	SET_BIT(GICR, GICR_INT2);

	switch(copy_u8SenseControl)
	{
	case INT2_FALLING_EDGE: CLR_BIT(MCUCSR, MCUCSR_ISC2); break;
	case INT2_RISING_EDGE : SET_BIT(MCUCSR, MCUCSR_ISC2); break;
	default				  : local_u8ErrorCode = 1; break;
	}

	return local_u8ErrorCode;
}


/**********************************Enable of Disable Interrupt (GIE)***********************************/

// ============================================================
// Global Interrupt Enable (GIE)
// ============================================================
// Enable GIE
void GIE_voidEnable(void)
{
	SET_BIT(SREG, SREG_I);
}
// Disable GIE
void GIE_voidDisable(void)
{
	CLR_BIT(SREG, SREG_I);
}




/***********************************Set Callback Function***********************************/

/*return: the error code, if return 1, means no errors
 	 	 	 	 	 	  if return 1, NULL user function
 * Parameters: pointer to function (address of a function
 */
void EXTI_voidSetCallBackINT0(void (*copy_pvUserFunc0)(void))
{

		EXTI_INT0PtrToFunc = copy_pvUserFunc0;
}

void EXTI_u8SetCallBackINT1(void (*copy_pvUserFunc1)(void))
{
	//u8 local_u8ErrorCode = OK;   //Ok is zero
		EXTI_INT1PtrToFunc = copy_pvUserFunc1;
}
// Interrupt Service Routine (ISR)
// Get Interrupt number from vector table in data sheet page 42
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

		// Function holds the address of the user function which is in main.c
		EXTI_INT0PtrToFunc();
		// Enable INT0 (PIE)
		SET_BIT(GICR, GICR_INT0);
}


void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	
		// Function holds the address of the user function which is in main.c
		EXTI_INT1PtrToFunc();
		// Enable INT1 (PIE)
		SET_BIT(GICR, GICR_INT1);
}
