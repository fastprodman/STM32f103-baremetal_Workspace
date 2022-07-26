#include "adc.h"
#define ADC1EN			(1U<<9)
#define GPIOAEN			(1U<<2)
#define ADC_CH1			(1U<<0)
#define ADC_SEQ_LEN_1	0x00
#define CR2_ADON		(1U<<0)
#define CR2_SWSTART		(1U<<22)
#define SR_EOC 			(1U<<1)
#define TSVREFE			(1U<<23)
#define EXTTRIG			(1U<<20)
#define SWSTARTON		((1U<<19)|(1U<<18)|(1U<<17))

void pa1_adc_init(void){
//	enable clock access to port A
//	Enable clock access to adc
	RCC->APB2ENR = (RCC->APB2ENR | GPIOAEN | ADC1EN);
// Set PA1 to analog mode
	GPIOA->CRL = (GPIOA->CRL &~ ((1U<<5)|(1U<<4)|(1U<<7)|(1U<<6)));
//	Configure sequence start
	ADC1->SQR3 = ADC_CH1;
//	Configure sequence length
	ADC1->SQR1 = ADC_SEQ_LEN_1;
//	Configure adc parameters
	ADC1->CR2 |= (SWSTARTON|CR2_ADON|EXTTRIG);

}

void start_conversion(void){
	ADC1->CR2 |= CR2_SWSTART;
}

uint32_t adc_read(void){
	//wait for conversion to be complete
	while(!(ADC1->SR & SR_EOC));
	//return dara
	return (ADC1->DR);
}
