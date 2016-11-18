/*******************************************************************************
* File Name: State_Retning_PM.c
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

#include "State_Retning.h"

/* Check for removal by optimization */
#if !defined(State_Retning_Sync_ctrl_reg__REMOVED)

static State_Retning_BACKUP_STRUCT  State_Retning_backup = {0u};

    
/*******************************************************************************
* Function Name: State_Retning_SaveConfig
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
void State_Retning_SaveConfig(void) 
{
    State_Retning_backup.controlState = State_Retning_Control;
}


/*******************************************************************************
* Function Name: State_Retning_RestoreConfig
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
void State_Retning_RestoreConfig(void) 
{
     State_Retning_Control = State_Retning_backup.controlState;
}


/*******************************************************************************
* Function Name: State_Retning_Sleep
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
void State_Retning_Sleep(void) 
{
    State_Retning_SaveConfig();
}


/*******************************************************************************
* Function Name: State_Retning_Wakeup
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
void State_Retning_Wakeup(void)  
{
    State_Retning_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
