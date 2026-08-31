#include <cstdint>

#ifndef USART_TYPEDEF_HPP
#define USART_TYPEDEF_HPP

struct USART_Typedef {
    volatile uint32_t SR;
    volatile uint32_t DR;
    volatile uint32_t BRR;
    volatile uint32_t CR1;
};

#define USART2 0x4004400
#define USART2EN 17

// CR1 Register macros
#define RE 2
#define TE 3
#define M 12
#define UE 13


#endif 