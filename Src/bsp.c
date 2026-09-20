#include "../Inc/bsp.h"
#include <stdint.h>

#define LCD_ON 0

void EXTI15_10_INIT(void) {
	SYSCFG->EXTICR4 |= (0b0010 << 4);

	EXTI->IMR |= (1 << 13);
	EXTI->FSTR |= (1 << 13);

	NVIC->ISER0[1] |= (1 << 8);
}

void EXTI15_10_IRQHandler(void) {
	set_bp();
	EXTI->PR |= (1 << 13);
}


void CLOCK_EN(void) {
	RCC->AHB1ENR |= (1 << 0);
	RCC->AHB1ENR |= (1 << 1);
	RCC->AHB1ENR |= (1 << 2);
	RCC->APB1ENR |= (1 << 0);
	RCC->APB2ENR |= (1 << 14);
	RCC->APB1ENR |= (1 << 17);
}

void init_bsp(void) {
	CLOCK_EN();
	GPIOA_INIT();
	GPIOB_INIT();
	GPIOC_INIT();
	USART2_INIT();
	tim_init();
	EXTI15_10_INIT();
	#if LCD_ON
		LCD_Init();
	#endif

}

