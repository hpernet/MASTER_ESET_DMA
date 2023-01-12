// Include
#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"

// Define
#define TABLE0_SIZE    10

// Global variables
uint8_t table0[TABLE0_SIZE] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

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

	// Infinite loop
	while(1)
	{
		// Nothing to do
	}
}

// Exported function
void button_is_pressed(void)
{
	// Variable declaration
	uint8_t index = 0U;

	for(index = 0; index < TABLE0_SIZE; index++)
	{
		while(((USART2->SR)&= (1<<7))==0);
		USART2->DR = table0[index];
	}
}

// End of file
