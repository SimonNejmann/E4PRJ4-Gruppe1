#if !defined(CY_MAIN_H)
#define CY_MAIN_H
    
#include <project.h>
    
    
/*****************************
     Funktion Prototype
*****************************/
 
void run_front(uint8 ang_1, uint8 speed_1);
void run_back(uint8 ang_2, uint8 speed_2);


/*Buffer and Packet size*/
#define BUFFER_SIZE         (4u)
#define PACKET_SIZE         (BUFFER_SIZE)

/* Packet position*/
#define PACKET_ANG_1_POS        (0u)
#define PACKET_SPEED_1_POS      (1u)
#define PACKET_ANG_2_POS        (2u)
#define PACKET_SPEED_2_POS      (3u)

/* Logic levels */
#define HIGH                (1u)
#define LOW                 (0u)
    
    
#endif /*CY_MAIN_H */