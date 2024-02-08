/*
 * Calculator.h
 *
 * Created: 10/25/2023 2:22:32 PM
 *  Author: Belal
 */ 


#ifndef CALCULATOR_H_
#define CALCULATOR_H_

#include "DIO.h"
#include <util/delay.h>

#define Error   13

int get_num(unsigned char);
unsigned char get_func(unsigned char);
void DispError(int);
void disp_num(int);
void calc();


#endif /* CALCULATOR_H_ */