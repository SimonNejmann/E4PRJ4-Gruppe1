#include <main.h>

extern uint8 i2cbuf[];
extern uint8 oldbuf[];
uint8 run_front(uint8 ang, uint8 ang2)
{
    
    uint8 newang = 0;
    uint8 newang2 = 0;
    //Opdatere oldbuf 
    oldbuf[ANG_FRONT_POS] = i2cbuf[ANG_FRONT_POS];

    //Steer mode
    if(ang2 == 0)
    {
        ang = (ang/2)+50;
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
    }
    
    // Straff mode
    else
    {   
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
        run_back(ang);
    }
    return 0;
}
