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
#define BUFFER_SIZE 4
int main(void)
{
    uint8 i2c_buffer[BUFFER_SIZE];
    EZI2C_1_Start();
    CyGlobalIntEnable; /* Enable global interrupts. */
    EZI2C_1_SetBuffer1(BUFFER_SIZE,BUFFER_SIZE,i2c_buffer);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
