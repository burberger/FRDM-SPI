#include <MKL25Z4.h>
#ifndef SPI
#define SPI
void SPI_init(void);
uint8_t SPI_status(void);
void SPI_write(uint8_t* p, int size, uint8_t addr);
void SPI_read(uint8_t* p, int size, uint8_t addr);
void SPI0_IRQHandler(void);
#endif