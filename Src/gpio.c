#include "../Inc/gpio.h"
#include <stdint.h>

#define DELAY 100000

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
	uint8_t bp;
};

static GPIODevice GPIOA_INST = {
		.addr = GPIOA_REG,
		.initFunc = GPIOA_INIT,
		.bp = 0
};

static GPIODevice GPIOB_INST = {
		.addr = GPIOB_REG,
		.initFunc = GPIOB_INIT,
		.bp = 0
};

static GPIODevice GPIOC_INST = {
		.addr = GPIOC_REG,
		.initFunc = GPIOC_INIT,
		.bp = 0
};


GPIODevice* const GPIOA = &GPIOA_INST;
GPIODevice* const GPIOB = &GPIOB_INST;
GPIODevice* const GPIOC = &GPIOC_INST;

void GPIOA_INIT(void) {
	GPIOA->addr->MODER &= ~(3 << (5 * 2));
	GPIOA->addr->MODER |= (1 << (5 * 2));

	GPIOA->addr->MODER &= ~(3 << (2 * 2));
	GPIOA->addr->MODER &= ~(3 << (3 * 2));

	GPIOA->addr->MODER |= (2 << (2 * 2));
	GPIOA->addr->MODER |= (2 << (3 * 2));

	GPIOA->addr->AFRL &= ~(0xF << (2 * 4));
	GPIOA->addr->AFRL &= ~(0xF << (3 * 4));

	GPIOA->addr->AFRL |= (7 << (2 * 4));
	GPIOA->addr->AFRL |= (7 << (3 * 4));
}

void GPIOB_INIT(void) {

	GPIOB->addr->MODER &= ~((3 << 0) | (3 << 2) | (3 << 4) | (3 << 6));
	GPIOB->addr->MODER |=  ((1 << 0) | (1 << 2) | (1 << 4) | (1 << 6));
}

void GPIOC_INIT(void) {
	GPIOC->addr->MODER &= ~(3 << (13 * 2));

	for(int i = 0; i <= 3; i++) {
		GPIOC->addr->MODER &= ~(3 << (i * 2));
		GPIOC->addr->MODER |= (1 << (i * 2));
	}

}

void led_on(void) {
	GPIOA->addr->ODR |= (1 << 5);
}

void led_off(void) {
	GPIOA->addr->ODR &= ~(1 << 5);
}

void set_bp(void) {
	GPIOA->bp = 1;
}

void clear_bp(void) {
	GPIOA->bp = 0;
}

uint8_t get_bp(void) {
	return GPIOA->bp;
}

// LCD Command macros
#define FN4BIT2 0x28 // Function set 4-bit 2 line
#define BOTTOM 0xC0 // Print to bottom line
#define TOP 0x80 // Print to top line

#define DCURSOR_ON 0x0D // Displau on cursor on
#define DCURSOR_OFF 0x0C // Display on cursor off
#define ENTRYNORM 0x06 // Standard entry mode (moves cursor right after each char)
#define CLEAR 0x01 /// Clear display

void delay(uint32_t del) {
	for(volatile uint32_t i = 0; i <= del; i++);
}

void EPulse(void) {
	GPIOB->addr->BSSR |= (1 << 3);
	delay(250);
	GPIOB->addr->BSSR |= (1 << 19);
	delay(250);
}

void sendBits(uint8_t value) {
	GPIOC->addr->ODR &= ~(0x0F);
	GPIOC->addr->ODR |= (value & 0x0F);
	EPulse();
}

void writeLCD(uint8_t byte, uint8_t data) {
	if(data) {
		GPIOB->addr->BSSR |= (1 << 1);
	}
	else {
		GPIOB->addr->BSSR |= (1 << 17);
	}

	sendBits(byte >> 4);
	sendBits(byte & 0x0F);
}

void LCD_Init(void) {
    delay(250);


    GPIOB->addr->BSSR = (1 << 17);
    GPIOB->addr->BSSR = (1 << 18);

    sendBits(0x03);
    delay(250);

    sendBits(0x03);
    delay(250);

    sendBits(0x03);
    delay(250);

    sendBits(0x02);
    delay(250);


    writeLCD(FN4BIT2, 0);
    writeLCD(DCURSOR_ON, 0);
    writeLCD(ENTRYNORM, 0);
    writeLCD(CLEAR, 0);
    delay(250);
}

void printNum(uint8_t num) {
	uint8_t d1 = num % 10;
	uint8_t d2 = num / 10;
	uint8_t d3 = d2 % 10;
	uint8_t d4 = d2 / 10;
	uint8_t d5 = d4 % 10;

	writeLCD(d5 + '0', 1);
	writeLCD(d3 + '0', 1);
	writeLCD(d1 + '0', 1);

}

void printStr(char* buffer) {
	while(*buffer) {
		writeLCD(*buffer,1);
		buffer++;
	}

}

void clearLCD(void) {
	writeLCD(CLEAR,0);
	delay(250);
}

void printTemp(float temp) {
	uint8_t t_int = (uint8_t)temp;
	uint8_t t_frac =  (uint8_t)(100.0f * (temp - (uint8_t)t_int));
	writeLCD(t_int,1);
	writeLCD('.',1);
	writeLCD(t_frac,1);
	delay(250);
}
