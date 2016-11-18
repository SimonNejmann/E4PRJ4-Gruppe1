/*******************************************************************************
* File Name: State_CtrlReg_1_PM.c
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

#include "State_CtrlReg_1.h"

/* Check for removal by optimization */
#if !defined(State_CtrlReg_1_Sync_ctrl_reg__REMOVED)

static State_CtrlReg_1_BACKUP_STRUCT  State_CtrlReg_1_backup = {0u};

    
/*******************************************************************************
* Function Name: State_CtrlReg_1_SaveConfig
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
void State_CtrlReg_1_SaveConfig(void) 
{
    State_CtrlReg_1_backup.controlState = State_CtrlReg_1_Control;
}


/*******************************************************************************
* Function Name: State_CtrlReg_1_RestoreConfig
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
void State_CtrlReg_1_RestoreConfig(void) 
{
     State_CtrlReg_1_Control = State_CtrlReg_1_backup.controlState;
}


/*******************************************************************************
* Function Name: State_CtrlReg_1_Sleep
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
void State_CtrlReg_1_Sleep(void) 
{
    State_CtrlReg_1_SaveConfig();
}


/*******************************************************************************
* Function Name: State_CtrlReg_1_Wakeup
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
void State_CtrlReg_1_Wakeup(void)  
{
    State_CtrlReg_1_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
