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
	// init timebase
	timebase_init();
    while(1)
    {
    	printf("Hello from STM32\n\r");
    	delay(2);
    }
}
