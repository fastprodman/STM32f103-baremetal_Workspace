#include <stdio.h>
#include <stdint.h>
#include "stm32f1xx.h"
#include "uart.h"


int main(void){
	I2C1_init();
	ssd1306_displayTest();
	while(1){
	}

}




