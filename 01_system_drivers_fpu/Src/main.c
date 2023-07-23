#include "stm32f4xx.h"
#include "stdint.h"
#include "fpu.h"
/*
 * FPU
 * UART
 * GPIO
 * TIMEBASE
 */

#define GPIOAEN     (1U<<0)
#define PIN5        (1U<<5)
#define LED_PIN     PIN5

int main(void)
{
	// enable fpu
	fpu_enable();

    while(1)
    {
    }
}
