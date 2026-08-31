#include <cstdint>

#ifndef DMA_HPP
#define DMA_HPP

// Only adding registers that we are going to currently use 
struct DMA_Typedef {
    volatile uint32_t LISR;
    volatile uint32_t HISR;
    volatile uint32_t LIFCR;
    volatile uint32_t HIFCR;
    volatile uint32_t r[6];
	volatile uint32_t S1CR;
	volatile uint32_t S1NDTR;
	volatile uint32_t S1PAR;
	volatile uint32_t S1M0AR;
	volatile uint32_t S1M1AR;
	volatile uint32_t S1FCR;
};

#define DMA2 0x40026400
#define DMA1 0x40026000

#endif 