#include "uart.h"

void uart_init(int baud_rate) {
	SIM->SCGC5 |= SIM_SCGC5_PORTA_MASK;
	SIM->SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM->SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;
	SIM->SOPT2 |= SIM_SOPT2_UART0SRC(1); // FLL/PLL source
	
}
