/*
 * KEYPAD.c
 *
 * Created: 10/23/2023 10:36:44 AM
 *  Author: Belal
 */ 
#define  F_CPU  16000000
#include "kEYPAD.h"
#include "seven_seg.h"
#include "util/delay.h" 

void KeyPad_init();
int Get_Press();

unsigned char KEYPAD_MATRIX[16] = {	'7','8','9','/',
	'4','5','6','x',
	'1','2','3','-',
' ','0','=','+'};
	
uint8_t KEYPAD_MATRIX_basma[16] ={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
void KeyPad_init()
{
	//ControlPortDIR(portC,OUTPUT);
	//ControlPortDIR(portD,INPUT);
	
	//Rows are output
	SETPINDIrection(portC,PIN5,OUTPUT);
	SETPINDIrection(portC,PIN4,OUTPUT);
	SETPINDIrection(portC,PIN3,OUTPUT);
	SETPINDIrection(portC,PIN2,OUTPUT);
	
	//colomns are input
	SETPINDIrection(portD,PIN7,INPUT);
	SETPINDIrection(portD,PIN6,INPUT);
	SETPINDIrection(portD,PIN5,INPUT);
	SETPINDIrection(portD,PIN3,INPUT);
		//zeros to rows
	setpinvalue(portC,2,LOW);
	setpinvalue(portC,3,LOW);
	setpinvalue(portC,4,LOW);
	setpinvalue(portC,5,LOW);
}

unsigned char KEYPAD_READ()
{
	DDRC = 0b11111111;
	PORTC =0b00000000;
	DDRD = 0b00000000;
	PORTD = 0b11111111;
	
	while(1){
		KEYPAD_R1(0); KEYPAD_R2(1); KEYPAD_R3(1); KEYPAD_R4(1);//row1
		if(KEYPAD_C1 == 0){
			_delay_ms(2);
			while(KEYPAD_C1 == 0);
			return KEYPAD_MATRIX[0];
			}		
		if(KEYPAD_C2 == 0){
			_delay_ms(2);
			while(KEYPAD_C2 == 0);
			return KEYPAD_MATRIX[1];
			}		
		if(KEYPAD_C3 == 0){
			_delay_ms(2);
			while(KEYPAD_C3 == 0);
			return KEYPAD_MATRIX[2];
			}		
		if(KEYPAD_C4 == 0){
			_delay_ms(2);
			while(KEYPAD_C4 == 0);
			return KEYPAD_MATRIX[3];
			}		
		_delay_ms(1);
	
		KEYPAD_R1(1); KEYPAD_R2(0); KEYPAD_R3(1); KEYPAD_R4(1);  //row2
		if(KEYPAD_C1 == 0){
			_delay_ms(2);
			while(KEYPAD_C1 == 0);
			return KEYPAD_MATRIX[4];
		}
		if(KEYPAD_C2 == 0){
			_delay_ms(2);
			while(KEYPAD_C2 == 0);
			return KEYPAD_MATRIX[5];
		}
		if(KEYPAD_C3 == 0){
			_delay_ms(2);
			while(KEYPAD_C3 == 0);
			return KEYPAD_MATRIX[6];
		}
		if(KEYPAD_C4 == 0){
			_delay_ms(2);
			while(KEYPAD_C4 == 0);
			return KEYPAD_MATRIX[7];
		}
		_delay_ms(1);
	
		KEYPAD_R1(1); KEYPAD_R2(1); KEYPAD_R3(0); KEYPAD_R4(1);     //row3
		if(KEYPAD_C1 == 0){
			_delay_ms(2);
			while(KEYPAD_C1 == 0);
			return KEYPAD_MATRIX[8];
		}
		if(KEYPAD_C2 == 0){
			_delay_ms(2);
			while(KEYPAD_C2 == 0);
			return KEYPAD_MATRIX[9];
		}
		if(KEYPAD_C3 == 0){
			_delay_ms(2);
			while(KEYPAD_C3 == 0);
			return KEYPAD_MATRIX[10];
		}
		if(KEYPAD_C4 == 0){
			_delay_ms(2);
			while(KEYPAD_C4 == 0);
			return KEYPAD_MATRIX[11];
		}
		_delay_ms(1);
	
		KEYPAD_R1(1); KEYPAD_R2(1); KEYPAD_R3(1); KEYPAD_R4(0);  //row4
		if(KEYPAD_C1 == 0){
			_delay_ms(2);
			while(KEYPAD_C1 == 0);
			return KEYPAD_MATRIX[12];
		}
		if(KEYPAD_C2 == 0){
			_delay_ms(2);
			while(KEYPAD_C2 == 0);
			return KEYPAD_MATRIX[13];
		}
		if(KEYPAD_C3 == 0){
			_delay_ms(2);
			while(KEYPAD_C3 == 0);
			return KEYPAD_MATRIX[14];
		}
		if(KEYPAD_C4 == 0){
			_delay_ms(2);
			while(KEYPAD_C4 == 0);
			return KEYPAD_MATRIX[15];
		}
		_delay_ms(1);
	}
	return 0xFF;
}



