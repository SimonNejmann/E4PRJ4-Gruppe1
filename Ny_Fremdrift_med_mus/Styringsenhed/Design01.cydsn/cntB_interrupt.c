#include <project.h>
#include <functions.h>

CY_ISR(cntB_interrupt) { 

    CyGlobalIntDisable;
    PWMB1_Stop();
    PWMB2_Stop();
    isr_cntB_compare_ClearPending();
    CyGlobalIntEnable;

}
