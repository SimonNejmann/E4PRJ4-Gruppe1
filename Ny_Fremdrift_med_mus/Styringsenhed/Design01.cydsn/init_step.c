#include <main.h>

void init_step()
{   
    // Retningsmotor init
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
    CounterB_S
    
    strafe(100); 
    while (CounterF_ReadCounter() != 100 && CounterB_ReadCounter() != 100) {
        
    }
    
    // Interrupt init
    isr_cntF_compare_StartEx(cntF_interrupt);
    isr_cntB_compare_StartEx(cntB_interrupt);
    isr_cntF_compare_ClearPending();
    isr_cntB_compare_ClearPending();
    
    //PWM og I2C init//
    PWMSF_Start();
    PWMSB_Start();
    I2C_Slave_Start();
}
