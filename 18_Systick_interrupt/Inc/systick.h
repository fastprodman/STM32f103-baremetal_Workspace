#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f1xx.h"

void systickDelayMs(int delay);

void systick_1hz_interrupt(void);

#endif /* SYSTICK_H_ */
