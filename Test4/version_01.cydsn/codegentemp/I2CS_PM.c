/*******************************************************************************
* File Name: I2CS_PM.c
* Version 2.0
*
* Description:
*  This file contains the API for the proper switching to/from the low power
*  modes.
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2CS_PVT.h"

I2CS_BACKUP_STRUCT I2CS_backup =
{
    I2CS_DISABLED,
    I2CS_DEFAULT_XCFG,
    I2CS_DEFAULT_ADDR,
    I2CS_DEFAULT_CFG,
    I2CS_DEFAULT_CLKDIV1,
    I2CS_DEFAULT_CLKDIV2
};

#if (I2CS_WAKEUP_ENABLED)
    volatile uint8 I2CS_wakeupSource;
#endif /* (I2CS_WAKEUP_ENABLED) */


/*******************************************************************************
* Function Name: I2CS_SaveConfig
********************************************************************************
*
* Summary:
*  The Enable wakeup from Sleep Mode selection influences this function
*  implementation:
*   Unchecked: Stores the component non-retention configuration registers.
*   Checked:   Enables backup regulator of the I2C hardware. If a transaction
*              intended for component executes during this function call,
*              it waits until the current transaction is completed and
*              I2C hardware is ready to go to sleep mode. All subsequent
*              I2C traffic is NAKed until the device is put to sleep mode.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  I2CS_backup - The non-retention registers are saved to.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2CS_SaveConfig(void) 
{
#if (I2CS_WAKEUP_ENABLED)
    uint8 interruptState;
#endif /* (I2CS_WAKEUP_ENABLED) */

    /* Store component configuration into backup structure */
    I2CS_backup.cfg     = I2CS_CFG_REG;
    I2CS_backup.xcfg    = I2CS_XCFG_REG;
    I2CS_backup.adr     = I2CS_ADDR_REG;
    I2CS_backup.clkDiv1 = I2CS_CLKDIV1_REG;
    I2CS_backup.clkDiv2 = I2CS_CLKDIV2_REG;

#if (I2CS_WAKEUP_ENABLED)
    /* Enable I2C backup regulator */
    interruptState = CyEnterCriticalSection();
    I2CS_PWRSYS_CR1_REG |= I2CS_PWRSYS_CR1_I2C_BACKUP;
    CyExitCriticalSection(interruptState);

    /* Wait for completion of the current transaction. The following
    * transactions have to be NACKed until the device enters the low power mode.
    * After a wakeup, the force NACK bit is cleared automatically.
    */
    I2CS_XCFG_REG |= I2CS_XCFG_FORCE_NACK;
    while (0u == (I2CS_XCFG_REG & I2CS_XCFG_SLEEP_READY))
    {
    }

     /* Setup wakeup interrupt */
    I2CS_DisableInt();
    I2CS_wakeupSource = 0u; /* Clear wakeup event */
    (void) CyIntSetVector(I2CS_ISR_NUMBER, &I2CS_WAKEUP_ISR);
    I2CS_EnableInt();
#endif /* (I2CS_WAKEUP_ENABLED) */
}


/*******************************************************************************
* Function Name: I2CS_RestoreConfig
********************************************************************************
*
* Summary:
*  The Enable wakeup from Sleep Mode selection influences this function
*  implementation:
*   Unchecked: Restores the component non-retention configuration registers
*              to the state they were in before I2C_Sleep() or I2C_SaveConfig()
*              was called.
*   Checked:   Disables the backup regulator of the I2C hardware. Sets up the
*              regular component interrupt handler and generates the component
*              interrupt if it was wake up source to release the bus and
*              continue in-coming I2C transaction.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  I2CS_backup - the non-retention registers are restored from.
*
* Reentrant:
*  No.
*
* Side Effects:
*  Calling this function before I2CS_SaveConfig() or
*  I2CS_Sleep() may produce unexpected behavior.
*
*******************************************************************************/
void I2CS_RestoreConfig(void) 
{
    uint8 intState;

    if (0u != (I2CS_PWRSYS_CR1_I2C_BACKUP & I2CS_PWRSYS_CR1_REG))
    /* Exit from Sleep */
    {
        /* Disable I2C backup regulator */
        intState = CyEnterCriticalSection();
        I2CS_PWRSYS_CR1_REG &= (uint8) ~I2CS_PWRSYS_CR1_I2C_BACKUP;
        CyExitCriticalSection(intState);
    }
    else /* Exit from Hibernate (bit is cleared) or wakeup disabled */
    {
    #if (I2CS_WAKEUP_ENABLED)
        /* Disable power to I2C block before register restore */
        intState = CyEnterCriticalSection();
        I2CS_PM_ACT_CFG_REG  &= (uint8) ~I2CS_ACT_PWR_EN;
        I2CS_PM_STBY_CFG_REG &= (uint8) ~I2CS_STBY_PWR_EN;
        CyExitCriticalSection(intState);

        /* Enable component after restore complete */
        I2CS_backup.enableState = I2CS_ENABLED;
    #endif /* (I2CS_WAKEUP_ENABLED) */

        /* Restore component registers: Hibernate disable power */
        I2CS_CFG_REG     = I2CS_backup.cfg;
        I2CS_XCFG_REG    = I2CS_backup.xcfg;
        I2CS_ADDR_REG    = I2CS_backup.adr;
        I2CS_CLKDIV1_REG = I2CS_backup.clkDiv1;
        I2CS_CLKDIV2_REG = I2CS_backup.clkDiv2;
    }

#if (I2CS_WAKEUP_ENABLED)
    /* Set I2C interrupt to be pending if component is source of wake up */
    I2CS_DisableInt();
    (void) CyIntSetVector(I2CS_ISR_NUMBER, &I2CS_ISR);
    if (0u != I2CS_wakeupSource)
    {
        /* Generate interrupt to release I2C bus */
        (void) CyIntSetPending(I2CS_ISR_NUMBER);
    }
    I2CS_EnableInt();
#endif /* (I2CS_WAKEUP_ENABLED) */
}


/*******************************************************************************
* Function Name: I2CS_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred method to prepare the component before device enters
*  sleep mode.
*  The Enable wakeup from Sleep Mode selection influences this function
*  implementation:
*   Unchecked: Checks current EZI2C component state, saves it, and disables the
*              component by calling EZI2C_Stop() if it is currently enabled.
*              EZI2C_SaveConfig() is then called to save the component
*              non-retention configuration registers.
*   Checked:   If a transaction intended for component is in progress during
*              this function call, it waits until the current transaction is
*              completed. All subsequent I2C traffic intended for component is
*              NAKed until the device is put to sleep mode. The address match
*              event wakes up the device.
*
*  Call the EZI2C_Sleep() function before calling the CyPmSleep() or the
*  CyPmHibernate() function. Refer to the PSoC Creator System Reference Guide
*  for more information about power-management functions.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  I2CS_backup - The non retention registers are saved to. Changed
*  by I2CS_SaveConfig() function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void I2CS_Sleep(void) 
{
#if (I2CS_WAKEUP_ENABLED)
    /* Do not re-enable component in I2CS_Wakeup(). It remains enabled as it is wakeup source */
    I2CS_backup.enableState = I2CS_DISABLED;
#else
    /* Store component state enabled or disable to restore after wakeup */
    I2CS_backup.enableState = (I2CS_PM_ACT_CFG_REG & I2CS_ACT_PWR_EN);

    if (0u != I2CS_backup.enableState)
    {
        /* Disable component before enter Sleep */
        I2CS_Stop();
    }
#endif /* (I2CS_WAKEUP_ENABLED) */

    I2CS_SaveConfig();
}


/*******************************************************************************
* Function Name: I2CS_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred method to prepare the component for active mode
*  operation (when device exits sleep mode).
*  The Enable wakeup from Sleep Mode selection influences this function
*  implementation:
*   Unchecked: Restores the component non-retention configuration registers
*              by calling EZI2C_RestoreConfig(). If the component was enabled
*              before the EZI2C_Sleep() function was called, EZI2C_Wakeup()
*              re-enables it.
*   Checked:   Disables the backup regulator of I2C hardware. The incoming
*              transaction continues as soon as the regular EZI2C interrupt
*              handler is set up (global interrupts has to be  enabled to
*              service EZI2C component interrupt).
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  I2CS_backup - The non retention registers are restored from.
*
* Reentrant:
*  No.
*
* Side Effects:
*  Calling this function before I2CS_SaveConfig() or
*  I2CS_Sleep() will lead to unpredictable results.
*
*******************************************************************************/
void I2CS_Wakeup(void) 
{
    I2CS_RestoreConfig();

    if (0u != I2CS_backup.enableState)
    {
        /* Enable component as it was enabled before Sleep */
        I2CS_Enable();
    }
}


/* [] END OF FILE */
