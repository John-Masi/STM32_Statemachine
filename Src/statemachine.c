#include "../Inc/statemachine.h"
//#include "../Inc/usart.h"
#include "../Inc/gpio.h"
#include "../Inc/exti.h"

volatile uint8_t bp = 0;
volatile uint32_t count = 0;
volatile uint32_t ticks = 0;

void EXTI15_10_IRQHandler(void) {
	bp = 1;
	EXTI->PR |= (1 << 13);
}

struct Statemachine {
	enum State current_state;
};

static Statemachine int_machine = {
		.current_state = STATE_OFF,
};


Statemachine* const myMachine = &int_machine;

void update_state(enum Event event,Statemachine* sm) {

	if(event == EVENT_NULL) { return; }

	switch(sm->current_state) {
		case STATE_OFF:
			if(event == BTN_PRESS) {
				led_on();
				sm->current_state = STATE_ON;
			}

			break;

		case STATE_ON:
			if(event == BTN_PRESS) {
				led_off();
				sm->current_state = STATE_OFF;
			}
	}
}

enum Event get_event(void) {
	if(bp) {
		bp = 0;
		return BTN_PRESS;
	}

	return EVENT_NULL;
}
