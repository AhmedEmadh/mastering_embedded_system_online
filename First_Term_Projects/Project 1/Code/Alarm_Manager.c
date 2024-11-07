//#include "state.h"
#include "Alarm_Manager.h"
#include "state.h"

unsigned int AMA_SensorValue;
//declaration of random function
// state variable
AMA_state_t AMA_state_id = AMA_HighPressureDetect;
//signals out
void HighPressure_detected();
void HighPressure_Notdetected();
//variables
unsigned int AMA_SensorValue = 0;
int threshold = 20;
//STATE Pointer to function
void (*AMA_state)() = STATE(AMA_HighPressureDetect);
//Signals in
void set_pressure_val(unsigned int value)
{
    AMA_SensorValue = value;
}

//Write States

STATE_define(AMA_HighPressureDetect)
{
    //state id
    AMA_state_id = AMA_HighPressureDetect;
    //state action
    if(AMA_SensorValue > threshold)
    {
        HighPressure_detected();
    }
    else 
    {
        HighPressure_Notdetected();
    }
    //state transition
    AMA_state = STATE(AMA_HighPressureDetect);
}