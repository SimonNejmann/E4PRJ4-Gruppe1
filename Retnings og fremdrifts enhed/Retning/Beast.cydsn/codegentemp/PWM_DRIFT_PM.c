/*******************************************************************************
* File Name: PWM_DRIFT_PM.c
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

#include "PWM_DRIFT.h"

static PWM_DRIFT_backupStruct PWM_DRIFT_backup;


/*******************************************************************************
* Function Name: PWM_DRIFT_SaveConfig
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
*  PWM_DRIFT_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_DRIFT_SaveConfig(void) 
{

    #if(!PWM_DRIFT_UsingFixedFunction)
        #if(!PWM_DRIFT_PWMModeIsCenterAligned)
            PWM_DRIFT_backup.PWMPeriod = PWM_DRIFT_ReadPeriod();
        #endif /* (!PWM_DRIFT_PWMModeIsCenterAligned) */
        PWM_DRIFT_backup.PWMUdb = PWM_DRIFT_ReadCounter();
        #if (PWM_DRIFT_UseStatus)
            PWM_DRIFT_backup.InterruptMaskValue = PWM_DRIFT_STATUS_MASK;
        #endif /* (PWM_DRIFT_UseStatus) */

        #if(PWM_DRIFT_DeadBandMode == PWM_DRIFT__B_PWM__DBM_256_CLOCKS || \
            PWM_DRIFT_DeadBandMode == PWM_DRIFT__B_PWM__DBM_2_4_CLOCKS)
            PWM_DRIFT_backup.PWMdeadBandValue = PWM_DRIFT_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_DRIFT_KillModeMinTime)
             PWM_DRIFT_backup.PWMKillCounterPeriod = PWM_DRIFT_ReadKillTime();
        #endif /* (PWM_DRIFT_KillModeMinTime) */

        #if(PWM_DRIFT_UseControl)
            PWM_DRIFT_backup.PWMControlRegister = PWM_DRIFT_ReadControlRegister();
        #endif /* (PWM_DRIFT_UseControl) */
    #endif  /* (!PWM_DRIFT_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_DRIFT_RestoreConfig
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
*  PWM_DRIFT_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_DRIFT_RestoreConfig(void) 
{
        #if(!PWM_DRIFT_UsingFixedFunction)
            #if(!PWM_DRIFT_PWMModeIsCenterAligned)
                PWM_DRIFT_WritePeriod(PWM_DRIFT_backup.PWMPeriod);
            #endif /* (!PWM_DRIFT_PWMModeIsCenterAligned) */

            PWM_DRIFT_WriteCounter(PWM_DRIFT_backup.PWMUdb);

            #if (PWM_DRIFT_UseStatus)
                PWM_DRIFT_STATUS_MASK = PWM_DRIFT_backup.InterruptMaskValue;
            #endif /* (PWM_DRIFT_UseStatus) */

            #if(PWM_DRIFT_DeadBandMode == PWM_DRIFT__B_PWM__DBM_256_CLOCKS || \
                PWM_DRIFT_DeadBandMode == PWM_DRIFT__B_PWM__DBM_2_4_CLOCKS)
                PWM_DRIFT_WriteDeadTime(PWM_DRIFT_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_DRIFT_KillModeMinTime)
                PWM_DRIFT_WriteKillTime(PWM_DRIFT_backup.PWMKillCounterPeriod);
            #endif /* (PWM_DRIFT_KillModeMinTime) */

            #if(PWM_DRIFT_UseControl)
                PWM_DRIFT_WriteControlRegister(PWM_DRIFT_backup.PWMControlRegister);
            #endif /* (PWM_DRIFT_UseControl) */
        #endif  /* (!PWM_DRIFT_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_DRIFT_Sleep
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
*  PWM_DRIFT_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_DRIFT_Sleep(void) 
{
    #if(PWM_DRIFT_UseControl)
        if(PWM_DRIFT_CTRL_ENABLE == (PWM_DRIFT_CONTROL & PWM_DRIFT_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_DRIFT_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_DRIFT_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_DRIFT_UseControl) */

    /* Stop component */
    PWM_DRIFT_Stop();

    /* Save registers configuration */
    PWM_DRIFT_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_DRIFT_Wakeup
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
*  PWM_DRIFT_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_DRIFT_Wakeup(void) 
{
     /* Restore registers values */
    PWM_DRIFT_RestoreConfig();

    if(PWM_DRIFT_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_DRIFT_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
