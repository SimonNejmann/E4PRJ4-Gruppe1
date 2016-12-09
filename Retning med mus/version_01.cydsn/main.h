#if !defined(CY_MAIN_H)
#define CY_MAIN_H
    
#include <project.h>
    
    
/*****************************
     Funktion Prototype
*****************************/
 
uint8 steer(uint8 ang, uint8 ang2);
uint8 strafe(uint8 ang, uint8 ang2);
uint8 stabil(uint8 ang);
void init_step();
#define SLAVE_ADDRESS       (0x49u)
/* Buffer and packet size */
#define BUFFER_SIZE         (8u)
#define BUFFER_RW_AREA      (4u)


/* I2C Array positions */
#define ANG_FRONT_POS       (0u)
#define SPEED_FRONT_POS     (1u)
#define ANG_BACK_POS        (2u)
#define SPEED_BACK_POS      (3u)

/*Stepper angle min and max positions*/
#define MIN_POS             (0u)
#define MAX_POS             (201u)

/* Logic levels */
#define HIGH                (1u)
#define LOW                 (0u)
    
    
#endif /*CY_MAIN_H */