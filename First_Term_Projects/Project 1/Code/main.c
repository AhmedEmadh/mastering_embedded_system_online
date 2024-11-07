#include <stdint.h>
//#include <stdio.h>

#include "driver/driver.h"
#include "PressureSensor_Driver.h"
#include "Alarm_Manager.h"
#include "AlarmMonitor.h"
#include "AlarmActuator_Driver.h"


// APIs are
// void Delay(int nCount);
// int getPressureVal();
// void Set_Alarm_actuator(int i);
// void GPIO_INITIALIZATION(); Done

int main (){
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(1);
	while (1)
	{
		PSD_state();
		AMA_state();
		AMO_state();
		AAD_state();
	}

}
