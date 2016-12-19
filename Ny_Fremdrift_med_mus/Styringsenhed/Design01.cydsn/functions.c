#include <project.h>
#include <functions.h>
#include <math.h>
#include <stdio.h>
#include <main.h>
#define THRESHOLD 1000

int16 mouseDataX = 0;
int16 mouseDataY = 0;
int16 *statusData;

extern CY_ISR_PROTO(PS2_interrupt);
extern CY_ISR_PROTO(cntF_interrupt);
extern CY_ISR_PROTO(cntB_interrupt);

int16 mouseX_global = 0;

void Init(struct mouse *mouseData) {
    //Variable
    uint8 initData[8] = {1, 1, 1, 1, 0, 1, 0, 0};

    /***********************************************************************/
    
    /***************************************************************************/
    /****************************Interrupt init*********************************/
    /***************************************************************************/
    isr_PS2_clock_StartEx(PS2_interrupt);
    isr_PS2_clock_ClearPending();
    
    
    /****************************Struct init********************************/
    resetMouseData(mouseData);
    
    /*********************Initializing mouse********************************/
    initMouse(initData);

    /****************************Enabling Interrupts************************/
    
}

void ISR_getMouseData(struct mouse *mouseData) {

    
    uint8 i = 0;
    char value[20];
    int16 multiplier = 1;
    uint8 tempData = 0;
    int8 j = 7;
    
    int distance = 0;
    int angle;

    
    int16 tmpX = 0;
    int16 tmpY = 0;
    while (i < PACKETSIZE) {
        if (i == 0 && PS2_Data_Read() == 1) {
            return;
        }
        
        else {
            if (i != 0) {
                while(PS2_Clock_Read());
            }
            
            if(i > 0 && i < 9) {
                mouseData->status[i-1] = PS2_Data_Read();
            }
            else if(i > 11 && i < 20) {
                mouseData->tmpMouseX[i-12] = PS2_Data_Read();
            }
            
            else if(i > 22 && i < 31) {
                mouseData->tmpMouseY[i-23] = PS2_Data_Read();
            }
            if(i == 32) {
                
            }
            else {
                while(!PS2_Clock_Read());
            }
        
        }
        i++;
    }
    
    //Laver binary om til decimal
    
    if (mouseData->status[4])
        tmpX = -1;
    if (mouseData->status[5]) {
        tmpY = -1;
    }
    for (j = 0; j<7; j++ )
    {
        if (mouseData->tmpMouseX[j]) {
            tmpX |= 1<<j;
        } 
        else {
            tmpX &= ~(1<<j);
        }
        
        if (mouseData->tmpMouseY[j]) {
            tmpY |= 1<<j;
        } 
        else {
            tmpY &= ~(1<<j);
        }
    }
    mouseData->finalX += tmpX;
    mouseData->finalY += tmpY;
    
    
    
        
        
        

        
}

void calcDistance(struct mouse *mouseData) {
    mouseData->distance = sqrt((mouseData->finalX*mouseData->finalX)+(mouseData->finalY*mouseData->finalY));
}

void calcAngle(struct mouse *mouseData) {
    int deg = 180/3.14*10;
    if (mouseData->finalX > 0 && mouseData->finalY > 0) {
        mouseData->angle = (asin(((float)mouseData->finalX)/(float)mouseData->distance)*deg)/10/1.8;  
    }
    
    else if (mouseData->finalX > 0 && mouseData->finalY < 0) {
        mouseData->angle = ((asin(((float)-mouseData->finalY)/(float)mouseData->distance)*deg)+900)/10/1.8;
    }
    
    else if (mouseData->finalX < 0 && mouseData->finalY < 0) {
        mouseData->angle = ((asin(((float)-mouseData->finalX)/(float)mouseData->distance)*deg)+1800)/10/1.8;
    }
    
    else if (mouseData->finalX < 0 && mouseData->finalY > 0) {
        mouseData->angle = ((asin(((float)mouseData->finalY)/(float)mouseData->distance)*deg)+2700)/10/1.8;
    }
}

void controlVehicle(struct mouse *mouseData) {
    if (mouseData->angle != mouseData->oldAngle) {      
            stabil(mouseData->angle);
            mouseData->oldAngle = mouseData->angle;
        }
        if (mouseData->distance > THRESHOLD) {
            PWMSF_WriteCompare(mouseData->distance/40);
        }
        else {
            PWMSF_WriteCompare(0);
        }
        
        if (mouseData->distance > 4000) {
            PWMSF_WriteCompare(0);
        }
        CyDelay(50);
}

void resetMouseData(struct mouse *mouseData) {
    int8 i = 0;
    for (i = 0; i < 8; i++) {
        mouseData->tmpMouseX[i] = 0;
        mouseData->tmpMouseY[i] = 0; 
        mouseData->status[i] = 0; 
    }
    mouseData->finalX = 0;
    mouseData->finalY = 0;
    mouseData->timesInterrupted = 20000;
    mouseData->angle = 0;
    mouseData->oldAngle = 0;
    mouseData->thresholdActive = 0;
    
}


void initMouse(uint8 *Data) {
    uint8 i = 0;
    const uint8 dataSize = 8;
    
    PS2_Clock_Write(0);
    
    CyDelayUs(150);
    PS2_Data_Write(0);
    
    PS2_Clock_Write(1);
    PS2_Clock_Read();
    while (i < 11){
        
        while(PS2_Clock_Read());
        
        if (i == 0) {
           PS2_Data_Write(0);
        }
        
        else if (i == 9) {
           PS2_Data_Write(0);
        }
        
        else if (i == 10) {
           PS2_Data_Write(1);
        }
        
        else {
           PS2_Data_Write(Data[dataSize-i]);
        }
        
        if (i < 10) {
            while(!PS2_Clock_Read());
        }
        i++;
    }
    PS2_Data_Read();
    PS2_Clock_Read();
}


