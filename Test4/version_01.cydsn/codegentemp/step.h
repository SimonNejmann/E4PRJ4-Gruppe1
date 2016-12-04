/*******************************************************************************
* File Name: step.h  
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

#if !defined(CY_PINS_step_H) /* Pins step_H */
#define CY_PINS_step_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "step_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 step__PORT == 15 && ((step__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    step_Write(uint8 value);
void    step_SetDriveMode(uint8 mode);
uint8   step_ReadDataReg(void);
uint8   step_Read(void);
void    step_SetInterruptMode(uint16 position, uint16 mode);
uint8   step_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the step_SetDriveMode() function.
     *  @{
     */
        #define step_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define step_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define step_DM_RES_UP          PIN_DM_RES_UP
        #define step_DM_RES_DWN         PIN_DM_RES_DWN
        #define step_DM_OD_LO           PIN_DM_OD_LO
        #define step_DM_OD_HI           PIN_DM_OD_HI
        #define step_DM_STRONG          PIN_DM_STRONG
        #define step_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define step_MASK               step__MASK
#define step_SHIFT              step__SHIFT
#define step_WIDTH              1u

/* Interrupt constants */
#if defined(step__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in step_SetInterruptMode() function.
     *  @{
     */
        #define step_INTR_NONE      (uint16)(0x0000u)
        #define step_INTR_RISING    (uint16)(0x0001u)
        #define step_INTR_FALLING   (uint16)(0x0002u)
        #define step_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define step_INTR_MASK      (0x01u) 
#endif /* (step__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define step_PS                     (* (reg8 *) step__PS)
/* Data Register */
#define step_DR                     (* (reg8 *) step__DR)
/* Port Number */
#define step_PRT_NUM                (* (reg8 *) step__PRT) 
/* Connect to Analog Globals */                                                  
#define step_AG                     (* (reg8 *) step__AG)                       
/* Analog MUX bux enable */
#define step_AMUX                   (* (reg8 *) step__AMUX) 
/* Bidirectional Enable */                                                        
#define step_BIE                    (* (reg8 *) step__BIE)
/* Bit-mask for Aliased Register Access */
#define step_BIT_MASK               (* (reg8 *) step__BIT_MASK)
/* Bypass Enable */
#define step_BYP                    (* (reg8 *) step__BYP)
/* Port wide control signals */                                                   
#define step_CTL                    (* (reg8 *) step__CTL)
/* Drive Modes */
#define step_DM0                    (* (reg8 *) step__DM0) 
#define step_DM1                    (* (reg8 *) step__DM1)
#define step_DM2                    (* (reg8 *) step__DM2) 
/* Input Buffer Disable Override */
#define step_INP_DIS                (* (reg8 *) step__INP_DIS)
/* LCD Common or Segment Drive */
#define step_LCD_COM_SEG            (* (reg8 *) step__LCD_COM_SEG)
/* Enable Segment LCD */
#define step_LCD_EN                 (* (reg8 *) step__LCD_EN)
/* Slew Rate Control */
#define step_SLW                    (* (reg8 *) step__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define step_PRTDSI__CAPS_SEL       (* (reg8 *) step__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define step_PRTDSI__DBL_SYNC_IN    (* (reg8 *) step__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define step_PRTDSI__OE_SEL0        (* (reg8 *) step__PRTDSI__OE_SEL0) 
#define step_PRTDSI__OE_SEL1        (* (reg8 *) step__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define step_PRTDSI__OUT_SEL0       (* (reg8 *) step__PRTDSI__OUT_SEL0) 
#define step_PRTDSI__OUT_SEL1       (* (reg8 *) step__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define step_PRTDSI__SYNC_OUT       (* (reg8 *) step__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(step__SIO_CFG)
    #define step_SIO_HYST_EN        (* (reg8 *) step__SIO_HYST_EN)
    #define step_SIO_REG_HIFREQ     (* (reg8 *) step__SIO_REG_HIFREQ)
    #define step_SIO_CFG            (* (reg8 *) step__SIO_CFG)
    #define step_SIO_DIFF           (* (reg8 *) step__SIO_DIFF)
#endif /* (step__SIO_CFG) */

/* Interrupt Registers */
#if defined(step__INTSTAT)
    #define step_INTSTAT            (* (reg8 *) step__INTSTAT)
    #define step_SNAP               (* (reg8 *) step__SNAP)
    
	#define step_0_INTTYPE_REG 		(* (reg8 *) step__0__INTTYPE)
#endif /* (step__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_step_H */


/* [] END OF FILE */
