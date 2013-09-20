#include <MKL25Z4.h>

#define LED_NUM 3
const uint32_t led_mask[] = {1UL << 18, 1UL << 19, 1UL << 1};
volatile uint32_t msTicks;

void SysTick_Handler(void) {
	msTicks++;
}

__INLINE static void delay (uint32_t num_delay) {
	uint32_t curTicks;
	
	curTicks = msTicks;
	while ((msTicks - curTicks) < num_delay);
}