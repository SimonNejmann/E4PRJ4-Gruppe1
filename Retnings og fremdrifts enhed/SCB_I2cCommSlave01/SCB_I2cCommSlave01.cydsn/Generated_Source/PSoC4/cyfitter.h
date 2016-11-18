#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice_trm.h"

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

/* PWM_2_cy_m0s8_tcpwm_1 */
#define PWM_2_cy_m0s8_tcpwm_1__CC CYREG_TCPWM_CNT0_CC
#define PWM_2_cy_m0s8_tcpwm_1__CC_BUFF CYREG_TCPWM_CNT0_CC_BUFF
#define PWM_2_cy_m0s8_tcpwm_1__COUNTER CYREG_TCPWM_CNT0_COUNTER
#define PWM_2_cy_m0s8_tcpwm_1__CTRL CYREG_TCPWM_CNT0_CTRL
#define PWM_2_cy_m0s8_tcpwm_1__INTR CYREG_TCPWM_CNT0_INTR
#define PWM_2_cy_m0s8_tcpwm_1__INTR_MASK CYREG_TCPWM_CNT0_INTR_MASK
#define PWM_2_cy_m0s8_tcpwm_1__INTR_MASKED CYREG_TCPWM_CNT0_INTR_MASKED
#define PWM_2_cy_m0s8_tcpwm_1__INTR_SET CYREG_TCPWM_CNT0_INTR_SET
#define PWM_2_cy_m0s8_tcpwm_1__PERIOD CYREG_TCPWM_CNT0_PERIOD
#define PWM_2_cy_m0s8_tcpwm_1__PERIOD_BUFF CYREG_TCPWM_CNT0_PERIOD_BUFF
#define PWM_2_cy_m0s8_tcpwm_1__STATUS CYREG_TCPWM_CNT0_STATUS
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMD CYREG_TCPWM_CMD
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_MASK 0x01u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDCAPTURE_SHIFT 0u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_MASK 0x100u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDRELOAD_SHIFT 8u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_MASK 0x1000000u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTART_SHIFT 24u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_MASK 0x10000u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CMDSTOP_SHIFT 16u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL CYREG_TCPWM_CTRL
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK 0x01u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_CTRL_SHIFT 0u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE CYREG_TCPWM_INTR_CAUSE
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_MASK 0x01u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE_SHIFT 0u
#define PWM_2_cy_m0s8_tcpwm_1__TCPWM_NUMBER 0u
#define PWM_2_cy_m0s8_tcpwm_1__TR_CTRL0 CYREG_TCPWM_CNT0_TR_CTRL0
#define PWM_2_cy_m0s8_tcpwm_1__TR_CTRL1 CYREG_TCPWM_CNT0_TR_CTRL1
#define PWM_2_cy_m0s8_tcpwm_1__TR_CTRL2 CYREG_TCPWM_CNT0_TR_CTRL2

/* Pin_1 */
#define Pin_1__0__DM__MASK 0x07u
#define Pin_1__0__DM__SHIFT 0u
#define Pin_1__0__DR CYREG_PRT2_DR
#define Pin_1__0__HSIOM CYREG_HSIOM_PORT_SEL2
#define Pin_1__0__HSIOM_MASK 0x0000000Fu
#define Pin_1__0__HSIOM_SHIFT 0u
#define Pin_1__0__INTCFG CYREG_PRT2_INTCFG
#define Pin_1__0__INTSTAT CYREG_PRT2_INTSTAT
#define Pin_1__0__MASK 0x01u
#define Pin_1__0__OUT_SEL CYREG_UDB_PA2_CFG10
#define Pin_1__0__OUT_SEL_SHIFT 0u
#define Pin_1__0__OUT_SEL_VAL 0u
#define Pin_1__0__PA__CFG0 CYREG_UDB_PA2_CFG0
#define Pin_1__0__PA__CFG1 CYREG_UDB_PA2_CFG1
#define Pin_1__0__PA__CFG10 CYREG_UDB_PA2_CFG10
#define Pin_1__0__PA__CFG11 CYREG_UDB_PA2_CFG11
#define Pin_1__0__PA__CFG12 CYREG_UDB_PA2_CFG12
#define Pin_1__0__PA__CFG13 CYREG_UDB_PA2_CFG13
#define Pin_1__0__PA__CFG14 CYREG_UDB_PA2_CFG14
#define Pin_1__0__PA__CFG2 CYREG_UDB_PA2_CFG2
#define Pin_1__0__PA__CFG3 CYREG_UDB_PA2_CFG3
#define Pin_1__0__PA__CFG4 CYREG_UDB_PA2_CFG4
#define Pin_1__0__PA__CFG5 CYREG_UDB_PA2_CFG5
#define Pin_1__0__PA__CFG6 CYREG_UDB_PA2_CFG6
#define Pin_1__0__PA__CFG7 CYREG_UDB_PA2_CFG7
#define Pin_1__0__PA__CFG8 CYREG_UDB_PA2_CFG8
#define Pin_1__0__PA__CFG9 CYREG_UDB_PA2_CFG9
#define Pin_1__0__PC CYREG_PRT2_PC
#define Pin_1__0__PC2 CYREG_PRT2_PC2
#define Pin_1__0__PORT 2u
#define Pin_1__0__PS CYREG_PRT2_PS
#define Pin_1__0__SHIFT 0u
#define Pin_1__DR CYREG_PRT2_DR
#define Pin_1__INTCFG CYREG_PRT2_INTCFG
#define Pin_1__INTSTAT CYREG_PRT2_INTSTAT
#define Pin_1__MASK 0x01u
#define Pin_1__PA__CFG0 CYREG_UDB_PA2_CFG0
#define Pin_1__PA__CFG1 CYREG_UDB_PA2_CFG1
#define Pin_1__PA__CFG10 CYREG_UDB_PA2_CFG10
#define Pin_1__PA__CFG11 CYREG_UDB_PA2_CFG11
#define Pin_1__PA__CFG12 CYREG_UDB_PA2_CFG12
#define Pin_1__PA__CFG13 CYREG_UDB_PA2_CFG13
#define Pin_1__PA__CFG14 CYREG_UDB_PA2_CFG14
#define Pin_1__PA__CFG2 CYREG_UDB_PA2_CFG2
#define Pin_1__PA__CFG3 CYREG_UDB_PA2_CFG3
#define Pin_1__PA__CFG4 CYREG_UDB_PA2_CFG4
#define Pin_1__PA__CFG5 CYREG_UDB_PA2_CFG5
#define Pin_1__PA__CFG6 CYREG_UDB_PA2_CFG6
#define Pin_1__PA__CFG7 CYREG_UDB_PA2_CFG7
#define Pin_1__PA__CFG8 CYREG_UDB_PA2_CFG8
#define Pin_1__PA__CFG9 CYREG_UDB_PA2_CFG9
#define Pin_1__PC CYREG_PRT2_PC
#define Pin_1__PC2 CYREG_PRT2_PC2
#define Pin_1__PORT 2u
#define Pin_1__PS CYREG_PRT2_PS
#define Pin_1__SHIFT 0u

/* Clock_1 */
#define Clock_1__DIVIDER_MASK 0x0000FFFFu
#define Clock_1__ENABLE CYREG_CLK_DIVIDER_B00
#define Clock_1__ENABLE_MASK 0x80000000u
#define Clock_1__MASK 0x80000000u
#define Clock_1__REGISTER CYREG_CLK_DIVIDER_B00

/* Miscellaneous */
#define CY_PROJECT_NAME "SCB_I2cCommSlave01"
#define CY_VERSION "PSoC Creator  3.3 CP3"
#define CYDEV_BANDGAP_VOLTAGE 1.024
#define CYDEV_BCLK__HFCLK__HZ 24000000U
#define CYDEV_BCLK__HFCLK__KHZ 24000U
#define CYDEV_BCLK__HFCLK__MHZ 24U
#define CYDEV_BCLK__SYSCLK__HZ 24000000U
#define CYDEV_BCLK__SYSCLK__KHZ 24000U
#define CYDEV_BCLK__SYSCLK__MHZ 24U
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 19u
#define CYDEV_CHIP_DIE_PSOC4A 11u
#define CYDEV_CHIP_DIE_PSOC5LP 18u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC4
#define CYDEV_CHIP_JTAG_ID 0x04C81193u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 11u
#define CYDEV_CHIP_MEMBER_4C 16u
#define CYDEV_CHIP_MEMBER_4D 7u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 12u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 10u
#define CYDEV_CHIP_MEMBER_4I 15u
#define CYDEV_CHIP_MEMBER_4J 8u
#define CYDEV_CHIP_MEMBER_4K 9u
#define CYDEV_CHIP_MEMBER_4L 14u
#define CYDEV_CHIP_MEMBER_4M 13u
#define CYDEV_CHIP_MEMBER_4N 6u
#define CYDEV_CHIP_MEMBER_4O 5u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 18u
#define CYDEV_CHIP_MEMBER_5B 17u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_4A
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
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
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_4A_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_READ_ACCELERATOR 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
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
#define CYDEV_HEAP_SIZE 0x0100
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
#define CYDEV_WDT_GENERATE_ISR 0u
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
