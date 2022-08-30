#include "systick.h"

#define SYSTICK_LOAD_VAL 8000
#define CTRL_SYSTICKEN 	(1U<<0)
#define CTRL_CLKSOURCE 	(1U<<2)
#define CTRL_COUNTFLAG	(1U<<16)

#define CTRL_TICKINT	(1U<<1)
#define ONE_SEC_LOAD	8000000

void systickDelayMs(int delay)
{
	SysTick->LOAD = SYSTICK_LOAD_VAL;
	SysTick->VAL = 0;
	SysTick->CTRL = (CTRL_SYSTICKEN | CTRL_CLKSOURCE);

	for(int i=0;i<delay;i++){
		while(!(SysTick->CTRL & CTRL_COUNTFLAG));
	}
	SysTick->CTRL = 0;
}


void systick_1hz_interrupt(void){
	SysTick->LOAD = ONE_SEC_LOAD - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = (CTRL_TICKINT | CTRL_SYSTICKEN | CTRL_CLKSOURCE);
}
