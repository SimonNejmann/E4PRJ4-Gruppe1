/*******************************************************************************
* File Name: State_CtrlReg_For.h  
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

#if !defined(CY_CONTROL_REG_State_CtrlReg_For_H) /* CY_CONTROL_REG_State_CtrlReg_For_H */
#define CY_CONTROL_REG_State_CtrlReg_For_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} State_CtrlReg_For_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    State_CtrlReg_For_Write(uint8 control) ;
uint8   State_CtrlReg_For_Read(void) ;

void State_CtrlReg_For_SaveConfig(void) ;
void State_CtrlReg_For_RestoreConfig(void) ;
void State_CtrlReg_For_Sleep(void) ; 
void State_CtrlReg_For_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define State_CtrlReg_For_Control        (* (reg8 *) State_CtrlReg_For_Sync_ctrl_reg__CONTROL_REG )
#define State_CtrlReg_For_Control_PTR    (  (reg8 *) State_CtrlReg_For_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_State_CtrlReg_For_H */


/* [] END OF FILE */
