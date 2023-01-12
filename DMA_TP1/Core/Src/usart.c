#include <stdint.h>
#include <stm32f446xx.h>
#include "main.h"
#include "usart.h"


void USART2_Init(void){
	/* USART2 Init */
	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;			// ABP1
	GPIOA->MODER |= ALT_MODE<<4;					// PA2
	GPIOA->MODER |= ALT_MODE<<6;					// PA3
	GPIOA->AFR[0] |= 7<<8;							// USART2
	GPIOA->AFR[0] |= 7<<12;							// USART2
	USART2->BRR  = 139;								// 115200 - APB1:16Mhz
	USART2->CR1 |= USART_CR1_TE | USART_CR1_RE;		// RX-TX
	USART2->CR1 |= USART_CR1_UE;
}


void USART2_TransmitChar(uint8_t data){
	USART2->DR = data;
	while( (USART2->SR & USART_SR_TXE)==0 );
}


uint8_t USART2_ReceiveChar(void){
	while( (USART2->SR & USART_SR_RXNE)==0 );
	return USART2->DR;

}
