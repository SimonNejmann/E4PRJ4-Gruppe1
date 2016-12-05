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
    
    
    
    
    Counter_Start();
    I2CS_Start(); 
    I2CS_SetBuffer1(6,6,i2cbuf);
    

    /* Start I2C slave (SCB mode) */
   
    

    CyGlobalIntEnable;
    

    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for (;;)
    {
         if(oldbuf[0] != i2cbuf[0])
        {
            run_front(i2cbuf[0]);
            
        }
    }
    return 0;
}

/* [] END OF FILE */