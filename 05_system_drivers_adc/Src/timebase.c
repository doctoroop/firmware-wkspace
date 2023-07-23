#include "timebase.h"

#define CTRL_ENABLE (1U<<0)
#define CTRL_TICKINT   (1U<<1)
#define CTRL_CLCKSRC    (1U<<2)
#define CTRL_COUNTFLAG (1U<<16)

#define ONE_SEC_LOAD     16000000

UINT32 g_curr_tick;
UINT32 g_curr_tick_p;
#define TICK_FREQ 1

UINT32 get_tick(void)
{
	__disable_irq();
	g_curr_tick_p = g_curr_tick;
	__enable_irq();
	return g_curr_tick_p;
}

// delay in seconds
void delay(UINT32 delay)
{
	UINT32 tickstart = get_tick();
	UINT32 wait = delay;
	wait += (UINT32)TICK_FREQ;
	while((get_tick() - tickstart) < wait){}
}

void tick_increment(void)
{
	g_curr_tick += TICK_FREQ;

}



void timebase_init(void)
{
	// disable global interrupts
	__disable_irq();

	// reload timer with # clock cycles for 1 second
	SysTick->LOAD = ONE_SEC_LOAD-1;

	// clear systick current value reg
	SysTick->VAL = 0;
	// select internal clock source
	SysTick->CTRL = CTRL_CLCKSRC;

	// enable interrupts
	SysTick->CTRL |= CTRL_TICKINT;

	// enable systick
	SysTick->CTRL |= CTRL_ENABLE;

	// enable global interrupts
	__enable_irq();
}

void SysTick_Handler(void)
{
	tick_increment();
}
