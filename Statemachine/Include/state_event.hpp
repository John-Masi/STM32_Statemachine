#include <cstdint>

#ifndef STATE_EVENT_HPP
#define STATE_EVENT_HPP

enum State: uint8_t {
    STATE_ON,
    STATE_OFF
}

enum Event: uint8_t {
    EVENT_PRESS,
    EVENT_LOG,
    EVENT_NULL
}

#endif 