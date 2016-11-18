/*******************************************************************************
* File Name: BackW.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_BackW_ALIASES_H) /* Pins BackW_ALIASES_H */
#define CY_PINS_BackW_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define BackW_0			(BackW__0__PC)
#define BackW_0_PS		(BackW__0__PS)
#define BackW_0_PC		(BackW__0__PC)
#define BackW_0_DR		(BackW__0__DR)
#define BackW_0_SHIFT	(BackW__0__SHIFT)
#define BackW_0_INTR	((uint16)((uint16)0x0003u << (BackW__0__SHIFT*2u)))

#define BackW_INTR_ALL	 ((uint16)(BackW_0_INTR))


#endif /* End Pins BackW_ALIASES_H */


/* [] END OF FILE */
