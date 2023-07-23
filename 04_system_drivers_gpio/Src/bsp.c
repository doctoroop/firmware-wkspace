#include "bsp.h"

// BSP supports dedicated LED and user button specific to the nucleo board


void led_init(void)
{
	// enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	// set PA5 mode to output mode
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);
}

void led_on(void)
{
	// set PA5 high
	GPIOA->ODR |= LED_PIN;
}

void led_off(void)
{
	// set PA5 low
	GPIOA->ODR &= ~LED_PIN;
}

void button_init(void)
{
	// enable clock access to GPIOC
	RCC->AHB1ENR |= GPIOCEN;
	// set PC13 mode to input mode
	GPIOC->MODER &= ~(1U<<26);
	GPIOC->MODER &= ~(1U<<27);
}

BOOL32 get_btn_state(void)
{
	// Note: BTN is active low
	// return button state
	if(GPIOC->IDR & BTN_PIN)
	{
		return FALSE;
	}
	return TRUE;
}
