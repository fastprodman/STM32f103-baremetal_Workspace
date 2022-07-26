#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"

#define GPIOCEN (1U<<4)
#define PIN13 (1U<<13)


int main(void){

	RCC->APB2ENR |= GPIOCEN;
	GPIOC->CRH = (GPIOC->CRH &~(1U<<23))&~(1U<<22);
	GPIOC->CRH = (GPIOC->CRH |(1U<<21))&~(1U<<20);

	//uart2_tx_init();
	systick_1hz_interrupt();

	while(1){

	}

}

void systick_callback(void){
	//printf("Second has passed... \n\r");
	GPIOC->ODR ^= PIN13;
}

void SysTick_Handler(void){
	systick_callback();
}


