//#include "state.h"
#include "PressureSensor_Driver.h"
//#include <stdlib.h>
//#include <time.h>
#include "driver/driver.h"
#include "state.h"
//declaration of random function
//int PS_Get_distance_random(int MinNum, int maxNum);

// state variable
PSD_state_t PSD_state_id = PSD_init;
int PSD_waitingCounter = 0;

int waitingValue = 1;
//signals out
void set_pressure_val(unsigned int value);
//variables
unsigned int PSD_SensorValue;

//STATE Pointer to function
void (*PSD_state)() = STATE(PSD_init);

//Write States
STATE_define(PSD_init)
{
    //state Name
    PSD_state_id = PSD_init;
    //state Action

    //event check
    PSD_state = STATE(PSD_reading);
}
STATE_define(PSD_reading)
{
    //state Name
    PSD_state_id = PSD_reading;
    //state Action
    PSD_SensorValue = getPressureVal();
    set_pressure_val(PSD_SensorValue);

    //event check
    PSD_state = STATE(PSD_waiting);
}
STATE_define(PSD_waiting)
{
    //state Name
    PSD_state_id = PSD_waiting;
    //state Action
    
    //event check
    if(PSD_waitingCounter >= waitingValue)
    {
        PSD_state = STATE(PSD_reading);
        PSD_waitingCounter = 0;
    }
    else 
    {
        PSD_waitingCounter++;
    }
    
}

// int PS_Get_distance_random(int MinNum, int maxNum)
// {
//     // Static variable to ensure srand() is called only once
//     static int seeded = 0;
//     if (!seeded) {
//         srand(time(0));
//         seeded = 1;
//     }

//     // Ensure maxNum is greater than minNum
//     if (MinNum > maxNum) {
//         int temp = MinNum;
//         MinNum = maxNum;
//         maxNum = temp;
//     }

//     // Generate random number in the range [minNum, maxNum]
//     return rand() % (maxNum - MinNum + 1) + MinNum;
// }
