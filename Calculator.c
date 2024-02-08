/*
 * Calculator.c
 *
 * Created: 10/25/2023 2:22:46 PM
 *  Author: Belal
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include "Calculator.h"
#include "lcd2.h"

int get_num(unsigned char ch)         //convert unsigned char into int
{
	int num = 0;
	switch(ch)
	{
		case '0':
		num = 0;
		break;
		case '1':
		num = 1;
		break;
		case '2':
		num = 2;
		break;
		case '3':
		num = 3;
		break;
		case '4':
		num = 4;
		break;
		case '5':
		num = 5;
		break;
		case '6':
		num = 6;
		break;
		case '7':
		num = 7;
		break;
		case '8':
		num = 8;
		break;
		case '9':
		num = 9;
		break;
		case 'C':
		LCD_SendCommand(0x01);
		num = Error;
		break;  //this is used as a clear screen and then reset by setting error
		default:
		DispError(0);
		num = Error;
		break;       //it means wrong input
	}
	return num;
}

unsigned char get_func(unsigned char chf)            //detects the errors in inputted function
{
	if(chf=='C')                   //if clear screen then clear the LCD and reset
	{
		LCD_SendCommand(0x01);             //clear display
		return 'e';
	}
	if( chf != '+' && chf != '-' && chf != 'x' && chf != '/' )  //if input is not from allowed funtions then show error
	{
		DispError(1);
		return 'e';
	}
	return chf;                        //function is correct so return the correct function
}


void DispError(int numb)           //displays differet error messages
{
	unsigned char msg1[] = {"Wrong Input"};
	unsigned char msg2[] = {"Wrong Function"};

	LCD_SendCommand(0x01);              //clear display
	switch(numb)
	{
		case 0:
			LCD_SendString(msg1);
			break;
		case 1:
			LCD_SendString(msg2);
			break;
		default:
			LCD_SendString(msg1);
			break;
	}
}

void disp_num(int numb)            //displays number on LCD
{
	unsigned char UnitDigit  = 0;  //It will contain unit digit of numb
	unsigned char TenthDigit = 0;  //It will contain 10th position digit of numb

	if(numb<0)    {
		numb = -1*numb;          // Make number positive
		LCD_SendChar('-');   // Display a negative sign on LCD
	}
	TenthDigit = (numb/10);                    // Find out Tenth Digit

	if( TenthDigit != 0)                    // If it is zero, then don't display
	LCD_SendChar(TenthDigit+0x30);    // Make Char of TenthDigit and then display it on LCD
	UnitDigit = numb - TenthDigit*10;
	LCD_SendChar(UnitDigit+0x30);    // Make Char of UnitDigit and then display it on LCD
}

void calc()
{
	unsigned char key;           	// Key char for keeping record of pressed key
	int num1, num2;       				// First number, second number
	char func;    				// Function to be performed among two numbers
	//
	// 	lcdgoto(5,1);
	// 	lcdstr("ATmega32 ");
	// 	lcdgoto(4,2);
	// 	lcdstr("Calculator");
	// 	_delay_ms(2000);
	// 	lcdclear();
	
	
	while(1)
	{
		key = KEYPAD_READ();		 //get numb1
		LCD_SendCommand(0x01);         	// Clear LCD screen
		LCD_SendChar(key);       		// Echo the key pressed to LCD
		num1 = get_num(key);       // Get int number from char value, it checks for wrong input as well

		if(num1 != Error)            // If correct input then proceed, num1==Error means wrong input
		{
			key = KEYPAD_READ();		//get function
			LCD_SendChar(key);             //Echo the key pressed to LCD
			func = get_func(key);            //it checks for wrong func
			if(func!='e')                    //if correct input then proceed, func=='e' means wrong input
			{
				key = KEYPAD_READ();		 	//get numb2
				LCD_SendChar(key);   				//Echo the key pressed to LCD
				num2 = get_num(key);  //Get int number from char value, it checks for wrong input as well
				if(num2!=Error)  				//if correct input then proceed, num2==Error means wrong input
				{
					key = KEYPAD_READ();	//get equal sign
					LCD_SendChar(key); //Echo the key pressed to LCD
					if(key == '=')    //if = is pressed then proceed
					{
						switch(func)    //switch on function
						{
							case '+':
							disp_num(num1+num2);
							break;
							case '-':
							disp_num(num1-num2);
							break;
							case 'x':
							disp_num(num1*num2);
							break;
							case '/':
							disp_num(num1/num2);
							break;
						}
					}
					else   //key other then = here means error wrong input
					{
						if(key == 'C')     //if clear screen is pressed then clear screen and reset
						LCD_SendCommand(0x01); // Clear LCD screen
						else
						DispError(0);     //Display wrong input error
					}
				}
			}
		}
		
	}
	
}