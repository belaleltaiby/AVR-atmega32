/*
 * WDT_porting.h
 *
 * Created: 10/31/2023 2:49:49 PM
 *  Author: Belal
 */ 


#ifndef WDT_PORTING_H_
#define WDT_PORTING_H_


// Watch dog Timer Control Register – WDTCR
#define WDTCR			*((volatile uint8*)0x41)
#define WDTCR_WDTOE		4
#define WDTCR_WDE		3
#define WDTCR_WDP2		2
#define WDTCR_WDP1		1
#define WDTCR_WDP0		0





#endif /* WDT_PORTING_H_ */