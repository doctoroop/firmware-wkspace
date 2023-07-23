#ifndef BSP_H_
#define BSP_H_
#include "std_types.h"
#include "stm32f4xx.h"
// BSP supports dedicated LED and user button specific to the nucleo board
#define GPIOAEN  (1U<<0)
#define GPIOCEN  (1U<<2)
#define PIN5    (1U<<5)
#define LED_PIN  PIN5
#define PIN13   (1U<<13)
#define BTN_PIN PIN13

void led_init(void);
void led_on(void);
void led_off(void);
void button_init(void);
BOOL32 get_btn_state(void);


#endif // BSP_H_
