#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"

#define GPIOCEN (1U<<4)
#define PIN13 (1U<<13)
#define SR_RXNE			(1U<<5)
char key;

int main(void){
	char message[18] = "Hello from STM32\n\r";

	RCC->APB2ENR |= GPIOCEN;
	GPIOC->CRH = (((GPIOC->CRH &~(1U<<23))&~(1U<<22))|(1U<<21))&~(1U<<20);

	uart2_tx_init();
	dma1_usart_init((uint32_t) message, (uint32_t) &USART2->DR, sizeof(message));

	while(1){
	}

}

static void USART2_callback(void){
	GPIOC->ODR |= PIN13;
}

void DMA1_Channel7_IRQHandler(void){
	if (DMA1->ISR & ISR_TCIF7){
		DMA1->IFCR |= IFCR_CTCIF7;
		USART2_callback();
	}
}




