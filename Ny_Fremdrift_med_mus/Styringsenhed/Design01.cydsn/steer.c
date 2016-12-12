#include <main.h>


uint8 steer(uint8 ang)
{
    uint8 newang = 0;
    uint8 newang2 = 0;
    //Opdatere oldbuf 
     ang = (ang/2) + 50;

    //Steer mode

        
        //tæl counter op og drejer steppermotoren med uret
    	if(ang > CounterF_ReadCounter() && ang <= 150)
        {   
//            PWMF1_Stop();
            PWMF2_Stop();
            newang = ang - CounterF_ReadCounter();
            newang += CounterF_ReadCounter();
            CounterF_WriteCompare(newang);
            Dir_stepF_Write(HIGH);  
            PWMF1_Start();
            ; 
           
        }

        //tæl counter ned og drejer steppermotoren mod uret
        else if(ang < CounterF_ReadCounter() && ang >= 50)
        {
            PWMF1_Stop();
//            PWMF2_Stop();
            CounterF_WriteCompare(ang);
            Dir_stepF_Write(LOW);
            PWMF2_Start();
            
        } 

    return 0;
}
