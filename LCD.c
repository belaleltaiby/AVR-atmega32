/*
 * LCD.c
 *
 * Created: 10/22/2023 10:15:45 AM
 *  Author: Belal
 */ 



#include "LCD.h"
#include "Types.h"
#include "DIO.h"
#include<util/delay.h> // delay header

#include "DIO_private.h"
#include "LCD.h"
#include "Types.h"
#include "Bit_Math.h"

void LCD_VoidSetLcdDirection()
{
	SETPINDIrection(LCD_PORT_PIN0,OUTPUT);
	SETPINDIrection(LCD_PORT_PIN1,OUTPUT);
	SETPINDIrection(LCD_PORT_PIN2,OUTPUT);
	SETPINDIrection(LCD_PORT_PIN3,OUTPUT);
}
void LCD_INIT()
{
	LCD_VoidSetLcdDirection();
	SETPINDIrection(portA,RS_PIN,OUTPUT);
	SETPINDIrection(portA,EN_PIN,OUTPUT);
	_delay_ms(15);
	LCD_WRITE_COMMAND(0x02);
	_delay_ms(2);
	LCD_WRITE_COMMAND(0x28);
	_delay_ms(2);
	LCD_WRITE_COMMAND(0x0C);
	LCD_WRITE_COMMAND(0x06);
	LCD_WRITE_COMMAND(0x01);
	_delay_ms(2);
}

void LCD_voidSetLCDValue( uint8 copy_data )
{
	setpinvalue(LCD_PORT_PIN0,(copy_data&0b00000001));
	setpinvalue(LCD_PORT_PIN1,(copy_data&0b00000010)>>1);
	setpinvalue(LCD_PORT_PIN2,(copy_data&0b00000100)>>2);
	setpinvalue(LCD_PORT_PIN3,(copy_data&0b00001000)>>3);
	
}

void LCD_WRITE_COMMAND(char data)
{
	
	clearBit(PORTA , RS_PIN);
		//Send High Nibble///////////
		LCD_voidSetLCDValue(data>>4);
        //RS 0 command
	setBit(EN_PORT,EN_PIN);
	_delay_ms(1);
	clearBit(EN_PORT,EN_PIN);
	
	_delay_ms(1);

	
	clearBit(PORTA , RS_PIN);
	//Send Low Nibble
	LCD_voidSetLCDValue(data);  //RS 0 command
	setBit(EN_PORT,EN_PIN);
	_delay_ms(1);
	clearBit(EN_PORT,EN_PIN);
	
	_delay_ms(1);
}

void LCD_WRITE_CHAR(char data)
{
	
	setBit(RS_PORT , RS_PIN);  //RS a1 for data
		//Send High Nibble///////////
		LCD_voidSetLCDValue(data>>4);
	setBit(EN_PORT,EN_PIN);
	_delay_ms(1);
	clearBit(EN_PORT,EN_PIN);
	
	_delay_ms(1);
	
	setBit(PORTA , RS_PIN);  //RS 1 
	
	//Send Low Nibble
	LCD_voidSetLCDValue(data);
	
	setBit(EN_PORT,EN_PIN);
	_delay_ms(1);
	clearBit(EN_PORT,EN_PIN);
	
	_delay_ms(1);
}
/*
void LCD_WRITE_STRING( char* string)
{
	int count=0;
	while(*string > 0){
		count++;
		LCD_WRITE_CHAR( *string++);
		if(count ==16){
			LCD_GOTO_XY( 1, 0);
		}
		if(count == 32 || count==33){
			LCD_clear_screen(LCD);
			LCD_GOTO_XY(LCD ,0, 0);
			count=0;
		}
	}
}


void LCD_clear_screen(LCD_TypeDef* LCD)
{
	LCD_WRITE_COMMAND(LCD,LCD_CLEAR_SCREEN);
}
void LCD_GOTO_XY(LCD_TypeDef* LCD,unsigned char line, unsigned char position)
{
	if(line == 0)
	{
		if(position < 20 && position >= 0)
		{
			LCD_WRITE_COMMAND(LCD,LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}

	if(line == 1)
	{
		if(position < 20 && position >= 0)
		{
			LCD_WRITE_COMMAND( LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}
*/
/**********************************************************************************************************************/


