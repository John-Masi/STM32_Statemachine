#include <cstdint>
#include "exti.hpp"
#include "syscfg.hpp"

#ifndef NVIC_HPP
#define NVIC_HPP

struct NVIC_Typedef {
    volatile uint32_t ISER0[7];
};

#define NVIC ((NVIC_Typedef *)0xE000E100)

void irq_init(void) {
    SYSCFG->EXTICR4 |= (1 << 4);
    EXTI->IMR |= (1 << 13);
    EXTI->FTSR |= (1 << 13);

    NVIC->ISER0[1] |= (1 << 8);
}

#endif 