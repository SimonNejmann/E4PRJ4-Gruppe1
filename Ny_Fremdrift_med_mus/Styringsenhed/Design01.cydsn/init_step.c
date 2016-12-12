#include <main.h>

void init_step()
{
    isr_PS2_clock_Disable();
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
    
    strafe(100); 
    while (CounterF_ReadCounter() != 100 && CounterB_ReadCounter() != 100) {
        
    }
    isr_PS2_clock_Enable();
   
}
