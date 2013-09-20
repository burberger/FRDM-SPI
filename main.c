#include <MKL25Z4.h>
#include "spi.h"

volatile uint32_t msTicks;                            /* counts 1ms timeTicks */

void SysTick_Handler(void) {
  msTicks++;                      
}

/* Delay for argument number of systicks */
__INLINE static void delay (uint32_t dlyTicks) {
  uint32_t curTicks;

  curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
}



int main (void) {
	SystemInit();
  SystemCoreClockUpdate();                      /* Get Core Clock Frequency */
  SysTick_Config(SystemCoreClock/1000);         /* Generate interrupt each 1 ms    */     

	SPI_init();
 
  while(1) {
		uint8_t data[2] = { 0xAA, 0x55 };
		SPI_write(data, 2);
  }
 }
