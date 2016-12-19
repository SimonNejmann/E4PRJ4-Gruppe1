#include <project.h>
#include <functions.h>
char value[20];
extern struct mouse mouseData;

extern uint8 i2c_buffer[BUFFER_SIZE];
CY_ISR(PS2_interrupt) { 
        getMouseData(&mouseData);
        calcDistance(&mouseData);
        calcAngle(&mouseData);
        controlVehicle(&mouseData);
        isr_PS2_clock_ClearPending();
}
