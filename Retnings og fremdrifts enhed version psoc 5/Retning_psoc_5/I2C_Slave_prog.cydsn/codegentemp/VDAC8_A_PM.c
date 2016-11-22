/*******************************************************************************
* File Name: VDAC8_A_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "VDAC8_A.h"

static VDAC8_A_backupStruct VDAC8_A_backup;


/*******************************************************************************
* Function Name: VDAC8_A_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void VDAC8_A_SaveConfig(void) 
{
    if (!((VDAC8_A_CR1 & VDAC8_A_SRC_MASK) == VDAC8_A_SRC_UDB))
    {
        VDAC8_A_backup.data_value = VDAC8_A_Data;
    }
}


/*******************************************************************************
* Function Name: VDAC8_A_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void VDAC8_A_RestoreConfig(void) 
{
    if (!((VDAC8_A_CR1 & VDAC8_A_SRC_MASK) == VDAC8_A_SRC_UDB))
    {
        if((VDAC8_A_Strobe & VDAC8_A_STRB_MASK) == VDAC8_A_STRB_EN)
        {
            VDAC8_A_Strobe &= (uint8)(~VDAC8_A_STRB_MASK);
            VDAC8_A_Data = VDAC8_A_backup.data_value;
            VDAC8_A_Strobe |= VDAC8_A_STRB_EN;
        }
        else
        {
            VDAC8_A_Data = VDAC8_A_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: VDAC8_A_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  VDAC8_A_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void VDAC8_A_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(VDAC8_A_ACT_PWR_EN == (VDAC8_A_PWRMGR & VDAC8_A_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        VDAC8_A_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        VDAC8_A_backup.enableState = 0u;
    }
    
    VDAC8_A_Stop();
    VDAC8_A_SaveConfig();
}


/*******************************************************************************
* Function Name: VDAC8_A_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  VDAC8_A_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VDAC8_A_Wakeup(void) 
{
    VDAC8_A_RestoreConfig();
    
    if(VDAC8_A_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        VDAC8_A_Enable();

        /* Restore the data register */
        VDAC8_A_SetValue(VDAC8_A_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
