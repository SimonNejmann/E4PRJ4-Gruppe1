#include <main.h>

uint8 run_front(uint8 ang, uint8 speed, uint8 ang2, uint8 speed2)
{
    int8 newang = ang;
    
   
    
	if(newang < 0)
    {
        PWM2_WriteCompare1(2);
        PWM2_WriteCompare2(1);
        while(UpDown_GetCounter()!=ang)
        {
            //Dir_Write(1);
            Dir_step_Write(1);            
            PWM2_Start();
        }
        PWM2_Stop();       
    }

    else if(newang >= 0)
    {
        PWM2_WriteCompare1(1);
        PWM2_WriteCompare2(2);
        while(UpDown_GetCounter()!=ang)
        {
            //Dir_Write(0);
            Dir_step_Write(0);
            PWM2_Start();
        }
        PWM2_Stop();
    }
    return 0;
}