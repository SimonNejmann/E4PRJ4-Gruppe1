/*******************************************************************************
* File Name: Dir_step.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Dir_step_H) /* Pins Dir_step_H */
#define CY_PINS_Dir_step_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dir_step_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dir_step__PORT == 15 && ((Dir_step__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dir_step_Write(uint8 value);
void    Dir_step_SetDriveMode(uint8 mode);
uint8   Dir_step_ReadDataReg(void);
uint8   Dir_step_Read(void);
void    Dir_step_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dir_step_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dir_step_SetDriveMode() function.
     *  @{
     */
        #define Dir_step_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dir_step_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dir_step_DM_RES_UP          PIN_DM_RES_UP
        #define Dir_step_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dir_step_DM_OD_LO           PIN_DM_OD_LO
        #define Dir_step_DM_OD_HI           PIN_DM_OD_HI
        #define Dir_step_DM_STRONG          PIN_DM_STRONG
        #define Dir_step_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dir_step_MASK               Dir_step__MASK
#define Dir_step_SHIFT              Dir_step__SHIFT
#define Dir_step_WIDTH              1u

/* Interrupt constants */
#if defined(Dir_step__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dir_step_SetInterruptMode() function.
     *  @{
     */
        #define Dir_step_INTR_NONE      (uint16)(0x0000u)
        #define Dir_step_INTR_RISING    (uint16)(0x0001u)
        #define Dir_step_INTR_FALLING   (uint16)(0x0002u)
        #define Dir_step_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dir_step_INTR_MASK      (0x01u) 
#endif /* (Dir_step__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dir_step_PS                     (* (reg8 *) Dir_step__PS)
/* Data Register */
#define Dir_step_DR                     (* (reg8 *) Dir_step__DR)
/* Port Number */
#define Dir_step_PRT_NUM                (* (reg8 *) Dir_step__PRT) 
/* Connect to Analog Globals */                                                  
#define Dir_step_AG                     (* (reg8 *) Dir_step__AG)                       
/* Analog MUX bux enable */
#define Dir_step_AMUX                   (* (reg8 *) Dir_step__AMUX) 
/* Bidirectional Enable */                                                        
#define Dir_step_BIE                    (* (reg8 *) Dir_step__BIE)
/* Bit-mask for Aliased Register Access */
#define Dir_step_BIT_MASK               (* (reg8 *) Dir_step__BIT_MASK)
/* Bypass Enable */
#define Dir_step_BYP                    (* (reg8 *) Dir_step__BYP)
/* Port wide control signals */                                                   
#define Dir_step_CTL                    (* (reg8 *) Dir_step__CTL)
/* Drive Modes */
#define Dir_step_DM0                    (* (reg8 *) Dir_step__DM0) 
#define Dir_step_DM1                    (* (reg8 *) Dir_step__DM1)
#define Dir_step_DM2                    (* (reg8 *) Dir_step__DM2) 
/* Input Buffer Disable Override */
#define Dir_step_INP_DIS                (* (reg8 *) Dir_step__INP_DIS)
/* LCD Common or Segment Drive */
#define Dir_step_LCD_COM_SEG            (* (reg8 *) Dir_step__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dir_step_LCD_EN                 (* (reg8 *) Dir_step__LCD_EN)
/* Slew Rate Control */
#define Dir_step_SLW                    (* (reg8 *) Dir_step__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dir_step_PRTDSI__CAPS_SEL       (* (reg8 *) Dir_step__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dir_step_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dir_step__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dir_step_PRTDSI__OE_SEL0        (* (reg8 *) Dir_step__PRTDSI__OE_SEL0) 
#define Dir_step_PRTDSI__OE_SEL1        (* (reg8 *) Dir_step__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dir_step_PRTDSI__OUT_SEL0       (* (reg8 *) Dir_step__PRTDSI__OUT_SEL0) 
#define Dir_step_PRTDSI__OUT_SEL1       (* (reg8 *) Dir_step__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dir_step_PRTDSI__SYNC_OUT       (* (reg8 *) Dir_step__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dir_step__SIO_CFG)
    #define Dir_step_SIO_HYST_EN        (* (reg8 *) Dir_step__SIO_HYST_EN)
    #define Dir_step_SIO_REG_HIFREQ     (* (reg8 *) Dir_step__SIO_REG_HIFREQ)
    #define Dir_step_SIO_CFG            (* (reg8 *) Dir_step__SIO_CFG)
    #define Dir_step_SIO_DIFF           (* (reg8 *) Dir_step__SIO_DIFF)
#endif /* (Dir_step__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dir_step__INTSTAT)
    #define Dir_step_INTSTAT            (* (reg8 *) Dir_step__INTSTAT)
    #define Dir_step_SNAP               (* (reg8 *) Dir_step__SNAP)
    
	#define Dir_step_0_INTTYPE_REG 		(* (reg8 *) Dir_step__0__INTTYPE)
#endif /* (Dir_step__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dir_step_H */


/* [] END OF FILE */
