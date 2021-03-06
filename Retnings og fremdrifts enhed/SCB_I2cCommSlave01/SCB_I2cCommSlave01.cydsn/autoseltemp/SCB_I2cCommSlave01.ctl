-- ======================================================================
-- SCB_I2cCommSlave01.ctl generated from SCB_I2cCommSlave01
-- 11/15/2016 at 14:40
-- This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
-- ======================================================================

-- TopDesign
-- =============================================================================
-- The following directives assign pins to the locations specific for the
-- CY8CKIT-042-BLE kit.
-- =============================================================================

-- === I2C slave (SCB mode) ===
attribute port_location of \I2CS:scl(0)\ : label is "PORT(3,5)";
attribute port_location of \I2CS:sda(0)\ : label is "PORT(3,4)";

-- === RGB LED ===
attribute port_location of LED_RED(0)   : label is "PORT(2,6)";
attribute port_location of LED_GREEN(0) : label is "PORT(3,6)";
attribute port_location of LED_BLUE(0)  : label is "PORT(3,7)";

-- M0S8 Clock Editor
-- Directives Editor
-- Analog Device Editor
