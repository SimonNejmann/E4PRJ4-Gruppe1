    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv_trm.inc

; I2CS_SCB
I2CS_SCB__CTRL EQU CYREG_SCB1_CTRL
I2CS_SCB__EZ_DATA0 EQU CYREG_SCB1_EZ_DATA0
I2CS_SCB__EZ_DATA1 EQU CYREG_SCB1_EZ_DATA1
I2CS_SCB__EZ_DATA10 EQU CYREG_SCB1_EZ_DATA10
I2CS_SCB__EZ_DATA11 EQU CYREG_SCB1_EZ_DATA11
I2CS_SCB__EZ_DATA12 EQU CYREG_SCB1_EZ_DATA12
I2CS_SCB__EZ_DATA13 EQU CYREG_SCB1_EZ_DATA13
I2CS_SCB__EZ_DATA14 EQU CYREG_SCB1_EZ_DATA14
I2CS_SCB__EZ_DATA15 EQU CYREG_SCB1_EZ_DATA15
I2CS_SCB__EZ_DATA16 EQU CYREG_SCB1_EZ_DATA16
I2CS_SCB__EZ_DATA17 EQU CYREG_SCB1_EZ_DATA17
I2CS_SCB__EZ_DATA18 EQU CYREG_SCB1_EZ_DATA18
I2CS_SCB__EZ_DATA19 EQU CYREG_SCB1_EZ_DATA19
I2CS_SCB__EZ_DATA2 EQU CYREG_SCB1_EZ_DATA2
I2CS_SCB__EZ_DATA20 EQU CYREG_SCB1_EZ_DATA20
I2CS_SCB__EZ_DATA21 EQU CYREG_SCB1_EZ_DATA21
I2CS_SCB__EZ_DATA22 EQU CYREG_SCB1_EZ_DATA22
I2CS_SCB__EZ_DATA23 EQU CYREG_SCB1_EZ_DATA23
I2CS_SCB__EZ_DATA24 EQU CYREG_SCB1_EZ_DATA24
I2CS_SCB__EZ_DATA25 EQU CYREG_SCB1_EZ_DATA25
I2CS_SCB__EZ_DATA26 EQU CYREG_SCB1_EZ_DATA26
I2CS_SCB__EZ_DATA27 EQU CYREG_SCB1_EZ_DATA27
I2CS_SCB__EZ_DATA28 EQU CYREG_SCB1_EZ_DATA28
I2CS_SCB__EZ_DATA29 EQU CYREG_SCB1_EZ_DATA29
I2CS_SCB__EZ_DATA3 EQU CYREG_SCB1_EZ_DATA3
I2CS_SCB__EZ_DATA30 EQU CYREG_SCB1_EZ_DATA30
I2CS_SCB__EZ_DATA31 EQU CYREG_SCB1_EZ_DATA31
I2CS_SCB__EZ_DATA4 EQU CYREG_SCB1_EZ_DATA4
I2CS_SCB__EZ_DATA5 EQU CYREG_SCB1_EZ_DATA5
I2CS_SCB__EZ_DATA6 EQU CYREG_SCB1_EZ_DATA6
I2CS_SCB__EZ_DATA7 EQU CYREG_SCB1_EZ_DATA7
I2CS_SCB__EZ_DATA8 EQU CYREG_SCB1_EZ_DATA8
I2CS_SCB__EZ_DATA9 EQU CYREG_SCB1_EZ_DATA9
I2CS_SCB__I2C_CFG EQU CYREG_SCB1_I2C_CFG
I2CS_SCB__I2C_CTRL EQU CYREG_SCB1_I2C_CTRL
I2CS_SCB__I2C_M_CMD EQU CYREG_SCB1_I2C_M_CMD
I2CS_SCB__I2C_S_CMD EQU CYREG_SCB1_I2C_S_CMD
I2CS_SCB__I2C_STATUS EQU CYREG_SCB1_I2C_STATUS
I2CS_SCB__INTR_CAUSE EQU CYREG_SCB1_INTR_CAUSE
I2CS_SCB__INTR_I2C_EC EQU CYREG_SCB1_INTR_I2C_EC
I2CS_SCB__INTR_I2C_EC_MASK EQU CYREG_SCB1_INTR_I2C_EC_MASK
I2CS_SCB__INTR_I2C_EC_MASKED EQU CYREG_SCB1_INTR_I2C_EC_MASKED
I2CS_SCB__INTR_M EQU CYREG_SCB1_INTR_M
I2CS_SCB__INTR_M_MASK EQU CYREG_SCB1_INTR_M_MASK
I2CS_SCB__INTR_M_MASKED EQU CYREG_SCB1_INTR_M_MASKED
I2CS_SCB__INTR_M_SET EQU CYREG_SCB1_INTR_M_SET
I2CS_SCB__INTR_RX EQU CYREG_SCB1_INTR_RX
I2CS_SCB__INTR_RX_MASK EQU CYREG_SCB1_INTR_RX_MASK
I2CS_SCB__INTR_RX_MASKED EQU CYREG_SCB1_INTR_RX_MASKED
I2CS_SCB__INTR_RX_SET EQU CYREG_SCB1_INTR_RX_SET
I2CS_SCB__INTR_S EQU CYREG_SCB1_INTR_S
I2CS_SCB__INTR_S_MASK EQU CYREG_SCB1_INTR_S_MASK
I2CS_SCB__INTR_S_MASKED EQU CYREG_SCB1_INTR_S_MASKED
I2CS_SCB__INTR_S_SET EQU CYREG_SCB1_INTR_S_SET
I2CS_SCB__INTR_SPI_EC EQU CYREG_SCB1_INTR_SPI_EC
I2CS_SCB__INTR_SPI_EC_MASK EQU CYREG_SCB1_INTR_SPI_EC_MASK
I2CS_SCB__INTR_SPI_EC_MASKED EQU CYREG_SCB1_INTR_SPI_EC_MASKED
I2CS_SCB__INTR_TX EQU CYREG_SCB1_INTR_TX
I2CS_SCB__INTR_TX_MASK EQU CYREG_SCB1_INTR_TX_MASK
I2CS_SCB__INTR_TX_MASKED EQU CYREG_SCB1_INTR_TX_MASKED
I2CS_SCB__INTR_TX_SET EQU CYREG_SCB1_INTR_TX_SET
I2CS_SCB__RX_CTRL EQU CYREG_SCB1_RX_CTRL
I2CS_SCB__RX_FIFO_CTRL EQU CYREG_SCB1_RX_FIFO_CTRL
I2CS_SCB__RX_FIFO_RD EQU CYREG_SCB1_RX_FIFO_RD
I2CS_SCB__RX_FIFO_RD_SILENT EQU CYREG_SCB1_RX_FIFO_RD_SILENT
I2CS_SCB__RX_FIFO_STATUS EQU CYREG_SCB1_RX_FIFO_STATUS
I2CS_SCB__RX_MATCH EQU CYREG_SCB1_RX_MATCH
I2CS_SCB__SPI_CTRL EQU CYREG_SCB1_SPI_CTRL
I2CS_SCB__SPI_STATUS EQU CYREG_SCB1_SPI_STATUS
I2CS_SCB__SS0_POSISTION EQU 0
I2CS_SCB__SS1_POSISTION EQU 1
I2CS_SCB__SS2_POSISTION EQU 2
I2CS_SCB__SS3_POSISTION EQU 3
I2CS_SCB__STATUS EQU CYREG_SCB1_STATUS
I2CS_SCB__TX_CTRL EQU CYREG_SCB1_TX_CTRL
I2CS_SCB__TX_FIFO_CTRL EQU CYREG_SCB1_TX_FIFO_CTRL
I2CS_SCB__TX_FIFO_STATUS EQU CYREG_SCB1_TX_FIFO_STATUS
I2CS_SCB__TX_FIFO_WR EQU CYREG_SCB1_TX_FIFO_WR
I2CS_SCB__UART_CTRL EQU CYREG_SCB1_UART_CTRL
I2CS_SCB__UART_FLOW_CTRL EQU CYREG_SCB1_UART_FLOW_CTRL
I2CS_SCB__UART_RX_CTRL EQU CYREG_SCB1_UART_RX_CTRL
I2CS_SCB__UART_RX_STATUS EQU CYREG_SCB1_UART_RX_STATUS
I2CS_SCB__UART_TX_CTRL EQU CYREG_SCB1_UART_TX_CTRL

; I2CS_SCB_IRQ
I2CS_SCB_IRQ__INTC_CLR_EN_REG EQU CYREG_CM0_ICER
I2CS_SCB_IRQ__INTC_CLR_PD_REG EQU CYREG_CM0_ICPR
I2CS_SCB_IRQ__INTC_MASK EQU 0x400
I2CS_SCB_IRQ__INTC_NUMBER EQU 10
I2CS_SCB_IRQ__INTC_PRIOR_MASK EQU 0xC00000
I2CS_SCB_IRQ__INTC_PRIOR_NUM EQU 3
I2CS_SCB_IRQ__INTC_PRIOR_REG EQU CYREG_CM0_IPR2
I2CS_SCB_IRQ__INTC_SET_EN_REG EQU CYREG_CM0_ISER
I2CS_SCB_IRQ__INTC_SET_PD_REG EQU CYREG_CM0_ISPR

; I2CS_SCBCLK
I2CS_SCBCLK__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL2
I2CS_SCBCLK__DIV_ID EQU 0x00000040
I2CS_SCBCLK__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL0
I2CS_SCBCLK__PA_DIV_ID EQU 0x000000FF

; I2CS_scl
I2CS_scl__0__DR EQU CYREG_GPIO_PRT3_DR
I2CS_scl__0__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
I2CS_scl__0__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
I2CS_scl__0__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
I2CS_scl__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
I2CS_scl__0__HSIOM_GPIO EQU 0
I2CS_scl__0__HSIOM_I2C EQU 14
I2CS_scl__0__HSIOM_I2C_SCL EQU 14
I2CS_scl__0__HSIOM_MASK EQU 0x00F00000
I2CS_scl__0__HSIOM_SHIFT EQU 20
I2CS_scl__0__HSIOM_UART EQU 9
I2CS_scl__0__HSIOM_UART_TX EQU 9
I2CS_scl__0__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
I2CS_scl__0__INTR EQU CYREG_GPIO_PRT3_INTR
I2CS_scl__0__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
I2CS_scl__0__INTSTAT EQU CYREG_GPIO_PRT3_INTR
I2CS_scl__0__MASK EQU 0x20
I2CS_scl__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
I2CS_scl__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
I2CS_scl__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
I2CS_scl__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
I2CS_scl__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
I2CS_scl__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
I2CS_scl__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
I2CS_scl__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
I2CS_scl__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
I2CS_scl__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
I2CS_scl__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
I2CS_scl__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
I2CS_scl__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
I2CS_scl__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
I2CS_scl__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
I2CS_scl__0__PC EQU CYREG_GPIO_PRT3_PC
I2CS_scl__0__PC2 EQU CYREG_GPIO_PRT3_PC2
I2CS_scl__0__PORT EQU 3
I2CS_scl__0__PS EQU CYREG_GPIO_PRT3_PS
I2CS_scl__0__SHIFT EQU 5
I2CS_scl__DR EQU CYREG_GPIO_PRT3_DR
I2CS_scl__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
I2CS_scl__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
I2CS_scl__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
I2CS_scl__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
I2CS_scl__INTR EQU CYREG_GPIO_PRT3_INTR
I2CS_scl__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
I2CS_scl__INTSTAT EQU CYREG_GPIO_PRT3_INTR
I2CS_scl__MASK EQU 0x20
I2CS_scl__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
I2CS_scl__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
I2CS_scl__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
I2CS_scl__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
I2CS_scl__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
I2CS_scl__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
I2CS_scl__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
I2CS_scl__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
I2CS_scl__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
I2CS_scl__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
I2CS_scl__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
I2CS_scl__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
I2CS_scl__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
I2CS_scl__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
I2CS_scl__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
I2CS_scl__PC EQU CYREG_GPIO_PRT3_PC
I2CS_scl__PC2 EQU CYREG_GPIO_PRT3_PC2
I2CS_scl__PORT EQU 3
I2CS_scl__PS EQU CYREG_GPIO_PRT3_PS
I2CS_scl__SHIFT EQU 5

; I2CS_sda
I2CS_sda__0__DR EQU CYREG_GPIO_PRT3_DR
I2CS_sda__0__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
I2CS_sda__0__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
I2CS_sda__0__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
I2CS_sda__0__HSIOM EQU CYREG_HSIOM_PORT_SEL3
I2CS_sda__0__HSIOM_GPIO EQU 0
I2CS_sda__0__HSIOM_I2C EQU 14
I2CS_sda__0__HSIOM_I2C_SDA EQU 14
I2CS_sda__0__HSIOM_MASK EQU 0x000F0000
I2CS_sda__0__HSIOM_SHIFT EQU 16
I2CS_sda__0__HSIOM_UART EQU 9
I2CS_sda__0__HSIOM_UART_RX EQU 9
I2CS_sda__0__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
I2CS_sda__0__INTR EQU CYREG_GPIO_PRT3_INTR
I2CS_sda__0__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
I2CS_sda__0__INTSTAT EQU CYREG_GPIO_PRT3_INTR
I2CS_sda__0__MASK EQU 0x10
I2CS_sda__0__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
I2CS_sda__0__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
I2CS_sda__0__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
I2CS_sda__0__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
I2CS_sda__0__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
I2CS_sda__0__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
I2CS_sda__0__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
I2CS_sda__0__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
I2CS_sda__0__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
I2CS_sda__0__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
I2CS_sda__0__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
I2CS_sda__0__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
I2CS_sda__0__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
I2CS_sda__0__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
I2CS_sda__0__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
I2CS_sda__0__PC EQU CYREG_GPIO_PRT3_PC
I2CS_sda__0__PC2 EQU CYREG_GPIO_PRT3_PC2
I2CS_sda__0__PORT EQU 3
I2CS_sda__0__PS EQU CYREG_GPIO_PRT3_PS
I2CS_sda__0__SHIFT EQU 4
I2CS_sda__DR EQU CYREG_GPIO_PRT3_DR
I2CS_sda__DR_CLR EQU CYREG_GPIO_PRT3_DR_CLR
I2CS_sda__DR_INV EQU CYREG_GPIO_PRT3_DR_INV
I2CS_sda__DR_SET EQU CYREG_GPIO_PRT3_DR_SET
I2CS_sda__INTCFG EQU CYREG_GPIO_PRT3_INTR_CFG
I2CS_sda__INTR EQU CYREG_GPIO_PRT3_INTR
I2CS_sda__INTR_CFG EQU CYREG_GPIO_PRT3_INTR_CFG
I2CS_sda__INTSTAT EQU CYREG_GPIO_PRT3_INTR
I2CS_sda__MASK EQU 0x10
I2CS_sda__PA__CFG0 EQU CYREG_UDB_PA3_CFG0
I2CS_sda__PA__CFG1 EQU CYREG_UDB_PA3_CFG1
I2CS_sda__PA__CFG10 EQU CYREG_UDB_PA3_CFG10
I2CS_sda__PA__CFG11 EQU CYREG_UDB_PA3_CFG11
I2CS_sda__PA__CFG12 EQU CYREG_UDB_PA3_CFG12
I2CS_sda__PA__CFG13 EQU CYREG_UDB_PA3_CFG13
I2CS_sda__PA__CFG14 EQU CYREG_UDB_PA3_CFG14
I2CS_sda__PA__CFG2 EQU CYREG_UDB_PA3_CFG2
I2CS_sda__PA__CFG3 EQU CYREG_UDB_PA3_CFG3
I2CS_sda__PA__CFG4 EQU CYREG_UDB_PA3_CFG4
I2CS_sda__PA__CFG5 EQU CYREG_UDB_PA3_CFG5
I2CS_sda__PA__CFG6 EQU CYREG_UDB_PA3_CFG6
I2CS_sda__PA__CFG7 EQU CYREG_UDB_PA3_CFG7
I2CS_sda__PA__CFG8 EQU CYREG_UDB_PA3_CFG8
I2CS_sda__PA__CFG9 EQU CYREG_UDB_PA3_CFG9
I2CS_sda__PC EQU CYREG_GPIO_PRT3_PC
I2CS_sda__PC2 EQU CYREG_GPIO_PRT3_PC2
I2CS_sda__PORT EQU 3
I2CS_sda__PS EQU CYREG_GPIO_PRT3_PS
I2CS_sda__SHIFT EQU 4

; PWM_1_PWMUDB
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL0
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_UDB_W16_CTL0
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_UDB_W16_CTL0
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_UDB_W16_CTL0
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_UDB_W16_CTL0
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_UDB_W16_MSK0
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_UDB_W16_MSK0
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_UDB_W16_MSK0
PWM_1_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_UDB_W16_MSK0
PWM_1_PWMUDB_genblk1_ctrlreg__32BIT_CONTROL_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL
PWM_1_PWMUDB_genblk1_ctrlreg__32BIT_CONTROL_REG EQU CYREG_UDB_W32_CTL
PWM_1_PWMUDB_genblk1_ctrlreg__32BIT_COUNT_REG EQU CYREG_UDB_W32_CTL
PWM_1_PWMUDB_genblk1_ctrlreg__32BIT_PERIOD_REG EQU CYREG_UDB_W32_MSK
PWM_1_PWMUDB_genblk1_ctrlreg__7__MASK EQU 0x80
PWM_1_PWMUDB_genblk1_ctrlreg__7__POS EQU 7
PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL0
PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_REG EQU CYREG_UDB_W8_CTL0
PWM_1_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG EQU CYREG_UDB_CAT16_CTL_ST0
PWM_1_PWMUDB_genblk1_ctrlreg__COUNT_REG EQU CYREG_UDB_W8_CTL0
PWM_1_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG EQU CYREG_UDB_CAT16_CTL_ST0
PWM_1_PWMUDB_genblk1_ctrlreg__MASK EQU 0x80
PWM_1_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PWM_1_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PWM_1_PWMUDB_genblk1_ctrlreg__PERIOD_REG EQU CYREG_UDB_W8_MSK0
PWM_1_PWMUDB_genblk8_stsreg__0__MASK EQU 0x01
PWM_1_PWMUDB_genblk8_stsreg__0__POS EQU 0
PWM_1_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL0
PWM_1_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG EQU CYREG_UDB_W16_ST0
PWM_1_PWMUDB_genblk8_stsreg__2__MASK EQU 0x04
PWM_1_PWMUDB_genblk8_stsreg__2__POS EQU 2
PWM_1_PWMUDB_genblk8_stsreg__3__MASK EQU 0x08
PWM_1_PWMUDB_genblk8_stsreg__3__POS EQU 3
PWM_1_PWMUDB_genblk8_stsreg__32BIT_MASK_REG EQU CYREG_UDB_W32_MSK
PWM_1_PWMUDB_genblk8_stsreg__32BIT_STATUS_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL
PWM_1_PWMUDB_genblk8_stsreg__32BIT_STATUS_REG EQU CYREG_UDB_W32_ST
PWM_1_PWMUDB_genblk8_stsreg__MASK EQU 0x0D
PWM_1_PWMUDB_genblk8_stsreg__MASK_REG EQU CYREG_UDB_W8_MSK0
PWM_1_PWMUDB_genblk8_stsreg__MASK_ST_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PWM_1_PWMUDB_genblk8_stsreg__PER_ST_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PWM_1_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL0
PWM_1_PWMUDB_genblk8_stsreg__STATUS_CNT_REG EQU CYREG_UDB_CAT16_CTL_ST0
PWM_1_PWMUDB_genblk8_stsreg__STATUS_CONTROL_REG EQU CYREG_UDB_CAT16_CTL_ST0
PWM_1_PWMUDB_genblk8_stsreg__STATUS_REG EQU CYREG_UDB_W8_ST0
PWM_1_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG EQU CYREG_UDB_W16_A00
PWM_1_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG EQU CYREG_UDB_W16_A10
PWM_1_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG EQU CYREG_UDB_W16_D00
PWM_1_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG EQU CYREG_UDB_W16_D10
PWM_1_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W16_ACTL0
PWM_1_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG EQU CYREG_UDB_W16_F00
PWM_1_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG EQU CYREG_UDB_W16_F10
PWM_1_PWMUDB_sP8_pwmdp_u0__32BIT_A0_REG EQU CYREG_UDB_W32_A0
PWM_1_PWMUDB_sP8_pwmdp_u0__32BIT_A1_REG EQU CYREG_UDB_W32_A1
PWM_1_PWMUDB_sP8_pwmdp_u0__32BIT_D0_REG EQU CYREG_UDB_W32_D0
PWM_1_PWMUDB_sP8_pwmdp_u0__32BIT_D1_REG EQU CYREG_UDB_W32_D1
PWM_1_PWMUDB_sP8_pwmdp_u0__32BIT_DP_AUX_CTL_REG EQU CYREG_UDB_W32_ACTL
PWM_1_PWMUDB_sP8_pwmdp_u0__32BIT_F0_REG EQU CYREG_UDB_W32_F0
PWM_1_PWMUDB_sP8_pwmdp_u0__32BIT_F1_REG EQU CYREG_UDB_W32_F1
PWM_1_PWMUDB_sP8_pwmdp_u0__A0_A1_REG EQU CYREG_UDB_CAT16_A0
PWM_1_PWMUDB_sP8_pwmdp_u0__A0_REG EQU CYREG_UDB_W8_A00
PWM_1_PWMUDB_sP8_pwmdp_u0__A1_REG EQU CYREG_UDB_W8_A10
PWM_1_PWMUDB_sP8_pwmdp_u0__D0_D1_REG EQU CYREG_UDB_CAT16_D0
PWM_1_PWMUDB_sP8_pwmdp_u0__D0_REG EQU CYREG_UDB_W8_D00
PWM_1_PWMUDB_sP8_pwmdp_u0__D1_REG EQU CYREG_UDB_W8_D10
PWM_1_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG EQU CYREG_UDB_W8_ACTL0
PWM_1_PWMUDB_sP8_pwmdp_u0__F0_F1_REG EQU CYREG_UDB_CAT16_F0
PWM_1_PWMUDB_sP8_pwmdp_u0__F0_REG EQU CYREG_UDB_W8_F00
PWM_1_PWMUDB_sP8_pwmdp_u0__F1_REG EQU CYREG_UDB_W8_F10
PWM_1_PWMUDB_sP8_pwmdp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0
PWM_1_PWMUDB_sP8_pwmdp_u0__PER_DP_AUX_CTL_REG EQU CYREG_UDB_CAT16_ACTL_MSK0

; Clock_1
Clock_1__CTRL_REGISTER EQU CYREG_PERI_PCLK_CTL11
Clock_1__DIV_ID EQU 0x00000041
Clock_1__DIV_REGISTER EQU CYREG_PERI_DIV_16_CTL1
Clock_1__PA_DIV_ID EQU 0x000000FF

; Miscellaneous
CYDEV_BCLK__HFCLK__HZ EQU 24000000
CYDEV_BCLK__HFCLK__KHZ EQU 24000
CYDEV_BCLK__HFCLK__MHZ EQU 24
CYDEV_BCLK__SYSCLK__HZ EQU 24000000
CYDEV_BCLK__SYSCLK__KHZ EQU 24000
CYDEV_BCLK__SYSCLK__MHZ EQU 24
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PANTHER EQU 19
CYDEV_CHIP_DIE_PSOC4A EQU 11
CYDEV_CHIP_DIE_PSOC5LP EQU 18
CYDEV_CHIP_DIE_TMA4 EQU 2
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC4
CYDEV_CHIP_JTAG_ID EQU 0x1A1611AA
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 11
CYDEV_CHIP_MEMBER_4C EQU 16
CYDEV_CHIP_MEMBER_4D EQU 7
CYDEV_CHIP_MEMBER_4E EQU 4
CYDEV_CHIP_MEMBER_4F EQU 12
CYDEV_CHIP_MEMBER_4G EQU 2
CYDEV_CHIP_MEMBER_4H EQU 10
CYDEV_CHIP_MEMBER_4I EQU 15
CYDEV_CHIP_MEMBER_4J EQU 8
CYDEV_CHIP_MEMBER_4K EQU 9
CYDEV_CHIP_MEMBER_4L EQU 14
CYDEV_CHIP_MEMBER_4M EQU 13
CYDEV_CHIP_MEMBER_4N EQU 6
CYDEV_CHIP_MEMBER_4O EQU 5
CYDEV_CHIP_MEMBER_4U EQU 3
CYDEV_CHIP_MEMBER_5A EQU 18
CYDEV_CHIP_MEMBER_5B EQU 17
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_4F
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_MEMBER_USED
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CHIP_REV_TMA4_ES EQU 17
CYDEV_CHIP_REV_TMA4_ES2 EQU 33
CYDEV_CHIP_REV_TMA4_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4C_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4D_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4E_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA EQU 0
CYDEV_CHIP_REVISION_4F_PRODUCTION_256K EQU 0
CYDEV_CHIP_REVISION_4G_ES EQU 17
CYDEV_CHIP_REVISION_4G_ES2 EQU 33
CYDEV_CHIP_REVISION_4G_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_4H_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4I_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4J_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4K_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4L_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4M_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4N_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4O_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_4U_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REVISION_USED
CYDEV_CONFIG_READ_ACCELERATOR EQU 1
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_DEBUG_PROTECT_KILL EQU 4
CYDEV_DEBUG_PROTECT_OPEN EQU 1
CYDEV_DEBUG_PROTECT EQU CYDEV_DEBUG_PROTECT_OPEN
CYDEV_DEBUG_PROTECT_PROTECTED EQU 2
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_DPS_SWD EQU 2
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DFT_SELECT_CLK0 EQU 10
CYDEV_DFT_SELECT_CLK1 EQU 11
CYDEV_DMA_CHANNELS_AVAILABLE EQU 8
CYDEV_HEAP_SIZE EQU 0x0100
CYDEV_IMO_TRIMMED_BY_USB EQU 0
CYDEV_IMO_TRIMMED_BY_WCO EQU 0
CYDEV_INTR_NUMBER_DMA EQU 21
CYDEV_IS_EXPORTING_CODE EQU 0
CYDEV_IS_IMPORTING_CODE EQU 0
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LAUNCHER EQU 5
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER EQU 4
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_STACK_SIZE EQU 0x0400
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VARIABLE_VDDA EQU 1
CYDEV_VDDA_MV EQU 3300
CYDEV_VDDD_MV EQU 3300
CYDEV_VDDR_MV EQU 3300
CYDEV_WDT_GENERATE_ISR EQU 0
CYIPBLOCK_m0s8bless_VERSION EQU 2
CYIPBLOCK_m0s8cpussv2_VERSION EQU 1
CYIPBLOCK_m0s8ioss_VERSION EQU 1
CYIPBLOCK_m0s8lpcomp_VERSION EQU 2
CYIPBLOCK_m0s8peri_VERSION EQU 1
CYIPBLOCK_m0s8scb_VERSION EQU 2
CYIPBLOCK_m0s8srssv2_VERSION EQU 1
CYIPBLOCK_m0s8tcpwm_VERSION EQU 2
CYIPBLOCK_m0s8udbif_VERSION EQU 1
CYIPBLOCK_s8pass4al_VERSION EQU 1
DMA_CHANNELS_USED__MASK EQU 0
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END
