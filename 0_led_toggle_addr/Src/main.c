//Where is the LED connected
//Port: A
//Pin:	1

#define PERIPH_BASE 		(0x40000000UL)
#define APB2PERIPH_OFFSET 	(0x00010000UL)
#define APB2PERIPH_BASE		(PERIPH_BASE + APB2PERIPH_OFFSET)
#define GPIOA_OFFSET  		(0x00000800UL)
#define GPIOA_BASE			(APB2PERIPH_BASE + GPIOA_OFFSET)
#define RCC_APB2EN_R 		(0x18UL)
#define MODE_R_OFFSET 		(0x00UL)
#define GPIOA_MODE_R 		(GPIOA_BASE + MODE_R_OFFSET)
#define OD_R_OFFSET 		(0x0C)
#define GPIOA_OD_R 			(GPIOA_BASE + OD_R_OFFSET)

#define IOPAEN (1U<<2)

#define PIN1 (1U<<1)
/*
 * (1U<<4)
 * &=~(1U<<5)
 * */
