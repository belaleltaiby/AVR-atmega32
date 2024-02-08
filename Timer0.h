/*
 * Timer0.h
 *
 * Created: 10/29/2023 11:03:56 AM
 *  Author: Belal
 */ 


#ifndef TIMER0_H_
#define TIMER0_H_
//#include "Timer0_porting.h"
#include "Types.h"
// typedef enum{
// 	No_clock_source,
// 	CLK_EN_No_prescaling,
// 	prescaler_8,
// 	prescaler_64,
// 	prescaler_256,
// 	prescaler_1024,
// 	External_clock_source_on_T0_pin_Clock_on_falling_edge,
// 	External_clock_source_on_T0_pin_Clock_on_rising_edge
// }prescaler_t;
// 
// typedef enum{
// 	Normal,
// 	PWM_Phase_Correct,
// 	CTC,
// 	Fast_PWM
// 	}TIM_mode_t;
// 	
// 
// void Tim0_Init(TIM_mode_t TIM_mode);
// void Tim0_Start();
// void Tim0_Stop();
// void Delay(int ms);
// void TIM0_Interrupt_Enable();
// void delay_ms(uint16_t milliseconds);


void TIMER0_init();
void  TIMER0_voidStart();
void TIMER0_voidSetCallBackInterrupt( void (*cb)(void));
void TIMER0_start();
#endif /* TIMER0_H_ */