/* ========================================
 *
 * Copyright Anders Dalsgaard Norlyk, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "main.h"

/* I2C slave read and write buffers */
uint8 i2cbuf[BUFFER_SIZE]={0};
uint8 oldbuf[BUFFER_SIZE]={0};

int main()
{
    
    
    
    
    //init_step();
    I2CS_Start(); 
    I2CS_SetBuffer1(BUFFER_SIZE,BUFFER_RW_AREA,i2cbuf);
    CounterF_Start();
    CounterB_Start();
    PWMSF_Start();
    PWMSB_Start();
    /* Start I2C slave (SCB mode) */
   
    

    CyGlobalIntEnable;
    

    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for (;;)
    {
        PWMSF_WriteCompare(i2cbuf[SPEED_FRONT_POS]);
        PWMSB_WriteCompare(i2cbuf[SPEED_BACK_POS]);
        
        if(oldbuf[ANG_FRONT_POS] != i2cbuf[ANG_FRONT_POS])
        {
            run_front(i2cbuf[ANG_FRONT_POS],i2cbuf[ANG_BACK_POS]);
        }
//        if(oldbuf[ANG_BACK_POS] != i2cbuf[ANG_BACK_POS])
//        {
//            run_back(i2cbuf[ANG_BACK_POS]);
//        }
    }
    return 0;
}

/* [] END OF FILE */