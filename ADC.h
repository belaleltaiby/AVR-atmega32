/*
 * ADC.h
 *
 * Created: 10/24/2023 2:19:35 PM
 *  Author: Belal
 */ 


#ifndef ADC_H_
#define ADC_H_
#include "Types.h"

#define  R_ADMUX_Address      *((volatile uint8*)(0x27))
#define  R_ADCSRA_Address      *((volatile uint8*)(0x26))
#define  R_ADCL_Address          *((volatile uint8*)(0x24))
#define  R_ADCH_Address          *((volatile uint8*)(0x25))


//void ADC_Init();
void ADC_voidInit (void);
void ADC_voidEnable(void);
void ADC_voidInterrputEnable(void);
void ADC_voidStartConversion();
#endif /* ADC_H_ */