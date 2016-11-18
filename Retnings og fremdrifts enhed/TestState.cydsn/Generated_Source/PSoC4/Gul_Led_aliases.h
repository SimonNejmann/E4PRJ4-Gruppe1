/*******************************************************************************
* File Name: Gul_Led.h  
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

#if !defined(CY_PINS_Gul_Led_ALIASES_H) /* Pins Gul_Led_ALIASES_H */
#define CY_PINS_Gul_Led_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Gul_Led_0			(Gul_Led__0__PC)
#define Gul_Led_0_PS		(Gul_Led__0__PS)
#define Gul_Led_0_PC		(Gul_Led__0__PC)
#define Gul_Led_0_DR		(Gul_Led__0__DR)
#define Gul_Led_0_SHIFT	(Gul_Led__0__SHIFT)
#define Gul_Led_0_INTR	((uint16)((uint16)0x0003u << (Gul_Led__0__SHIFT*2u)))

#define Gul_Led_INTR_ALL	 ((uint16)(Gul_Led_0_INTR))


#endif /* End Pins Gul_Led_ALIASES_H */


/* [] END OF FILE */
