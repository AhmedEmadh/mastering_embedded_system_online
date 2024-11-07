//#include "state.h"
#include "AlarmMonitor.h"
#include "AlarmActuator_Driver.h"
#include "AlarmMonitor.h"
#include "state.h"
#include "driver/driver.h"
//state id
AMO_state_t AMO_state_id = AMO_alarmOff;
//state pointer to function
void (*AMO_state)() = STATE(AMO_alarmOff);
//variables
int alarm_periode = 60;
int AMO_isHighPressureDetected = 0;
//out signals
void StartAlarm();
void StopAlarm();
//in signals
void HighPressure_detected()
{
    AMO_isHighPressureDetected = 1;
}
void HighPressure_Notdetected()
{
    AMO_isHighPressureDetected = 0;
}
//states
STATE_define(AMO_alarmOff)
{
    //state id
    AMO_state_id = AMO_alarmOff;
    //state action
    if(AMO_isHighPressureDetected)
    {
        AMO_state = STATE(AMO_alarmOn);
    }
    else 
    {
        StopAlarm();
    }
    //state transition

}
STATE_define(AMO_alarmOn)
{
    //state id
    AMO_state_id = AMO_alarmOn;
    //state action
    StartAlarm();
    AMO_state = STATE(AMO_waiting);
    //state transition
    
}
STATE_define(AMO_waiting)
{
    //state id
    AMO_state_id = AMO_waiting;
    //state action
    Delay(6000000);
    //state transition
    AMO_state = STATE(AMO_alarmOff);
}