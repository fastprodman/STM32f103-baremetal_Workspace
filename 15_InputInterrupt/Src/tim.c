#include "tim.h"

#define TIM2EN 	(1U<<0)
#define TIM3EN 	(1U<<1)
#define CR1_CEN (1U<<0)
#define CCMR1_OC1M_TOGGLE ((1U<<5)|(1U<<4))//(0x3<<4)
#define CCER_CC1E (1U<<0)
#define RCC_IOPAEN (1U<<2)
#define CCER_CC1S (1U<<0)
#define EGR_UG		(1U<<0)


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
//	GPIOA->CRL = (GPIOA->CRL|(0x2<<2)|(0x3<<0));
	GPIOA->CRL = (GPIOA->CRL | (1U<<3)|(1U<<1)|(1U<<0))&~(1U<<2);
//	Set alternate function type to TIM2_CH1
//	enable clock access to TIM2
	RCC->APB1ENR |= TIM2EN;
//	Set prescaler val
	TIM2->PSC = 80 - 1; // 8MHz / 800 = 10 k
	TIM2->EGR |= EGR_UG;
//	Set autoreload val
	TIM2->ARR = 10000 - 1;
	TIM2->CCR1 = 10000 - 1;

//	Set output compare toggle mode
	TIM2->CCMR1 = CCMR1_OC1M_TOGGLE;
//	Enable tim2 channel 1 (PA0)
	TIM2->CCER |= CCER_CC1E;
//	Clear counter
	TIM2->CNT = 0;
//	Enable timer
	TIM2->CR1 = CR1_CEN;
}

void tim3_pa6_input_capture(void){
	RCC->APB2ENR |= RCC_IOPAEN;
	//	Set pa6 to alternate function
	GPIOA->CRL = ((((GPIOA->CRL &~(1U<<26))&~(1U<<25))&~(1U<<24))|(1U<<27));
	//	enable clock access to TIM3
	RCC->APB1ENR |= TIM3EN;
	//set prescaler
	TIM3->PSC = 8000 - 1; // 8MHz / 800 = 10 k
	TIM3->EGR |= EGR_UG;
	//set CH1 to input mode
	TIM3->CCMR1 = CCER_CC1S;// 01: CC1 channel is configured as input, IC1 is mapped on TI1.
	//set CH1 to capture at rising edge
	TIM3->CCER = CCER_CC1E; //1: Capture enabled.
	//Enable TIM3
	TIM3->CR1 = CR1_CEN; //1: Counter enabled
}
