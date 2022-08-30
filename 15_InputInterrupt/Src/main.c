#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"
#include "exti.h"


int main(void){
	uart2_tx_init();
	pc13_exti_init();
	while(1){
	}
}

static void exti_callback(void){
	printf("BTN pressed...");
}

void EXTI15_10_IRQHandler(void){
	if((EXTI->PR & LINE13)!= 0){
		EXTI->PR |= LINE13;
		exti_callback();
	}
}
