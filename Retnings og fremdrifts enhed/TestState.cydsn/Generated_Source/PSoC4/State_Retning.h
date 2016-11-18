/*******************************************************************************
* File Name: State_Retning.h  
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

#if !defined(CY_CONTROL_REG_State_Retning_H) /* CY_CONTROL_REG_State_Retning_H */
#define CY_CONTROL_REG_State_Retning_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} State_Retning_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    State_Retning_Write(uint8 control) ;
uint8   State_Retning_Read(void) ;

void State_Retning_SaveConfig(void) ;
void State_Retning_RestoreConfig(void) ;
void State_Retning_Sleep(void) ; 
void State_Retning_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define State_Retning_Control        (* (reg8 *) State_Retning_Sync_ctrl_reg__CONTROL_REG )
#define State_Retning_Control_PTR    (  (reg8 *) State_Retning_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_State_Retning_H */


/* [] END OF FILE */
