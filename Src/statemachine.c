#include "../Inc/statemachine.h"
#include "../Inc/gpio.h"
#include <stdint.h>

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
	if(get_bp()) {
		clear_bp();
		return BTN_PRESS;
	}

	//if(count == 1) {
	//	ticks++;
	//	count = 0;
	//	if(ticks >= 60) {
	//		return EVENT_LOG;
	//	}
	//}

	return EVENT_NULL;
}
