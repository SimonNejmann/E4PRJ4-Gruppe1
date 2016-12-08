#include <main.h>

extern uint8 i2cbuf[];
extern uint8 oldbuf[];
uint8 strafe(uint8 ang, uint8 ang2)
{
    
    uint8 newang = 0;
    
    //Opdatere oldbuf 
    oldbuf[ANG_BACK_POS] = i2cbuf[ANG_BACK_POS];
    
     // Straff mode
 
      //Front engine
        //tæl counter op og drejer steppermotoren med uret
	if(ang > CounterF_ReadCounter() && ang < MAX_POS)
    {
        newang = ang - CounterF_ReadCounter();
        newang += CounterF_ReadCounter();
        
        Dir_stepF_Write(HIGH);  
        PWMF1_Start();
        while(CounterF_ReadCounter()!=newang)
        {    
           
            if(ang != i2cbuf[ANG_FRONT_POS])
            break;
        }
        PWMF1_Stop(); 
       
    }

    //tæl counter ned og drejer steppermotoren mod uret
    else if(ang < CounterF_ReadCounter() && ang > MIN_POS)
    {
        Dir_stepF_Write(LOW);
        PWMF2_Start();
        while(CounterF_ReadCounter()!=ang)
        {    
            
            if(ang != i2cbuf[ANG_FRONT_POS])
            break;
        }
        PWMF2_Stop();
    }
    
    
    
    // Back engine
         
        
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
    else if(ang < CounterB_ReadCounter() && ang > MIN_POS)
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
