/*******************************************************************************
* File Name: PGA_B_PM.c  
* Version 2.0
*
* Description:
*  This file provides the power manager source code to the API for PGA 
*  Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "PGA_B.h"

static PGA_B_BACKUP_STRUCT  PGA_B_backup;


/*******************************************************************************
* Function Name: PGA_B_SaveConfig
********************************************************************************
*
* Summary:
*  Save the current user register configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA_B_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: PGA_B_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void PGA_B_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: PGA_B_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PGA_B_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void PGA_B_Sleep(void) 
{
    /* Save PGA enable state */
    if((PGA_B_PM_ACT_CFG_REG & PGA_B_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        PGA_B_backup.enableState = 1u;
        /* Stop the configuration */
        PGA_B_Stop();
    }
    else
    {
        /* Component is disabled */
        PGA_B_backup.enableState = 0u;
    }
    /* Save the configuration */
    PGA_B_SaveConfig();
}


/*******************************************************************************
* Function Name: PGA_B_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  void
*
* Global variables:
*  PGA_B_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
* 
*******************************************************************************/
void PGA_B_Wakeup(void) 
{
    /* Restore the configurations */
    PGA_B_RestoreConfig();
     /* Enables the component operation */
    if(PGA_B_backup.enableState == 1u)
    {
        PGA_B_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
