#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "systick.h"
#include "tim.h"


int main(void){

	//uart2_tx_init();
	tim2_PA0_output_compare();
	while(1);

}
