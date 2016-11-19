/*******************************************************************************
* File Name: State_3_CtrlReg_Run.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_State_3_CtrlReg_Run_H) /* CY_CONTROL_REG_State_3_CtrlReg_Run_H */
#define CY_CONTROL_REG_State_3_CtrlReg_Run_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} State_3_CtrlReg_Run_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    State_3_CtrlReg_Run_Write(uint8 control) ;
uint8   State_3_CtrlReg_Run_Read(void) ;

void State_3_CtrlReg_Run_SaveConfig(void) ;
void State_3_CtrlReg_Run_RestoreConfig(void) ;
void State_3_CtrlReg_Run_Sleep(void) ; 
void State_3_CtrlReg_Run_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define State_3_CtrlReg_Run_Control        (* (reg8 *) State_3_CtrlReg_Run_Sync_ctrl_reg__CONTROL_REG )
#define State_3_CtrlReg_Run_Control_PTR    (  (reg8 *) State_3_CtrlReg_Run_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_State_3_CtrlReg_Run_H */


/* [] END OF FILE */
