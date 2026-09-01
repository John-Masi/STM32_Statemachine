#include <cstdint>
#include "exti.hpp"
#include "syscfg.hpp"

#ifndef NVIC_HPP
#define NVIC_HPP

struct NVIC_Typedef {
    volatile uint32_t ISER0[7];
};

#define NVIC ((NVIC_Typedef *)0xE000E100)

#endif 
