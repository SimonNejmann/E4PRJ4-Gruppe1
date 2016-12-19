#include <project.h>
#include <stdio.h>

#define PACKETSIZE 33
#define BUFFER_SIZE 9
struct mouse {
    uint8 tmpMouseX[8];
    uint8 tmpMouseY[8];
    uint8 status[8];
    uint16 timesInterrupted;
    uint16 distance;
    uint16 thresholdActive;
    uint8 angle;
    uint8 oldAngle;
    int16 finalX;
    int16 finalY;
    
    
    
};

void Init(struct mouse *); 
void printBinaryData(uint8 *statusData, uint8 *xData, uint8 *yData);
void getMouseData(struct mouse *mouseData);
void initMouse(uint8 *Data);
void ISR_getMouseData(struct mouse *);
void printData(struct mouse *);
void resetMouseData(struct mouse *);
void calcDistance(struct mouse *);
void calcAngle(struct mouse *);
void controlVehicle(struct mouse*);
int8 WriteI2CData(uint8_t *Data);
uint8 stabil(uint8 ang);



