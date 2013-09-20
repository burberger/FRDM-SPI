#include "spi.h"

void SPI_init(void) {
	// Enable clock network to SPI0
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;
	SIM->SCGC4 |= SIM_SCGC4_SPI0_MASK;
	
	// configure output crossbar
	PORTD->PCR[0] = PORT_PCR_MUX(2);  // PCS
	PORTD->PCR[1] = PORT_PCR_MUX(2);  // SCK
	PORTD->PCR[2] = PORT_PCR_MUX(2);  // MOSI
	PORTD->PCR[3] = PORT_PCR_MUX(2);  // MISO
	
	// Config registers, turn on SPI0 as master
	SPI0->C1 = 0x50;
	SPI0->C2 = 0x00;
	SPI0->BR = 0x00;
}

uint8_t SPI_status(void) {
	return SPI0->S;
}

// Write out all characters in supplied buffer to the SPI device
void SPI_write(uint8_t* p, int size) {
	int i;
	for (i = 0; i < size; ++i) {
		while ((SPI_status() | 0x20) != 0x20);
		SPI0->D = p[i];
	}
}
