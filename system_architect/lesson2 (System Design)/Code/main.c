

#include "CA.h"
#include <stdlib.h>
void setup()
{
    //init all the drivers
    //init IRQ ....
    //init HAL US_Driver DC_Driver
    //init BLOCK
    //Set States pointer for each Block
}



int main()
{
	volatile long long i;
    setup();
    while (1) {
        CA_state();
		for(i=0;i<90000000;i++);
        //system("pause");
    }
}