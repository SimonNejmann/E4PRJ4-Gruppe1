# THIS FILE IS AUTOMATICALLY GENERATED
# Project: E:\Projekt 4. semester\HellYaeh\SCB_I2cCommSlave01\SCB_I2cCommSlave01.cydsn\SCB_I2cCommSlave01.cyprj
# Date: Tue, 15 Nov 2016 13:40:51 GMT
#set_units -time ns
create_clock -name {I2CS_SCBCLK(FFB)} -period 125 -waveform {0 62.5} [list [get_pins {ClockBlock/ff_div_2}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]
create_clock -name {CyWCO} -period 30517.578125 -waveform {0 15258.7890625} [list [get_pins {ClockBlock/wco}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyECO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/eco}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 961 1921} [list [get_pins {ClockBlock/udb_div_0}]]
create_generated_clock -name {I2CS_SCBCLK} -source [get_pins {ClockBlock/hfclk}] -edges {1 3 7} [list]


# Component constraints for E:\Projekt 4. semester\HellYaeh\SCB_I2cCommSlave01\SCB_I2cCommSlave01.cydsn\TopDesign\TopDesign.cysch
# Project: E:\Projekt 4. semester\HellYaeh\SCB_I2cCommSlave01\SCB_I2cCommSlave01.cydsn\SCB_I2cCommSlave01.cyprj
# Date: Tue, 15 Nov 2016 13:40:47 GMT