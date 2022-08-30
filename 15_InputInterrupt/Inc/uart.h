#ifndef UART_H_
#define UART_H_
#include "stm32f1xx.h"
#include <stdint.h>

void uart2_rxtx_init(void);
void uart2_tx_init(void);
char uart2_read(void);
void uart2_write(int ch);
#endif /* UART_H_ */
