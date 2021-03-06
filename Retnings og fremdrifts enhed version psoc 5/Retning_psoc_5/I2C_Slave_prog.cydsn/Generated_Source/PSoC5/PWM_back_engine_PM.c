/*******************************************************************************
* File Name: PWM_back_engine_PM.c
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

#include "PWM_back_engine.h"

static PWM_back_engine_backupStruct PWM_back_engine_backup;


/*******************************************************************************
* Function Name: PWM_back_engine_SaveConfig
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
*  PWM_back_engine_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_back_engine_SaveConfig(void) 
{

    #if(!PWM_back_engine_UsingFixedFunction)
        #if(!PWM_back_engine_PWMModeIsCenterAligned)
            PWM_back_engine_backup.PWMPeriod = PWM_back_engine_ReadPeriod();
        #endif /* (!PWM_back_engine_PWMModeIsCenterAligned) */
        PWM_back_engine_backup.PWMUdb = PWM_back_engine_ReadCounter();
        #if (PWM_back_engine_UseStatus)
            PWM_back_engine_backup.InterruptMaskValue = PWM_back_engine_STATUS_MASK;
        #endif /* (PWM_back_engine_UseStatus) */

        #if(PWM_back_engine_DeadBandMode == PWM_back_engine__B_PWM__DBM_256_CLOCKS || \
            PWM_back_engine_DeadBandMode == PWM_back_engine__B_PWM__DBM_2_4_CLOCKS)
            PWM_back_engine_backup.PWMdeadBandValue = PWM_back_engine_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_back_engine_KillModeMinTime)
             PWM_back_engine_backup.PWMKillCounterPeriod = PWM_back_engine_ReadKillTime();
        #endif /* (PWM_back_engine_KillModeMinTime) */

        #if(PWM_back_engine_UseControl)
            PWM_back_engine_backup.PWMControlRegister = PWM_back_engine_ReadControlRegister();
        #endif /* (PWM_back_engine_UseControl) */
    #endif  /* (!PWM_back_engine_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_back_engine_RestoreConfig
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
*  PWM_back_engine_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_back_engine_RestoreConfig(void) 
{
        #if(!PWM_back_engine_UsingFixedFunction)
            #if(!PWM_back_engine_PWMModeIsCenterAligned)
                PWM_back_engine_WritePeriod(PWM_back_engine_backup.PWMPeriod);
            #endif /* (!PWM_back_engine_PWMModeIsCenterAligned) */

            PWM_back_engine_WriteCounter(PWM_back_engine_backup.PWMUdb);

            #if (PWM_back_engine_UseStatus)
                PWM_back_engine_STATUS_MASK = PWM_back_engine_backup.InterruptMaskValue;
            #endif /* (PWM_back_engine_UseStatus) */

            #if(PWM_back_engine_DeadBandMode == PWM_back_engine__B_PWM__DBM_256_CLOCKS || \
                PWM_back_engine_DeadBandMode == PWM_back_engine__B_PWM__DBM_2_4_CLOCKS)
                PWM_back_engine_WriteDeadTime(PWM_back_engine_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_back_engine_KillModeMinTime)
                PWM_back_engine_WriteKillTime(PWM_back_engine_backup.PWMKillCounterPeriod);
            #endif /* (PWM_back_engine_KillModeMinTime) */

            #if(PWM_back_engine_UseControl)
                PWM_back_engine_WriteControlRegister(PWM_back_engine_backup.PWMControlRegister);
            #endif /* (PWM_back_engine_UseControl) */
        #endif  /* (!PWM_back_engine_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_back_engine_Sleep
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
*  PWM_back_engine_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_back_engine_Sleep(void) 
{
    #if(PWM_back_engine_UseControl)
        if(PWM_back_engine_CTRL_ENABLE == (PWM_back_engine_CONTROL & PWM_back_engine_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_back_engine_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_back_engine_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_back_engine_UseControl) */

    /* Stop component */
    PWM_back_engine_Stop();

    /* Save registers configuration */
    PWM_back_engine_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_back_engine_Wakeup
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
*  PWM_back_engine_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_back_engine_Wakeup(void) 
{
     /* Restore registers values */
    PWM_back_engine_RestoreConfig();

    if(PWM_back_engine_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_back_engine_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
