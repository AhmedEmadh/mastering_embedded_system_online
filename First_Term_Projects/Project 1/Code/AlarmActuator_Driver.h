#ifndef ALARMACTUATOR_DRIVER_H_
#define ALARMACTUATOR_DRIVER_H_
//state type
#include "state.h"

extern void (*AAD_state)();


typedef enum
{
    AAD_init,
    AAD_waiting,
    AAD_AlarmOff,
    AAD_AlarmOn
}AAD_state_t;

//function declarations

STATE_define(AAD_init);
STATE_define(AAD_waiting);
STATE_define(AAD_AlarmOff);
STATE_define(AAD_AlarmOn);


#endif //ALARMACTUATOR_DRIVER_H_
