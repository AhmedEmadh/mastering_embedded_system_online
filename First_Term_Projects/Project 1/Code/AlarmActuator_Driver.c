//#include "state.h"
#include "AlarmActuator_Driver.h"
#include "state.h"
#include "driver/driver.h"
// #include <stdio.h>
//declaration of random function
// state variable
AAD_state_t AAD_state_id = AAD_init;
//signals out
//variables
int AAD_AlarmState = 0;
//STATE Pointer to function
void (*AAD_state)() = STATE(AAD_init);
//Signals in
void StopAlarm()
{
    AAD_state = STATE(AAD_AlarmOff);
}
void StartAlarm()
{
    AAD_state = STATE(AAD_AlarmOn);
}

//Write States
STATE_define(AAD_init)
{
    //state id
    AAD_state_id = AAD_init;
    //state action
    /* Nothing */
    //state transition
    AAD_state = STATE(AAD_waiting);
}
STATE_define(AAD_waiting)
{
    //state id
    AAD_state_id = AAD_waiting;
    //state action
    
    //state transition
    
}
STATE_define(AAD_AlarmOff)
{
    //state id
    AAD_state_id = AAD_AlarmOff;
    //state action
    /* Alarm Turned Off */
    AAD_AlarmState = 0;
    Set_Alarm_actuator(!AAD_AlarmState);
    //state transition
    AAD_state = STATE(AAD_waiting);
}
STATE_define(AAD_AlarmOn)
{
    //state id
    AAD_state_id = AAD_AlarmOn;
    //state action
    /* Alarm Turned On */
    AAD_AlarmState = 1;
    Set_Alarm_actuator(!AAD_AlarmState);
    //state transition
    AAD_state = STATE(AAD_waiting);
}