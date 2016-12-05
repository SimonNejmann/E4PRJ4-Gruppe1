#include <main.h>

extern uint8 i2cbuf[];
extern uint8 oldbuf[];
uint8 run_front(uint8 ang)
{
    oldbuf[0] = i2cbuf[0];
    uint8 newang = 0;
    uint8 max_pos = 201;
    uint8 min_pos = 0;
   
    //tæl counter op
	if(ang > Counter_ReadCounter() && ang < max_pos)
    {
        newang = ang - Counter_ReadCounter();
        newang += Counter_ReadCounter();
        
        Dir_step_Write(1);  
        PWM1_Start();
        while(Counter_ReadCounter()!=newang)
        {    
           
            if(ang != i2cbuf[0])
            break;
        }
        PWM1_Stop(); 
       
    }

    //tæl counter ned
    else if(ang < Counter_ReadCounter() && ang > min_pos)
    {
        Dir_step_Write(0);
        PWM2_Start();
        while(Counter_ReadCounter()!=ang)
        {    
            
            if(ang != i2cbuf[0])
            break;
        }
        PWM2_Stop();
    }
    return 0;
}
