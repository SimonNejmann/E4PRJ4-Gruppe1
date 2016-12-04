#include <main.h>

uint8 run_front(uint8 ang, uint8 speed, uint8 ang2, uint8 speed2)
{
	if(ang < 100)
    {
        while(Counter_ReadCounter()!=ang)
        {
            //Dir_Write(1);
            Dir_step_Write(1);
            PWM1_Start();
        }
        PWM1_Stop();       
    }

    else if(ang>100)
    {
        while(Counter_ReadCounter()!=ang)
        {
            //Dir_Write(0);
            Dir_step_Write(0);
            PWM2_Start();
        }
        PWM2_Stop();
    }
    return 0;
}