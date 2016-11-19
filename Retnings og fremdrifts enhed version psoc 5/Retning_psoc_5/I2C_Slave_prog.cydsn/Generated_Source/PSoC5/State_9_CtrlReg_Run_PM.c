/*******************************************************************************
* File Name: State_9_CtrlReg_Run_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "State_9_CtrlReg_Run.h"

/* Check for removal by optimization */
#if !defined(State_9_CtrlReg_Run_Sync_ctrl_reg__REMOVED)

static State_9_CtrlReg_Run_BACKUP_STRUCT  State_9_CtrlReg_Run_backup = {0u};

    
/*******************************************************************************
* Function Name: State_9_CtrlReg_Run_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void State_9_CtrlReg_Run_SaveConfig(void) 
{
    State_9_CtrlReg_Run_backup.controlState = State_9_CtrlReg_Run_Control;
}


/*******************************************************************************
* Function Name: State_9_CtrlReg_Run_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void State_9_CtrlReg_Run_RestoreConfig(void) 
{
     State_9_CtrlReg_Run_Control = State_9_CtrlReg_Run_backup.controlState;
}


/*******************************************************************************
* Function Name: State_9_CtrlReg_Run_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void State_9_CtrlReg_Run_Sleep(void) 
{
    State_9_CtrlReg_Run_SaveConfig();
}


/*******************************************************************************
* Function Name: State_9_CtrlReg_Run_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void State_9_CtrlReg_Run_Wakeup(void)  
{
    State_9_CtrlReg_Run_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
