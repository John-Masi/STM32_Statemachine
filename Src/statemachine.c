#include "../Inc/statemachine.h"


struct Statemachine {
	State current_state;
};

static Statemachine int_machine = {
		.current_state = STATE_OFF,
};


Statemachine* const my_machine = &int_machine;

void update_state(Event event,Statemachine* sm) {

	if(event == EVENT_NULL) { return; }

	switch(sm->current_state) {
		case STATE_OFF:
			if(event == BTN_PRESS) {
				sm->current_state = STATE_ON;
			}

			break;

		case STATE_ON:
			if(event == BTN_PRESS) {
				sm->current_state = STATE_OFF;
			}
	}
}

Event get_event(void) {


	return EVENT_NULL;
}
