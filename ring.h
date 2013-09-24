#include <MKL25Z4.h>
#ifndef RING
#define RING
typedef struct ring_buf {
	volatile uint16_t head;
	volatile uint16_t tail;
	volatile uint16_t size;
	volatile uint8_t data[];
} ring_buf;

void buf_reset(ring_buf *buf, int size);
int buf_len(const ring_buf *buf);
int buf_isfull(const ring_buf *buf);
int buf_isempty(const ring_buf *buf);
uint8_t buf_getchar(ring_buf *buf);
void buf_putchar(ring_buf *buf, uint8_t val);
#endif