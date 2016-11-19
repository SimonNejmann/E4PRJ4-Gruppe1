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
    I2CS_SlaveInitReadBuf (i2cReadBuffer,  BUFFER_SIZE);
    I2CS_SlaveInitWriteBuf(i2cWriteBuffer, BUFFER_SIZE);
    I2CS_Start();

    CyGlobalIntEnable;
    

    /***************************************************************************
    * Main polling loop
    ***************************************************************************/
    for (;;)
    {
            
        /* Write complete: parse command packet */
        if (0u != (I2CS_SlaveStatus() & I2CS_SSTAT_WR_CMPLT))
        {
            /* Check packet length */
            if (PACKET_SIZE == I2CS_SlaveGetWriteBufSize())
            {
                /* Check start and end of packet markers */
                if ((i2cWriteBuffer[PACKET_SOP_POS] == PACKET_SOP) &&
                    (i2cWriteBuffer[PACKET_EOP_POS] == PACKET_EOP))
                {
                    status = run_front(i2cWriteBuffer[PACKET_ANG1_POS],i2cWriteBuffer[PACKET_SPEED1_POS],i2cWriteBuffer[PACKET_ANG2_POS],i2cWriteBuffer[PACKET_SPEED2_POS]);
                    
                }
            }

            /* Clear slave write buffer and status */
            I2CS_SlaveClearWriteBuf();
            (void) I2CS_SlaveClearWriteStatus();

            /*  read buffer */
            i2cReadBuffer[PACKET_STS_1_POS] = status;
            status = STS_CMD_FAIL;
        }

        /* Read complete: expose buffer to master */
        if (0u != (I2CS_SlaveStatus() & I2CS_SSTAT_RD_CMPLT))
        {
            /* Clear slave read buffer and status */
            I2CS_SlaveClearReadBuf();
            (void) I2CS_SlaveClearReadStatus();
        }
    }
    return 0;
}

/* [] END OF FILE */
