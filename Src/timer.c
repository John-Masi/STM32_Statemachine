#include "../Inc/timer.h"
#include "../Inc/exti.h"

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

#define TIM2ADDR ((TIM_Typedef*)0x40000000)

struct TIMDevice {
	TIM_Typedef* addr;
	uint32_t count;
};

static TIMDevice TIM2_Inst = {
		.addr = TIM2ADDR,
		.count = 0
};

TIMDevice* const TIM2 = &TIM2_Inst;

void start_tim(void) {
	TIM2->addr->CR1 |= (1 << 0);
}

void stop_tim(void) {
	TIM2->addr->CR1 &= ~(1 << 0);
}

void tim_init(void) {
	TIM2->addr->ARR = 15623;
	TIM2->addr->PSC = 1023;
	TIM2->addr->DIER |= (1 << 0);
	NVIC->ISER0[0] |= (1 << 28);

	TIM2->addr->CR1 |= (1 << 0);
}

void TIM2IRQ(void) {
	if(TIM2->addr->CR1 & (1 << 0)) {
		TIM2->addr->CR1 &= ~(1 << 0);
		TIM2->count++;
	}
}

uint32_t get_count(void) {
	return TIM2->count;
}

void update_count(uint32_t val) {
	TIM2->count = val;
}

void TIM2_IRQHandler(void) {
	if(TIM2->addr->SR & (1 << 0)) {
		TIM2->addr->SR &= ~(1 << 0);
		TIM2->count++;
	}
}
