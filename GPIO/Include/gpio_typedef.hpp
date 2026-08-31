#include <cstdint>

#ifndef GPIO_TYPEDEF_HPP
#define GPIO_TYPEDEF_HPP

struct GPIO_Typedef {
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR_A;
    volatile uint32_t PUPDR_B;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;
    volatile uint32_t BSRR;
    volatile uint32_t LCKR;
    volatile uint32_t AFRL;
    volatile uint32_t AFRH;
};

enum MODER : uint8_t {
    INPUT = 0b00,
    OUTPUT = 0b01,
    ALTERNATE = 0b10,
    ANALOG = 0b11

};

#define GPIOA 0x40020200
#define GPIOB 0X40020400
#define GPIOC 0X40020800

#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2
#define SYSCFGEN 14
#define BTTN_PIN ~(3 << (13 * 2))

#endif 
