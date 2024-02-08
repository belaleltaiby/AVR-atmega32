/*
 * UART_INTERFACE.h
 *
 * Created: 10/28/2023 1:01:34 PM
 *  Author: Belal
 */ 


#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_
#include "Types.h"
//configuration structure
typedef struct{
// 	uint8_t  Mode ;                //specifies Tx/Rx   @ref UART_MODE_define
									// must be set // @ref UART_MODE_define
	uint32_t Baudrate;              //@ref BaudRate_define
	uint8_t  Payload_lenght;         //@ref length_define
	uint8_t  stopBits;                 //@ref UART_stopBits_define
	uint8_t  parity;                  //@ref parity_define
	uint8_t  Type;                     //@ref USART_Type
	uint8_t  IRQ_Enable;               //@ref UART_IRQ_define

	void (*P_IRQ_callback)(void);
}UART_config_t;


//@ref USART_Type
#define UART_SELECT                     (uint8_t)(0)
#define USART_SELECT                    (uint8_t)(1<<6)

//@ref parity_define
#define parity_none                   (uint8_t)0
#define parity_even                   (uint8_t)(2<<5)
#define parity_odd                    (uint8_t)(1<<5  | 1<<4)


//@ref UART_stopBits_define
#define UART_stopBits_1               (uint8_t)0
#define UART_stopBits_2               (uint8_t)(1<<3)

//@ref UART_Payload_lenght_define
#define UART_Payload_lenght_8           (uint8_t) (1<<1  | 1<<2)
//#define UART_Payload_lenght_9           (uint8_t) (1<<12)


//@ref BaudRate_define   8M clock
#define BaudRate_2400            207
#define BaudRate_9600            51
#define BaudRate_19200           25
#define BaudRate_57600           8



// @ref UART_MODE_define
#define UART_MODE_Tx                   (uint8_t)(1<<3)            //Bit 3 TE: Transmitter enable
#define UART_MODE_Rx                   (uint8_t)(1<<4)            //Bit 2 RE: Receiver enable




//@ref UART_IRQ_define       //SR reg
#define UART_IRQ_RxC        (uint8_t)(1<<7)  //• Bit 7 – RXCIE: RX Complete Interrupt Enable
#define UART_IRQ_TxC        (uint8_t)(1<<6)  // Bit 6 – TXCIE: TX Complete Interrupt Enable
#define UART_IRQ_DRE         (uint8_t)(1<<5) //• Bit 5 – UDRIE: USART Data Register Empty Interrupt Enable
#define UART_IRQ_NoInterrupt  (uint8_t)0




//@ref Hw_flowCtrl_define
#define Hw_flowCtrl_none              (uint32_t)0
#define Hw_flowCtrl_CTS               (uint32_t)(1<<9)
#define Hw_flowCtrl_RTS               (uint32_t)(1<<8)
#define Hw_flowCtrl_CTS_RTS           (uint32_t)(1<<9 |1<<8)

enum polling_mechanism{enable,disable};

// void UART_INIT(UART_config_t* UART_config);
// void UART_TX(uint8_t data);
// void UART_RX(uint16_t* pRxBuffer);
// // 
void USART_Init() ;
void USART_Transmit(unsigned char data);
unsigned char USART_Receive();
#endif /* UART_INTERFACE_H_ */