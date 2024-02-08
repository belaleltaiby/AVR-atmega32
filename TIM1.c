/*
 * TIM1.c
 *
 * Created: 10/30/2023 12:21:48 PM
 *  Author: Belal
 */ 

#include "TIM1_interface.h"
#include "TIM1_porting.h"
#include "DIO.h"

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void TIM1_MOD14_FPWM(){
		
	 
	 //Configure TIMER1
	 TCCR1A|=(1<<COM1A1)|(1<<WGM11);        //NON Inverted PWM
	 TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11); //PRESCALER=8 MODE 14(FAST PWM)

	 ICR1=19999;  //fPWM=50Hz (Period = 20ms Standard).
	 DDRD|=(1<<PD5);   //PWM Pins as Out

	
}
//servo motor
void setting_OCR_for_FPWM1_MOD14(){
		
// 		OCR1A=1000;  
// 		_delay_ms(100);
// 		OCR1A=1250;
// 		_delay_ms(100);
// 		OCR1A=1500;
// 		_delay_ms(100);
// 		OCR1A=1750;
// 		_delay_ms(100);
		OCR1A=19999;
		_delay_ms(100);
// 		OCR1A=1750;
// 		_delay_ms(100);
// 		OCR1A=1500;
// 		_delay_ms(100);
// 		OCR1A=1250;
// 		_delay_ms(100);
// 		OCR1A=1000;
// 		_delay_ms(100);
		
}

void pwm1_init();

void pwm1_init(){ //PRESCALER=1 MODE 7 (FAST PWM)

	TCCR1A=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11)|(1<<WGM10);  //NON Inverted PWM
	TCCR1B=(1<<WGM12)|(1<<CS10); //fPWM=(F_CPU)/(N*(1+TOP)) = (16X10^6)/(1*1024) =15.6 kHz

	DDRD|=(1<<5);   //PWM Pins as Out (OCR1A)
   
}
void Set_OCR1A(unsigned char duty){
	unsigned long OCRa=0;
	OCRa = (((duty*65536)/100)-1);
	TIM1_OCR1AH = (OCRa>>8);
	TIM1_OCR1AL = OCRa;
}








////////////////////////////////////////
// 
// void Set_OCR1A(unsigned char ocrVAl){
// 	OCR1A = ocrVAl;
// }


void timer1_init() {
	// Set Timer/Counter1 Control Register A (TCCR1A) and Control Register B (TCCR1B)
	// Choose the desired mode by setting the relevant bits.

	// Normal mode (Overflow after 0xFFFF)
	TCCR1A = 0x00;
	TCCR1B = 0x01; // Clock source: CLK/1

	// CTC mode (Clear Timer on Compare Match)
	// TCCR1A = 0x00;
	// TCCR1B = 0x0A; // Clock source: CLK/8, WGM12 = 1

	// Fast PWM mode (0xFF as top, non-inverting)
	// TIM1_TCCR1A = 0xA3; // COM1A1 and WGM11 are set
	// TIM1_TCCR1B = 0x09; // Clock source: CLK/1, WGM12 = 1
	//SETPINDIrection(portB,PIN3,OUTPUT);
	// Phase Correct PWM mode (0xFF as top, non-inverting)
	// TCCR1A = 0x83; // COM1A1 and WGM11 are set
	// TCCR1B = 0x09; // Clock source: CLK/1, WGM12 = 1

	// Set the value at which the timer should compare (for CTC mode)
	// OCR1A = 15624; // Adjust this value as needed

	 //Enable Timer1 overflow interrupt (if needed)
	 TIM1_TIMSK |= (1 << 2);
}


// Timer1 overflow interrupt service routine (if enabled)
ISR(TIMER1_OVF_vect) {
	// Your interrupt code here
	Enable_Ginterrupt;
}




