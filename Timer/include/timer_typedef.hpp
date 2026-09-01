#include <cstdint>

#ifndef TIMER_TYPEDEF_HPP
#define TIMER_TYPEDEF_HPP

struct TIM_TypeDef {
    volatile uint32_t CR1;
	volatile uint32_t r[2];
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t CCRM1;
	volatile uint32_t CCRM2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
};

#define TIM2 0x40000000 
#define NVIC_TIM2 28
#define START (1 << 0)
#define STOP (~(1 << 0))

#endif
