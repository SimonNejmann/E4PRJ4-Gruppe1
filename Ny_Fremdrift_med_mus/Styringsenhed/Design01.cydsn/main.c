/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"
#include <functions.h>
#include <main.h>

#define BUFFER_SIZE 3

struct mouse mouseData;

CY_ISR_PROTO(PS2_interrupt);
CY_ISR_PROTO(cntF_interrupt);
CY_ISR_PROTO(cntB_interrupt);
uint8 i2c_buffer[BUFFER_SIZE];
uint8 oldStrafe_i2c_buffer[BUFFER_SIZE] = {0};
uint8 oldSteer_i2c_buffer[BUFFER_SIZE] = {0};
int main(void)
{
    
    Init(&mouseData);
    
    I2C_Slave_SetBuffer1(BUFFER_SIZE,BUFFER_SIZE,i2c_buffer);
    
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    uint8 strafeMode = 0;
    uint8 steerMode = 0;
    int8 i = 0;
    for(;;)
    {
        /* Place your application code here. */
        if (i2c_buffer[1] == 0) {
            PWMSF_WriteCompare(0);
            isr_PS2_clock_Enable();
        }
        
        else {
            
            isr_PS2_clock_Disable();
            resetMouseData(&mouseData);
            
            
            //Steer
            if (i2c_buffer[2] == 0) {
                PWMB1_Stop();
                PWMB2_Stop();
                PWMSF_WriteCompare(i2c_buffer[1]);
                PWMSB_WriteCompare(0);
                steerMode = 1;
                if (strafeMode == 1) {
                    oldSteer_i2c_buffer[0] = oldStrafe_i2c_buffer[0]/2;
                    strafeMode = 0;
                }
                if (i2c_buffer[0] != oldSteer_i2c_buffer[0]) {
                    oldSteer_i2c_buffer[0] = i2c_buffer[0];
                    PWMSF_WriteCompare(i2c_buffer[1]);
                    steer(i2c_buffer[0]);
                }
            }
            
            //Strafe
            else if (i2c_buffer[2] == 255) {
                strafeMode = 1;
                PWMSF_WriteCompare(i2c_buffer[1]);
                PWMSB_WriteCompare(i2c_buffer[1]);
                if (steerMode == 1) {
                    if (oldSteer_i2c_buffer[0] == 100) {
                        oldSteer_i2c_buffer[0]--;
                    }
                    oldStrafe_i2c_buffer[0] = (oldSteer_i2c_buffer[0]/2)+50;
                    steerMode = 0;
                }
                if(i2c_buffer[0] != oldStrafe_i2c_buffer[0]){
                    oldStrafe_i2c_buffer[0] = i2c_buffer[0];
                    PWMSF_WriteCompare(i2c_buffer[1]);
                    PWMSB_WriteCompare(i2c_buffer[1]);
                    strafe(i2c_buffer[0]);
                    
                }
            }
        }
    }
}

/* [] END OF FILE */
