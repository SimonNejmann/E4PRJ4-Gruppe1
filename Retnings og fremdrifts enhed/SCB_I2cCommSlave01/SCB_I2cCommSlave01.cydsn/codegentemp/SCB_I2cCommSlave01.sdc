# THIS FILE IS AUTOMATICALLY GENERATED
# Project: E:\Projekt 4. semester\HellYaeh\SCB_I2cCommSlave01\SCB_I2cCommSlave01.cydsn\SCB_I2cCommSlave01.cyprj
# Date: Tue, 15 Nov 2016 13:58:54 GMT
#set_units -time ns
create_clock -name {Clock_1(FFB)} -period 2083.333333333333 -waveform {0 1041.66666666667} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {I2CS_SCBCLK(FFB)} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/ff_div_3}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 51 99} -nominal_period 2083.333333333333 [list]
create_generated_clock -name {I2CS_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 7} [list]


# Component constraints for E:\Projekt 4. semester\HellYaeh\SCB_I2cCommSlave01\SCB_I2cCommSlave01.cydsn\TopDesign\TopDesign.cysch
# Project: E:\Projekt 4. semester\HellYaeh\SCB_I2cCommSlave01\SCB_I2cCommSlave01.cydsn\SCB_I2cCommSlave01.cyprj
# Date: Tue, 15 Nov 2016 13:58:51 GMT
