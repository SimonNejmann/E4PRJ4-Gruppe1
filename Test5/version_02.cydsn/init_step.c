#include <main.h>

void init_step()
{
    Dir_stepF_Write(HIGH);  
    PWMF1_Start();
    
    while(MicroF_Read() != HIGH)
        {    
        }   
            
    PWMF1_Stop();
    CounterF_Start();
    
    Dir_stepB_Write(HIGH);
    PWMB1_Start();
    
    while(MicroB_Read() != HIGH)
        {    
        }
    
    PWMB1_Stop();
    CounterB_Start();
        
        
   
}
