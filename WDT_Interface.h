/*
 * WDT_Interface.h
 *
 * Created: 10/31/2023 2:49:29 PM
 *  Author: Belal
 */ 


#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_

#include "Types.h"
// Enable Watch Dog Timer: Start counting till timeout (reset MCU)
void WDT_voidEnable(void);

// Disable Watch Dog Timer: Stop counting time.
void WDT_voidDisable(void);

// Sleep function (timeout)
void WDT_voidSleep(uint8 copy_u8SleepTime);



#endif /* WDT_INTERFACE_H_ */