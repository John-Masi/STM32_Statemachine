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

#define LCD_ON 0

void update_state(enum Event event,Statemachine* sm) {

	if(event == EVENT_NULL) { return; }

	if(event == EVENT_LOG) {
		send_str("Checking HTU31 connection");
		send_char('\n');
		if(isHTU31()) {
			send_str("HTU31 ACK");
			send_char('\n');
			i2c_poll();
		}
		else {
			send_str("HTU31 NACK");
			send_char('\n');
		}

		#if LCD_ON
			clearLCD();
		#endif

		ticks = 0;
	}

	switch(sm->current_state) {
		case STATE_OFF:
			if(event == BTN_PRESS) {
				led_on();
				#if LCD_ON
					clearLCD();
					printStr("LED on");
				#endif
				send_str("LED ON");
				send_char('\n');
				sm->current_state = STATE_ON;
			}

			break;

		case STATE_ON:
			if(event == BTN_PRESS) {
				led_off();
				#if LCD_ON
					clearLCD();
					printStr("LED off");
				#endif
				send_str("LED OFF");
				send_char('\n');
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
		update_count(0);
		ticks++;
		if(ticks >= 10) {
			return EVENT_LOG;
		}
	}

	return EVENT_NULL;
}

	return EVENT_NULL;
}
