/*
 * Bit_Math.h
 *
 * Created: 10/20/2023 2:27:07 PM
 *  Author: Belal
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define setBit(byte,nbit)        byte |= (1<<nbit)
#define clearBit(byte,nbit)      byte &= ~(1<<nbit)
#define toggleBit(byte,nbit)     byte ^= (1<<nbit)
#define getbit(byte,nbit)         ((byte>>nbit) & 0x01) 


#define SET_BIT(VAR, BIT_NO) (VAR |= (1 << BIT_NO))
#define CLR_BIT(VAR, BIT_NO) (VAR &= ~(1 << BIT_NO))
#define TOG_BIT(VAR, BIT_NO) (VAR ^= (1 << BIT_NO))
#define GET_BIT(VAR, BIT_NO) ((VAR >> BIT_NO) & 1)

#endif /* BIT_MATH_H_ */