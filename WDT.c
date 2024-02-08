/*
 * WDT.c
 *
 * Created: 10/31/2023 2:49:08 PM
 *  Author: Belal
 */ 
// MCAL

#include "WDT_Interface.h"
#include "WDT_porting.h"
#include "Bit_Math.h"


// Enable Watch Dog Timer: Start counting till timeout (reset MCU)
void WDT_voidEnable(void)
{
	setBit(WDTCR, WDTCR_WDE);
}


// Disable Watch Dog Timer: Stop counting time.
void WDT_voidDisable(void)
{
	/* WDT Disable Sequence (See data sheet):
	 * 1. Set the WDE and WDTOE to 1 at the same operation.
	 * 2. Write 0 on the WDE bit in the next 4 clock cycles.
	 */
	WDTCR = 0b00011000;
	WDTCR = 0;
}


// WDT Pre-scaler Select: Each pre-scaler maps to a specific timeout value (sleep time).
// Input argument from 1 : 7 (each value maps to a specific timeout value (sleep time).
void WDT_voidSleep(uint8 copy_u8SleepTime)
{
	if(copy_u8SleepTime < 8)
	{
		// Bit masking Sequence:
		// 1. clear the desired bits
		// 2. Put the required value in it
		WDTCR &= 0b01111000;
		WDTCR |= copy_u8SleepTime;
	}
}