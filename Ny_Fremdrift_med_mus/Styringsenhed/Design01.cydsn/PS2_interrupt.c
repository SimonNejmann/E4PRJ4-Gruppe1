#include <project.h>
#include <functions.h>
char value[20];
extern struct mouse mouseData;

extern uint8 i2c_buffer[BUFFER_SIZE];
CY_ISR(PS2_interrupt) { 
        ISR_getMouseData(&mouseData);
        isr_PS2_clock_ClearPending();
}
