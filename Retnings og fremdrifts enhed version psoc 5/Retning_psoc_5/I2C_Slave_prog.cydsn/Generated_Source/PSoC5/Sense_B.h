/*******************************************************************************
* File Name: Sense_B.h  
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

#if !defined(CY_PINS_Sense_B_H) /* Pins Sense_B_H */
#define CY_PINS_Sense_B_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sense_B_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sense_B__PORT == 15 && ((Sense_B__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sense_B_Write(uint8 value);
void    Sense_B_SetDriveMode(uint8 mode);
uint8   Sense_B_ReadDataReg(void);
uint8   Sense_B_Read(void);
void    Sense_B_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sense_B_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sense_B_SetDriveMode() function.
     *  @{
     */
        #define Sense_B_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sense_B_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sense_B_DM_RES_UP          PIN_DM_RES_UP
        #define Sense_B_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sense_B_DM_OD_LO           PIN_DM_OD_LO
        #define Sense_B_DM_OD_HI           PIN_DM_OD_HI
        #define Sense_B_DM_STRONG          PIN_DM_STRONG
        #define Sense_B_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sense_B_MASK               Sense_B__MASK
#define Sense_B_SHIFT              Sense_B__SHIFT
#define Sense_B_WIDTH              1u

/* Interrupt constants */
#if defined(Sense_B__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sense_B_SetInterruptMode() function.
     *  @{
     */
        #define Sense_B_INTR_NONE      (uint16)(0x0000u)
        #define Sense_B_INTR_RISING    (uint16)(0x0001u)
        #define Sense_B_INTR_FALLING   (uint16)(0x0002u)
        #define Sense_B_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sense_B_INTR_MASK      (0x01u) 
#endif /* (Sense_B__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sense_B_PS                     (* (reg8 *) Sense_B__PS)
/* Data Register */
#define Sense_B_DR                     (* (reg8 *) Sense_B__DR)
/* Port Number */
#define Sense_B_PRT_NUM                (* (reg8 *) Sense_B__PRT) 
/* Connect to Analog Globals */                                                  
#define Sense_B_AG                     (* (reg8 *) Sense_B__AG)                       
/* Analog MUX bux enable */
#define Sense_B_AMUX                   (* (reg8 *) Sense_B__AMUX) 
/* Bidirectional Enable */                                                        
#define Sense_B_BIE                    (* (reg8 *) Sense_B__BIE)
/* Bit-mask for Aliased Register Access */
#define Sense_B_BIT_MASK               (* (reg8 *) Sense_B__BIT_MASK)
/* Bypass Enable */
#define Sense_B_BYP                    (* (reg8 *) Sense_B__BYP)
/* Port wide control signals */                                                   
#define Sense_B_CTL                    (* (reg8 *) Sense_B__CTL)
/* Drive Modes */
#define Sense_B_DM0                    (* (reg8 *) Sense_B__DM0) 
#define Sense_B_DM1                    (* (reg8 *) Sense_B__DM1)
#define Sense_B_DM2                    (* (reg8 *) Sense_B__DM2) 
/* Input Buffer Disable Override */
#define Sense_B_INP_DIS                (* (reg8 *) Sense_B__INP_DIS)
/* LCD Common or Segment Drive */
#define Sense_B_LCD_COM_SEG            (* (reg8 *) Sense_B__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sense_B_LCD_EN                 (* (reg8 *) Sense_B__LCD_EN)
/* Slew Rate Control */
#define Sense_B_SLW                    (* (reg8 *) Sense_B__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sense_B_PRTDSI__CAPS_SEL       (* (reg8 *) Sense_B__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sense_B_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sense_B__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sense_B_PRTDSI__OE_SEL0        (* (reg8 *) Sense_B__PRTDSI__OE_SEL0) 
#define Sense_B_PRTDSI__OE_SEL1        (* (reg8 *) Sense_B__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sense_B_PRTDSI__OUT_SEL0       (* (reg8 *) Sense_B__PRTDSI__OUT_SEL0) 
#define Sense_B_PRTDSI__OUT_SEL1       (* (reg8 *) Sense_B__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sense_B_PRTDSI__SYNC_OUT       (* (reg8 *) Sense_B__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sense_B__SIO_CFG)
    #define Sense_B_SIO_HYST_EN        (* (reg8 *) Sense_B__SIO_HYST_EN)
    #define Sense_B_SIO_REG_HIFREQ     (* (reg8 *) Sense_B__SIO_REG_HIFREQ)
    #define Sense_B_SIO_CFG            (* (reg8 *) Sense_B__SIO_CFG)
    #define Sense_B_SIO_DIFF           (* (reg8 *) Sense_B__SIO_DIFF)
#endif /* (Sense_B__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sense_B__INTSTAT)
    #define Sense_B_INTSTAT            (* (reg8 *) Sense_B__INTSTAT)
    #define Sense_B_SNAP               (* (reg8 *) Sense_B__SNAP)
    
	#define Sense_B_0_INTTYPE_REG 		(* (reg8 *) Sense_B__0__INTTYPE)
#endif /* (Sense_B__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sense_B_H */


/* [] END OF FILE */
