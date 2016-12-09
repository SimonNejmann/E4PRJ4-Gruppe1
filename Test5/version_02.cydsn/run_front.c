#include <main.h>

extern uint8 i2cbuf[];
extern uint8 oldbuf[];
uint8 run_front(uint8 ang, uint8 speed)
{
    
    uint8 newang = 0;
    
    //Opdatere oldbuf 
    oldbuf[ANG_FRONT_POS] = i2cbuf[ANG_FRONT_POS];
    oldbuf[SPEED_FRONT_POS] = i2cbuf[SPEED_FRONT_POS];
    
    
    //Sætter hastighed på fremdriftsmotor 
    SpeedForW_Write(HIGH);
    PWMSF_WriteCompare(speed);
    
    //tæl counter op og drejer steppermotoren med uret
	if(ang > CounterF_ReadCounter() && ang < MAX_POS)
    {
        newang = ang - CounterF_ReadCounter();
        newang += CounterF_ReadCounter();
        
        Dir_stepF_Write(HIGH);  
        //PWMF1_Start();
        step_1_Forward_cnt = newang;
        step_1_CtrlReg_Dir_Write(1);
        step_1_CtrlReg_Run_Write(1);
        while(CounterF_ReadCounter()!=newang)
        {    
            
            if(ang != i2cbuf[ANG_FRONT_POS])
            break;
        }
        //PWMF1_Stop();
        step_1_CtrlReg_Dir_Write(0);
        step_1_CtrlReg_Run_Write(0);
       
        
    }

    //tæl counter ned og drejer steppermotoren mod uret
    if(ang < CounterF_ReadCounter() && ang > MIN_POS)
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
    return 0;
}
