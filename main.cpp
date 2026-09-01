#include <cstdint>
#include <cstdlib>
#include "GPIO/Include/leds.hpp"
#include "USART/include/usart.hpp"
#include "syscfg-nvic-rcc/include/exti.hpp"

// Basic state machine using a basic LED and the button on a nucleof446re  

static LEDS<GPIOA,GPIOC> led;
static USART<USART2> usart;
static Timer<TIM2> timer(1024,15624,0);

volatile uint8_t bp{0};
volatile uint32_t count{0};
volatile uint8_t ticks{0};
volatile char buff[32];

// LED State 
enum State {
    STATE_ON,
    STATE_OFF,
    STATE_TOGGLE
};

enum Event {
    EVENT_PRESS, 
    EVENT_LOG,
    EVENT_NULL
};

State current_state = STATE_OFF;

Event check_event(void) {
    if(bp) {
        bp = 0;
        return EVENT_PRESS;
    }

    if(count == 1) {
        ticks++;
        count = 0;
        if(ticks >= 60) {
            return EVENT_LOG;
        }
    }

    return EVENT_NULL

}

void update_statemachine(Event event) {
    if(event == EVENT_NULL) {return;}

    if(event == EVENT_LOG) {
        usart.send_str("Uptime: ");
        itoa(ticks,buff,10);
        send_str(buff);
        ticks = 0;
    }

    switch (current_state) {
        case STATE_OFF:
            if(event == EVENT_PRESS) {
                usart.send_str("LED is on");
                led.led_on(5);
                current_state = STATE_ON;
            }
        break;

        case STATE_ON:
            if(event == EVENT_PRESS) {
                usart.send_str("LED is off");
                led.led_off(5); 
                current_state = STATE_OFF;
            }
        break;
    }
}

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
    usart.USART_init();
    led.button_init(0);

    while(1) {
        Event event = check_event();
        update_statemachine(event);

    }
};
