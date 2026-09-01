#include "../include/timer.hpp"

template <uintptr_t BASE> 
void Timer<BASE>::start_timer(void) {
    tim->CR1 |= START;
}

template <uintptr_t BASE> 
void Timer<BASE>::stop_timer(void) {
    tim->CR1 &= STOP;
}

template <uintptr_t BASE> 
void Timer<BASE>::enable_dma(void) {
    tim->DIER |= (1 << 8);
}
