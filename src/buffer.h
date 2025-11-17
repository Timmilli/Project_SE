#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "constants.h"

#include <avr/io.h>

#define RING_BUFFER_SIZE 32

struct ring_buffer {
  uint8_t head;
  uint8_t tail;
  uint8_t data[RING_BUFFER_SIZE];
};

// Initialize the buffer
// Also resets the data array
void ring_buffer_init(struct ring_buffer *rb);

// Adds a byte to the buffer
// Does not check if buffer full
void ring_buffer_put(struct ring_buffer *rb, uint8_t data);

// Get a byte from the buffer
// Does not check if buffer full
uint8_t ring_buffer_get(struct ring_buffer *rb);

// Indicates the number of bytes currently used in the buffer
uint8_t ring_buffer_available_bytes(struct ring_buffer *rb);

// Indicates if the buffer is full
uint8_t ring_buffer_is_full(struct ring_buffer *rb);

// Prints the buffer content
void ring_buffer_print(struct ring_buffer *rb);

#endif // __BUFFER_H__
