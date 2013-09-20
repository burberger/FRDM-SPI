#ifndef UART
#define UART
#endif

int uart_init(int baud_rate);
int uart_read(char *p, int len);
int uart_write(char *p, int len);
int uart_err(char *p, int len);
void UART0_IRQHandler(void);