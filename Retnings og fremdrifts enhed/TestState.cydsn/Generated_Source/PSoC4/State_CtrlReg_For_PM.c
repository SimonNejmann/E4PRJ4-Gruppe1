/*******************************************************************************
* File Name: State_CtrlReg_For_PM.c
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

#include "State_CtrlReg_For.h"

/* Check for removal by optimization */
#if !defined(State_CtrlReg_For_Sync_ctrl_reg__REMOVED)

static State_CtrlReg_For_BACKUP_STRUCT  State_CtrlReg_For_backup = {0u};

    
/*******************************************************************************
* Function Name: State_CtrlReg_For_SaveConfig
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
void State_CtrlReg_For_SaveConfig(void) 
{
    State_CtrlReg_For_backup.controlState = State_CtrlReg_For_Control;
}


/*******************************************************************************
* Function Name: State_CtrlReg_For_RestoreConfig
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
void State_CtrlReg_For_RestoreConfig(void) 
{
     State_CtrlReg_For_Control = State_CtrlReg_For_backup.controlState;
}


/*******************************************************************************
* Function Name: State_CtrlReg_For_Sleep
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
void State_CtrlReg_For_Sleep(void) 
{
    State_CtrlReg_For_SaveConfig();
}


/*******************************************************************************
* Function Name: State_CtrlReg_For_Wakeup
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
void State_CtrlReg_For_Wakeup(void)  
{
    State_CtrlReg_For_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
