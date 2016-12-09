/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    uint8 i2cbuf[1];
    i2cbuf[0]=0;
    CyGlobalIntEnable; /* Enable global interrupts. */
    uint8 newang = 0;
    uint8 max_pos = 201;
    uint8 min_pos = 0;
    
    I2C_Start();
    Counter_Start();
    I2C_SetBuffer1(1,1,i2cbuf);

    for(;;)
    {
        
    uint8 ang = i2cbuf[0];
    //tæl counter op
	if(ang > Counter_ReadCounter() && ang < max_pos)
    {
        newang = ang - Counter_ReadCounter();
        newang += Counter_ReadCounter();
        
        Dir_step_Write(1);  
        PWM1_Start();
        while(Counter_ReadCounter()!=newang)
        {    
            
            if(ang != i2cbuf[0])
            break;
        }
        PWM1_Stop(); 
       
    }

    //tæl counter ned
    else if(ang < Counter_ReadCounter() && ang > min_pos)
    {
        Dir_step_Write(0);
        PWM2_Start();
        while(Counter_ReadCounter()!=ang)
        {    
            
            if(ang != i2cbuf[0])
            break;
        }
        PWM2_Stop();
    }/* Place your application code here. */
    }
    
}

/* [] END OF FILE */
