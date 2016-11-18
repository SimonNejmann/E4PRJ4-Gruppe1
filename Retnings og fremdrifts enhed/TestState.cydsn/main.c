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
uint8 i2cReadBuffer [BUFFER_SIZE] = {PACKET_SOP, STS_CMD_FAIL, STS_CMD_DONE, STS_CMD_DONE, STS_CMD_DONE, PACKET_EOP};
uint8 i2cWriteBuffer[BUFFER_SIZE];

int main()
{
    uint8 status = STS_CMD_FAIL;
    
    

    /* Start I2C slave (SCB mode) */
    I2CS_I2CSlaveInitReadBuf (i2cReadBuffer,  BUFFER_SIZE);
    I2CS_I2CSlaveInitWriteBuf(i2cWriteBuffer, BUFFER_SIZE);
    I2CS_Start();

    CyGlobalIntEnable;
    

    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for (;;)
    {
            
        /* Write complete: parse command packet */
        if (0u != (I2CS_I2CSlaveStatus() & I2CS_I2C_SSTAT_WR_CMPLT))
        {
            /* Check packet length */
            if (PACKET_SIZE == I2CS_I2CSlaveGetWriteBufSize())
            {
                /* Check start and end of packet markers */
                if ((i2cWriteBuffer[PACKET_SOP_POS] == PACKET_SOP) &&
                    (i2cWriteBuffer[PACKET_EOP_POS] == PACKET_EOP))
                {
                    status = run_front(i2cWriteBuffer[PACKET_ANG1_POS],i2cWriteBuffer[PACKET_SPEED1_POS],i2cWriteBuffer[PACKET_ANG2_POS],i2cWriteBuffer[PACKET_SPEED2_POS]);
                    
                }
            }

            /* Clear slave write buffer and status */
            I2CS_I2CSlaveClearWriteBuf();
            (void) I2CS_I2CSlaveClearWriteStatus();

            /* Update read buffer */
            i2cReadBuffer[PACKET_STS_1_POS] = status;
            status = STS_CMD_FAIL;
        }

        /* Read complete: expose buffer to master */
        if (0u != (I2CS_I2CSlaveStatus() & I2CS_I2C_SSTAT_RD_CMPLT))
        {
            /* Clear slave read buffer and status */
            I2CS_I2CSlaveClearReadBuf();
            (void) I2CS_I2CSlaveClearReadStatus();
        }
    }
    return 0;
}

/* [] END OF FILE */
