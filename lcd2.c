/*
 * lcd2.c
 *
 * Created: 10/24/2023 1:32:57 PM
 *  Author: Belal
 */ 

#include "DIO.h"
#include "DIO_private.h"
#include "Bit_Math.h"
#include "lcd2.h"
#include "DIO_private.h"
# define F_CPU 16000000  
#include "util/delay.h"  
#define LCD_CONFIG_WORD             (0x30)

#define LCD_CLR                     (0x01)

#define LCD_CURSOR_HOME             (0x02)

#define LCD_SET_ENTRY_MODE          (0x40)
#define LCD_INCREMENT_CURSOR        (0x02)
#define LCD_DECREMENT_CURSOR        (0x00)
#define LCD_DISPLAY_SHIFT_ON        (0x01)
#define LCD_DISPLAY_SHIFT_OFF       (0x00)

#define LCD_DISPLAY_CONTROL         (0x08)
#define LCD_DISPLAY_ON              (0x04)
#define LCD_DISPLAY_OFF             (0x00)
#define LCD_CURSOR_ON               (0x02)
#define LCD_CURSOR_OFF              (0x00)
#define LCD_CURSOR_BLINK_ON         (0x01)
#define LCD_CURSOR_BLINK_OFF        (0x00)

#define LCD_CURSOR_DISPLAY_CONTROL  (0x10)
#define LCD_SHIFT_CURSOR            (0x00)
#define LCD_SHIFT_DISPLAY           (0x08)
#define LCD_SHIFT_LEFT              (0x00)
#define LCD_SHIFT_RIGHT             (0x04)

#define LCD_FUNCTION_SET            (0x20)
#define LCD_DATA_LENGTH_4           (0x00)
#define LCD_DATA_LENGTH_8           (0x10)
#define LCD_ONE_LINE                (0x00)
#define LCD_TWO_LINES               (0x08)
#define LCD_SMALL_FONT              (0x00)
#define LCD_LARGE_FONT              (0x04)

#define LCD_SET_CGRAM_ADDRESS       (0x40)

#define LCD_SET_DDRAM_ADDRESS       (0x80)

#define LCD_DDRAM_LINE_SIZE         (0x28)
#define LCD_DDRAM_LINE_2_ADDRESS    (0x40)

void LCD_SendCommand(uint8 command);
static void LCD_SendData(uint8 character);

void LCD_Init(void)
{
	/* Add your code here */
	/* Initialize Pins */
	//ControlPortDIR(portB,OUTPUT);
	//ControlPortDIR(portA,OUTPUT);
	
	SETPINDIrection(portA,PIN3,OUTPUT);
	SETPINDIrection(portA,PIN2,OUTPUT);
	
	SETPINDIrection(portB,PIN0,OUTPUT);
	SETPINDIrection(portB,PIN1,OUTPUT);
	SETPINDIrection(portB,PIN2,OUTPUT);
	SETPINDIrection(portB,PIN4,OUTPUT);
	
	SETPINDIrection(portB,PIN3,INPUT);
	_delay_ms(15);
	LCD_SendCommand(0x02);
	_delay_ms(2);
	LCD_SendCommand(0x28);
	_delay_ms(2);
	LCD_SendCommand(0x0c);
	LCD_SendCommand(0x06);
	LCD_SendCommand(0x01);
	_delay_ms(2);
	
	
	/* Initialization sequence */

	/* Initial LCD commands */
	/* Select data length = 8 bits, 2 lines LCD and small font */

	/* Turn display , cursor and blinking OFF */

	/* Clear LCD */

	/* Increment cursor and turn off display shift */

	/* Turn display ON */


	/* End of your code !*/
}
void LCD_SendChar(uint8 ch)
{
	/* Add your code here */
	/* Change position and send character */
	LCD_SendData(ch);
	/* End of your code !*/

}

void LCD_SendString(char * str)
{
	uint8 i;
	/* Add your code here */
	for (i=0;str[i];i++)
	{
		LCD_SendData(str[i]);
	}
	/* Clear screen and send character by character to the LCD */

	/* End of your code !*/
}

void LCD_SendCommand(uint8 command)
{
	/* Add your code here */
	//setpinvalue(RS,LOW);
	clearBit(PORTA,3);
	//setpinvalue(D4,READBIT(command,4));
	
	setpinvalue(portB,PIN0,getbit(command,4));
	setpinvalue(portB,PIN1,getbit(command,5));
	setpinvalue(portB,PIN2,getbit(command,6));
	setpinvalue(portB,PIN4,getbit(command,7));
	
	setpinvalue(portA,PIN2,HIGH);
	_delay_ms(1);
	setpinvalue(portA,PIN2,LOW);
	_delay_ms(1);
	//sent the lower nibble
	setpinvalue(portB,PIN0,getbit(command,0));
	setpinvalue(portB,PIN1,getbit(command,1));
	setpinvalue(portB,PIN2,getbit(command,2));
	setpinvalue(portB,PIN4,getbit(command,3));
	
	setpinvalue(portA,PIN2,HIGH);
	_delay_ms(1);
	setpinvalue(portA,PIN2,LOW);
	_delay_ms(1);
	/* End of your code !*/

}

static void LCD_SendData(uint8 character)
{
	/* Add your code here */
	setBit(PORTA,3);
	
	setpinvalue(portB,PIN0,getbit(character,4));
	setpinvalue(portB,PIN1,getbit(character,5));
	setpinvalue(portB,PIN2,getbit(character,6));
	setpinvalue(portB,PIN4,getbit(character,7));
	
	setpinvalue(portA,PIN2,HIGH);
	_delay_ms(1);
	setpinvalue(portA,PIN2,LOW);
	_delay_ms(1);
	
	setpinvalue(portB,PIN0,getbit(character,0));
	setpinvalue(portB,PIN1,getbit(character,1));
	setpinvalue(portB,PIN2,getbit(character,2));
	setpinvalue(portB,PIN4,getbit(character,3));
	
	setpinvalue(portA,PIN2,HIGH);
	_delay_ms(1);
	setpinvalue(portA,PIN2,LOW);
	_delay_ms(1);
	/* End of your code !*/
}

void LCD_GoTo(uint8 line, uint8 column)
{
	uint8 address = 0;
	/* Calculate address in DDRAM */
	switch(line){
		case 0: address = (column); break;;
		case 1: address = (column+0x40); break;;
		case 2: address = (column+0x14); break;;
		case 3: address = (column+0x54); break;;
	}
	LCD_SendCommand(address|(0x80));
	/* Send address to LCD */

	/* End of your code !*/

}

void LCD_CustomChar(uint8 address,uint8*pattern)
{
	uint8 i;
	LCD_SendCommand(0x40+(address*8));
	for(i=0;i<8;i++){
		LCD_SendData(pattern[i]);
	}
	LCD_SendCommand(0x80);
}

void LCD_Clear(void)
{
	LCD_SendCommand(0x01);
}


void LCD_writeNumber(int num)
{
	int n=0;
	uint8 flag=0,rem=0;
	if(num<0){
		LCD_SendChar('-');
		num=num*(-1);
	}
	if(num==0){
		LCD_SendChar('0');
	}
	else{
		while(num){
			rem=num%10;
			if(n==0 && rem==0){
				flag++;
			}
			n=(n*10)+rem;
			num=num/10;
		}
		while(n){
			rem=n%10;
			LCD_SendChar('0'+rem);
			n=n/10;
		}
		while(flag){
			LCD_SendChar('0');
			flag--;
		}
	}
}