#include <project.h>
#include <functions.h>
char value[20];
extern struct mouse mouseData;
CY_ISR(PS2_interrupt) { 

    //CyGlobalIntDisable;
        ISR_getMouseData(&mouseData);
        isr_PS2_clock_ClearPending();
//    CyGlobalIntEnable;

}
