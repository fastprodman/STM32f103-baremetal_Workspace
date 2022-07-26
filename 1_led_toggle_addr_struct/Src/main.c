//Where is the LED connected
//Port: C
//Pin:	13
#include <stdint.h>

#define PERIPH_BASE 		(0x40000000UL)
#define APB2PERIPH_OFFSET 	(0x00010000UL)
#define APB2PERIPH_BASE		(PERIPH_BASE + APB2PERIPH_OFFSET)
#define GPIOC_OFFSET  		(0x00001000UL)
#define GPIOC_BASE			(APB2PERIPH_BASE + GPIOC_OFFSET)
#define RCC_BASE			(0x40021000UL)
//4
#define IOPCEN (1U<<4)

#define PIN13 (1U<<13)

#define __IO volatile

typedef struct
{
	__IO uint32_t CRL; //used to confihure mode and clock (low)
	__IO uint32_t CRH; //used to confihure mode and clock (high)
	__IO uint32_t IDR; //input data register
	__IO uint32_t ODR; //output data register
	__IO uint32_t BSRR; // bit set/reset register
	__IO uint32_t BRR; //bit reset register
	__IO uint32_t LCKR; //configuration lock register
}GPIO_TypeDef;

typedef struct
{
	__IO uint32_t CR; // clock control register
	__IO uint32_t CFGR; // clock configuration register
	__IO uint32_t CIR; // clock interrupt register
	__IO uint32_t APB2RSTR; // APB2 peripheral reset register
	__IO uint32_t APB1RSTR; // APB1 peripheral reset register
	__IO uint32_t AHBENR; // AHB peripheral clock enable reg
	__IO uint32_t APB2ENR; // APB2 peripheral clock enable reg
	__IO uint32_t APB1ENR; // APB1 peripheral clock enable reg
	__IO uint32_t BDCR; // backup domain control register
	__IO uint32_t CSR; // Control/status register
}RCC_TypeDef;

#define RCC		((RCC_TypeDef*) RCC_BASE)
#define GPIOC   ((GPIO_TypeDef*) GPIOC_BASE)

int main(void){

	//RCC_APB2EN_R |= IOPCEN;
	RCC->APB2ENR |= IOPCEN;

//	mode config	output push-pull
//	GPIOC_MODE_R = (GPIOC_MODE_R &~(1U<<23))&~(1U<<22);
	GPIOC->CRH = (GPIOC->CRH &~(1U<<23))&~(1U<<22);

//	max speed config 2Mhz
//	GPIOC_MODE_R = (GPIOC_MODE_R |(1U<<21))&~(1U<<20);
	GPIOC->CRH = (GPIOC->CRH |(1U<<21))&~(1U<<20);

	while (1){
		//GPIOC_OD_R ^= PIN13;
		GPIOC->ODR ^= PIN13;
		for(int i=0; i<1000000; i++);
	}
}
