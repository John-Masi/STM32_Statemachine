#include "../Include/statemachine.hpp"


Event Statemachine::get_event(void) {
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

    return EVENT_NULL;
}

void Statemachine::update_statemachine(Event event) {
    if(event == EVENT_NULL) { return; }

    if(event == EVENT_LOG) {

    }

    switch (current_state) {
        case STATE_OFF:
            if(event == EVENT_PRESS) {
                usart.send_str("LED is off");
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