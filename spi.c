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
	
	// configure gpio address select
	/* here */
	
	// Config registers, turn on SPI0 as master
	// Enable chip select
	SPI0->C1 = 0x52;
	SPI0->C2 = 0x10;
	SPI0->BR = 0x00;
}

uint8_t SPI_status(void) {
	return SPI0->S;
}

// Write out all characters in supplied buffer to register at address
void SPI_write(uint8_t* p, int size, uint8_t addr) {
	int i;
	// set SPI line to output (BIDROE = 1)
	//SPI0->C2 |= 0x04;
	for (i = 0; i < size; ++i) {
		// poll until empty
		while ((SPI_status() & 0x20) != 0x20);
		SPI0->D = p[i];
	}
}

// Read size number of characters into buffer p from register at address
void SPI_read(uint8_t* p, int size, uint8_t addr) {
	int i;
	// set SPI line to input (BIDROE = 0)
	//SPI0->C2 &= 0xF7;
	for (i = 0; i < size; ++i) {
		// poll until full
		SPI0->D = 0x00;
		while ((SPI_status() & 0x80) != 0x80);
		p[i] = SPI0->D;
	}
}
