#ifndef TIM_H_
#define TIM_H_
#define SR_UIF 		(1U<<0)
#define SR_CC1IF	(1U<<1)
#define SR_CC1OF	(1U<<9)
#include "stm32f1xx.h"
void tim3_pa6_input_capture(void);
void tim2_PA0_output_compare(void);
void tim2_1hz_init(void);
#endif /* TIM_H_ */
