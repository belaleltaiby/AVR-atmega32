/*
 * I2C_Private.h
 *
 * Created: 11/4/2023 1:37:59 PM
 *  Author: Belal
 */ 


#ifndef I2C_PRIVATE_H_
#define I2C_PRIVATE_H_
#include "Types.h"

#define TWDR         *((volatile uint8*)0x23)
#define TWAR         *((volatile uint8*)0x22)
#define TWSR         *((volatile uint8*)0x21)
#define TWBR         *((volatile uint8*)0x20)
#define TWCR         *((volatile uint8*)0x56)


/* TWCR PINS */

#define TWCR_TWINT               7
#define TWCR_TWEA                6
#define TWCR_TWSTA               5
#define TWCR_TWSTO               4
#define TWCR_TWWC                3
#define TWCR_TWEN                2
#define TWCR_TWIE                0


/* TWSR PINS */
#define TWSR_TWPS1               1
#define TWSR_TWPS0               0



#define I2C_STATUS_CODE_MASK   0xF8
/* Status Codes */
/* Master Transmit */

#define I2C_MT_SC_ACK          0x08
#define I2C_MT_RSC_ACK         0x10
#define I2C_MT_SLA_W_ACK       0x18
#define I2C_MT_DATA_ACK        0x28



/* Master Receive */

#define I2C_MR_SC_ACK          0x08
#define I2C_MR_RSC_ACK         0x10
#define I2C_MR_SLA_R_ACK       0x40
#define I2C_MR_DATA_ACK        0x50





#endif /* I2C_PRIVATE_H_ */