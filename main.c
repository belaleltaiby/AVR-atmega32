/*
 * GccApplication2.c
 *
 * Created: 10/20/2023 2:14:10 PM
 * Author : Belal
 */ 

#include "DIO.h"
# define F_CPU 8000000  
#include "seven_seg.h"
#include "DIO_private.h"
#include "kEYPAD.h"
#include "lcd2.h"
#include "ADC.h"
#include "Timer0.h"
#include "Digital_clock.h"
#include "EXTI_Interface.h"
#include "avr/delay.h"
#include "UART_INTERFACE.h"
#include <stdlib.h>

void Send_routine();
///global var
uint8 security_flag=0;

int main()
{
	USART_Init();
	
	while(1)
	{
		char data = USART_Receive();
		
		USART_Transmit(data);
		
	}
	
}

// int main()
// {
// 	USART_Init();
// 	LCD_Init();
// 	char add_ID;
// 	unsigned char *Transmit_data;
// 	unsigned char *receivedData =&add_ID ;
// 	unsigned char *ch_Encrypted_num;
// 	int rand_num;
// 	char *encryptedNUM_to_str;
// 	char *Received_encryptedNUM;
// 	//int div=1000;
// 	int flag =0;
// 	int _2701_flag=0;
// 	
// 	while (1)
// 	{
// 		while (*receivedData != 13)
// 		{
// 			*receivedData = USART_Receive();
// 			receivedData++;
// 		}
// 		*receivedData ='\0';
// 		receivedData= &add_ID;
// 		if (strcmp(receivedData,"2701") == 0)
// 		{
// 			_2701_flag =1;
// 			security_flag =1;
// 			rand_num = rand();
// 			Transmit_data = "6701";
// 			while(*Transmit_data != '\0')
// 			{
// 			 	USART_Transmit(*Transmit_data);
// 			 	LCD_SendChar(*Transmit_data);
// 				Transmit_data++;
// 			}
// 			Transmit_data=&add_ID;
// 			LCD_writeNumber(rand_num);	
// 		}
// 		
// 		if ((receivedData == "2702") && (_2701_flag ==1))
// 		{
// 			int encrypted_num = rand_num ^ 35 ;
// 			Transmit_data = "6702";
// 			//receivedData=0;
// 			//receive the encrypted rand number
// 			while (*receivedData != 13)
// 			{
// 				*receivedData = USART_Receive();
// 				receivedData++;
// 			}
// 			receivedData = &add_ID;
// 			sprintf(encryptedNUM_to_str, "%d", encrypted_num);
// 			//MCU will reply if the encrypted num is equal to the number i entered
// 			for (int i=0;i<4;i++)
// 			{
// 			 	if(*receivedData == *encryptedNUM_to_str ){receivedData++;encryptedNUM_to_str++; continue;}
// 			 	flag =1;
// 			 	USART_Transmit(' ');
// 			}
// 			receivedData = &add_ID;
// 			
// 			if (flag==1)
// 			{
// 			 	for (int j=0;j<4;j++){USART_Transmit(Transmit_data[j]);}
// 			 	for (int j=0;j<4;j++){LCD_SendChar(Transmit_data[j]);}
// 			 }
// 			
// 		}
// 	}
// }


/////////////////////////////////////////////////////
// unsigned char Transmit_data[4];
// unsigned char receivedData[4];
// unsigned char ch_Encrypted_num[4];
// unsigned char rand_num[4];
// char encryptedNUM_to_str[20];
// char Received_encryptedNUM[20];
// //int div=1000;
// int flag =0;
// void MCU_Receive_Command(uint8 *receivedcommand );
// void GenerateRandomNumber(uint8* Random4Bytes);
// int random_num;
// 
// 
// 
// int main() {
// 	USART_Init();
// 	LCD_Init();
// 	
// 	//USART_Transmit('A');
// 	while (1)
// 	{
// 		
// 		
// 		Send_routine();
// 		//MCU receive the first command
// 		MCU_Receive_Command(receivedData);
// 		//check if the received command is 2701
// 		if ((receivedData[0] == '2') && (receivedData[1] == '7') && (receivedData[2] == '0') && (receivedData[3] == '1') )
// 		{
// 			security_flag =1;
// 			Transmit_data[0] = '6';
// 			Transmit_data[1] = '7';
// 			Transmit_data[2] = '0';
// 			Transmit_data[3] = '1';
// 			
// 			random_num=rand();
// 			//MCU send 6701 to LCD with rand_num
// 			LCD_Clear();
// 			for (int j=0;j<4;j++)
// 			{
// 				USART_Transmit(Transmit_data[j]);
// 				LCD_SendChar(Transmit_data[j]);
// 			}
// 			USART_Transmit(' ');
// 			LCD_writeNumber(random_num);
// 
// 		}//the 1st if
// 		
// 		//MCU receive the next command
// 
// 		MCU_Receive_Command(receivedData);
// 		
// 		if ((receivedData[0] == '2') && (receivedData[1] == '7') && (receivedData[2] == '0') && (receivedData[3] == '2') )
// 		{
// 			//if the command is 2702 then receive the encrypted rand_num
// 			
// 			MCU_Receive_Command(Received_encryptedNUM);
// 			
// 			int rec_encrypted_num = atoi(Received_encryptedNUM);
// 			Transmit_data[0] = '6';
// 			Transmit_data[1] = '7';
// 			Transmit_data[2] = '0';
// 			Transmit_data[3] = '2';
// 			LCD_Clear();
// 		
// 			//MCU reply me with 6702 if the number is equal to encrypted rand_num
// 			if (rec_encrypted_num != random_num)
// 			{
// 				flag =1;
// 				
// 				}else{USART_Transmit('E');}
// 				
// 				
// 				if (flag==1)
// 				{
// 					for (int j=0;j<4;j++){USART_Transmit(Transmit_data[j]);}
// 					for (int j=0;j<4;j++){LCD_SendChar(Transmit_data[j]);}
// 				}
// 				Send_routine();
// 			}//the second if
// 			
// 		}
// 
// 		return 0;
// 	}
// 
// 	void GenerateRandomNumber(uint8* Random4Bytes)
// 	{
// 		for(int i=0;i<4;i++)
// 		{
// 			Random4Bytes[i]= (rand() % 10 + 1); // use rand() function to get the random number
// 		}
// 	}
// 	void EncryptRandomNumber(uint8* Random4Bytes,uint8* EncryptedRandom4Bytes)
// 	{
// 		for(int i=0;i<4;i++)
// 		{
// 			EncryptedRandom4Bytes[i]= Random4Bytes[i]; // This was left as direct assignment just to make it easy during testing
// 			
// 		}
// 	}
// 	void MCU_Receive_Command(uint8 *receivedcommand)
// 	{
// 		for (int i=0;i<4;i++)
// 		{
// 			receivedcommand[i] = USART_Receive();
// 		}
// 	}
// 
// 	void Send_routine()
// 	{
// 		unsigned char received_routine[8];
// 		unsigned char reply_on_routine[6];
// 		//MCU receive the routine
// 		for (int i=0;i<8;i++)
// 		{
// 			received_routine[i] = USART_Receive();
// 		}
// 		if ((received_routine[0] == '3') && (received_routine[1] == '1') && (received_routine[2] == '0') &&
// 		(received_routine[3] == '1') && (received_routine[4] == 'A') && (received_routine[5] == 'A') && (received_routine[6] == '0')
// 		&& (received_routine[7] == '0') )
// 		{
// 			if (security_flag == 1)
// 			{
// 				received_routine[0]='7';
// 				received_routine[1]='1';
// 				received_routine[2]='0';
// 				received_routine[3]='1';
// 				received_routine[4]='A';
// 				received_routine[5]='A';
// 				received_routine[6]='0';
// 				received_routine[7]='0';
// 				
// 				LCD_Clear();
// 				for (int j=0;j<8;j++)
// 				{
// 					USART_Transmit(received_routine[j]);
// 					LCD_SendChar(received_routine[j]);
// 				}
// 				
// 				DIO_INIT();
// 				SETPINDIrection(portA,PIN0,OUTPUT);
// 				setpinvalue(portA,PIN0,HIGH);
// 				}else{
// 				received_routine[0]='7';
// 				received_routine[1]='F';
// 				received_routine[2]='3';
// 				received_routine[3]='1';
// 				received_routine[4]='3';
// 				received_routine[5]='3';
// 				LCD_Clear();
// 				for (int j=0;j<6;j++)
// 				{
// 					USART_Transmit(received_routine[j]);
// 					LCD_SendChar(received_routine[j]);
// 				}
// 			}
// 		}
// 








///////////////////////////////////Digital clock/////////////////
/*
 uint8 minutes=1;
 uint8 hours =2;
 uint8 flag1=0;
 uint8 flag2=0;
 uint8 count=1;
void TIM0_OV_FuncToISR();
void Push_button_blink();
void Push_button_setClock();
 
 
int main()
{
	DIO_INIT();
	
	//GIE_voidEnable();
	Enable_Ginterrupt;
	ControlPortDIR(portB,OUTPUT);
	
	TIMER0_init();
	TIMER0_start();
	TIMER0_voidSetCallBackInterrupt(TIM0_OV_FuncToISR);
	
	EXTI_u8INT0Init(INT0_RISING_EDGE);
	EXTI_u8INT1Init(INT1_RISING_EDGE);
 	EXTI_voidSetCallBackINT0(Push_button_blink);
	EXTI_u8SetCallBackINT1(Push_button_setClock);

	Enable_digit(digit1);
	Set_number(digit1,5);

	while(1)
	{

		Set_all_Digits(minutes%10,minutes/10,hours%10,hours/10);
	}
	
}

void TIM0_OV_FuncToISR()
{
	setpinvalue(portB,PIN7,HIGH);
	if(minutes < 59)
	{
		minutes ++;
	}
	else if(hours < 23)
	{
		minutes = 0;
		hours++;
	}
	else
	{
		hours = 0;
		minutes = 0;
	}
}


void Push_button_blink()
{
	setpinvalue(portB,PIN7,HIGH);
	if(count == 1)
	{
		flag1 = 1;
		flag2 = 0;
		count = 2;
	}else if(count==2)
	{
		flag1 = 0;
		flag2 = 1;
		count = 3;
	}else if(count==3)
	{
		flag1 = 0;
		flag2 = 0;
		count = 1;
	}
}

void Push_button_setClock()
{
	if(flag1 && (hours < 23) )
	{
		hours++;
	}else if(flag1 && (hours >= 23))
	{
		hours = 0;
	}else if(flag2 && (minutes < 59))
	{
		minutes++;
	}else if(flag2 && (minutes >= 59))
	{
		minutes = 0;
	}
}
*/