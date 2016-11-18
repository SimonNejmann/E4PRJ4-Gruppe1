#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

/* A */
#define A__0__DM__MASK 0x07u
#define A__0__DM__SHIFT 0u
#define A__0__DR CYREG_PRT2_DR
#define A__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define A__0__HSIOM_MASK 0x0000000Fu
#define A__0__HSIOM_SHIFT 0u
#define A__0__INTCFG CYREG_PRT2_INTCFG
#define A__0__INTSTAT CYREG_PRT2_INTSTAT
#define A__0__MASK 0x01u
#define A__0__OUT_SEL CYREG_UDB_PA2_CFG10
#define A__0__OUT_SEL_SHIFT 0u
#define A__0__OUT_SEL_VAL 3u
#define A__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define A__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define A__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define A__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define A__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define A__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define A__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define A__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define A__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define A__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define A__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define A__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define A__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define A__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define A__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define A__0__PC CYREG_PRT2_PC
#define A__0__PC2 CYREG_PRT2_PC2
#define A__0__PORT 2u
#define A__0__PS CYREG_PRT2_PS
#define A__0__SHIFT 0u
#define A__DR CYREG_PRT2_DR
#define A__INTCFG CYREG_PRT2_INTCFG
#define A__INTSTAT CYREG_PRT2_INTSTAT
#define A__MASK 0x01u
#define A__PA__CFG0 CYREG_UDB_PA2_CFG0
#define A__PA__CFG1 CYREG_UDB_PA2_CFG1
#define A__PA__CFG10 CYREG_UDB_PA2_CFG10
#define A__PA__CFG11 CYREG_UDB_PA2_CFG11
#define A__PA__CFG12 CYREG_UDB_PA2_CFG12
#define A__PA__CFG13 CYREG_UDB_PA2_CFG13
#define A__PA__CFG14 CYREG_UDB_PA2_CFG14
#define A__PA__CFG2 CYREG_UDB_PA2_CFG2
#define A__PA__CFG3 CYREG_UDB_PA2_CFG3
#define A__PA__CFG4 CYREG_UDB_PA2_CFG4
#define A__PA__CFG5 CYREG_UDB_PA2_CFG5
#define A__PA__CFG6 CYREG_UDB_PA2_CFG6
#define A__PA__CFG7 CYREG_UDB_PA2_CFG7
#define A__PA__CFG8 CYREG_UDB_PA2_CFG8
#define A__PA__CFG9 CYREG_UDB_PA2_CFG9
#define A__PC CYREG_PRT2_PC
#define A__PC2 CYREG_PRT2_PC2
#define A__PORT 2u
#define A__PS CYREG_PRT2_PS
#define A__SHIFT 0u

/* B */
#define B__0__DM__MASK 0x38u
#define B__0__DM__SHIFT 3u
#define B__0__DR CYREG_PRT2_DR
#define B__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define B__0__HSIOM_MASK 0x000000F0u
#define B__0__HSIOM_SHIFT 4u
#define B__0__INTCFG CYREG_PRT2_INTCFG
#define B__0__INTSTAT CYREG_PRT2_INTSTAT
#define B__0__MASK 0x02u
#define B__0__OUT_SEL CYREG_UDB_PA2_CFG10
#define B__0__OUT_SEL_SHIFT 2u
#define B__0__OUT_SEL_VAL 0u
#define B__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define B__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define B__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define B__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define B__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define B__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define B__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define B__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define B__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define B__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define B__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define B__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define B__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define B__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define B__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define B__0__PC CYREG_PRT2_PC
#define B__0__PC2 CYREG_PRT2_PC2
#define B__0__PORT 2u
#define B__0__PS CYREG_PRT2_PS
#define B__0__SHIFT 1u
#define B__DR CYREG_PRT2_DR
#define B__INTCFG CYREG_PRT2_INTCFG
#define B__INTSTAT CYREG_PRT2_INTSTAT
#define B__MASK 0x02u
#define B__PA__CFG0 CYREG_UDB_PA2_CFG0
#define B__PA__CFG1 CYREG_UDB_PA2_CFG1
#define B__PA__CFG10 CYREG_UDB_PA2_CFG10
#define B__PA__CFG11 CYREG_UDB_PA2_CFG11
#define B__PA__CFG12 CYREG_UDB_PA2_CFG12
#define B__PA__CFG13 CYREG_UDB_PA2_CFG13
#define B__PA__CFG14 CYREG_UDB_PA2_CFG14
#define B__PA__CFG2 CYREG_UDB_PA2_CFG2
#define B__PA__CFG3 CYREG_UDB_PA2_CFG3
#define B__PA__CFG4 CYREG_UDB_PA2_CFG4
#define B__PA__CFG5 CYREG_UDB_PA2_CFG5
#define B__PA__CFG6 CYREG_UDB_PA2_CFG6
#define B__PA__CFG7 CYREG_UDB_PA2_CFG7
#define B__PA__CFG8 CYREG_UDB_PA2_CFG8
#define B__PA__CFG9 CYREG_UDB_PA2_CFG9
#define B__PC CYREG_PRT2_PC
#define B__PC2 CYREG_PRT2_PC2
#define B__PORT 2u
#define B__PS CYREG_PRT2_PS
#define B__SHIFT 1u

/* C */
#define C__0__DM__MASK 0x1C0u
#define C__0__DM__SHIFT 6u
#define C__0__DR CYREG_PRT2_DR
#define C__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define C__0__HSIOM_MASK 0x00000F00u
#define C__0__HSIOM_SHIFT 8u
#define C__0__INTCFG CYREG_PRT2_INTCFG
#define C__0__INTSTAT CYREG_PRT2_INTSTAT
#define C__0__MASK 0x04u
#define C__0__OUT_SEL CYREG_UDB_PA2_CFG10
#define C__0__OUT_SEL_SHIFT 4u
#define C__0__OUT_SEL_VAL 1u
#define C__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define C__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define C__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define C__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define C__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define C__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define C__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define C__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define C__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define C__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define C__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define C__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define C__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define C__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define C__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define C__0__PC CYREG_PRT2_PC
#define C__0__PC2 CYREG_PRT2_PC2
#define C__0__PORT 2u
#define C__0__PS CYREG_PRT2_PS
#define C__0__SHIFT 2u
#define C__DR CYREG_PRT2_DR
#define C__INTCFG CYREG_PRT2_INTCFG
#define C__INTSTAT CYREG_PRT2_INTSTAT
#define C__MASK 0x04u
#define C__PA__CFG0 CYREG_UDB_PA2_CFG0
#define C__PA__CFG1 CYREG_UDB_PA2_CFG1
#define C__PA__CFG10 CYREG_UDB_PA2_CFG10
#define C__PA__CFG11 CYREG_UDB_PA2_CFG11
#define C__PA__CFG12 CYREG_UDB_PA2_CFG12
#define C__PA__CFG13 CYREG_UDB_PA2_CFG13
#define C__PA__CFG14 CYREG_UDB_PA2_CFG14
#define C__PA__CFG2 CYREG_UDB_PA2_CFG2
#define C__PA__CFG3 CYREG_UDB_PA2_CFG3
#define C__PA__CFG4 CYREG_UDB_PA2_CFG4
#define C__PA__CFG5 CYREG_UDB_PA2_CFG5
#define C__PA__CFG6 CYREG_UDB_PA2_CFG6
#define C__PA__CFG7 CYREG_UDB_PA2_CFG7
#define C__PA__CFG8 CYREG_UDB_PA2_CFG8
#define C__PA__CFG9 CYREG_UDB_PA2_CFG9
#define C__PC CYREG_PRT2_PC
#define C__PC2 CYREG_PRT2_PC2
#define C__PORT 2u
#define C__PS CYREG_PRT2_PS
#define C__SHIFT 2u

/* D */
#define D__0__DM__MASK 0xE00u
#define D__0__DM__SHIFT 9u
#define D__0__DR CYREG_PRT2_DR
#define D__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define D__0__HSIOM_MASK 0x0000F000u
#define D__0__HSIOM_SHIFT 12u
#define D__0__INTCFG CYREG_PRT2_INTCFG
#define D__0__INTSTAT CYREG_PRT2_INTSTAT
#define D__0__MASK 0x08u
#define D__0__OUT_SEL CYREG_UDB_PA2_CFG10
#define D__0__OUT_SEL_SHIFT 6u
#define D__0__OUT_SEL_VAL 2u
#define D__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define D__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define D__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define D__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define D__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define D__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define D__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define D__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define D__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define D__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define D__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define D__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define D__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define D__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define D__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define D__0__PC CYREG_PRT2_PC
#define D__0__PC2 CYREG_PRT2_PC2
#define D__0__PORT 2u
#define D__0__PS CYREG_PRT2_PS
#define D__0__SHIFT 3u
#define D__DR CYREG_PRT2_DR
#define D__INTCFG CYREG_PRT2_INTCFG
#define D__INTSTAT CYREG_PRT2_INTSTAT
#define D__MASK 0x08u
#define D__PA__CFG0 CYREG_UDB_PA2_CFG0
#define D__PA__CFG1 CYREG_UDB_PA2_CFG1
#define D__PA__CFG10 CYREG_UDB_PA2_CFG10
#define D__PA__CFG11 CYREG_UDB_PA2_CFG11
#define D__PA__CFG12 CYREG_UDB_PA2_CFG12
#define D__PA__CFG13 CYREG_UDB_PA2_CFG13
#define D__PA__CFG14 CYREG_UDB_PA2_CFG14
#define D__PA__CFG2 CYREG_UDB_PA2_CFG2
#define D__PA__CFG3 CYREG_UDB_PA2_CFG3
#define D__PA__CFG4 CYREG_UDB_PA2_CFG4
#define D__PA__CFG5 CYREG_UDB_PA2_CFG5
#define D__PA__CFG6 CYREG_UDB_PA2_CFG6
#define D__PA__CFG7 CYREG_UDB_PA2_CFG7
#define D__PA__CFG8 CYREG_UDB_PA2_CFG8
#define D__PA__CFG9 CYREG_UDB_PA2_CFG9
#define D__PC CYREG_PRT2_PC
#define D__PC2 CYREG_PRT2_PC2
#define D__PORT 2u
#define D__PS CYREG_PRT2_PS
#define D__SHIFT 3u

/* I2CS_SCB */
#define I2CS_SCB__BIST_CONTROL CYREG_SCB1_BIST_CONTROL
#define I2CS_SCB__BIST_DATA CYREG_SCB1_BIST_DATA
#define I2CS_SCB__CTRL CYREG_SCB1_CTRL
#define I2CS_SCB__EZ_DATA00 CYREG_SCB1_EZ_DATA00
#define I2CS_SCB__EZ_DATA01 CYREG_SCB1_EZ_DATA01
#define I2CS_SCB__EZ_DATA02 CYREG_SCB1_EZ_DATA02
#define I2CS_SCB__EZ_DATA03 CYREG_SCB1_EZ_DATA03
#define I2CS_SCB__EZ_DATA04 CYREG_SCB1_EZ_DATA04
#define I2CS_SCB__EZ_DATA05 CYREG_SCB1_EZ_DATA05
#define I2CS_SCB__EZ_DATA06 CYREG_SCB1_EZ_DATA06
#define I2CS_SCB__EZ_DATA07 CYREG_SCB1_EZ_DATA07
#define I2CS_SCB__EZ_DATA08 CYREG_SCB1_EZ_DATA08
#define I2CS_SCB__EZ_DATA09 CYREG_SCB1_EZ_DATA09
#define I2CS_SCB__EZ_DATA10 CYREG_SCB1_EZ_DATA10
#define I2CS_SCB__EZ_DATA11 CYREG_SCB1_EZ_DATA11
#define I2CS_SCB__EZ_DATA12 CYREG_SCB1_EZ_DATA12
#define I2CS_SCB__EZ_DATA13 CYREG_SCB1_EZ_DATA13
#define I2CS_SCB__EZ_DATA14 CYREG_SCB1_EZ_DATA14
#define I2CS_SCB__EZ_DATA15 CYREG_SCB1_EZ_DATA15
#define I2CS_SCB__EZ_DATA16 CYREG_SCB1_EZ_DATA16
#define I2CS_SCB__EZ_DATA17 CYREG_SCB1_EZ_DATA17
#define I2CS_SCB__EZ_DATA18 CYREG_SCB1_EZ_DATA18
#define I2CS_SCB__EZ_DATA19 CYREG_SCB1_EZ_DATA19
#define I2CS_SCB__EZ_DATA20 CYREG_SCB1_EZ_DATA20
#define I2CS_SCB__EZ_DATA21 CYREG_SCB1_EZ_DATA21
#define I2CS_SCB__EZ_DATA22 CYREG_SCB1_EZ_DATA22
#define I2CS_SCB__EZ_DATA23 CYREG_SCB1_EZ_DATA23
#define I2CS_SCB__EZ_DATA24 CYREG_SCB1_EZ_DATA24
#define I2CS_SCB__EZ_DATA25 CYREG_SCB1_EZ_DATA25
#define I2CS_SCB__EZ_DATA26 CYREG_SCB1_EZ_DATA26
#define I2CS_SCB__EZ_DATA27 CYREG_SCB1_EZ_DATA27
#define I2CS_SCB__EZ_DATA28 CYREG_SCB1_EZ_DATA28
#define I2CS_SCB__EZ_DATA29 CYREG_SCB1_EZ_DATA29
#define I2CS_SCB__EZ_DATA30 CYREG_SCB1_EZ_DATA30
#define I2CS_SCB__EZ_DATA31 CYREG_SCB1_EZ_DATA31
#define I2CS_SCB__I2C_CFG CYREG_SCB1_I2C_CFG
#define I2CS_SCB__I2C_CTRL CYREG_SCB1_I2C_CTRL
#define I2CS_SCB__I2C_M_CMD CYREG_SCB1_I2C_M_CMD
#define I2CS_SCB__I2C_S_CMD CYREG_SCB1_I2C_S_CMD
#define I2CS_SCB__I2C_STATUS CYREG_SCB1_I2C_STATUS
#define I2CS_SCB__INTR_CAUSE CYREG_SCB1_INTR_CAUSE
#define I2CS_SCB__INTR_I2C_EC CYREG_SCB1_INTR_I2C_EC
#define I2CS_SCB__INTR_I2C_EC_MASK CYREG_SCB1_INTR_I2C_EC_MASK
#define I2CS_SCB__INTR_I2C_EC_MASKED CYREG_SCB1_INTR_I2C_EC_MASKED
#define I2CS_SCB__INTR_M CYREG_SCB1_INTR_M
#define I2CS_SCB__INTR_M_MASK CYREG_SCB1_INTR_M_MASK
#define I2CS_SCB__INTR_M_MASKED CYREG_SCB1_INTR_M_MASKED
#define I2CS_SCB__INTR_M_SET CYREG_SCB1_INTR_M_SET
#define I2CS_SCB__INTR_RX CYREG_SCB1_INTR_RX
#define I2CS_SCB__INTR_RX_MASK CYREG_SCB1_INTR_RX_MASK
#define I2CS_SCB__INTR_RX_MASKED CYREG_SCB1_INTR_RX_MASKED
#define I2CS_SCB__INTR_RX_SET CYREG_SCB1_INTR_RX_SET
#define I2CS_SCB__INTR_S CYREG_SCB1_INTR_S
#define I2CS_SCB__INTR_S_MASK CYREG_SCB1_INTR_S_MASK
#define I2CS_SCB__INTR_S_MASKED CYREG_SCB1_INTR_S_MASKED
#define I2CS_SCB__INTR_S_SET CYREG_SCB1_INTR_S_SET
#define I2CS_SCB__INTR_SPI_EC CYREG_SCB1_INTR_SPI_EC
#define I2CS_SCB__INTR_SPI_EC_MASK CYREG_SCB1_INTR_SPI_EC_MASK
#define I2CS_SCB__INTR_SPI_EC_MASKED CYREG_SCB1_INTR_SPI_EC_MASKED
#define I2CS_SCB__INTR_TX CYREG_SCB1_INTR_TX
#define I2CS_SCB__INTR_TX_MASK CYREG_SCB1_INTR_TX_MASK
#define I2CS_SCB__INTR_TX_MASKED CYREG_SCB1_INTR_TX_MASKED
#define I2CS_SCB__INTR_TX_SET CYREG_SCB1_INTR_TX_SET
#define I2CS_SCB__RX_CTRL CYREG_SCB1_RX_CTRL
#define I2CS_SCB__RX_FIFO_CTRL CYREG_SCB1_RX_FIFO_CTRL
#define I2CS_SCB__RX_FIFO_RD CYREG_SCB1_RX_FIFO_RD
#define I2CS_SCB__RX_FIFO_RD_SILENT CYREG_SCB1_RX_FIFO_RD_SILENT
#define I2CS_SCB__RX_FIFO_STATUS CYREG_SCB1_RX_FIFO_STATUS
#define I2CS_SCB__RX_MATCH CYREG_SCB1_RX_MATCH
#define I2CS_SCB__SPI_CTRL CYREG_SCB1_SPI_CTRL
#define I2CS_SCB__SPI_STATUS CYREG_SCB1_SPI_STATUS
#define I2CS_SCB__SS0_POSISTION 0u
#define I2CS_SCB__SS1_POSISTION 1u
#define I2CS_SCB__SS2_POSISTION 2u
#define I2CS_SCB__SS3_POSISTION 3u
#define I2CS_SCB__STATUS CYREG_SCB1_STATUS
#define I2CS_SCB__TX_CTRL CYREG_SCB1_TX_CTRL
#define I2CS_SCB__TX_FIFO_CTRL CYREG_SCB1_TX_FIFO_CTRL
#define I2CS_SCB__TX_FIFO_STATUS CYREG_SCB1_TX_FIFO_STATUS
#define I2CS_SCB__TX_FIFO_WR CYREG_SCB1_TX_FIFO_WR
#define I2CS_SCB__UART_CTRL CYREG_SCB1_UART_CTRL
#define I2CS_SCB__UART_RX_CTRL CYREG_SCB1_UART_RX_CTRL
#define I2CS_SCB__UART_RX_STATUS CYREG_SCB1_UART_RX_STATUS
#define I2CS_SCB__UART_TX_CTRL CYREG_SCB1_UART_TX_CTRL

/* I2CS_SCB_IRQ */
#define I2CS_SCB_IRQ__INTC_CLR_EN_REG CYREG_CM0_ICER
#define I2CS_SCB_IRQ__INTC_CLR_PD_REG CYREG_CM0_ICPR
#define I2CS_SCB_IRQ__INTC_MASK 0x800u
#define I2CS_SCB_IRQ__INTC_NUMBER 11u
#define I2CS_SCB_IRQ__INTC_PRIOR_MASK 0xC0000000u
#define I2CS_SCB_IRQ__INTC_PRIOR_NUM 3u
#define I2CS_SCB_IRQ__INTC_PRIOR_REG CYREG_CM0_IPR2
#define I2CS_SCB_IRQ__INTC_SET_EN_REG CYREG_CM0_ISER
#define I2CS_SCB_IRQ__INTC_SET_PD_REG CYREG_CM0_ISPR

/* I2CS_SCBCLK */
#define I2CS_SCBCLK__DIVIDER_MASK 0x0000FFFFu
#define I2CS_SCBCLK__ENABLE CYREG_CLK_DIVIDER_A00
#define I2CS_SCBCLK__ENABLE_MASK 0x80000000u
#define I2CS_SCBCLK__MASK 0x80000000u
#define I2CS_SCBCLK__REGISTER CYREG_CLK_DIVIDER_A00

/* I2CS_scl */
#define I2CS_scl__0__DM__MASK 0x07u
#define I2CS_scl__0__DM__SHIFT 0u
#define I2CS_scl__0__DR CYREG_PRT3_DR
#define I2CS_scl__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define I2CS_scl__0__HSIOM_GPIO 0u
#define I2CS_scl__0__HSIOM_I2C 14u
#define I2CS_scl__0__HSIOM_I2C_SCL 14u
#define I2CS_scl__0__HSIOM_MASK 0x0000000Fu
#define I2CS_scl__0__HSIOM_SHIFT 0u
#define I2CS_scl__0__HSIOM_SPI 15u
#define I2CS_scl__0__HSIOM_SPI_MOSI 15u
#define I2CS_scl__0__HSIOM_UART 9u
#define I2CS_scl__0__HSIOM_UART_RX 9u
#define I2CS_scl__0__INTCFG CYREG_PRT3_INTCFG
#define I2CS_scl__0__INTSTAT CYREG_PRT3_INTSTAT
#define I2CS_scl__0__MASK 0x01u
#define I2CS_scl__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define I2CS_scl__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define I2CS_scl__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define I2CS_scl__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define I2CS_scl__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define I2CS_scl__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define I2CS_scl__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define I2CS_scl__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define I2CS_scl__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define I2CS_scl__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define I2CS_scl__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define I2CS_scl__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define I2CS_scl__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define I2CS_scl__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define I2CS_scl__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define I2CS_scl__0__PC CYREG_PRT3_PC
#define I2CS_scl__0__PC2 CYREG_PRT3_PC2
#define I2CS_scl__0__PORT 3u
#define I2CS_scl__0__PS CYREG_PRT3_PS
#define I2CS_scl__0__SHIFT 0u
#define I2CS_scl__DR CYREG_PRT3_DR
#define I2CS_scl__INTCFG CYREG_PRT3_INTCFG
#define I2CS_scl__INTSTAT CYREG_PRT3_INTSTAT
#define I2CS_scl__MASK 0x01u
#define I2CS_scl__PA__CFG0 CYREG_UDB_PA3_CFG0
#define I2CS_scl__PA__CFG1 CYREG_UDB_PA3_CFG1
#define I2CS_scl__PA__CFG10 CYREG_UDB_PA3_CFG10
#define I2CS_scl__PA__CFG11 CYREG_UDB_PA3_CFG11
#define I2CS_scl__PA__CFG12 CYREG_UDB_PA3_CFG12
#define I2CS_scl__PA__CFG13 CYREG_UDB_PA3_CFG13
#define I2CS_scl__PA__CFG14 CYREG_UDB_PA3_CFG14
#define I2CS_scl__PA__CFG2 CYREG_UDB_PA3_CFG2
#define I2CS_scl__PA__CFG3 CYREG_UDB_PA3_CFG3
#define I2CS_scl__PA__CFG4 CYREG_UDB_PA3_CFG4
#define I2CS_scl__PA__CFG5 CYREG_UDB_PA3_CFG5
#define I2CS_scl__PA__CFG6 CYREG_UDB_PA3_CFG6
#define I2CS_scl__PA__CFG7 CYREG_UDB_PA3_CFG7
#define I2CS_scl__PA__CFG8 CYREG_UDB_PA3_CFG8
#define I2CS_scl__PA__CFG9 CYREG_UDB_PA3_CFG9
#define I2CS_scl__PC CYREG_PRT3_PC
#define I2CS_scl__PC2 CYREG_PRT3_PC2
#define I2CS_scl__PORT 3u
#define I2CS_scl__PS CYREG_PRT3_PS
#define I2CS_scl__SHIFT 0u

/* I2CS_sda */
#define I2CS_sda__0__DM__MASK 0x38u
#define I2CS_sda__0__DM__SHIFT 3u
#define I2CS_sda__0__DR CYREG_PRT3_DR
#define I2CS_sda__0__HSIOM CYREG_HSIOM_PORT_SEL3
#define I2CS_sda__0__HSIOM_GPIO 0u
#define I2CS_sda__0__HSIOM_I2C 14u
#define I2CS_sda__0__HSIOM_I2C_SDA 14u
#define I2CS_sda__0__HSIOM_MASK 0x000000F0u
#define I2CS_sda__0__HSIOM_SHIFT 4u
#define I2CS_sda__0__HSIOM_SPI 15u
#define I2CS_sda__0__HSIOM_SPI_MISO 15u
#define I2CS_sda__0__HSIOM_UART 9u
#define I2CS_sda__0__HSIOM_UART_TX 9u
#define I2CS_sda__0__INTCFG CYREG_PRT3_INTCFG
#define I2CS_sda__0__INTSTAT CYREG_PRT3_INTSTAT
#define I2CS_sda__0__MASK 0x02u
#define I2CS_sda__0__PA__CFG0 CYREG_UDB_PA3_CFG0
#define I2CS_sda__0__PA__CFG1 CYREG_UDB_PA3_CFG1
#define I2CS_sda__0__PA__CFG10 CYREG_UDB_PA3_CFG10
#define I2CS_sda__0__PA__CFG11 CYREG_UDB_PA3_CFG11
#define I2CS_sda__0__PA__CFG12 CYREG_UDB_PA3_CFG12
#define I2CS_sda__0__PA__CFG13 CYREG_UDB_PA3_CFG13
#define I2CS_sda__0__PA__CFG14 CYREG_UDB_PA3_CFG14
#define I2CS_sda__0__PA__CFG2 CYREG_UDB_PA3_CFG2
#define I2CS_sda__0__PA__CFG3 CYREG_UDB_PA3_CFG3
#define I2CS_sda__0__PA__CFG4 CYREG_UDB_PA3_CFG4
#define I2CS_sda__0__PA__CFG5 CYREG_UDB_PA3_CFG5
#define I2CS_sda__0__PA__CFG6 CYREG_UDB_PA3_CFG6
#define I2CS_sda__0__PA__CFG7 CYREG_UDB_PA3_CFG7
#define I2CS_sda__0__PA__CFG8 CYREG_UDB_PA3_CFG8
#define I2CS_sda__0__PA__CFG9 CYREG_UDB_PA3_CFG9
#define I2CS_sda__0__PC CYREG_PRT3_PC
#define I2CS_sda__0__PC2 CYREG_PRT3_PC2
#define I2CS_sda__0__PORT 3u
#define I2CS_sda__0__PS CYREG_PRT3_PS
#define I2CS_sda__0__SHIFT 1u
#define I2CS_sda__DR CYREG_PRT3_DR
#define I2CS_sda__INTCFG CYREG_PRT3_INTCFG
#define I2CS_sda__INTSTAT CYREG_PRT3_INTSTAT
#define I2CS_sda__MASK 0x02u
#define I2CS_sda__PA__CFG0 CYREG_UDB_PA3_CFG0
#define I2CS_sda__PA__CFG1 CYREG_UDB_PA3_CFG1
#define I2CS_sda__PA__CFG10 CYREG_UDB_PA3_CFG10
#define I2CS_sda__PA__CFG11 CYREG_UDB_PA3_CFG11
#define I2CS_sda__PA__CFG12 CYREG_UDB_PA3_CFG12
#define I2CS_sda__PA__CFG13 CYREG_UDB_PA3_CFG13
#define I2CS_sda__PA__CFG14 CYREG_UDB_PA3_CFG14
#define I2CS_sda__PA__CFG2 CYREG_UDB_PA3_CFG2
#define I2CS_sda__PA__CFG3 CYREG_UDB_PA3_CFG3
#define I2CS_sda__PA__CFG4 CYREG_UDB_PA3_CFG4
#define I2CS_sda__PA__CFG5 CYREG_UDB_PA3_CFG5
#define I2CS_sda__PA__CFG6 CYREG_UDB_PA3_CFG6
#define I2CS_sda__PA__CFG7 CYREG_UDB_PA3_CFG7
#define I2CS_sda__PA__CFG8 CYREG_UDB_PA3_CFG8
#define I2CS_sda__PA__CFG9 CYREG_UDB_PA3_CFG9
#define I2CS_sda__PC CYREG_PRT3_PC
#define I2CS_sda__PC2 CYREG_PRT3_PC2
#define I2CS_sda__PORT 3u
#define I2CS_sda__PS CYREG_PRT3_PS
#define I2CS_sda__SHIFT 1u

/* State_CtrlReg_Dir */
#define State_CtrlReg_Dir_Sync_ctrl_reg__0__MASK 0x01u
#define State_CtrlReg_Dir_Sync_ctrl_reg__0__POS 0
#define State_CtrlReg_Dir_Sync_ctrl_reg__1__MASK 0x02u
#define State_CtrlReg_Dir_Sync_ctrl_reg__1__POS 1
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__32BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W32_ACTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__32BIT_CONTROL_REG CYREG_UDB_W32_CTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__32BIT_COUNT_REG CYREG_UDB_W32_CTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__32BIT_PERIOD_REG CYREG_UDB_W32_MSK_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__CONTROL_REG CYREG_UDB_W8_CTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__COUNT_REG CYREG_UDB_W8_CTL_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__MASK 0x03u
#define State_CtrlReg_Dir_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define State_CtrlReg_Dir_Sync_ctrl_reg__PERIOD_REG CYREG_UDB_W8_MSK_00

/* State_CtrlReg_Run */
#define State_CtrlReg_Run_Sync_ctrl_reg__0__MASK 0x01u
#define State_CtrlReg_Run_Sync_ctrl_reg__0__POS 0
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_CONTROL_AUX_CTL_REG CYREG_UDB_W16_ACTL_01
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_CONTROL_CONTROL_REG CYREG_UDB_W16_CTL_01
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_CONTROL_COUNT_REG CYREG_UDB_W16_CTL_01
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_COUNT_CONTROL_REG CYREG_UDB_W16_CTL_01
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_COUNT_COUNT_REG CYREG_UDB_W16_CTL_01
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_MASK_MASK_REG CYREG_UDB_W16_MSK_01
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_MASK_PERIOD_REG CYREG_UDB_W16_MSK_01
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_PERIOD_MASK_REG CYREG_UDB_W16_MSK_01
#define State_CtrlReg_Run_Sync_ctrl_reg__16BIT_PERIOD_PERIOD_REG CYREG_UDB_W16_MSK_01
#define State_CtrlReg_Run_Sync_ctrl_reg__CONTROL_AUX_CTL_REG CYREG_UDB_W8_ACTL_01
#define State_CtrlReg_Run_Sync_ctrl_reg__CONTROL_REG CYREG_UDB_W8_CTL_01
#define State_CtrlReg_Run_Sync_ctrl_reg__CONTROL_ST_REG CYREG_UDB_CAT16_CTL_ST_01
#define State_CtrlReg_Run_Sync_ctrl_reg__COUNT_REG CYREG_UDB_W8_CTL_01
#define State_CtrlReg_Run_Sync_ctrl_reg__COUNT_ST_REG CYREG_UDB_CAT16_CTL_ST_01
#define State_CtrlReg_Run_Sync_ctrl_reg__MASK 0x01u
#define State_CtrlReg_Run_Sync_ctrl_reg__MASK_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_01
#define State_CtrlReg_Run_Sync_ctrl_reg__PER_CTL_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_01
#define State_CtrlReg_Run_Sync_ctrl_reg__PERIOD_REG CYREG_UDB_W8_MSK_01
#define State_Forward_u0__16BIT_A0_REG CYREG_UDB_W16_A0_00
#define State_Forward_u0__16BIT_A1_REG CYREG_UDB_W16_A1_00
#define State_Forward_u0__16BIT_D0_REG CYREG_UDB_W16_D0_00
#define State_Forward_u0__16BIT_D1_REG CYREG_UDB_W16_D1_00
#define State_Forward_u0__16BIT_DP_AUX_CTL_REG CYREG_UDB_W16_ACTL_00
#define State_Forward_u0__16BIT_F0_REG CYREG_UDB_W16_F0_00
#define State_Forward_u0__16BIT_F1_REG CYREG_UDB_W16_F1_00
#define State_Forward_u0__32BIT_A0_REG CYREG_UDB_W32_A0_00
#define State_Forward_u0__32BIT_A1_REG CYREG_UDB_W32_A1_00
#define State_Forward_u0__32BIT_D0_REG CYREG_UDB_W32_D0_00
#define State_Forward_u0__32BIT_D1_REG CYREG_UDB_W32_D1_00
#define State_Forward_u0__32BIT_DP_AUX_CTL_REG CYREG_UDB_W32_ACTL_00
#define State_Forward_u0__32BIT_F0_REG CYREG_UDB_W32_F0_00
#define State_Forward_u0__32BIT_F1_REG CYREG_UDB_W32_F1_00
#define State_Forward_u0__A0_A1_REG CYREG_UDB_CAT16_A_00
#define State_Forward_u0__A0_REG CYREG_UDB_W8_A0_00
#define State_Forward_u0__A1_REG CYREG_UDB_W8_A1_00
#define State_Forward_u0__D0_D1_REG CYREG_UDB_CAT16_D_00
#define State_Forward_u0__D0_REG CYREG_UDB_W8_D0_00
#define State_Forward_u0__D1_REG CYREG_UDB_W8_D1_00
#define State_Forward_u0__DP_AUX_CTL_REG CYREG_UDB_W8_ACTL_00
#define State_Forward_u0__F0_F1_REG CYREG_UDB_CAT16_F_00
#define State_Forward_u0__F0_REG CYREG_UDB_W8_F0_00
#define State_Forward_u0__F1_REG CYREG_UDB_W8_F1_00
#define State_Forward_u0__MSK_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00
#define State_Forward_u0__PER_DP_AUX_CTL_REG CYREG_UDB_CAT16_ACTL_MSK_00

/* Clock_2 */
#define Clock_2__DIVIDER_MASK 0x0000FFFFu
#define Clock_2__ENABLE CYREG_CLK_DIVIDER_C00
#define Clock_2__ENABLE_MASK 0x80000000u
#define Clock_2__MASK 0x80000000u
#define Clock_2__REGISTER CYREG_CLK_DIVIDER_C00

/* P0_0_clk */
#define P0_0_clk__0__DM__MASK 0x7000u
#define P0_0_clk__0__DM__SHIFT 12u
#define P0_0_clk__0__DR CYREG_PRT2_DR
#define P0_0_clk__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define P0_0_clk__0__HSIOM_MASK 0x000F0000u
#define P0_0_clk__0__HSIOM_SHIFT 16u
#define P0_0_clk__0__INTCFG CYREG_PRT2_INTCFG
#define P0_0_clk__0__INTSTAT CYREG_PRT2_INTSTAT
#define P0_0_clk__0__MASK 0x10u
#define P0_0_clk__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define P0_0_clk__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define P0_0_clk__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define P0_0_clk__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define P0_0_clk__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define P0_0_clk__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define P0_0_clk__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define P0_0_clk__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define P0_0_clk__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define P0_0_clk__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define P0_0_clk__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define P0_0_clk__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define P0_0_clk__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define P0_0_clk__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define P0_0_clk__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define P0_0_clk__0__PC CYREG_PRT2_PC
#define P0_0_clk__0__PC2 CYREG_PRT2_PC2
#define P0_0_clk__0__PORT 2u
#define P0_0_clk__0__PS CYREG_PRT2_PS
#define P0_0_clk__0__SHIFT 4u
#define P0_0_clk__DR CYREG_PRT2_DR
#define P0_0_clk__INTCFG CYREG_PRT2_INTCFG
#define P0_0_clk__INTSTAT CYREG_PRT2_INTSTAT
#define P0_0_clk__MASK 0x10u
#define P0_0_clk__PA__CFG0 CYREG_UDB_PA2_CFG0
#define P0_0_clk__PA__CFG1 CYREG_UDB_PA2_CFG1
#define P0_0_clk__PA__CFG10 CYREG_UDB_PA2_CFG10
#define P0_0_clk__PA__CFG11 CYREG_UDB_PA2_CFG11
#define P0_0_clk__PA__CFG12 CYREG_UDB_PA2_CFG12
#define P0_0_clk__PA__CFG13 CYREG_UDB_PA2_CFG13
#define P0_0_clk__PA__CFG14 CYREG_UDB_PA2_CFG14
#define P0_0_clk__PA__CFG2 CYREG_UDB_PA2_CFG2
#define P0_0_clk__PA__CFG3 CYREG_UDB_PA2_CFG3
#define P0_0_clk__PA__CFG4 CYREG_UDB_PA2_CFG4
#define P0_0_clk__PA__CFG5 CYREG_UDB_PA2_CFG5
#define P0_0_clk__PA__CFG6 CYREG_UDB_PA2_CFG6
#define P0_0_clk__PA__CFG7 CYREG_UDB_PA2_CFG7
#define P0_0_clk__PA__CFG8 CYREG_UDB_PA2_CFG8
#define P0_0_clk__PA__CFG9 CYREG_UDB_PA2_CFG9
#define P0_0_clk__PC CYREG_PRT2_PC
#define P0_0_clk__PC2 CYREG_PRT2_PC2
#define P0_0_clk__PORT 2u
#define P0_0_clk__PS CYREG_PRT2_PS
#define P0_0_clk__SHIFT 4u

/* Miscellaneous */
#define CY_PROJECT_NAME "TestState"
#define CY_VERSION "PSoC Creator  4.0"
#define CYDEV_BANDGAP_VOLTAGE 1.024
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 12u
#define CYDEV_CHIP_DIE_PSOC5LP 19u
#define CYDEV_CHIP_DIE_PSOC5TM 20u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 4u
#define CYDEV_CHIP_FAMILY_FM3 5u
#define CYDEV_CHIP_FAMILY_FM4 6u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 12u
#define CYDEV_CHIP_MEMBER_4C 18u
#define CYDEV_CHIP_MEMBER_4D 8u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 13u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 11u
#define CYDEV_CHIP_MEMBER_4I 17u
#define CYDEV_CHIP_MEMBER_4J 9u
#define CYDEV_CHIP_MEMBER_4K 10u
#define CYDEV_CHIP_MEMBER_4L 16u
#define CYDEV_CHIP_MEMBER_4M 15u
#define CYDEV_CHIP_MEMBER_4N 6u
#define CYDEV_CHIP_MEMBER_4O 5u
#define CYDEV_CHIP_MEMBER_4P 14u
#define CYDEV_CHIP_MEMBER_4Q 7u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 20u
#define CYDEV_CHIP_MEMBER_5B 19u
#define CYDEV_CHIP_MEMBER_FM3 24u
#define CYDEV_CHIP_MEMBER_FM4 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_Disallowed
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_PROTECT_KILL 4
#define CYDEV_DEBUG_PROTECT_OPEN 1
#define CYDEV_DEBUG_PROTECT CYDEV_DEBUG_PROTECT_OPEN
#define CYDEV_DEBUG_PROTECT_PROTECTED 2
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DFT_SELECT_CLK0 1u
#define CYDEV_DFT_SELECT_CLK1 2u
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_IMO_TRIMMED_BY_USB 0u
#define CYDEV_IMO_TRIMMED_BY_WCO 0u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_STACK_SIZE 0x0400
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 1
#define CYDEV_VDDA 3.3
#define CYDEV_VDDA_MV 3300
#define CYDEV_VDDD 3.3
#define CYDEV_VDDD_MV 3300
#define CYDEV_WDT_GENERATE_ISR 1u
#define CYIPBLOCK_M0S8_CTBM_VERSION 0
#define CYIPBLOCK_m0s8cpuss_VERSION 0
#define CYIPBLOCK_m0s8csd_VERSION 0
#define CYIPBLOCK_m0s8gpio2_VERSION 0
#define CYIPBLOCK_m0s8hsiom4a_VERSION 0
#define CYIPBLOCK_m0s8lcd_VERSION 0
#define CYIPBLOCK_m0s8lpcomp_VERSION 0
#define CYIPBLOCK_m0s8pclk_VERSION 0
#define CYIPBLOCK_m0s8sar_VERSION 0
#define CYIPBLOCK_m0s8scb_VERSION 0
#define CYIPBLOCK_m0s8srssv2_VERSION 1
#define CYIPBLOCK_m0s8tcpwm_VERSION 0
#define CYIPBLOCK_m0s8udbif_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 2
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
