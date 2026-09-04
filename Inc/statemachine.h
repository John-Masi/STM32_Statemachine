#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "usart.h"
#include "gpio.h"
#include "exti.h"

#include <stdint.h>

enum State {
	STATE_OFF,
	STATE_ON
};

enum Event {
	BTN_PRESS,
	EVENT_LOG,
	EVENT_NULL
};

typedef struct Statemachine Statemachine;

extern Statemachine* const myMachine;

void update_state(enum Event event,Statemachine* sm);
enum Event get_event(void);

#endif
