// Include
#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "dma.h"

// Global variables
uint8_t table0[TABLE0_SIZE] = "HELLO";

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
