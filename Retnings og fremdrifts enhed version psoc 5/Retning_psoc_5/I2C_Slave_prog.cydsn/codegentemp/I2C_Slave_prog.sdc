# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Anders\Desktop\Projekt 4. semester\E4PRJ4-Gruppe1\Retnings og fremdrifts enhed version psoc 5\Retning_psoc_5\I2C_Slave_prog.cydsn\I2C_Slave_prog.cyprj
# Date: Sun, 04 Dec 2016 13:24:01 GMT
#set_units -time ns
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {CyBUS_CLK(fixed-function)} -period 41.666666666666664 -waveform {0 20.8333333333333} [get_pins {ClockBlock/clk_bus_glb_ff}]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/clk_sync}] -edges {1 121 241} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 120001 240001} [list [get_pins {ClockBlock/dclk_glb_1}]]


# Component constraints for C:\Users\Anders\Desktop\Projekt 4. semester\E4PRJ4-Gruppe1\Retnings og fremdrifts enhed version psoc 5\Retning_psoc_5\I2C_Slave_prog.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Anders\Desktop\Projekt 4. semester\E4PRJ4-Gruppe1\Retnings og fremdrifts enhed version psoc 5\Retning_psoc_5\I2C_Slave_prog.cydsn\I2C_Slave_prog.cyprj
# Date: Sun, 04 Dec 2016 13:23:56 GMT
