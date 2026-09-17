#include "../Inc/statemachine.h"
#include <stdint.h>

static uint8_t ticks = 0;

struct Statemachine {
	enum State current_state;
};

static Statemachine int_machine = {
		.current_state = STATE_OFF,
};

Statemachine* const myMachine = &int_machine;

void update_state(enum Event event,Statemachine* sm) {

	if(event == EVENT_NULL) { return; }

	if(event == EVENT_LOG) {
		clearLCD();
		printStr("Timer");
		ticks = 0;
	}

	switch(sm->current_state) {
		case STATE_OFF:
			if(event == BTN_PRESS) {
				led_on();
				clearLCD();
				printStr("LED on");
				sm->current_state = STATE_ON;
			}

			break;

		case STATE_ON:
			if(event == BTN_PRESS) {
				led_off();
				clearLCD();
				printStr("LED off");
				sm->current_state = STATE_OFF;
			}
	}
}

enum Event get_event(void) {
	if(get_bp()) {
		clear_bp();
		return BTN_PRESS;
	}

	if(get_count()) {
		led_on();
		update_count(0);
		ticks++;
		if(ticks >= 20) {
			return EVENT_LOG;
		}
	}

	return EVENT_NULL;
}
