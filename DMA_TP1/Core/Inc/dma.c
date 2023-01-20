/*
 * dma.c
 *
 *  Created on: 20 janv. 2023
 *      Author: hugop
 */

void DMA_Init(void)
{
	RCC->AHB1ENR = RCC_AHB1ENR_DMA1EN;             // Activate the clock
    DMA1_Stream6->CR  &= ~(DMA_SxCR_EN);           // deactivate DMA stream for configuration
    DMA1_Stream6->CR  &= ~(DMA_SxCR_CHSEL);        // clear bits
    DMA1_Stream6->CR  |=  (DMA_SxCR_CHSEL_2);      // 100 = channel 4
    DMA1_Stream6->CR  &= ~(DMA_SxCR_PL);           // priority 00 = low
    DMA1_Stream6->CR  &= ~(DMA_SxCR_PSIZE);        // size 00 = 8bit
    DMA1_Stream6->CR  |=  (DMA_SxCR_MINC);         // increment memory pointer with each DMA transfer
    DMA1_Stream6->CR  &= ~(DMA_SxCR_DIR);          // clear bits
    DMA1_Stream6->CR  |=  (DMA_SxCR_DIR_0);        // 01 = memory-to-peripheral
    DMA1_Stream6->CR  |=  (DMA_SxCR_TCIE);
    DMA1_Stream6->PAR  =  &USART2->DR;             // peripheral memory address
    DMA1_Stream6->M0AR =  table0;                  // data memory address
    DMA1_Stream6->NDTR = ( uint16_t ) TABLE0_SIZE; // number of bytes to transfer
	HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);         // Activate DMA interrupt line in NVIC
	HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 1, 1);
}


// End of file
