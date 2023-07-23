#include "uart.h"

#define GPIOAEN (1U<<0)
#define UART2EN (1U<<17)
#define DBG_UART_BAUDRATE 115200
#define SYS_FREQ          16000000
#define APB1_CLK          SYS_FREQ
#define CR1_TE            (1U<<3)
#define CR1_UE            (1U<<13)
#define SR_TXE            (1U<<7)


static void uart_set_baudrate(UINT32 periph_clk, UINT32 baudrate);
static void uart_write(INT32 ch);

int __io_putchar(int ch) // use "int" to avoid confusing linkage
{
	uart_write(ch);
	return ch;
}

void debug_uart_init(void)
{
	// enable clock access to gpioa
	RCC->AHB1ENR |= GPIOAEN;

	// set mode of pa2 to alternaqte fcn mode
	GPIOA->MODER &=~(1u<<4);
	GPIOA->MODER |= (1u<<5);

	//set alternate function type to AF7 (UART2_TX)
	GPIOA->AFR[0] |= (1u<<8);
	GPIOA->AFR[0] |= (1u<<9);
	GPIOA->AFR[0] |= (1u<<10);
	GPIOA->AFR[0] &= ~(1u<<11);

	// enable clock access to UART2
	RCC->APB1ENR  |= UART2EN;

	// configure uart baudrate
	uart_set_baudrate(APB1_CLK,DBG_UART_BAUDRATE);

	// configure transfer direction
	USART2->CR1 = CR1_TE; // tx enable and everything else off

	// enable UART module
	USART2->CR1 |= CR1_UE;

}

static void uart_write(INT32 ch)
{
	// ensure tx data register is empty
	while(!(USART2->SR & SR_TXE)){}
	// write ch into tx data register
	USART2->DR = (ch & 0x00FF);
}
static UINT16 compute_uart_bd(UINT32 periph_clk, UINT32 baudrate)
{
	return (((periph_clk + (baudrate/2U))/baudrate));
}

void uart_set_baudrate(UINT32 periph_clk, UINT32 baudrate)
{
	USART2->BRR = compute_uart_bd(periph_clk, baudrate);
}
