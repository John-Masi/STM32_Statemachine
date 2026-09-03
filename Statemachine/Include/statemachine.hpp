#include <cstdlib>
#include "state_event.hpp"
#include "GPIO/Include/leds.hpp"
#include "USART/include/usart.hpp"
#include "Timer/include/timer.hpp"
#include "syscfg-nvic-rcc/include/exti.hpp"

#ifndef STATEMACHINE_HPP
#define STATEMACHINE_HPP

volatile uint8_t bp{0};
volatile uint32_t count{0};
volatile uint8_t ticks{0};
volatile char buff[32];

State current_state = STATE_OFF;

class Statemachine {
    public:
        Statemachine() = default;

        void update_statemachine(Event event);
        Event get_event(void);

        void start_machine(void) {
            while(1) {
                Event event = get_event();
                update_statemachine(event);
            }
        }

    private:
        State current_state = STATE_OFF;

        static LEDS<GPIOA,GPIOC> led;
        static USART<USART2> usart;
        static Timer<TIM2> timer(1024,15624,0);

};

#endif 
