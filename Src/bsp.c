#include "../Inc/bsp.h"
#include <stdint.h>


void init_bsp(void) {
	RCC->AHB1ENR |= (1 << 0);
	GPIOA_INIT();
	GPIOC_INIT();
}

