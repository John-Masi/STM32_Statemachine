#include <cstdint> 

#ifndef EXTI_HPP
#define EXTI_HPP

struct EXTI_Typedef {
    volatile uint32_t IMR;
    volatile uint32_t EMR;
    volatile uint32_t RSTR;
    volatile uint32_t FTSR;
    volatile uint32_t SWIER;
    volatile uint32_t PR;
};

#define EXTI ((EXTI_Typedef *)0x40013C00)


#endif 