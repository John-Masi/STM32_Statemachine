#include "Statemachine/Include/statemachine.hpp"

extern "C" void EXTI15_10_IRQHandler(void) {
    bp = 1;
    EXTI->PR |= (1 << 13);
}

extern "C" void TIM2_IRQHandler(void) {
    if(timer.timer->CR1 & (1 << 0)) {
        timer.timer->CR1 &= ~(1 << 0);
        count++;
    }
}

int main(void) {
    Statemachine state_machine;
    state_machine.start_machine();
};
