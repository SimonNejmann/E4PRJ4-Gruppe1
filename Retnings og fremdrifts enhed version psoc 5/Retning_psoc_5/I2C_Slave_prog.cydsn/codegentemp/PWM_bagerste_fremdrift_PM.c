/*******************************************************************************
* File Name: PWM_bagerste_fremdrift_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_bagerste_fremdrift.h"

static PWM_bagerste_fremdrift_backupStruct PWM_bagerste_fremdrift_backup;


/*******************************************************************************
* Function Name: PWM_bagerste_fremdrift_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_bagerste_fremdrift_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_bagerste_fremdrift_SaveConfig(void) 
{

    #if(!PWM_bagerste_fremdrift_UsingFixedFunction)
        #if(!PWM_bagerste_fremdrift_PWMModeIsCenterAligned)
            PWM_bagerste_fremdrift_backup.PWMPeriod = PWM_bagerste_fremdrift_ReadPeriod();
        #endif /* (!PWM_bagerste_fremdrift_PWMModeIsCenterAligned) */
        PWM_bagerste_fremdrift_backup.PWMUdb = PWM_bagerste_fremdrift_ReadCounter();
        #if (PWM_bagerste_fremdrift_UseStatus)
            PWM_bagerste_fremdrift_backup.InterruptMaskValue = PWM_bagerste_fremdrift_STATUS_MASK;
        #endif /* (PWM_bagerste_fremdrift_UseStatus) */

        #if(PWM_bagerste_fremdrift_DeadBandMode == PWM_bagerste_fremdrift__B_PWM__DBM_256_CLOCKS || \
            PWM_bagerste_fremdrift_DeadBandMode == PWM_bagerste_fremdrift__B_PWM__DBM_2_4_CLOCKS)
            PWM_bagerste_fremdrift_backup.PWMdeadBandValue = PWM_bagerste_fremdrift_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_bagerste_fremdrift_KillModeMinTime)
             PWM_bagerste_fremdrift_backup.PWMKillCounterPeriod = PWM_bagerste_fremdrift_ReadKillTime();
        #endif /* (PWM_bagerste_fremdrift_KillModeMinTime) */

        #if(PWM_bagerste_fremdrift_UseControl)
            PWM_bagerste_fremdrift_backup.PWMControlRegister = PWM_bagerste_fremdrift_ReadControlRegister();
        #endif /* (PWM_bagerste_fremdrift_UseControl) */
    #endif  /* (!PWM_bagerste_fremdrift_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_bagerste_fremdrift_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_bagerste_fremdrift_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_bagerste_fremdrift_RestoreConfig(void) 
{
        #if(!PWM_bagerste_fremdrift_UsingFixedFunction)
            #if(!PWM_bagerste_fremdrift_PWMModeIsCenterAligned)
                PWM_bagerste_fremdrift_WritePeriod(PWM_bagerste_fremdrift_backup.PWMPeriod);
            #endif /* (!PWM_bagerste_fremdrift_PWMModeIsCenterAligned) */

            PWM_bagerste_fremdrift_WriteCounter(PWM_bagerste_fremdrift_backup.PWMUdb);

            #if (PWM_bagerste_fremdrift_UseStatus)
                PWM_bagerste_fremdrift_STATUS_MASK = PWM_bagerste_fremdrift_backup.InterruptMaskValue;
            #endif /* (PWM_bagerste_fremdrift_UseStatus) */

            #if(PWM_bagerste_fremdrift_DeadBandMode == PWM_bagerste_fremdrift__B_PWM__DBM_256_CLOCKS || \
                PWM_bagerste_fremdrift_DeadBandMode == PWM_bagerste_fremdrift__B_PWM__DBM_2_4_CLOCKS)
                PWM_bagerste_fremdrift_WriteDeadTime(PWM_bagerste_fremdrift_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_bagerste_fremdrift_KillModeMinTime)
                PWM_bagerste_fremdrift_WriteKillTime(PWM_bagerste_fremdrift_backup.PWMKillCounterPeriod);
            #endif /* (PWM_bagerste_fremdrift_KillModeMinTime) */

            #if(PWM_bagerste_fremdrift_UseControl)
                PWM_bagerste_fremdrift_WriteControlRegister(PWM_bagerste_fremdrift_backup.PWMControlRegister);
            #endif /* (PWM_bagerste_fremdrift_UseControl) */
        #endif  /* (!PWM_bagerste_fremdrift_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_bagerste_fremdrift_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_bagerste_fremdrift_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_bagerste_fremdrift_Sleep(void) 
{
    #if(PWM_bagerste_fremdrift_UseControl)
        if(PWM_bagerste_fremdrift_CTRL_ENABLE == (PWM_bagerste_fremdrift_CONTROL & PWM_bagerste_fremdrift_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_bagerste_fremdrift_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_bagerste_fremdrift_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_bagerste_fremdrift_UseControl) */

    /* Stop component */
    PWM_bagerste_fremdrift_Stop();

    /* Save registers configuration */
    PWM_bagerste_fremdrift_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_bagerste_fremdrift_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_bagerste_fremdrift_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_bagerste_fremdrift_Wakeup(void) 
{
     /* Restore registers values */
    PWM_bagerste_fremdrift_RestoreConfig();

    if(PWM_bagerste_fremdrift_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_bagerste_fremdrift_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
