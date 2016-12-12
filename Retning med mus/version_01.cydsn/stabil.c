#include <main.h>


uint8 stabil(uint8 ang)
{
    
    uint8 newang = 0;
    uint8 newang2 = 0;
    //Opdatere oldbuf 
    
        //Stabil mode
     //  ang = ang/1.8;
            //tæl counter op og drejer steppermotoren med uret
        	if(ang > CounterF_ReadCounter() && ang < MAX_POS)
            {
                newang = ang - CounterF_ReadCounter();
                newang += CounterF_ReadCounter();
                
                Dir_stepF_Write(HIGH);  
                PWMF1_Start();
                while(CounterF_ReadCounter()!=newang)
                {    
                   
                    
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
                    
                }
                PWMF2_Stop();
            }
      

    return 0;
}

