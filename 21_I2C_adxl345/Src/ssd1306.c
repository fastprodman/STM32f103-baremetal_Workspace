#include "ssd1306.h"

#define DEVID		0x3C
#define CTL_COMMAND	0x80
#define DISP_ON		0xA5


void ssd1306_displayTest(void){
	char data[1];
	data[0] = DISP_ON;
	I2C1_burstWrite(DEVID, 0x80, 1, data);
}


