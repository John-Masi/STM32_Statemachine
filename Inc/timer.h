

#pragma once


typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t r[2];
	volatile uint32_t DIER;
	volatile uint32_t SR;
	volatile uint32_t EGR;
	volatile uint32_t CCMR1;
	volatile uint32_t CCMR2;
	volatile uint32_t CCER;
	volatile uint32_t CNT;
	volatile uint32_t PSC;
	volatile uint32_t ARR;
	volatile uint32_t r2;
	volatile uint32_t CCR1;
	volatile uint32_t CCR2;
} TIM_Typedef;


#define TIM2 ((TIM_Typedef*)0x40000000)


void tim_init(void) {
	TIM2->ARR = 15624;
	TIM2->PSC = 1024;
	TIM2->DIER |= (1 << 0);
	NVIC->ISER0[0] = (1 << 28);
}

void start_tim(void) {
	TIM2->CR1 |= (1 << 0);
}

void stop_tim(void) {
	TIM2->CR1 &= ~(1 << 0);
}
