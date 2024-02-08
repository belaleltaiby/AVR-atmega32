/*
* seven_seg.c
*
* Created: 10/21/2023 12:53:18 PM
*  Author: Belal
*/
#include "seven_seg.h"
#include "DIO_private.h"
#include <avr/delay.h>
uint8 m = 0;
void disable_digit(DIGITS digit)
{
	switch (digit)
	{
		case digit0:
			setpinvalue(portA,PIN3,LOW);
			break;
		case digit1:
			setpinvalue(portA,PIN2,LOW);
			break;
		case digit2:
			setpinvalue(portB,PIN5,LOW);
			break;
		case digit3:
			setpinvalue(portB,PIN6,LOW);
			break;
	}
}

void Enable_digit(DIGITS digit)
{
	switch (digit)
	{
		case digit0:
		SETPINDIrection(portA,PIN3,OUTPUT);
		setpinvalue(portA,PIN3,HIGH);  //porta3-> Digit1
		setpinvalue(portA,PIN2,LOW);	//porta2 ->digit2
		setpinvalue(portB,PIN5,LOW);	//portb5 ->digit3
		setpinvalue(portB,PIN6,LOW);	//portb6 ->digit4
		break;
		case digit1:
		SETPINDIrection(portA,PIN2,OUTPUT);
		setpinvalue(portA,PIN3,LOW);
		setpinvalue(portA,PIN2,HIGH);
		setpinvalue(portB,PIN5,LOW);
		setpinvalue(portB,PIN6,LOW);
		break;
		case digit2:
		SETPINDIrection(portB,PIN5,OUTPUT);
		setpinvalue(portA,PIN3,LOW);
		setpinvalue(portA,PIN2,LOW);
		setpinvalue(portB,PIN5,HIGH);
		setpinvalue(portB,PIN6,LOW);
		break;
		case digit3:
		SETPINDIrection(portB,PIN6,OUTPUT);
		setpinvalue(portA,PIN3,LOW);
		setpinvalue(portA,PIN2,LOW);
		setpinvalue(portB,PIN5,LOW);
		setpinvalue(portB,PIN6,HIGH);
		break;
	}
}

void Set_number(DIGITS Digit, int num)
{
	ControlPortDIR(portB,OUTPUT);
	switch (num)
	{
		case 0:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,0); 
				setpinvalue(portB,PIN1,0); 
				setpinvalue(portB,PIN2,0); 
				setpinvalue(portB,PIN4,0); 
				
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,0);
				setpinvalue(portB,PIN1,0);
				setpinvalue(portB,PIN2,0);
				setpinvalue(portB,PIN4,0);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,0);
				setpinvalue(portB,PIN1,0);
				setpinvalue(portB,PIN2,0);
				setpinvalue(portB,PIN4,0);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,0);
				setpinvalue(portB,PIN1,0);
				setpinvalue(portB,PIN2,0);
				setpinvalue(portB,PIN4,0);
				break;
		}
		break;
		case 1:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,0xE1);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,0xE1);
					setpinvalue(portB,PIN0,HIGH);
					setpinvalue(portB,PIN1,LOW);
					setpinvalue(portB,PIN2,LOW);
					setpinvalue(portB,PIN4,LOW);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
		}
		break;
		
		case 2:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x02 | PORTB));
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x02 | PORTB));
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
		}
		break;
		case 3:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,0xE3);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,0xE3);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x03 | PORTB));
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x03 | PORTB));
					setpinvalue(portB,PIN0,HIGH);
					setpinvalue(portB,PIN1,HIGH);
					setpinvalue(portB,PIN2,LOW);
					setpinvalue(portB,PIN4,LOW);
				break;
		}
		break;
		
		case 4:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x04 | PORTB));
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x04 | PORTB));
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
		}
		break;
		case 5:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
			
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x05 | PORTB));
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x05 | PORTB));
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
		}
		break;
		case 6:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x06 | PORTB));
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,(0x06 | PORTB));
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
		}
		break;
		case 7:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,HIGH);
				setpinvalue(portB,PIN2,HIGH);
				setpinvalue(portB,PIN4,LOW);
				break;
		}
		break;
		case 8:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,HIGH);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,HIGH);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,HIGH);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,LOW);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,HIGH);
				break;
		}
		break;
		case 9:
		switch (Digit){
			case digit0:
				Enable_digit(digit0);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,HIGH);
				break;
			case digit1:
				Enable_digit(digit1);
				//ControlPortDIR(portB,OUTPUT);
				//controlPortValue(portB,0xF1);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,HIGH);
				break;
			case digit2:
				Enable_digit(digit2);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,HIGH);
				break;
			case digit3:
				Enable_digit(digit3);
				//ControlPortDIR(portB,OUTPUT);
				setpinvalue(portB,PIN0,HIGH);
				setpinvalue(portB,PIN1,LOW);
				setpinvalue(portB,PIN2,LOW);
				setpinvalue(portB,PIN4,HIGH);
				break;
		}
		break;
		default:
			setpinvalue(portB,PIN0,HIGH);
			setpinvalue(portB,PIN1,HIGH);
			setpinvalue(portB,PIN2,HIGH);
			setpinvalue(portB,PIN4,HIGH);
		 break;
		
	}
}


void Set_all_Digits(uint8 Digit0,uint8 Digit1,uint8 Digit2,uint8 Digit3){
	int i;
	for (i=0;i<4;i++)
	{
		Enable_digit(i);
		switch (i){
			case 0:
				Set_number(digit0,Digit0);
				break;
			case 1:
				Set_number(digit1,Digit1);
				break;
			case 2:
				Set_number(digit2,Digit2);
				break;
			case 3:
				Set_number(digit3,Digit3);
				break;
		}
		
		_delay_ms(10);
		disable_digit(i);
	}
}


void Set_all_Digits_digitalClock(int Digit0,int Digit1,int Digit2,int Digit3,uint8 FlagB1,uint8 FlagB2)
{
	static uint8 a,b,c,d = 0;
	int i;
	for (i=0;i<4;i++)
	{
		Enable_digit(i);
		_delay_ms(40);
		switch (i){
			case 0: 
			if (FlagB2 && a)
			{
 				Set_number(digit0,20);
				
				a=0;
			}else{
				
				Set_number(digit0,Digit0);
				a=1;
			}
			break;
			case 1:
			if (FlagB2 && b)
			{
				Set_number(digit1,20);
				//_delay_ms(5);
				b=0;
			}else{
				Set_number(digit1,Digit1);
				//_delay_ms(5);
				b=1;
			}
			break;
			case 2:
			if (FlagB1 && c)
			{
				Set_number(digit2,20);
				//_delay_ms(5);
				c=0;
			}else{
				Set_number(digit2,Digit2);
				//_delay_ms(5);
				c=1;
			}
			break;
			case 3:
			if (FlagB1 && d)
			{
				Set_number(digit3,20);
				
				d=0;
			}else{
				Set_number(digit3,Digit3);
				
				d=1;
			}
			break;
		}
		_delay_ms(5);
		disable_digit(i);
	}
}
// void Seg_Blinking_Dig2_3()
// {
// 	static uint8 a,b,c,d = 0;
// 	int i ;
// 	for (i=0;i<4;i++)
// 	{
// 		Enable_digit(i);
// 		switch (i){
// 			case 0:
// 			Set_number(digit0,digit0);
// 			break;
// 			case 1:
// 			Set_number(digit1,digit1);
// 			break;
// 			case 2:
// 			Set_number(digit2,digit2);
// 			break;
// 			case 3:
// 			Set_number(digit3,digit3);
// 			break;
// 		}
// 		
// 		_delay_ms(10);
// 		disable_digit(i);
// 	}
// }


void SEG_voidBlink(uint8 Copy_u8Num1,uint8 Copy_u8Num2,uint8 Copy_u8Num3,uint8 Copy_u8Num4){
	static int c,m = 0;

	for(int i=0;i<4;i++){
		Enable_digit(i);
		_delay_ms(40);
		switch (i){
			case 0:Set_number(i,Copy_u8Num1+c);
			if(c==10){
				c=0;
				}else{
				c= 10;
			}
			break;
			case 1:Set_number(i,Copy_u8Num2+m);
			if(m==10){
				m=0;
				}else{
				m= 10;
			}break;
			case 2:Set_number(i,Copy_u8Num3);break;
			case 3:Set_number(i,Copy_u8Num4);break;
			default:Set_number(i,0);break;
		}
		_delay_ms(10);
		disable_digit(i);
	}

}


void SEG_voidBlink2(uint8 Copy_u8Num1,uint8 Copy_u8Num2,uint8 Copy_u8Num3,uint8 Copy_u8Num4){
	static int n,k = 0;

	for(int i=0;i<4;i++){
		Enable_digit(i);
		_delay_ms(40);
		switch (i){
			case 0:Set_number(i,Copy_u8Num1);break;
			case 1:Set_number(i,Copy_u8Num2);break;
			case 2:Set_number(i,Copy_u8Num3+n);if(n==10){
				n=0;
				}else{
				n= 10;
			}break;
			case 3:Set_number(i,Copy_u8Num4+k);if(k==10){
				k=0;
				}else{
				k= 10;
			}break;
			default:Set_number(i,0);break;
		}
		_delay_ms(10);
		disable_digit(i);
	}

}