/*
 * ADC.c
 *
 * Created: 10/24/2023 2:19:57 PM
 *  Author: Belal
 */ 
#include "ADC.h"

// 
// void ADC_Init()
// {
//     /* Add your code here ! */
//     /* Turn ADC , configure clock and configure port */
//     //1-Select Vref = AVCC
// 	// AVCC or an internal 2.56V reference voltage may be connected to the AREF pin by writing to the REFSn bits in the ADMUX Register
// 	R_ADMUX_Address  = 0x00 ;
// 	R_ADMUX_Address |= 1<<6 ;
//     //2-Right Adjust
// 	R_ADMUX_Address &= ~(1<<5);
//     //3-Disable Auto Trigger
// 	R_ADCSRA_Address &= ~(1<<5);
//     //4-Select CLK  //128 Prescaler
// 	R_ADCSRA_Address |=  0b00000111;
//     //5-Enable ADC    Bit 7 – ADEN: ADC Enable  in ADCSRA
// 	R_ADCSRA_Address |= 1<<7 ;
// 	
//     /* End of your code ! */
// 
// }
// 
// int ADC_Convert(uint8 channel)
// {
//     //int  ret = 0;
//     /* Add your code here ! */
//     /* Turn ADC ON, select result adjustment and channel then start conversion.
//        After conversion return result */
// 	R_ADMUX_Address  |= (channel & 0x0F);
// 	//• Bit 6 – ADSC: ADC Start Conversion in ADCSRA
// 	 R_ADCSRA_Address |= 1<<6 ;
//     return R_ADC_Address;
//     /* End of your code ! */
//     //return ret;
// }
// 
// void ADC_Inturrupt_enable()
// {
// 	R_SREG_Address  |= 1<<7;
// 	R_ADCSRA_Address |= 1<<3;
// }
///////////////////////////////////////////////////ENG AMR////////////////////////////////////////////////////////////////////




void __vector_16(void) __attribute__((signal));




// void __vector_16(void)
// {
// 	/* reading to be put on LCD */
// }


//or  ISR(ADC_VECT){


//}


void ADC_voidInit (void)
{
	
	/* voltage refrenece */
	R_ADMUX_Address  = 0x00 ;
	R_ADMUX_Address |= 1<<6 ;

	/* right or left adjustment */
	R_ADMUX_Address &= ~(1<<5);

	/* adc channel */
	R_ADMUX_Address  |= ( 0 & 0x0F);         //channel 0   //bug
	
	
	/** disable ADC in initialization function  			   **/
	
	R_ADCSRA_Address &=~ (1<<7) ;
	
	

	/** disable ADC Auto Trigger in initialization function	   **/
	/** ADATE = 0 =====> 				   **/
	// Bit 5 – ADATE: ADC Auto Trigger Enable
	R_ADCSRA_Address &= ~(1<<5);                    

	
	/** ADIF = 1 =====> 	SET_BIT( ADIF , 4 ); 			   **/
	/** ADC Interrupt Flag ( Conversion Complete ) cleared by  **/
	/** set ADIF by Logical 1 .								   **/
	
	/** ADIE = 0 =====> 			   **/
	/** ADC Interrupt Enable is cleared in initialization	   **/
	//R_SREG_Address  |= 1<<7;
	R_ADCSRA_Address &=~ (1<<3);
	
	/* ADC prescaler   */ //128 prescaler
	R_ADCSRA_Address |=  0b00000111;
	
}


void ADC_voidEnable()
{
	/*	enable ADC */
	R_ADCSRA_Address |= (1<<7) ;
}

void ADC_voidInterrputEnable()
{
	/* ENABLE INTERRUPT BIT */
	R_SREG_Address  |= 1<<7;
	R_ADCSRA_Address |= 1<<3;
}

void ADC_voidStartConversion()
{
	/* set adc start conversion bit */
		//• Bit 6 – ADSC: ADC Start Conversion in ADCSRA
		R_ADCSRA_Address |= 1<<6 ;
}

