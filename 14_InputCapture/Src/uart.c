#include "uart.h"

#define GPIOAEN			(1U<<2) //ENABLE A Port
#define USART2EN		(1U<<17) // Enable usart 2
#define CR1_TE			(1U<<3)
#define CR1_UE			(1U<<13)
#define CR1_RE			(1U<<2)
#define SR_TXE			(1U<<7)
#define SR_RXNE			(1U<<5)
#define SYS_FREQ		8000000
#define APB1_CLK		SYS_FREQ
#define UART_BAUDRATE	115200

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BoudRate);
static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BoudRate);
void uart2_write(int ch);

int __io_putchar(int ch){
	uart2_write(ch);
	return ch;
}


void uart2_tx_init(void){
	//Config uart gpio pin
	//1.Enable clock access to gpio C
	RCC->APB2ENR |= GPIOAEN; // clock enabled

	//2.Set PA2 mode to alternate function mode
	GPIOA->CRL = (GPIOA->CRL |(1U<<9)|(1U<<8)|(1U<<11))&~(1U<<10); //output 50 mhz max
	//3.Set PA2 alternate func mode to UART_TX
	//by default


	//Config uart module
	//enable clock access to uart2
	RCC->APB1ENR |= USART2EN;
	//Configure uart boudrate
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
	//configure transfer direction
	USART2->CR1 = CR1_UE | CR1_TE; // Transmitter enable, Enable USART
}

void uart2_rxtx_init(void){
	//Config uart gpio pin
	//1.Enable clock access to gpio C
	RCC->APB2ENR |= GPIOAEN; // clock enabled

	//2.Set PA2 mode to alternate function mode
	GPIOA->CRL = (((GPIOA->CRL |(1U<<9)|(1U<<8)|(1U<<11))&~(1U<<10))|(1U<<13)|(1U<<12)|(1U<<15))&~(1U<<14); //output 50 mhz max
	//3.Set PA2 alternate func mode to UART_TX
	//by default

	//1.Set PA3 mode to alternative function
	//GPIOA->CRL = (GPIOA->CRL |(1U<<13)|(1U<<12)|(1U<<15))&~(1U<<14);

	//Config uart module
	//enable clock access to uart2
	RCC->APB1ENR |= USART2EN;
	//Configure uart boudrate
	uart_set_baudrate(USART2, APB1_CLK, UART_BAUDRATE);
	//configure transfer direction
	USART2->CR1 = CR1_UE | CR1_TE | CR1_RE; // Transmitter enable, Enable USART
}

void uart2_write(int ch){
	//Make sure transmit data register is empty
	while(!(USART2->SR & SR_TXE));
	//Write to transmit data register
	USART2->DR = (ch & 0xFF);
}

char uart2_read(void){
	while(!(USART2->SR & SR_RXNE));
	return USART2->DR;
}

static void uart_set_baudrate(USART_TypeDef *USARTx, uint32_t PeriphClk, uint32_t BoudRate){
	USARTx->BRR = compute_uart_div(PeriphClk, BoudRate);
}

static uint16_t compute_uart_div(uint32_t PeriphClk, uint32_t BaudRate){
	return ((PeriphClk + (BaudRate/2U))/BaudRate);
}
