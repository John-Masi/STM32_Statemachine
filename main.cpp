#include <cstdint>
#include "GPIO/Include/leds.hpp"
#include "USART/include/usart.hpp"
#include "syscfg-nvic-rcc/include/exti.hpp"

// Basic state machine using a basic LED and the button on a nucleof446re  

static LEDS<GPIOA,GPIOC> led;
static USART<USART2> usart;

// LED State 
enum LEDState {
    STATE_ON,
    STATE_OFF,
    STATE_TOGGLE
};

enum LEDEvent {
    EVENT_PRESS, 
    EVENT_NULL,
};

LEDState current_state = STATE_OFF;
volatile uint8_t bp{0};

LEDEvent check_event(void) {
    if(bp) {
        bp = 0;
        return EVENT_PRESS;
    }

}

void update_statemachine(LEDEvent event) {
    switch (current_state) {
        case STATE_OFF:
            if(event == LEDEvent::EVENT_PRESS) {
                usart.send_str("LED is on");
                led.led_on(5);
                current_state = STATE_ON;
            }
        break;

        case STATE_ON:
            if(event == LEDEvent::EVENT_PRESS) {
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


int main(void) {
    usart.USART_init();
    led.button_init(0);

    while(1) {
        LEDEvent event = check_event();
        update_statemachine(event);

    }
};
