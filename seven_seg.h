/*
 * seven_seg.h
 *
 * Created: 10/21/2023 12:52:44 PM
 *  Author: Belal
 */ 


#ifndef SEVEN_SEG_H_
#define SEVEN_SEG_H_


#include "DIO.h"
typedef enum{
	digit0,
	digit1,
	digit2,
	digit3
}DIGITS;
//APIS
void Enable_digit(DIGITS digit);
void Set_number(DIGITS Digit,int num);
void Set_all_Digits(uint8 Digit0,uint8 Digit1,uint8 Digit2,uint8 Digit3);
void SEG_voidBlink(uint8 Copy_u8Num1,uint8 Copy_u8Num2,uint8 Copy_u8Num3,uint8 Copy_u8Num4);
void SEG_voidBlink2(uint8 Copy_u8Num1,uint8 Copy_u8Num2,uint8 Copy_u8Num3,uint8 Copy_u8Num4);
void Seg_Blinking_Dig2_3();
void disable_digit(DIGITS digit);
void Set_all_Digits_digitalClock(int Digit0,int Digit1,int Digit2,int Digit3,uint8 FlagB1,uint8 FalgB2);
#endif /* SEVEN_SEG_H_ */