
#pragma once

#include "rcc.h"
#include "exti.h"
#include "timer.h"
#include "i2c.h"

typedef struct {
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
} USART_Typedef;

#define BIT(x) (1UL << (x))
#define BITSET(REG,BIT_NUM) ((REG) |= BIT(BIT_NUM))

#define USART2 ((USART_Typedef *)0x40004400)
#define BUFF_SIZE 32

char buffer[BUFF_SIZE];

char get_char(void) {
	while(!(USART2->SR & (1 << 5)));
	char c = USART2->DR;
	return c;
}

void send_char(char c) {
	while(!(USART2->SR & (1 << 7)));
	USART2->DR = c;
}

void send_str(volatile char * buffer) {
	while(*buffer) {
		send_char(*buffer);
		buffer++;
	}
}

