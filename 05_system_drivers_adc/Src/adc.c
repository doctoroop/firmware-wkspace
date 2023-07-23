#include "adc.h"



void pa1_adc_init(void)
{
	// note: PA1 is input for ADC1 channel 1
	// enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	// configure PA1 for analog
	GPIOA->MODER |= (1U<<2);
	GPIOA->MODER |= (1U<<3);
	// enable clock access to adc1
	RCC->APB2ENR |= ADC1EN;
	// set conversion sequence start
	ADC1->SQR3 = ADC_CH1;

	//set conversion sequence length
	ADC1->SQR1 = 0UL;
	// enable adc module
	ADC1->CR2 |= CR2_ADCON;
}

void start_conversion(void)
{
	// enable continuous conversion
	ADC1->CR2 |= CR2_CONT;
	// start AD conversion
	ADC1->CR2 |= CR2_SWSTART;
}

UINT32 adc_read(void)
{
	// wait for conversion to complete
	while(!(ADC1->SR & SR_EOC)){}
	// read converted value
	return (ADC1->DR);
}
