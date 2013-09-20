#include <MKL25Z4.h>
#ifndef SPI
#define SPI
#endif

void SPI_init(void);
uint8_t SPI_status(void);
void SPI_write(uint8_t* p, int size);
int SPI_read(char* p, int size);
