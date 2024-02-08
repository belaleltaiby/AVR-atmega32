/*
 * EEPROM_Interface.h
 *
 * Created: 11/4/2023 7:00:02 PM
 *  Author: Belal
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_
#include "Types.h"
#include "Bit_Math.h"

uint8		EEPROM_u8WriteByte(uint16 Add , uint8 Data);

uint8		EEPROM_u8ReadByte(uint16 Add , uint8 * Data);




#endif /* EEPROM_INTERFACE_H_ */