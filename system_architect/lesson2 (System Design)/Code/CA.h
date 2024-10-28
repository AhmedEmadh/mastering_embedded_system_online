#ifndef CA_H_
#define CA_H_
#include "state.h"

typedef enum {
    CA_waiting,
    CA_driving
} CA_state_t;

extern void (*CA_state)();

//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);

#endif //CA_H_
