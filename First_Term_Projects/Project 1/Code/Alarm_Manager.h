#ifndef ALARM_MANAGER_H_
#define ALARM_MANAGER_H_

#include "state.h"
//state type
typedef enum {
    AMA_HighPressureDetect
} AMA_state_t;

//Pointer to function declaration (extern)
extern void (*AMA_state)();
//declare states functions
STATE_define(AMA_HighPressureDetect);

#endif //ALARM_MANAGER_H_

