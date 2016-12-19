#if !defined(CY_MAIN_H)
#define CY_MAIN_H
    
#include <project.h>
    
CY_ISR_PROTO(PS2_interrupt);
CY_ISR_PROTO(cntF_interrupt);
CY_ISR_PROTO(cntB_interrupt);
/*****************************
     Funktion Prototype
*****************************/
 
uint8 steer(uint8 ang);
uint8 strafe(uint8 ang);
void Init_step();



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