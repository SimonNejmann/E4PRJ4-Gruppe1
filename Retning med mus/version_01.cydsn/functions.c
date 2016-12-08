#include <project.h>
#include <functions.h>
#include <math.h>
#include <stdio.h>
#include <main.h>
#define THRESHOLD 50

int16 mouseDataX = 0;
int16 mouseDataY = 0;
int16 *statusData;



int16 mouseX_global = 0;

void Init(struct mouse *mouseData) {
    //UART_1_Start();

    
    /****************************Struct init********************************/
    int8 i = 0;
    for (i = 0; i < 8; i++) {
        mouseData->tmpMouseX[i] = 0;
        mouseData->tmpMouseY[i] = 0; 
        mouseData->status[i] = 0; 
    }
    mouseData->finalX = 0;
    mouseData->timesInterrupted = 0;
    mouseData->angle = 0;
    
    /*********************Initializing mouse********************************/
    
    
    uint8 initData[8] = {1, 1, 1, 1, 0, 1, 0, 0};
    initMouse(initData);

    
    
    /****************************Enabling Interrupts************************/
    
}

void printBinaryData(uint8 *statusData, uint8 *xData, uint8 *yData) {
   char value[20];
   int8 i = 0;
   for(i = 0; i < 8; i++) {
            
            if (i == 7) {
                sprintf(value,"%d | ",statusData[i]);
                //UART_1_UartPutString(value);
            }
            else {
                
                sprintf(value,"%d",statusData[i]);
                //UART_1_UartPutString(value);
            }
            
        }
        
        for(i = 0; i < 8; i++) {
            
            if (i == 7) {
                sprintf(value,"%d | ",xData[i]);
                //UART_1_UartPutString(value);
            }
            else {
                
                sprintf(value,"%d",xData[i]);
                //UART_1_UartPutString(value);
            }
            
        }
        
        for(i = 0; i < 8; i++) {
            
            if (i == 7) {
                //sprintf(value,"%d \n\r",yData[i]);
               // UART_1_UartPutString(value);
            }
            else {
                
               //sprintf(value,"%d",yData[i]);
               // UART_1_UartPutString(value);
            }
            
        }   
}

void ISR_getMouseData(struct mouse *mouseData) {

    int deg = 180/3.14*10;
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
    mouseData->timesInterrupted++;
    distance = sqrt((mouseData->finalX*mouseData->finalX)+(mouseData->finalY*mouseData->finalY));
    
        if (distance > THRESHOLD || distance < -THRESHOLD) {
        
            if (mouseData->finalX >= 0 && mouseData->finalY > 0) {
                mouseData->angle = (asin(((float)mouseData->finalX)/(float)distance)*deg)/10/1.8;  
            }
            
            else if (mouseData->finalX > 0 && mouseData->finalY < 0) {
                mouseData->angle = ((asin(((float)-mouseData->finalY)/(float)distance)*deg)+900)/10/1.8;
            }
            
            else if (mouseData->finalX <= 0 && mouseData->finalY < 0) {
                mouseData->angle = ((asin(((float)-mouseData->finalX)/(float)distance)*deg)+1800)/10/1.8;
            }
            
            else if (mouseData->finalX < 0 && mouseData->finalY >=          0) {
                mouseData->angle = ((asin(((float)mouseData->finalY)/(float)distance)*deg)+2700)/10/1.8;
            }
       
            stabil(mouseData->angle);

    }
        
    if (mouseData->timesInterrupted == 250) {
        mouseData->finalX = 0;
        mouseData->finalY = 0;
        mouseData->timesInterrupted = 0;
        stabil(200);
    }
//    sprintf(value,"X = %d | ",mouseData->finalX);
//    //UART_1_UartPutString(value);
//    sprintf(value,"Y = %d \n\r",mouseData->finalY);
//    //UART_1_UartPutString(value);
//    sprintf(value,"Distance = %d | ",distance);
//    //UART_1_UartPutString(value);
//    sprintf(value,"Angle = %d \n\r",angle);
//    //UART_1_UartPutString(value);
    
    
    
    
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

//void printData(struct mouse *mouseData) {
//    char value[20];
//    sprintf(value,"X = %d | \n\r",mouseData->finalX);
//    UART_1_UartPutString(value);
//}

//int8 WriteI2CData(uint8_t *Data) {
//
//    /* Initialize buffer with packet */
//    (void) I2C_1_I2CMasterWriteBuf(I2C_SLAVE_ADDR, Data, BUFFER_SIZE, \
//                                  I2C_1_I2C_MODE_COMPLETE_XFER);
//    while (0u == (I2C_1_I2CMasterStatus() & I2C_1_I2C_MSTAT_WR_CMPLT))
//    {
//    }
//
//    if (I2C_1_I2CMasterGetWriteBufSize()== BUFFER_SIZE) {
//        return 1;
//    }
//    
//    else {
//        return 0;
//    }
//}

