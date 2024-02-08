/*
 * IncFile1.h
 *
 * Created: 10/20/2023 2:20:36 PM
 *  Author: Belal
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "Types.h"
//#include "DIO_private.h"
typedef enum {OK,NOK} ERROR_status;

#define PIN_OUTPUT 0x1
#define PIN_INPUT  0x0

#define PORT_OUTPUT 0xFF
#define PORT_INPUT 0x00

#define LOW  0
#define HIGH 1

#define PIN0  0
#define PIN1  1
#define PIN2  2
#define PIN3  3
#define PIN4  4
#define PIN5  5
#define PIN6  6
#define PIN7  7

typedef struct{
	uint8 PINx;
	uint8 DDRx;
	uint8 PORTx;
	}GPIO_TypeDef;


#define  GPIOA      ((GPIO_TypeDef*) 0x39)
#define  GPIOB      ((GPIO_TypeDef*) 0x36)
#define  GPIOC      ((GPIO_TypeDef*) 0x33)
#define  GPIOD      ((GPIO_TypeDef*) 0x30)

typedef enum {
	portA = 1,
	portB,
	portC,
	portD
}PORTS;

typedef enum {INPUT=0,OUTPUT}STATE;

typedef enum { ZERO=0,ONE}PIN_STATE;
//prototypes
void DIO_INIT(void); // ddrx input
ERROR_status SETPINDIrection(PORTS PORT,uint8 PIN,STATE state);     //define PIN input or output
ERROR_status setpinvalue(PORTS PORT,uint8 PIN,PIN_STATE  value);          //set or clear specific PIN
ERROR_status getpinvalue(PORTS PORT,uint8 PIN,int * value);
ERROR_status togglepinvalue(PORTS PORT,uint8 PIN);
ERROR_status controlPortValue(PORTS PORT,unsigned char  Value);              
ERROR_status ControlPortDIR(PORTS PORT,STATE Direction);
void ToggleBit(PORTS port,uint8 PIN);




#endif /* INCFILE1_H_ */