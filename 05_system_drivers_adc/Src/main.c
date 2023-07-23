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

INT32 sensor_value;
int main(void)
{
	// enable fpu
	fpu_enable();
    // initialize uart
	debug_uart_init();

	timebase_init();

	led_init();

	button_init();

	pa1_adc_init();
	start_conversion();

    while(1)
    {
    	sensor_value = adc_read();
    	delay(1);
    }
}
