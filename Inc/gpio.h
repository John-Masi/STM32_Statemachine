#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

typedef struct GPIODevice GPIODevice;

extern GPIODevice* const GPIOA;
extern GPIODevice* const GPIOB;
extern GPIODevice* const GPIOC;

#define BIT(x) (1UL << (x))
#define BITSET(REG,BIT_NUM) ((REG) |= BIT(BIT_NUM))

#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2

// GPIO Funcs
void GPIOA_INIT(void);
void GPIOB_INIT(void);
void GPIOC_INIT(void);
void GPIOC_AFR(void);
void led_on(void);
void led_off(void);
void clear_bp(void);
void set_bp(void);
uint8_t get_bp(void);


// LCD Funcs
void delay(void);
void EPulse(void);
void sendBits(uint8_t value);
void writeLCD(uint8_t byte,uint8_t data);
void LCD_Init(void);
void printNum(uint8_t num);
void printStr(char* buffer);
void clearLCD(void);

#endif
