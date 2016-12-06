#include <main.h>

extern uint8 i2cbuf[];
extern uint8 oldbuf[];
uint8 run_back(uint8 ang, uint8 speed)
{
    
    uint8 newang = 0;
    
    //Opdatere oldbuf 
    oldbuf[ANG_BACK_POS] = i2cbuf[ANG_BACK_POS];
    oldbuf[SPEED_BACK_POS] = i2cbuf[SPEED_BACK_POS];
    
    //Sætter hastighed på fremdriftsmotor 
    SpeedBackW_Write(HIGH);
    PWMSB_WriteCompare(speed);
    
    //tæl counter op og drejer steppermotoren med uret
	if(ang > CounterB_ReadCounter() && ang < MAX_POS)
    {
        newang = ang - CounterB_ReadCounter();
        newang += CounterB_ReadCounter();
        
        Dir_stepB_Write(HIGH);  
        PWMB1_Start();
        while(CounterB_ReadCounter()!=newang)
        {    
           
            if(ang != i2cbuf[ANG_BACK_POS])
            break;
        }
        PWMB1_Stop(); 
       
    }

    //tæl counter ned og drejer steppermotoren mod uret
    else if(ang < CounterF_ReadCounter() && ang > MIN_POS)
    {
        Dir_stepB_Write(LOW);
        PWMB2_Start();
        while(CounterB_ReadCounter()!=ang)
        {    
            
            if(ang != i2cbuf[ANG_BACK_POS])
            break;
        }
        PWMB2_Stop();
    }
    return 0;
}
