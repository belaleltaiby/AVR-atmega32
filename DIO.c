/*
 * DIO.c
 *
 * Created: 10/20/2023 2:20:26 PM
 *  Author: Belal
 */ 
#include "DIO.h"
#include "Bit_Math.h"
#include "DIO_private.h"

void DIO_INIT(void)
{
	DDRA = PORT_INPUT;
	DDRB = PORT_INPUT;
	DDRC = PORT_INPUT;
	DDRD = PORT_INPUT;
}

ERROR_status SETPINDIrection(PORTS PORT,uint8 PIN, STATE state)
{
	int loc_variable = OK;
	if(PORT>=portA && PORT <=portD)
	{
		switch(PORT){
			
			case portA:
				switch(state)
				{
					case OUTPUT:
					setBit(DDRA,PIN);
					break;
					case INPUT:
					clearBit(DDRA,PIN);
					break;
					default: loc_variable = NOK; break;
				}
				break;
			case portB:
				switch(state)
				{
					case OUTPUT:
					setBit(DDRB,PIN);
					break;
					case INPUT:
					clearBit(DDRB,PIN);
					break;
					default: loc_variable = NOK; break;
				}
				break;
			case portC:
				switch(state)
				{
					case OUTPUT:
						setBit(DDRC,PIN);
						break;
					case INPUT:
						clearBit(DDRC,PIN);
						break;
					default: loc_variable = NOK;  break;
				}
				break;
			case portD:
				switch(state)
				{
					case OUTPUT:
						setBit(DDRD,PIN);
						break;
					case INPUT:
						clearBit(DDRD,PIN);
						break;
					default: loc_variable = NOK; break;
				}
				break;
			default : loc_variable = NOK;  break;
			}
		}
		else
		{
			loc_variable = NOK;
		}
		return loc_variable;
	}


ERROR_status setpinvalue(PORTS PORT,uint8 PIN,PIN_STATE  value)
{
		int loc_variable = OK;
		if(PORT>=portA && PORT <=portD)
		{
			switch(PORT){
				case portA:
					switch(value)
					{
						case HIGH:
							setBit(PORTA,PIN);
							break;
						case LOW:
							clearBit(PORTA,PIN);
							break;
						default: loc_variable = NOK; break;
					}
					break;
				case portB:
					switch(value)
					{
						case HIGH:
							setBit(PORTB,PIN);
							break;
						case LOW:
							clearBit(PORTB,PIN);
							break;
						default: loc_variable = NOK; break;
					}
					break;
				case portC:
					switch(value)
					{
						case HIGH:
							setBit(PORTC,PIN);
							break;
						case LOW:
							clearBit(PORTC,PIN);
							break;
						default: loc_variable = NOK; break;
					}
					break;
				case portD:
					switch(value)
					{
						case OUTPUT:
							setBit(PORTD,PIN);
							break;
						case INPUT:
							clearBit(PORTD,PIN);
							break;
						default: loc_variable = NOK; break;
					}
					break;
				default : loc_variable = NOK; break;
			}
		}
		else
		{
			loc_variable = NOK;
		}
	return loc_variable;

}


ERROR_status getpinvalue(PORTS PORT,uint8 PIN,int * value)
{
	int loc_variable = OK;
	if(PORT>=portA && PORT <=portD)
	{
		switch(PORT){
			
			case portA:
			*value=getbit(PORTA,PIN);
			break;
			case portB:
			*value=getbit(PORTB,PIN);
			break;
			case portC:
			*value=getbit(PORTC,PIN);
			break;
			case portD:
			*value=getbit(PORTD,PIN);
			break;
			default : loc_variable = NOK; break;
		}
	}else
	{
		loc_variable = NOK;
	}
	return loc_variable;
}

ERROR_status togglepinvalue(PORTS PORT,uint8 PIN)
{
	int loc_variable = OK;
	if(PORT>=portA && PORT <=portD)
	{
		switch(PORT){
						
			case portA:
			toggleBit(PORTA,PIN);
			break;
			case portB:
			toggleBit(PORTB,PIN);
			break;
			case portC:
			toggleBit(PORTC,PIN);
			break;
			case portD:
			toggleBit(PORTD,PIN);
			break;
			default : loc_variable = NOK; break;
			}
		}else
		{
			loc_variable = NOK;
		}
	return loc_variable;
}

ERROR_status ControlPortDIR(PORTS PORT,STATE Direction)
{
	int loc_variable = OK;
	if(PORT>=portA && PORT <=portD)
	{
		switch(PORT){
							
			case portA:
				if (Direction == OUTPUT)
				{
					DDRA = 0xFF;
				}else if (Direction == INPUT)
				{
					DDRA = 0x00;
				}
				break;
			case portB:
				if (Direction == OUTPUT)
				{
					DDRB = 0xFF;
				}else if (Direction == INPUT)
				{
					DDRB = 0x00;
				}
				break;
			case portC:
				if (Direction == OUTPUT)
				{
					DDRC = 0xFF;
				}else if (Direction == INPUT)
				{
					DDRC = 0x00;
				}
				break;
			case portD:
				if (Direction == OUTPUT)
				{
					DDRD = 0xFF;
				}else if (Direction == INPUT)
				{
					DDRD = 0x00;
				}
				break;
			default : loc_variable = NOK; break;
			}
		}else
		{
			loc_variable = NOK;
		}
		return loc_variable;
}
				
				
					
ERROR_status controlPortValue(PORTS PORT,unsigned char  value)
{
	int loc_variable = OK;
	if(PORT>=portA && PORT <=portD)
	{
		switch(PORT){
							
			case portA:
			PORTA = value;
							
			break;
			case portB:
			PORTB = value;
							
			break;
			case portC:
			PORTC = value;
							
			break;
			case portD:
			PORTD = value;
							
			break;
			default : loc_variable = NOK; break;
		}
	}
		else
		{
			loc_variable = NOK;
		}
		return loc_variable;
}

void ToggleBit(PORTS port,uint8 PIN){
	if (port ==portA)
	{
		toggleBit(PORTA,PIN);
    }else if (port ==portB)
	{
		toggleBit(PORTB,PIN);
	}else if (port ==portC)
	{
		toggleBit(PORTC,PIN);
	}else if (port ==portD)
	{
		toggleBit(PORTD,PIN);
	}

}