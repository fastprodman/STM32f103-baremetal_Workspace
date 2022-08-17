#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"


int main(void){

	uart2_tx_init();
	tim2_1hz_init();
	while(1){
//
		while(!(TIM2->SR & SR_UIF));
		TIM2->SR &=~ SR_UIF;
		printf("Hello world! \n\r");

	}

}
