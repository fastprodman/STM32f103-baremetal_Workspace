#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"


int main(void){

	uart2_tx_init();
	tim2_1hz_interrupt_init();

	while(1){

	}

}

static void tim2_callback(void){
	printf("Hello world! \n\r");
}

void TIM2_IRQHandler(void){
	TIM2->SR &=~ SR_UIF;
	tim2_callback();
}
