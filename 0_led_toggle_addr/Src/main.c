//Where is the LED connected
//Port: C
//Pin:	13

#define PERIPH_BASE 		(0x40000000UL)
#define APB2PERIPH_OFFSET 	(0x00010000UL)
#define APB2PERIPH_BASE		(PERIPH_BASE + APB2PERIPH_OFFSET)
#define GPIOC_OFFSET  		(0x00001000UL)
#define GPIOC_BASE			(APB2PERIPH_BASE + GPIOC_OFFSET)
#define RCC_BASE			(0x40021000UL)
#define RCC_APB2EN_R_OFFSET (0x18UL)
#define RCC_APB2EN_R		(*(volatile unsigned int *)(RCC_BASE + RCC_APB2EN_R_OFFSET))
#define MODE_R_OFFSET 		(0x04UL)
#define GPIOC_MODE_R 		(*(volatile unsigned int *)(GPIOC_BASE + MODE_R_OFFSET))
#define OD_R_OFFSET 		(0x0CUL)
#define GPIOC_OD_R 			(*(volatile unsigned int *)(GPIOC_BASE + OD_R_OFFSET))
//4
#define IOPCEN (1U<<4)

#define PIN13 (1U<<13)


int main(void){

	RCC_APB2EN_R |= IOPCEN;
//	mode config	output push-pull
	GPIOC_MODE_R = (GPIOC_MODE_R &~(1U<<23))&~(1U<<22);
//	max speed config 2Mhz
	GPIOC_MODE_R = (GPIOC_MODE_R |(1U<<21))&~(1U<<20);

	while (1){
		GPIOC_OD_R ^= PIN13;
		for(int i=0; i<1000000; i++);
	}
}
