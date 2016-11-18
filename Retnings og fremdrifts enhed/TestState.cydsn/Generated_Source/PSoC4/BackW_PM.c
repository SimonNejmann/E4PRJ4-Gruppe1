/*******************************************************************************
* File Name: BackW.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "BackW.h"

static BackW_BACKUP_STRUCT  BackW_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: BackW_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function must be called for SIO and USBIO
*  pins. It is not essential if using GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet BackW_SUT.c usage_BackW_Sleep_Wakeup
*******************************************************************************/
void BackW_Sleep(void)
{
    #if defined(BackW__PC)
        BackW_backup.pcState = BackW_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            BackW_backup.usbState = BackW_CR1_REG;
            BackW_USB_POWER_REG |= BackW_USBIO_ENTER_SLEEP;
            BackW_CR1_REG &= BackW_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(BackW__SIO)
        BackW_backup.sioState = BackW_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        BackW_SIO_REG &= (uint32)(~BackW_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: BackW_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep().
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to BackW_Sleep() for an example usage.
*******************************************************************************/
void BackW_Wakeup(void)
{
    #if defined(BackW__PC)
        BackW_PC = BackW_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            BackW_USB_POWER_REG &= BackW_USBIO_EXIT_SLEEP_PH1;
            BackW_CR1_REG = BackW_backup.usbState;
            BackW_USB_POWER_REG &= BackW_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(BackW__SIO)
        BackW_SIO_REG = BackW_backup.sioState;
    #endif
}


/* [] END OF FILE */
