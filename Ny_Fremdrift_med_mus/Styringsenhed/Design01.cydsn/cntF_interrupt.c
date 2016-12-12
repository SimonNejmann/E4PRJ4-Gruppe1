#include <project.h>
#include <functions.h>

CY_ISR(cntF_interrupt) { 

    CyGlobalIntDisable;
    PWMF1_Stop();
    PWMF2_Stop();
    isr_cntF_compare_ClearPending();
    CyGlobalIntEnable;

}