// Includes
#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "dma.h"

// Global variables
uint8_t table0[TABLE0_SIZE] = {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9};
uint8_t table1[TABLE0_SIZE] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

// Private functions
int __io_putchar(int ch)
{
	while(((USART2->SR)&= (1<<7))==0);
	USART2->DR = ch;
}

// Main
int main(void)
{
	// Initialize peripherals
	GPIO_Init();
	USART2_Init();
	DMA_Init();

	// Infinite loop
	while(1)
	{
		// Nothing to do
	}
}

// End of file
