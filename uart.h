#include <MKL25Z4.h>
#ifndef UART
#define UART
#define OVER_SAMPLE 16
void uart_init(int baud_rate);
int uart_read(uint8_t *p, int len);
int uart_write(uint8_t *p, int len);
int uart_err(uint8_t *p, int len);
void UART0_IRQHandler(void);
#endif