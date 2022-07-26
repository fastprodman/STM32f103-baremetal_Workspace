#include "stm32f1xx.h"

#define GPIOCEN	(1U<<4)
#define PIN13	(1U<<13)

int main(void){

	RCC->APB2ENR |= GPIOCEN; // clock enabled
	//PIN13
	GPIOC->CRH = (GPIOC->CRH &~(1U<<23))&~(1U<<22); // 00 General purpose output push-pull
	GPIOC->CRH = (GPIOC->CRH |(1U<<21))&~(1U<<20); // 10 Output mode, max speed 2 MHz.
	//PIN14
	GPIOC->CRH = (GPIOC->CRH &~(1U<<27))&~(1U<<22); // 00 General purpose output push-pull
	GPIOC->CRH = (GPIOC->CRH &~(1U<<25))&~(1U<<24); // 10 Output mode, max speed 2 MHz.
	while(1){
		GPIOC->BSRR = PIN13;
		for(int i = 0; i<200000;i++);
		GPIOC->BSRR = (1U<<29);
		for(int i = 0; i<200000;i++);
	}
}
