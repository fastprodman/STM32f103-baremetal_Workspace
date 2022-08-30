#include "exti.h"

#define GPIOC_EN		(1U<<4)
#define EXTI_PC13_EN	(1U<<5)
#define AFIOEN			(1U<<0)
#define MR13			(1U<<13)
#define FTSR_TR13		(1U<<13)

void pc13_exti_init(void){
//	desable global interrupt
	__disable_irq();
//	enable clock access to gpio c
//	Enable clock access to SYSCFG >> (AFIO)
	RCC->APB2ENR = (RCC->APB2ENR | GPIOC_EN | AFIOEN);
//	Set PC13 as input
//GPIOC->CRH = ((GPIOC->CRH |(1U<<23))&~(1U<<22));
//	Select PORTC for EXTI13
	AFIO->EXTICR[3] |= EXTI_PC13_EN;
//	Unmask EXTI13
	EXTI->IMR |= MR13;
//	Select falling edge trigger
	EXTI->FTSR |= FTSR_TR13;
//	enable exti line in NVIC
	NVIC_EnableIRQ(EXTI15_10_IRQn);
//	Enable global interrupt
	__enable_irq();
}
