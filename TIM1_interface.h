/*
 * TIM1_interface.h
 *
 * Created: 10/30/2023 12:22:33 PM
 *  Author: Belal
 */ 


#ifndef TIM1_INTERFACE_H_
#define TIM1_INTERFACE_H_

#include "Types.h"
void timer1_init();
void ControlLed_intensity(float mVolt);
void Set_OCR1A(unsigned char duty);
void pwm1_init();
void setting_OCR_for_FPWM1_MOD14();
void TIM1_MOD14_FPWM();

#endif /* TIM1_INTERFACE_H_ */