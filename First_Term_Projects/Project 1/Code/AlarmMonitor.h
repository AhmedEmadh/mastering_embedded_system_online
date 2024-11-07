#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"

extern void (*AMO_state)();

//State Type
typedef enum{
    AMO_alarmOff,
    AMO_alarmOn,
    AMO_waiting
} AMO_state_t;
//function declarations
STATE_define(AMO_alarmOff);
STATE_define(AMO_alarmOn);
STATE_define(AMO_waiting);

#endif //ALARM_MONITOR_H_
