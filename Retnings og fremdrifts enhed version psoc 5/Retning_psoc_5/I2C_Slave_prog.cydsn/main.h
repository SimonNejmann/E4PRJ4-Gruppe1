#if !defined(CY_MAIN_H)
#define CY_MAIN_H
    
#include <project.h>
    
    
/*****************************
     Funktion Prototype
*****************************/
 
uint8 run_front(uint8 ang_1, uint8 speed_1, uint8 ang_2, uint8 speed_2);
uint8 run_back(uint8 ang_2, uint8 speed_2);

#define SLAVE_ADDRESS   (0x49u)
/* Buffer and packet size */
#define BUFFER_SIZE     (6u)
#define PACKET_SIZE     (BUFFER_SIZE)

/* Packet positions */
#define PACKET_SOP_POS      (0u)
#define PACKET_ANG1_POS     (1u)
#define PACKET_SPEED1_POS   (2u)
#define PACKET_ANG2_POS     (3u)
#define PACKET_SPEED2_POS   (4u)
#define PACKET_STS_1_POS    (PACKET_ANG1_POS)
#define PACKET_STS_2_POS    (PACKET_SPEED1_POS)
#define PACKET_STS_3_POS    (PACKET_ANG2_POS)
#define PACKET_STS_4_POS    (PACKET_SPEED2_POS)
#define PACKET_EOP_POS      (5u)

/* Start and end of packet markers */
#define PACKET_SOP      (0x01u)
#define PACKET_EOP      (0x17u)

/* Command valid status */
#define STS_CMD_DONE    (0x00u)
#define STS_CMD_FAIL    (0xFFu)




/* Logic levels */
#define HIGH                (1u)
#define LOW                 (0u)
    
    
#endif /*CY_MAIN_H */