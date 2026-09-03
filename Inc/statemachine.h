
#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdint.h>

enum State {
	STATE_OFF,
	STATE_ON
};

enum Event {
	EVENT_BTN,
	EVENT_LOG,
	EVENT_NULL
};

typedef struct Statemachine Statemachine;

static Statemachine* const myMachine;

void update_state(Event event);
Event get_event(void);

#endif
