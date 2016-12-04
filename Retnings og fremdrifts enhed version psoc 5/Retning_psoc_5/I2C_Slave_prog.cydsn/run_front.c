#include <main.h>

uint8 run_front(uint8 ang, uint8 speed, uint8 ang2, uint8 speed2)
{
	if(State_front_engine_Pos_cnt > 200)
	{
		State_front_engine_Pos_cnt = 100;
	}
    uint8 ang_forw;
	uint8 ang_backw;
	
    if(ang > 99) 
    {
		ang_forw = (ang - State_front_engine_Pos_cnt);
        State_front_engine_Forward_cnt = ang;
        State_front_engine_CtrlReg_Dir_Write(1);
        State_front_engine_CtrlReg_Run_Write(1);
    }
		    
    
    else if(ang < 100) 
    {
		ang_backw = (State_front_engine_Pos_cnt - ang);
        State_front_engine_Forward_cnt = ang_backw;
        State_front_engine_CtrlReg_Dir_Write(2);
        State_front_engine_CtrlReg_Run_Write(1);
    }
    

  
    
    return 0;
}
    
