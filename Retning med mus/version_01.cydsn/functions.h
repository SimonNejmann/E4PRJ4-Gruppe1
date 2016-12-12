#include <project.h>
#include <stdio.h>

#define PACKETSIZE 33
#define I2C_SLAVE_ADDR 8
#define BUFFER_SIZE 4

struct mouse {
    uint8 tmpMouseX[8];
    uint8 tmpMouseY[8];
    uint8 status[8];
    uint16 timesInterrupted;
    
    uint8 angle;
    int16 finalX;
    int16 finalY;
    
    
    
};

void Init(struct mouse *); 
void printBinaryData(uint8 *statusData, uint8 *xData, uint8 *yData);
void getMouseData(struct mouse *mouseData);
void initMouse(uint8 *Data);
void ISR_getMouseData(struct mouse *);
void printData(struct mouse *);
int8 WriteI2CData(uint8_t *Data);



