#include <main.h>


uint8 strafe(uint8 ang)
{
    uint8 newang = 0;
    // Straff mode
 
    //Front engine
    //tæl counter op og drejer steppermotoren med uret
	if(ang > CounterF_ReadCounter() && ang < MAX_POS)
    {
        newang = ang - CounterF_ReadCounter();
        newang += CounterF_ReadCounter();
        CounterF_WriteCompare(newang);
        Dir_stepF_Write(HIGH);  
        PWMF1_Start();
    }

    //tæl counter ned og drejer steppermotoren mod uret
    else if(ang < CounterF_ReadCounter() && ang > MIN_POS)
    {
        CounterF_WriteCompare(ang);
        Dir_stepF_Write(LOW);
        PWMF2_Start();    
    }
    
    // Back engine  
    //tæl counter op og drejer steppermotoren med uret
	if(ang > CounterB_ReadCounter() && ang < MAX_POS)
    {
        newang = ang - CounterB_ReadCounter();
        newang += CounterB_ReadCounter();
        CounterB_WriteCompare(newang);
        Dir_stepB_Write(HIGH);  
        PWMB1_Start();   
    }

    //tæl counter ned og drejer steppermotoren mod uret
    else if(ang < CounterB_ReadCounter() && ang > MIN_POS)
    {
        CounterB_WriteCompare(ang);
        Dir_stepB_Write(LOW);
        PWMB2_Start();    
    }
    return 0;
}
