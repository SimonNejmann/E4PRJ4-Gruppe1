#include <project.h>
#include <stdio.h>
#include <functions.h>
#include <math.h>


#define MOUSEBUTTON_XYOVERFLOW 0
#define X_MOVEMENT 1
#define Y_MOVEMENT 1
#define PACKETSIZE 33

struct mouse mouseData;


CY_ISR_PROTO(PS2_interrupt);

int main()
{
    Init(&mouseData);
    UART_1_Start();
    char value[20];
    isr_PS2_clock_StartEx(PS2_interrupt);
    isr_PS2_clock_ClearPending();
    CyGlobalIntEnable;

    for(;;)
    {
      

    }
}