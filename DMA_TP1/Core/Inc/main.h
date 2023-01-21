
#ifndef MAIN_H_
#define MAIN_H_

// Includes -------------------------------------------------------------------------------------------------
#include "stm32f4xx_hal.h"

// Defines --------------------------------------------------------------------------------------------------
#define INPUT_MODE 	0
#define OUTPUT_MODE	1
#define ALT_MODE 	2
#define ANALOG_MODE	3

#define BITMASK_1BITS	0b1
#define BITMASK_2BITS	0b11
#define BITMASK_3BITS	0b111
#define BITMASK_4BITS	0b1111
#define BITMASK_5BITS	0b11111

#define TABLE0_SIZE    10

#define BUFFER_SIZE_SINUS 	            16000
#define AUDIOFREQ_16K 		            ((uint32_t)16000U)  //AUDIOFREQ_16K = 16 Khz
#define AMPLITUDE			            350
#define OFFSET                          400
#define PI					            3.141592


#endif
// End of file
