#include "../Inc/bsp.h"

/*void tim2_init(void) {
	RCC->APB1ENR |= (1 << 0);
	TIM2->addr->ARR = 15624;
	TIM2->addr->PSC = 1024;
	TIM2->addr->DIER |= (1 << 0);
	NVIC->ISER0[0] = (1 << 28);
} */

void init_bsp(void) {
	RCC->AHB1ENR |= (1 << 0);
	GPIOA_INIT();
	GPIOC_INIT();
	//tim2_init();
}

