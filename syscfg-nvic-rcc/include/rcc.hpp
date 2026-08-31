#include <stdint.h>

#ifndef RCC_HPP
#define RCC_HPP

struct RCC_Typedef {
    volatile uint32_t r0[12];
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t r;
    volatile uint32_t APB1ENR;
    volatile uint32_t APB2ENR;
}; 

#define RCC ((RCC_Typedef *)0x40023800)
#define USART1EN 4
#define GPIOAEN 0
#define GPIOCEN 2

#endif 