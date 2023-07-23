#include "stm32f4xx.h"

void fpu_enable(void)
{
	// ENABLE FLOATING POINT UNIT: ENABLE cp10 AND cp11 FULL ACCESS
	SCB->CPACR |= (1<<20);
	SCB->CPACR |= (1<<21);
	SCB->CPACR |= (1<<22);
	SCB->CPACR |= (1<<23);
}
