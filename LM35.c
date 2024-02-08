/*
 * LM35.c
 *
 * Created: 10/26/2023 9:51:44 AM
 *  Author: Belal
 */ 
#include "ADC.h"

#include "LM35.h"

int read_temp()
{
	// Wait for the conversion to complete
	while ( R_ADCSRA_Address & (1 << 6));

	// Read the ADC result
	 //void ADC_voidStartConversion();
	uint16_t adc_value = R_ADCL_Address;
	adc_value |= (R_ADCH_Address<<8);
	return adc_value;
	
}