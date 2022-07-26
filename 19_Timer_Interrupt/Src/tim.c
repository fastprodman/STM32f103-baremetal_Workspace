#include "tim.h"

#define TIM2EN 	(1U<<0)
#define CR1_CEN (1U<<0)
#define DIER_UIE	(1U<<0)


void tim2_1hz_init(void){
//	enable clock access to TIM2
	RCC->APB1ENR |= TIM2EN;
//	Set prescaler val
	TIM2->PSC = 800 - 1; // 8MHz / 800 = 10 k
//	Set autoreload val
	TIM2->ARR = 10000 - 1;
//	Clear counter
	TIM2->CNT = 0;
//	Enable timer
	TIM2->CR1 = CR1_CEN;
}

void tim2_1hz_interrupt_init(void){
//	enable clock access to TIM2
	RCC->APB1ENR |= TIM2EN;
//	Set prescaler val
	TIM2->PSC = 800 - 1; // 8MHz / 800 = 10 k
//	Set autoreload val
	TIM2->ARR = 10000 - 1;
//	Clear counter
	TIM2->CNT = 0;
//	Enable timer
	TIM2->CR1 = CR1_CEN;

	TIM2->DIER |= DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
}
