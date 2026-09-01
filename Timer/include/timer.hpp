#include <cstdint>
#include <memory>
#include "timer_typedef.hpp"
#include "../../syscfg-nvic-rcc/include/rcc.hpp"
#include "../../syscfg-nvic-rcc/include/nvic.hpp"

#ifndef TIMER_HPP
#define TIMER_HPP

// Pos defaults to TIM2 APB1ENR index 
template <uintptr_t BASE>
class Timer {
    public:

        Timer(uint8_t p, uint16_t a,uint8_t POS = 0) {
            RCC->APB1ENR |= (1 << POS);
            timer->PSC = p;
            timer->ARR = a;
        };

        void start_timer(void);
        void stop_timer(void);
        //void enable_dma(void); - TODO: Create individual class for a DMA Timer 

    private:
        inline static auto timer = reinterpret_cast<TIM_TypeDef*>(BASE);
};

#endif 
