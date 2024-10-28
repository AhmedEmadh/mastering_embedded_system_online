#include "CA.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//declaration of random function
int US_Get_distance_random(int MinNum, int maxNum);

// state variable
CA_state_t CA_state_id = CA_waiting;

//variables
static int CA_speed = 0;
static int CA_distance = 0;
static int CA_threshold = 50;

//STATE Pointer to function
    void (*CA_state)() = STATE(CA_waiting);

STATE_define(CA_waiting)
{
    //state_name
    CA_state_id = CA_waiting;
    //state_action
    CA_speed = 0;
    //DC_motor(CA_speed)
    CA_distance = US_Get_distance_random(45,55);
    //event_check
    (CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
    printf("CA_waiting state: distance %d Speed %d\n",CA_distance,CA_speed);
	fflush(stdout);
}

STATE_define(CA_driving)
{
    //state_name
    CA_state_id = CA_driving;
    //state_action
    CA_speed = 30;
    //DC_motor(CA_speed)
    CA_distance = US_Get_distance_random(45,55);
    //event_check
    (CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)):(CA_state = STATE(CA_driving));
    printf("CA_driving state: distance %d Speed %d\n",CA_distance,CA_speed);
	fflush(stdout);
}
int US_Get_distance_random(int MinNum, int maxNum)
{
    // Static variable to ensure srand() is called only once
    static int seeded = 0;
    if (!seeded) {
        srand(time(0));
        seeded = 1;
    }

    // Ensure maxNum is greater than minNum
    if (MinNum > maxNum) {
        int temp = MinNum;
        MinNum = maxNum;
        maxNum = temp;
    }

    // Generate random number in the range [minNum, maxNum]
    return rand() % (maxNum - MinNum + 1) + MinNum;
}

