#include <main.h>
#include <functions.h>

uint8 stabil(uint8 ang)
{
    //Stabil mode
    uint8 newang = 0;
    
            //tæl counter op og drejer steppermotoren med uret
         	if(ang > CounterF_ReadCounter() && ang < MAX_POS)
            {     
                PWMF1_Stop();
                PWMF2_Stop();
                newang = ang - CounterF_ReadCounter();
                newang += CounterF_ReadCounter();
                CounterF_WriteCompare(newang);
                Dir_stepF_Write(HIGH);  
                PWMF1_Start();
            }

            //tæl counter ned og drejer steppermotoren mod uret
           if(ang < CounterF_ReadCounter() && ang > MIN_POS)
            {
                PWMF1_Stop();
                PWMF2_Stop();
                Dir_stepF_Write(LOW);
                CounterF_WriteCompare(ang);
                PWMF2_Start();
            } 
    return 0;
}

