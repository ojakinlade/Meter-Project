#include <stdbool.h>
#include <stdint.h>
#include "system.h"
#include "lm358.h"
#include "meas.h"


/*
CURRENT SENSOR: PA2
VOLTAGE DIVIDER: PA1
*/

typedef struct
{
	double voltage;
	double current;
	double phase_diff;
	
	
}room_t;

room_t room1 = {0};

uint32_t count1;
uint32_t count2;

uint16_t adcVoltage[NUMBER_OF_SAMPLES] = {0};
uint16_t adcCurrent[NUMBER_OF_SAMPLES] = {0};


int main(void)
{
	System_Init();
	voltage_CurrentMeasurement_Init();
	voltage_Init();
	current_Init();
	
	while(1)
	{
		room1.voltage = getVoltage(adcVoltage);
		room1.current = getCurrent(adcCurrent);
		
		if(get_Flag_Status())
		{
			get_Voltage_Timer_Value(&count1);
			get_Current_Timer_Value(&count2);
			
			if(count1 > count2)
			{
				room1.phase_diff = ((count1 - count2)/20.0) * 360.0;
				
			}
			else
			{
				room1.phase_diff = ((count2 - count1)/20.0) * 360.0;
			}
			
			reset_Flag_Status();
			
		}
	}
}
