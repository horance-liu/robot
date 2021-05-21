#ifndef F6B84441_5294_4175_B4D3_78FEF22FC4CD
#define F6B84441_5294_4175_B4D3_78FEF22FC4CD

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum EventType {
    ORDER_FULL,
    ORDER_EMPTY,
    ORDER_FINISHED,

    POWER_LOW1,
    POWER_LOW2,
} EventType;

void ctrl_report(EventType type, const void*); 

#ifdef __cplusplus
}
#endif

#endif /* F6B84441_5294_4175_B4D3_78FEF22FC4CD */
