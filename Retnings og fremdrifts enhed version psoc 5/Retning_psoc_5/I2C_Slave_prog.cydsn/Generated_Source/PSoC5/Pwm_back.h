/*******************************************************************************
* File Name: Pwm_back.h  
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

#if !defined(CY_PINS_Pwm_back_H) /* Pins Pwm_back_H */
#define CY_PINS_Pwm_back_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Pwm_back_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Pwm_back__PORT == 15 && ((Pwm_back__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Pwm_back_Write(uint8 value);
void    Pwm_back_SetDriveMode(uint8 mode);
uint8   Pwm_back_ReadDataReg(void);
uint8   Pwm_back_Read(void);
void    Pwm_back_SetInterruptMode(uint16 position, uint16 mode);
uint8   Pwm_back_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Pwm_back_SetDriveMode() function.
     *  @{
     */
        #define Pwm_back_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Pwm_back_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Pwm_back_DM_RES_UP          PIN_DM_RES_UP
        #define Pwm_back_DM_RES_DWN         PIN_DM_RES_DWN
        #define Pwm_back_DM_OD_LO           PIN_DM_OD_LO
        #define Pwm_back_DM_OD_HI           PIN_DM_OD_HI
        #define Pwm_back_DM_STRONG          PIN_DM_STRONG
        #define Pwm_back_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Pwm_back_MASK               Pwm_back__MASK
#define Pwm_back_SHIFT              Pwm_back__SHIFT
#define Pwm_back_WIDTH              1u

/* Interrupt constants */
#if defined(Pwm_back__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Pwm_back_SetInterruptMode() function.
     *  @{
     */
        #define Pwm_back_INTR_NONE      (uint16)(0x0000u)
        #define Pwm_back_INTR_RISING    (uint16)(0x0001u)
        #define Pwm_back_INTR_FALLING   (uint16)(0x0002u)
        #define Pwm_back_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Pwm_back_INTR_MASK      (0x01u) 
#endif /* (Pwm_back__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Pwm_back_PS                     (* (reg8 *) Pwm_back__PS)
/* Data Register */
#define Pwm_back_DR                     (* (reg8 *) Pwm_back__DR)
/* Port Number */
#define Pwm_back_PRT_NUM                (* (reg8 *) Pwm_back__PRT) 
/* Connect to Analog Globals */                                                  
#define Pwm_back_AG                     (* (reg8 *) Pwm_back__AG)                       
/* Analog MUX bux enable */
#define Pwm_back_AMUX                   (* (reg8 *) Pwm_back__AMUX) 
/* Bidirectional Enable */                                                        
#define Pwm_back_BIE                    (* (reg8 *) Pwm_back__BIE)
/* Bit-mask for Aliased Register Access */
#define Pwm_back_BIT_MASK               (* (reg8 *) Pwm_back__BIT_MASK)
/* Bypass Enable */
#define Pwm_back_BYP                    (* (reg8 *) Pwm_back__BYP)
/* Port wide control signals */                                                   
#define Pwm_back_CTL                    (* (reg8 *) Pwm_back__CTL)
/* Drive Modes */
#define Pwm_back_DM0                    (* (reg8 *) Pwm_back__DM0) 
#define Pwm_back_DM1                    (* (reg8 *) Pwm_back__DM1)
#define Pwm_back_DM2                    (* (reg8 *) Pwm_back__DM2) 
/* Input Buffer Disable Override */
#define Pwm_back_INP_DIS                (* (reg8 *) Pwm_back__INP_DIS)
/* LCD Common or Segment Drive */
#define Pwm_back_LCD_COM_SEG            (* (reg8 *) Pwm_back__LCD_COM_SEG)
/* Enable Segment LCD */
#define Pwm_back_LCD_EN                 (* (reg8 *) Pwm_back__LCD_EN)
/* Slew Rate Control */
#define Pwm_back_SLW                    (* (reg8 *) Pwm_back__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Pwm_back_PRTDSI__CAPS_SEL       (* (reg8 *) Pwm_back__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Pwm_back_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Pwm_back__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Pwm_back_PRTDSI__OE_SEL0        (* (reg8 *) Pwm_back__PRTDSI__OE_SEL0) 
#define Pwm_back_PRTDSI__OE_SEL1        (* (reg8 *) Pwm_back__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Pwm_back_PRTDSI__OUT_SEL0       (* (reg8 *) Pwm_back__PRTDSI__OUT_SEL0) 
#define Pwm_back_PRTDSI__OUT_SEL1       (* (reg8 *) Pwm_back__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Pwm_back_PRTDSI__SYNC_OUT       (* (reg8 *) Pwm_back__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Pwm_back__SIO_CFG)
    #define Pwm_back_SIO_HYST_EN        (* (reg8 *) Pwm_back__SIO_HYST_EN)
    #define Pwm_back_SIO_REG_HIFREQ     (* (reg8 *) Pwm_back__SIO_REG_HIFREQ)
    #define Pwm_back_SIO_CFG            (* (reg8 *) Pwm_back__SIO_CFG)
    #define Pwm_back_SIO_DIFF           (* (reg8 *) Pwm_back__SIO_DIFF)
#endif /* (Pwm_back__SIO_CFG) */

/* Interrupt Registers */
#if defined(Pwm_back__INTSTAT)
    #define Pwm_back_INTSTAT            (* (reg8 *) Pwm_back__INTSTAT)
    #define Pwm_back_SNAP               (* (reg8 *) Pwm_back__SNAP)
    
	#define Pwm_back_0_INTTYPE_REG 		(* (reg8 *) Pwm_back__0__INTTYPE)
#endif /* (Pwm_back__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Pwm_back_H */


/* [] END OF FILE */
