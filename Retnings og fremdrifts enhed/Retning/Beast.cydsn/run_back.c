#include <main.h>

void run_back(uint8 ang_2, uint8 speed_2)
{
    int8 ang = (int8)ang_2;
    PWM_DRIFT_WriteCompare2(speed_2);
}