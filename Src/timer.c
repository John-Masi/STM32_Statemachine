#include "../Inc/timer.h"

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
};

static TIMDevice TIM2_Inst = {
		.addr = TIM2ADDR
};

TIMDevice* const TIM2 = &TIM2_Inst;

void start_tim(void) {
	TIM2->addr->CR1 |= (1 << 0);
}

void stop_tim(void) {
	TIM2->addr->CR1 &= ~(1 << 0);
}

void tim_init(void) {
	TIM2->addr->ARR = 15624;
	TIM2->addr->PSC = 1024;
	TIM2->addr->DIER |= (1 << 0);
}

void TIMIRQ(uint32_t cnt) {
	if(TIM2->addr->CR1 & (1 << 0)) {
		TIM2->addr->CR1 &= ~(1 << 0);
		cnt++;
	}
}

