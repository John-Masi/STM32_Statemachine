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

void GPIOA_INIT(void);
void GPIOB_INIT(void);
void GPIOC_INIT(void);
void led_on(void);
void led_off(void);
void clear_bp(void);
void set_bp(void);
uint8_t get_bp(void);

#endif
