#include <cstdint> 

#ifndef SYSCFG_HPP
#define SYSCFG_HPP 

struct SYSCFG_Typedef {
    volatile uint32_t r[5];
    volatile uint32_t EXTICR4;
};

#define SYSCFG ((SYSCFG_Typedef *)0x40013800)


#endif 