/*
 * LCD.h
 *
 * Created: 10/22/2023 10:15:59 AM
 *  Author: Belal
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "Types.h"
//#include "DIO_private.h"
#include "Bit_Math.h"
#include "DIO.h"

#define LCD_PORT_PIN0    portB,PIN0
#define LCD_PORT_PIN1    portB,PIN1
#define LCD_PORT_PIN2    portB,PIN2
#define LCD_PORT_PIN3    portB,PIN4

// LCD configuration for 4 Bit Mode
typedef struct{
	GPIO_TypeDef * RS_Port;
	//uint16_t RS_PIN;

	GPIO_TypeDef * EN_Port;
	//uint16_t EN_PIN;

	GPIO_TypeDef * D4_Port;
	//uint16_t D4_PIN;

	GPIO_TypeDef * D5_Port;
	//uint16_t D5_PIN;

	GPIO_TypeDef * D6_Port;
	//uint16_t D6_PIN;

	GPIO_TypeDef * D7_Port;
	//uint16_t D7_PIN;

}LCD_TypeDef;
#define  RS_GPIO           GPIOA
#define  RS_PORT           PORTA
#define  RS_PIN            3

#define  EN_GPIO           GPIOA
#define  EN_PORT           PORTA
#define  EN_PIN            2

#define  D4_GPIO           GPIOB
#define  D4_PORT           PORTB
#define  D4_PIN            0

#define  D5_GPIO           GPIOB
#define  D5_PORT           PORTB
#define  D5_PIN            1

#define  D6_GPIO           GPIOB
#define  D6_PORT           PORTB
#define  D6_PIN            2

#define  D7_GPIO           GPIOB
#define  D7_PORT           PORTB
#define  D7_PIN            4

/*------------ Declaring Private Macro -----------------*/

/*--------------------commands for LCD------------------------*/
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_8BIT_1LINE   					(0x30)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC  								(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

#define PIN_LOW(PORT,PIN)	clearBit(PORT,PIN);
#define PIN_HIGH(PORT,PIN)	setBit(PORT,PIN);
//GPIO_PinConfig_t*  PCFG;

/*---------------------APIs-------------------*/
void LCD_INIT(void);
void LCD_WRITE_COMMAND(char data);
void LCD_WRITE_CHAR(char data);
void LCD_WRITE_STRING(LCD_TypeDef* LCD , char* string);
void LCD_clear_screen(LCD_TypeDef* LCD);
void LCD_GOTO_XY(LCD_TypeDef* LCD , unsigned char line, unsigned char position);















/********************************************************************************************/

#endif /* LCD_H_ */