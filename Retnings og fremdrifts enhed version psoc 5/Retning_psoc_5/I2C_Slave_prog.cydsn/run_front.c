#include <main.h>

uint8 run_front(uint8 ang, uint8 speed, uint8 ang2, uint8 speed2)
{
    
    if(ang > 0 && speed == 0)
    {
        State_Forward_cnt = ang;
        State_CtrlReg_Dir_Write(1);
        State_CtrlReg_Run_Write(1);
    }
      
    
    else if(speed > 0 && ang == 0)
    {
        State_Forward_cnt = speed;
        State_CtrlReg_Dir_Write(2);
        State_CtrlReg_Run_Write(1);
    }
    

  
    
    return 0;
}
    
