#include "../Inc/usart.h"

#include <stdint.h>

typedef struct {
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
} USART_Typedef;

#define USART2_ADDR ((USART_Typedef *)0x40004400)

struct USARTDevice {
	USART_Typedef* addr;
};

static USARTDevice USART2_INST = {
		.addr = USART2_ADDR
};

USARTDevice* const USART2 = &USART2_INST;

char get_char(void) {
	while(!(USART2_ADDR->SR & (1 << 5)));
	char c = USART2_ADDR->DR;
	return c;
}

void send_char(char c) {
	while(!(USART2_ADDR->SR & (1 << 7)));
	USART2_ADDR->DR = c;
}

void send_str(char* buffer) {
	while(*buffer) {
		send_char(*buffer);
		buffer++;
	}
}

void USART2_INIT(void) {
	USART2_ADDR->BRR = 0x008B;
	USART2_ADDR->CR1 = (1 << 2);
	USART2_ADDR->CR1 = (1 << 3);
	USART2_ADDR->CR1 = (1 << 13);
}
