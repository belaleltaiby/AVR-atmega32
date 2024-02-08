/*
 * Digital_clock.c
 *
 * Created: 10/31/2023 11:57:24 PM
 *  Author: Belal
 */ 
#include "Digital_clock.h"
#include "seven_seg.h"
#include "Calculator.h"

unsigned char KEYPAD_MATRIX_for_digital_clock[16] = {	'7','8','9','/',
	'4','5','6','x',
	'1','2','3','-',
' ','0','=','+'};

static uint8 Blinking_Button = 56;
static uint8 Setting_clock_Button=56;
static uint8 Capture_hour=56;
static uint8 Capture_minutes=56;
static uint8 Last_Capture_hour_num=0;
static uint8 Last_Capture_minutes_num = 0;

extern uint8 Press_counts;
extern uint8 Press2_counts;
extern uint8 minutes;
extern uint8 houres ;
extern uint8 cnt_OVS ;
extern uint8 G_cntSeconds;


void Push_Button_reset()
{
	houres=0;
	minutes=0;
	Set_all_Digits(0,0,0,0);
}

// 
// void Button_Blinking_thenSetting_hours()
// {
// 	Press_counts++;
// 	
// 	Blinking_Button = 0xFF;
// 	Setting_clock_Button=0xFF;
// 	Capture_hour=0xFf;
// 	Capture_minutes=0xFF;
// 	Last_Capture_hour_num=0xFF;
// 	Last_Capture_minutes_num = 0xFF;
// 		
// 	
// 	while(Blinking_Button !=  KEYPAD_MATRIX_for_digital_clock[3])
// 	{
// 		Blinking_Button = KEYPAD_READ();
// 	}
// 	
// 	if (Blinking_Button == KEYPAD_MATRIX_for_digital_clock[3] && Press_counts == 1)
// 	{
// 			while(Setting_clock_Button !=KEYPAD_MATRIX_for_digital_clock[7])
// 			{
// 				//Enable_digit(digit2);
// 				//Set_number(digit2,Last_Capture_hour_num);
// 				Set_all_Digits(Last_Capture_minutes_num,Last_Capture_minutes_num,Last_Capture_hour_num, Last_Capture_hour_num);
// 				//_delay_ms(50);
// 				//disable_digit(digit2);
// 				//SEG_voidBlink2(Last_Capture_minutes_num,0,Last_Capture_hour_num,0);
// 				Setting_clock_Button = KEYPAD_READ();
// 			}
// 			
// 			if (Setting_clock_Button == KEYPAD_MATRIX_for_digital_clock[7] )
// 			{
// 				//Enable_digit(digit2);
// 				_delay_ms(10);
// 				while(Capture_hour == 0XFF)
// 				{
// 					Capture_hour = KEYPAD_READ();
// 				}
// 				
// 				uint8 Capture_hour_num = get_num(Capture_hour);
// 				Last_Capture_hour_num = Capture_hour_num;
// 				//Set_number(digit2,Capture_hour_num);
// 				Set_all_Digits(Last_Capture_minutes_num,Last_Capture_minutes_num,Capture_hour_num, Capture_hour_num);
// 			}
// 	}else if (Blinking_Button == KEYPAD_MATRIX_for_digital_clock[3] && Press_counts == 2)
// 	{
// 		while(Setting_clock_Button !=KEYPAD_MATRIX_for_digital_clock[7])
// 		{
// 			//Enable_digit(digit0);
// 			Set_all_Digits(Last_Capture_minutes_num,Last_Capture_minutes_num,Last_Capture_hour_num, Last_Capture_hour_num);
// 			_delay_ms(50);
// 			//disable_digit(digit0);
// 			//SEG_voidBlink(Last_Capture_minutes_num,0,Last_Capture_hour_num,0);
// 			Setting_clock_Button = KEYPAD_READ();
// 		}
// 		if (Setting_clock_Button == KEYPAD_MATRIX_for_digital_clock[7] )
// 		{
// 			//Enable_digit(digit0);
// 			_delay_ms(10);
// 			while(Capture_minutes == 0XFF)
// 			{
// 				Capture_minutes = KEYPAD_READ();
// 			}
// 			uint8 Capture_minutes_num = get_num(Capture_minutes);
// 			Last_Capture_minutes_num =Capture_minutes_num;
// 			//Set_number(digit0,Capture_minutes_num);
// 			Set_all_Digits(Capture_minutes_num,Capture_minutes_num,Last_Capture_hour_num, Last_Capture_hour_num);
// 
// 		}
// 		Press_counts=0;
// 	}
// }