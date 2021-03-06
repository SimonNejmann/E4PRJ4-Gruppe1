/*******************************************************************************
* File Name: I2CS.c
* Version 2.0
*
* Description:
*  This file contains the setup, control and status commands for the EZI2C
*  component. The actual protocol and operation code resides in the interrupt
*  service routine file.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CS_PVT.h"

/**********************************
*      System variables
**********************************/

uint8 I2CS_initVar = 0u; /* Defines if component was initialized */

/* Status and state variables */
volatile uint8 I2CS_curStatus; /* Current status of the component */
volatile uint8 I2CS_curState;  /* Current state of state machine */

/* Primary slave address variables */
volatile uint8* I2CS_dataPtrS1; /* Pointer to data buffer 1 */
volatile uint16 I2CS_bufSizeS1; /* Size of buffer 1 in bytes */
volatile uint16 I2CS_wrProtectS1; /* Start index of write protected area in buffer 1 */
volatile uint8  I2CS_rwOffsetS1; /* Current offset within buffer 1 */
volatile uint8  I2CS_rwIndexS1;  /* Current index within buffer 1 */

/* Secondary slave address variables */
#if(I2CS_ADDRESSES == I2CS_TWO_ADDRESSES)
    volatile uint8  I2CS_addrS1; /* Primary slave address: software comparison */
    volatile uint8  I2CS_addrS2; /* Secondary slave address: software comparison */
    volatile uint8* I2CS_dataPtrS2; /* Pointer to data buffer 1 */
    volatile uint16 I2CS_bufSizeS2; /* Size of buffer 2 in bytes */
    volatile uint16 I2CS_wrProtectS2; /* Start index of write protected area in buffer 2 */
    volatile uint8 I2CS_rwOffsetS2; /* Current offset within buffer 2 */
    volatile uint8 I2CS_rwIndexS2;  /* Current index within buffer 2 */
#endif  /* (I2CS_ADDRESSES == I2CS_TWO_ADDRESSES) */


/*******************************************************************************
* Function Name: I2CS_Init
********************************************************************************
*
* Summary:
*  Initializes or restores the component according to the Configure dialog
*  settings. It is not necessary to call EZI2C_Init() because the EZI2C_Start()
*  API calls this function, which is the preferred method to begin component
*  operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  I2CS_initVar - It is used to indicate the initial configuration
*  of this component.  The variable is initialized to zero and set to 1
*  the first time I2CS_Start() is called. This allows component  !
*  initialization without re-initialization in all subsequent calls
*  to the I2CS_Start() routine.
*
*  I2CS_curStatus - Stores the current status of the component.
*
*  I2CS_curState- Stores the current state of an I2C state machine.
*
*  I2CS_rwOffsetS1 - The global variable which stores an offset for read
*  and write operations, is set at each write sequence of the first slave
*  address is reset if I2CS_initVar is 0, by
*  I2CS_initVar function call.
*
*  I2CS_rwIndexS1 - The global variable which stores a pointer to the
*  next value to be read or written for the first slave address is reset if
*  I2CS_initVar is 0, by I2CS_initVar function call.
*
* I2CS_wrProtectS1 - The global variable which stores an offset where data
*  is read only for the first slave address is reset if
*  I2CS_initVar is 0, by I2CS_initVar function call.
*
*  I2CS_rwOffsetS2 - The global variable, which stores an offset for read
*  and write operations, is set at each write sequence of the second slave
*  device is reset if I2CS_initVar is 0, by I2CS_initVar
*  function call.
*
*  I2CS_rwIndexS2 - The global variable which stores a pointer to the
*  next value to be read or written for the second slave address is reset if
*  I2CS_initVar is 0, by I2CS_initVar function call.
*
* I2CS_wrProtectS2 - The global variable which stores an offset where data
*  is read only for the second slave address is reset if
*  I2CS_initVar is 0, by I2CS_initVar function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2CS_Init(void) 
{
    /* Configure fixed function block */
    I2CS_CFG_REG  = I2CS_DEFAULT_CFG;
    I2CS_XCFG_REG = I2CS_DEFAULT_XCFG;
    I2CS_ADDR_REG = I2CS_DEFAULT_ADDR;
    I2CS_CLKDIV1_REG = I2CS_DEFAULT_CLKDIV1;
    I2CS_CLKDIV2_REG = I2CS_DEFAULT_CLKDIV2;

#if (I2CS_TWO_ADDRESSES == I2CS_ADDRESSES)
    /* Set address variables */
    I2CS_SetAddress1(I2CS_DEFAULT_ADDR1);
    I2CS_SetAddress2(I2CS_DEFAULT_ADDR2);
#endif /* #if (I2CS_TWO_ADDRESSES == I2CS_ADDRESSES) */

    /* Configure interrupt */
    CyIntDisable         (I2CS_ISR_NUMBER);
    CyIntSetPriority     (I2CS_ISR_NUMBER, I2CS_ISR_PRIORITY);
    (void) CyIntSetVector(I2CS_ISR_NUMBER, &I2CS_ISR);

     /* Reset state and status to default */
    I2CS_curState  = I2CS_SM_IDLE;
    I2CS_curStatus = 0u;

    /* Reset all buffer 1 indexes (primary address) */
    I2CS_rwOffsetS1  = 0u;
    I2CS_rwIndexS1   = 0u;
    I2CS_wrProtectS1 = 0u;

#if (I2CS_ADDRESSES == I2CS_TWO_ADDRESSES)
    /* Reset all buffer 2 indexes (secondary address) */
    I2CS_rwOffsetS2  = 0u;
    I2CS_rwIndexS2   = 0u;
    I2CS_wrProtectS2 = 0u;
#endif  /* (I2CS_ADDRESSES == I2CS_TWO_ADDRESSES) */
}


/*******************************************************************************
* Function Name: I2CS_Enable
********************************************************************************
*
* Summary:
*  Activates the hardware and begins component operation.Calls EZI2C_EnableInt()
*  to enable the I2C component interrupt. It is not necessary to call
*  EZI2C_Enable() because the EZI2C_Start() API calls this function, which is
*  the preferred method to begin component operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void I2CS_Enable(void) 
{
    uint8 intState;

    /* Enable power to block */
    intState = CyEnterCriticalSection();
    I2CS_PM_ACT_CFG_REG  |= I2CS_ACT_PWR_EN;
    I2CS_PM_STBY_CFG_REG |= I2CS_STBY_PWR_EN;
    CyExitCriticalSection(intState);

    /* Enable interrupt to start operation */
    I2CS_EnableInt();
}


/*******************************************************************************
* Function Name: I2CS_Start
********************************************************************************
*
* Summary:
*  This is the preferred method to begin component operation. EZI2C_Start(),
*  calls the EZI2C_Init() function, and then calls the EZI2C_Enable() function.
*  It must be executed before I2C bus operation.
*  This function enables the component interrupt because interrupt is required
*  for most component operations.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2CS_Start(void) 
{
    if (0u == I2CS_initVar)
    {
        I2CS_Init();
        I2CS_initVar = 1u; /* Component initialized */
    }

    I2CS_Enable();
}


/*******************************************************************************
* Function Name: I2CS_Stop
********************************************************************************
*
* Summary:
*  Disables I2C hardware and component interrupt. The I2C bus is released if it
*  was locked up by the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void I2CS_Stop(void) 
{
    uint8  intState;
    uint16 blockResetCycles;

    I2CS_DisableInt();

    /* Store registers effected by block disable */
    I2CS_backup.adr     = I2CS_ADDR_REG;
    I2CS_backup.clkDiv1 = I2CS_CLKDIV1_REG;
    I2CS_backup.clkDiv2 = I2CS_CLKDIV2_REG;

    /* Calculate number of cycles to reset block */
    blockResetCycles = ((uint16) ((uint16) I2CS_CLKDIV2_REG << 8u) | I2CS_CLKDIV1_REG) + 1u;

    /* Disable block */
    I2CS_CFG_REG &= (uint8) ~I2CS_CFG_EN_SLAVE;
    /* Wait for block reset before disable power */
    CyDelayCycles((uint32) blockResetCycles);

    /* Disable power to block */
    intState = CyEnterCriticalSection();
    I2CS_PM_ACT_CFG_REG  &= (uint8) ~I2CS_ACT_PWR_EN;
    I2CS_PM_STBY_CFG_REG &= (uint8) ~I2CS_STBY_PWR_EN;
    CyExitCriticalSection(intState);

    /* Enable block */
    I2CS_CFG_REG |= (uint8) I2CS_CFG_EN_SLAVE;

    /* Restore registers effected by block disable. Ticket ID#198004 */
    I2CS_ADDR_REG    = I2CS_backup.adr;
    I2CS_ADDR_REG    = I2CS_backup.adr;
    I2CS_CLKDIV1_REG = I2CS_backup.clkDiv1;
    I2CS_CLKDIV2_REG = I2CS_backup.clkDiv2;

    I2CS_ClearPendingInt();

    /* Reset state and status to default */
    I2CS_curState  = I2CS_SM_IDLE;
    I2CS_curStatus = 0u;
}


/*******************************************************************************
* Function Name: I2CS_SetAddress1
********************************************************************************
*
* Summary:
*  Sets the primary I2C slave address. This address is used by the master to
*  access the primary data buffer.
*
* Parameters:
*  address: Primary I2C slave address.
*           This address is the 7-bit right-justified slave address and does not
*           include the R/W bit.
*           This value can be any address between 0 and 127 (0x00 to 0x7F).
*
* Return:
*  None.
*
* Global variables:
*  I2CS_addrS1 - A new slave address for the first slave device is
*  saved in it, if the component is configured to act as two slave devices.
*
* Reentrant:
*  No, if two addresses are used.
*
*******************************************************************************/
void I2CS_SetAddress1(uint8 address) 
{
#if (I2CS_ONE_ADDRESS == I2CS_ADDRESSES)
    I2CS_ADDR_REG = (address & I2CS_SADDR_MASK);
#else
    I2CS_addrS1   = (address & I2CS_SADDR_MASK);
#endif /* (I2CS_ONE_ADDRESS == I2CS_ADDRESSES) */
}


/*******************************************************************************
* Function Name: I2CS_GetAddress1
********************************************************************************
*
* Summary:
*  Returns the primary I2C slave address.
*  This address is the 7-bit right-justified slave address and does not include
*  the R/W bit.
*
* Parameters:
*  None.
*
* Return:
*  Primary I2C slave address.
*
* Global variables:
*  I2CS_addrS1 - If component is configured to has two slave
*  addresses than the primary address is saved here, otherwise the address is written to
*  the register.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 I2CS_GetAddress1(void) 
{
#if (I2CS_ONE_ADDRESS == I2CS_ADDRESSES)
    return (I2CS_ADDR_REG);
#else
    return (I2CS_addrS1);
#endif /* (I2CS_ONE_ADDRESS == I2CS_ADDRESSES) */
}


/*******************************************************************************
* Function Name: I2CS_GetActivity
********************************************************************************
*
* Summary:
*  Returns a non-zero value if an I2C read or write cycle has occurred since
*  the last time this function was called. The activity flag resets to zero at
*  the end of this function call.
*  The Read and Write busy flags are cleared when read, but the “BUSY” flag is
*  only cleared when slave is free (i.e master finishes communication with
*  slave generating Stop or repeated Start condition).
*
* Parameters:
*  None
*
* Return:
*  Status of I2C activity.
*
*   I2CS_STATUS_READ1   Set if a Read sequence is detected for the first
*                                   address. Cleared when the status is read.
*
*   I2CS_STATUS_WRITE1  Set if a Write sequence is detected for the first
*                                   address. Cleared when the status is  read.
*
*   I2CS_STATUS_READ2   Set if a Read sequence is detected for the second
*                                   address (if enabled). Cleared when the status
*                                   read.
*
*   I2CS_STATUS_WRITE2  Set if a Write sequence is detected for the second
*                                   address (if enabled). Cleared when the status is
*                                   read.
*
*   I2CS_STATUS_BUSY    Set when the master starts communication with
*                                   the slave (the slave is addressed with Start or
*                                   repeated Start) and cleared when the master
*                                   finishes communication (a Stop or repeated
*                                   Start condition is generated).
*
*   I2CS_STATUS_ERR     Set when the I2C hardware is detected, cleared
*                                   when the status is read.
*
* Global variables:
*  I2CS_curStatus - The global variable which stores the current
*  component status.
*
* Reentrant:
*  No.
*
*******************************************************************************/
uint8 I2CS_GetActivity(void) 
{
    uint8 tmpStatus;

    I2CS_DisableInt(); /* Lock from component interrupt */

    tmpStatus = I2CS_curStatus;
    /* Clear status bits. Do not touch busy status */
    I2CS_curStatus &= I2CS_STATUS_BUSY;

    I2CS_EnableInt(); /* Release lock */

    return (tmpStatus);
}


/*******************************************************************************
* Function Name: I2CS_SetBuffer1
********************************************************************************
*
* Summary:
*  Sets up the data buffer to be exposed to the master on a primary slave
*  address request.
*
* Parameters:
*  bufSize:    Size of the buffer in bytes.
*  rwBoundary: Number of data bytes starting from the beginning of the buffer
*              with read and write access. Data bytes located at offset
*              rwBoundary or greater are read only.
*              This value must be less than or equal to the buffer size.
*  dataPtr:    Pointer to the data buffer.
*
* Return:
*  None.
*
* Global variables:
*  I2CS_dataPtrS1 - Stores the pointer to the data exposed to an I2C
*  master for the first slave address, is modified with the the new pointer to    the    ?? no sense without a comma
*  data passed by the function parameter.
*
*  I2CS_rwOffsetS1 - Stores an offset for read and write operations, is
*  modified at each write sequence of the first slave address is?? reset.   ?
*
*  I2CS_rwIndexS1 - Stores the pointer to the next value to be read or
*  written for the first slave address is?? set to 0.  ??
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2CS_SetBuffer1(uint16 bufSize, uint16 rwBoundary, volatile uint8 * dataPtr) 
{
    I2CS_DisableInt(); /* Lock from component interrupt */

    if (NULL != dataPtr)
    {
        /* Configure buffer 1 */
        I2CS_dataPtrS1   = dataPtr;
        I2CS_bufSizeS1   = bufSize;
        I2CS_wrProtectS1 = rwBoundary;
    }

    /* Clear buffer offset and index */
    I2CS_rwOffsetS1 = 0u;
    I2CS_rwIndexS1  = 0u;

    I2CS_EnableInt(); /* Release lock */
}


#if (I2CS_TWO_ADDRESSES == I2CS_ADDRESSES)
    /*******************************************************************************
    * Function Name: I2CS_SetBuffer2
    ********************************************************************************
    *
    * Summary:
    *  Sets up the data buffer to be exposed to the master on a secondary slave
    *  address request.
    *
    * Parameters:
    *  bufSize:    Size of the buffer in bytes.
    *  rwBoundary: Number of data bytes starting from the beginning of the buffer
    *              with read and write access. Data bytes located at offset
    *              rwBoundary or greater are read only.
    *              This value must be less than or equal to the buffer size.
    *  dataPtr:    Pointer to the data buffer.
    *
    * Return:
    *  None.
    *
    * Global variables:
    *  I2CS_dataPtrS2 - Stores the pointer to the data exposed to an I2C
    *  master for the second slave address, is modified with the the new pointer to the
    *  data, passed by the unction parameter.
    *
    *  I2CS_rwOffsetS2 - Stores teh offset for read and write operations,
    *  is modified at each write sequence of the second slave address is?? reset.  ??
    *
    *  I2CS_rwIndexS2 - Stores the pointer to the next value to be read or
    *  written for the second slave address is?? set to 0.  ??
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void I2CS_SetBuffer2(uint16 bufSize, uint16 rwBoundary, volatile uint8 * dataPtr) 
    {
        I2CS_DisableInt(); /* Lock from component interrupt */

        if (NULL != dataPtr)
        {
            /* Configure buffer 2 */
            I2CS_dataPtrS2   = dataPtr;
            I2CS_bufSizeS2   = bufSize;
            I2CS_wrProtectS2 = rwBoundary;
        }

        /* Clear buffer offset and index */
        I2CS_rwOffsetS2 = 0u;
        I2CS_rwIndexS2  = 0u;

        I2CS_EnableInt(); /* Release lock */
    }


    /*******************************************************************************
    * Function Name: I2CS_SetAddress2
    ********************************************************************************
    *
    * Summary:
    *  Sets the secondary I2C slave address. This address is used by the master to
    *  access the secondary data buffer.
    *
    * Parameters:
    *  address: Secondary I2C slave address.
    *           This address is the 7-bit right-justified slave address and does
    *           not include the R/W bit. This value can be any address between
    *           0 and 127 (0x00 to 0x7F).
    *
    * Return:
    *  None.
    *
    * Global variables:
    *  I2CS_addrS2 - The secondary slave address is modified.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void I2CS_SetAddress2(uint8 address) 
    {
        I2CS_addrS2 = (address & I2CS_SADDR_MASK);
    }


    /*******************************************************************************
    * Function Name: I2CS_GetAddress2
    ********************************************************************************
    *
    * Summary:
    *  Returns the secondary I2C slave address.
    *  This address is the 7-bit right-justified slave address and does not
    *  include the R/W bit.
    *
    * Parameters:
    *  I2CS_addrS2 - The global variable which stores the second I2C
    *   address.
    *
    * Return:
    *  Secondary I2C slave address.
    *
    * Global variables:
    *  I2CS_addrS2 - The secondary slave address is used.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 I2CS_GetAddress2(void) 
    {
        return (I2CS_addrS2);
    }

#endif  /* (I2CS_TWO_ADDRESSES == I2CS_ADDRESSES) */


/* [] END OF FILE */
