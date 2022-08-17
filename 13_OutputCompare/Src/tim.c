#include "tim.h"

#define TIM2EN 	(1U<<0)
#define CR1_CEN (1U<<0)
#define CCMR1_OC1M_TOGGLE ((1U<<5)|(1U<<4))//(0x3<<4)
#define CCER_CC1E (1U<<0)
#define RCC_IOPAEN (1U<<2)


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

void tim2_PA0_output_compare(void){
//	enable clk to GPIOA
	RCC->APB2ENR |= RCC_IOPAEN;
//	Set pa0 to alternate function
	GPIOA->CRL |= ((1U<<3)|(1U<<1)|(1U<<0))&~(1U<<2);//((0x2<<2)|(0x3<<0));
//	Set alternate function type to TIM2_CH1
//	enable clock access to TIM2
	RCC->APB1ENR |= TIM2EN;
//	Set prescaler val
	TIM2->PSC = 800 - 1; // 8MHz / 800 = 10 k
//	Set autoreload val
	TIM2->ARR = 10000 - 1;
	//TIM2->CCR1 = 10000 - 1;

//	Set output compare toggle mode
	TIM2->CCMR1 |= CCMR1_OC1M_TOGGLE;
//	Enable tim2 channel 1 (PA0)
	TIM2->CCER |= CCER_CC1E;
//	Clear counter
	TIM2->CNT = 0;
//	Enable timer
	TIM2->CR1 = CR1_CEN;
}
