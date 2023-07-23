#include "stm32f4xx.h"
#include "stdint.h"
#include "std_types.h"
#include "fpu.h"
#include "uart.h"
/*System Modules:
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
    // initialize uart
	debug_uart_init();

	timebase_init();

	led_init();

	button_init();

    while(1)
    {
    	led_on();
    	for(int i = 0;i < 1000000;i++){}
    }
}
