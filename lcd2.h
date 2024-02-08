/*
 * lcd2.h
 *
 * Created: 10/24/2023 1:33:22 PM
 *  Author: Belal
 */ 


#ifndef LCD2_H_
#define LCD2_H_
#include "Types.h"

void LCD_Init(void);
void LCD_SendChar(uint8 ch);
void LCD_SendString(char * str);
void LCD_GoTo(uint8 line, uint8 column);
void LCD_CustomChar(uint8 address,uint8*pattern);
void LCD_Clear(void);
void LCD_writeNumber(int num);
void LCD_SendCommand(uint8 command);



#endif /* LCD2_H_ */