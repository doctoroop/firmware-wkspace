#ifndef TIMEBASE_H_
#define TIMEBASE_H_
#include "stm32f4xx.h"
#include "std_types.h"

UINT32 get_tick(void);
void timebase_init(void);
void delay(UINT32 delay);

#endif // TIMEBASE_H_
