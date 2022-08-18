#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"

int timestamp = 1;

int main(void){

	//uart2_tx_init();
	tim2_PA0_output_compare();
	tim3_pa6_input_capture();
	while(1){
		while(!(TIM3->SR & SR_CC1IF)){
			timestamp = TIM3->CCR1;
		}
	}

}
