/*******************************************************************************
* File Name: main.c
*
* Version: 1.20
*
* Description:
*  This example project demonstrates the basic operation of the I2C slave
*  (SCB mode) component. The I2C slave accepts a packet with a command from
*  the I2C master to control the RGB LED color. The I2C slave updates its
*  buffer with a status packet in response to the accepted command.
*  For more information refer to the example project datasheet.
*
********************************************************************************
* Copyright 2014-2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <main.h>

/* I2C slave read and write buffers */
uint8 i2cReadBuffer [BUFFER_SIZE] = {PACKET_SOP, STS_CMD_FAIL, PACKET_EOP};
uint8 i2cWriteBuffer[BUFFER_SIZE];



/*******************************************************************************
* Function Name: main
********************************************************************************
* Summary:
*  Main function performs following actions:
*   1. Turns off status RGB LED
*   2. Sets up I2C slave write and read buffers.
*   3. Starts I2C slave (SCB mode) component.
*   4. Enables global interrupts.
*   5. Waits for command from the I2C master to control the RGB LED.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
int main()
{
    uint8 status = STS_CMD_FAIL;

    PWM_2_Start();

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
                    status = ExecuteCommand(i2cWriteBuffer[PACKET_CMD_POS],i2cWriteBuffer[PACKET_CMD1_POS]);
                }
            }

            /* Clear slave write buffer and status */
            I2CS_I2CSlaveClearWriteBuf();
            (void) I2CS_I2CSlaveClearWriteStatus();

            /* Update read buffer */
            i2cReadBuffer[PACKET_STS_POS] = status;
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
}


/*******************************************************************************
* Function Name: ExecuteCommand
********************************************************************************
* Summary:
*  Executes received command to control the LED color and returns status.
*  If the command is unknown, the LED color is not changed.
*
* Parameters:
*  cmd: command to execute. Available commands:
*   - CMD_SET_RED:   set red color of the LED.
*   - CMD_SET_GREEN: set green color of the LED.
*   - CMD_SET_BLUE:  set blue color of the LED.
*   - CMD_SET_OFF:   turn off the LED.
*
* Return:
*  Returns status of command execution. There are two statuses
*  - STS_CMD_DONE: command is executed successfully.
*  - STS_CMD_FAIL: unknown command
*
*******************************************************************************/
uint8 ExecuteCommand(uint32 cmd, uint32 cmd1)
{
    uint8 status;
    uint16 pos = cmd << 8 | cmd1;
    status = STS_CMD_DONE;

    PWM_2_WriteCompare(pos);
    

    return (status);
}


/* [] END OF FILE */
