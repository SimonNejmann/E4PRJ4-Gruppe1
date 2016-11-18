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
//int8 i2cReadBuffer [BUFFER_SIZE] = {};
uint8 i2cWriteBuffer [BUFFER_SIZE];

int main(void)
{
    /* Start PWM */
    PWM_DRIFT_Start();
    
    /* Initialization of status reg */
    run_front(0u, 0u);
    run_back(0u, 0u);
    
    /* Start I2C slave (SCB mode)*/
    I2CS_Start();
    I2CS_I2CSlaveInitWriteBuf(i2cWriteBuffer, BUFFER_SIZE);
    
   /* Change SCL and SDA pins drive mode to Resistive Pull Up */
    I2CS_scl_SetDriveMode(I2CS_scl_DM_RES_UP);
    I2CS_sda_SetDriveMode(I2CS_sda_DM_RES_UP);
    
    
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Write complete: parse command packet */
        if (0u != (I2CS_I2CSlaveStatus() & I2CS_I2C_SSTAT_WR_CMPLT))
        {
            /* Check packet length */
            if (PACKET_SIZE == I2CS_I2CSlaveGetWriteBufSize())
            {
                run_front(i2cWriteBuffer[PACKET_ANG_1_POS], i2cWriteBuffer[PACKET_SPEED_1_POS]);
                run_back(i2cWriteBuffer[PACKET_ANG_2_POS], i2cWriteBuffer[PACKET_SPEED_2_POS]);
            }
        }
    return 0; 
    }
}

/* [] END OF FILE */
