/*******************************************************************************
* File Name: PWM_retning_voltreguator_PM.c
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

#include "PWM_retning_voltreguator.h"

static PWM_retning_voltreguator_backupStruct PWM_retning_voltreguator_backup;


/*******************************************************************************
* Function Name: PWM_retning_voltreguator_SaveConfig
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
*  PWM_retning_voltreguator_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_retning_voltreguator_SaveConfig(void) 
{

    #if(!PWM_retning_voltreguator_UsingFixedFunction)
        #if(!PWM_retning_voltreguator_PWMModeIsCenterAligned)
            PWM_retning_voltreguator_backup.PWMPeriod = PWM_retning_voltreguator_ReadPeriod();
        #endif /* (!PWM_retning_voltreguator_PWMModeIsCenterAligned) */
        PWM_retning_voltreguator_backup.PWMUdb = PWM_retning_voltreguator_ReadCounter();
        #if (PWM_retning_voltreguator_UseStatus)
            PWM_retning_voltreguator_backup.InterruptMaskValue = PWM_retning_voltreguator_STATUS_MASK;
        #endif /* (PWM_retning_voltreguator_UseStatus) */

        #if(PWM_retning_voltreguator_DeadBandMode == PWM_retning_voltreguator__B_PWM__DBM_256_CLOCKS || \
            PWM_retning_voltreguator_DeadBandMode == PWM_retning_voltreguator__B_PWM__DBM_2_4_CLOCKS)
            PWM_retning_voltreguator_backup.PWMdeadBandValue = PWM_retning_voltreguator_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_retning_voltreguator_KillModeMinTime)
             PWM_retning_voltreguator_backup.PWMKillCounterPeriod = PWM_retning_voltreguator_ReadKillTime();
        #endif /* (PWM_retning_voltreguator_KillModeMinTime) */

        #if(PWM_retning_voltreguator_UseControl)
            PWM_retning_voltreguator_backup.PWMControlRegister = PWM_retning_voltreguator_ReadControlRegister();
        #endif /* (PWM_retning_voltreguator_UseControl) */
    #endif  /* (!PWM_retning_voltreguator_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_retning_voltreguator_RestoreConfig
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
*  PWM_retning_voltreguator_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_retning_voltreguator_RestoreConfig(void) 
{
        #if(!PWM_retning_voltreguator_UsingFixedFunction)
            #if(!PWM_retning_voltreguator_PWMModeIsCenterAligned)
                PWM_retning_voltreguator_WritePeriod(PWM_retning_voltreguator_backup.PWMPeriod);
            #endif /* (!PWM_retning_voltreguator_PWMModeIsCenterAligned) */

            PWM_retning_voltreguator_WriteCounter(PWM_retning_voltreguator_backup.PWMUdb);

            #if (PWM_retning_voltreguator_UseStatus)
                PWM_retning_voltreguator_STATUS_MASK = PWM_retning_voltreguator_backup.InterruptMaskValue;
            #endif /* (PWM_retning_voltreguator_UseStatus) */

            #if(PWM_retning_voltreguator_DeadBandMode == PWM_retning_voltreguator__B_PWM__DBM_256_CLOCKS || \
                PWM_retning_voltreguator_DeadBandMode == PWM_retning_voltreguator__B_PWM__DBM_2_4_CLOCKS)
                PWM_retning_voltreguator_WriteDeadTime(PWM_retning_voltreguator_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_retning_voltreguator_KillModeMinTime)
                PWM_retning_voltreguator_WriteKillTime(PWM_retning_voltreguator_backup.PWMKillCounterPeriod);
            #endif /* (PWM_retning_voltreguator_KillModeMinTime) */

            #if(PWM_retning_voltreguator_UseControl)
                PWM_retning_voltreguator_WriteControlRegister(PWM_retning_voltreguator_backup.PWMControlRegister);
            #endif /* (PWM_retning_voltreguator_UseControl) */
        #endif  /* (!PWM_retning_voltreguator_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_retning_voltreguator_Sleep
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
*  PWM_retning_voltreguator_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_retning_voltreguator_Sleep(void) 
{
    #if(PWM_retning_voltreguator_UseControl)
        if(PWM_retning_voltreguator_CTRL_ENABLE == (PWM_retning_voltreguator_CONTROL & PWM_retning_voltreguator_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_retning_voltreguator_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_retning_voltreguator_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_retning_voltreguator_UseControl) */

    /* Stop component */
    PWM_retning_voltreguator_Stop();

    /* Save registers configuration */
    PWM_retning_voltreguator_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_retning_voltreguator_Wakeup
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
*  PWM_retning_voltreguator_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_retning_voltreguator_Wakeup(void) 
{
     /* Restore registers values */
    PWM_retning_voltreguator_RestoreConfig();

    if(PWM_retning_voltreguator_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_retning_voltreguator_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
