#include "state.h"
//state type
typedef enum {
    PSD_init,
    PSD_reading,
    PSD_waiting
} PSD_state_t;

//Pointer to function declaration (extern)
extern void (*PSD_state)();
//declare states functions
STATE_define(PSD_init);
STATE_define(PSD_reading);
STATE_define(PSD_waiting);