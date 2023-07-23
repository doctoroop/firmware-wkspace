#ifndef ADC_H_
#define ADC_H_
#include "stm32f4xx.h"
#include "std_types.h"
#define GPIOAEN (1U<<0)
#define ADC1EN  (1U<<8)
#define ADC_CH1 (1U<<0)
#define CR2_ADCON (1U<<0)
#define CR2_CONT  (1U<<1)
#define CR2_SWSTART (1U<<30)
#define SR_EOC     (1U<<1)

void pa1_adc_init(void);
void start_conversion(void);
UINT32 adc_read(void);


#endif // ADC_H_
