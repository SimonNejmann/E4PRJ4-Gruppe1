/*******************************************************************************
* File Name: ForW.h  
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

#if !defined(CY_PINS_ForW_ALIASES_H) /* Pins ForW_ALIASES_H */
#define CY_PINS_ForW_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define ForW_0			(ForW__0__PC)
#define ForW_0_PS		(ForW__0__PS)
#define ForW_0_PC		(ForW__0__PC)
#define ForW_0_DR		(ForW__0__DR)
#define ForW_0_SHIFT	(ForW__0__SHIFT)
#define ForW_0_INTR	((uint16)((uint16)0x0003u << (ForW__0__SHIFT*2u)))

#define ForW_INTR_ALL	 ((uint16)(ForW_0_INTR))


#endif /* End Pins ForW_ALIASES_H */


/* [] END OF FILE */
