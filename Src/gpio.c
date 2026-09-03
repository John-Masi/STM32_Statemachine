#include "../Inc/gpio.h"
#include "../Inc/exti.h"
#include "../Inc/rcc.h"


typedef struct {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSSR;
    volatile uint32_t r0;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
} GPIO_Typedef;

typedef void (*EnableClock)(void);
typedef void (*GPIO_Init)(void);

#define GPIOA_REG ((GPIO_Typedef*)0x40020000)
#define GPIOB_REG ((GPIO_Typedef*)0x40020400)
#define GPIOC_REG ((GPIO_Typedef*)0x40020800)

struct GPIODevice {
	GPIO_Typedef* addr;
	GPIO_Init initFunc;
};

static GPIODevice GPIOA_INST = {
		.addr = GPIOA_REG,
		.initFunc = GPIOA_INIT,
};

static GPIODevice GPIOB_INST = {
		.addr = GPIOB_REG,
		.initFunc = GPIOB_INIT,
};

static GPIODevice GPIOC_INST = {
		.addr = GPIOC_REG,
		.initFunc = GPIOC_INIT,
};


GPIODevice* const GPIOA = &GPIOA_INST;
GPIODevice* const GPIOB = &GPIOB_INST;
GPIODevice* const GPIOC = &GPIOC_INST;

void GPIOA_INIT(void) {
	GPIOA->addr->MODER &= ~(3 << (5 * 2));
	GPIOA->addr->MODER |= (1 << (5 * 2));
}

void GPIOB_INIT(void) {when
	return;
}

void GPIOC_INIT(void) {
	RCC->AHB1ENR |= (1 << 2);
	RCC->APB2ENR |= (1 << 14);

	GPIOC->addr->MODER &= ~(3 << (13 * 2));

	SYSCFG->EXTICR4 |= (0b0010 << 4);

	EXTI->IMR |= (1 << 13);
	EXTI->FSTR |= (1 << 13);

	NVIC->ISER0[1] |= (1 << 8);
}

void led_on(void) {
	GPIOA->addr->ODR |= (1 << 5);
}

void led_off(void) {
	GPIOA->addr->ODR &= ~(1 << 5);
}




