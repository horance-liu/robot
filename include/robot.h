#ifndef B3B7013C_2992_4583_BF0D_DA6ABF7BD856
#define B3B7013C_2992_4583_BF0D_DA6ABF7BD856

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef uint32_t Status;

#define M_OK   0 
#define M_FAIL 1 

#define MIN_REMAIN_POWER 10

typedef struct Robot {
    uint32_t numOfOrders;
    uint32_t maxOrderNum;

    uint32_t remainPower;
} Robot;

void robot_init(uint32_t maxOrderNum, uint32_t maxPower);

Status robot_push_order();
Status robot_fetch_order();
Status robot_exhaust(uint32_t power);

#ifdef __cplusplus
}
#endif

#endif /* B3B7013C_2992_4583_BF0D_DA6ABF7BD856 */
