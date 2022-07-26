#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"

#define GPIOCEN (1U<<4)
#define PIN13 (1U<<13)
#define SR_RXNE			(1U<<5)
char key;

int main(void){

	RCC->APB2ENR |= GPIOCEN;
	GPIOC->CRH = (((GPIOC->CRH &~(1U<<23))&~(1U<<22))|(1U<<21))&~(1U<<20);

	uart2_rxtx_interrupt_init();

	while(1){
	}

}

static void USART2_callback(void){
	key = USART2->DR;
	if(key == '1'){
		GPIOC->ODR |= PIN13;
	}else{
		GPIOC->ODR &= ~PIN13;
	}
}

void USART2_IRQHandler(void){
	if(USART2->SR & SR_RXNE){
		USART2_callback();
	}
}




