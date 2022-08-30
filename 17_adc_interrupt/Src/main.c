#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"
#include "adc.h"

uint32_t sensor_value;

int main(void){

	uart2_tx_init();
	pa1_adc_interrupt_init();
	start_conversion();
	while(1){

	}

}

static void adc_callback(void){
	printf("Sensor value: %d \n\r", (int)(ADC1->DR));
}

void ADC1_2_IRQHandler(void){
//	Check for eoc in SR
	if(ADC1->SR & SR_EOC){
		ADC1->SR &=~ SR_EOC;
		adc_callback();
	}
}


