// Includes
#include <stdint.h>
#include <stm32f446xx.h>
#include <stdio.h>
#include "main.h"
#include "gpio.h"
#include "usart.h"
#include "dma.h"
#include "math.h"

// Global variables
uint8_t table0[TABLE0_SIZE] = {  0,  1,  2,  3,  4,  5,  6,  7,  8,  9};
uint8_t table1[TABLE0_SIZE] = { 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
uint16_t sinusTable[BUFFER_SIZE_SINUS] = { 0 };

// Private functions
int __io_putchar(int ch)
{
	while(((USART2->SR)&= (1<<7))==0);
	USART2->DR = ch;
}

void init_sinus_table(void)
{
    for  (uint32_t i = 0; i < BUFFER_SIZE_SINUS; i++)
    {
        sinusTable[i] = OFFSET + (AMPLITUDE * sin((2 * PI * i) / AUDIOFREQ_16K));
    }
}

// Main
int main(void)
{
	// Initialize peripherals
	GPIO_Init();
	USART2_Init();
	DMA_bis_Init();

    __HAL_RCC_DAC_CLK_ENABLE();
	DAC1->CR |= DAC_CR_MAMP1_3 | DAC_CR_MAMP1_1 | DAC_CR_MAMP1_0;
	DAC1->CR |= DAC_CR_DMAEN1;
	DAC1->CR |= DAC_CR_EN1;

	init_sinus_table();

	// Infinite loop
	while(1)
	{

	}
}

// End of file
