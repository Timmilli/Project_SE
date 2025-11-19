#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "constants.h"

#include <avr/io.h>

#define RING_BUFFER_SIZE 32

typedef enum {
  NONE = 0,
  SET_HOUR = 1,
} process_action_e;

typedef struct {
  uint8_t head;
  uint8_t tail;
  uint8_t data[RING_BUFFER_SIZE];
} ring_buffer_t;

// Initialize the buffer
// Also resets the data array
void ring_buffer_init(ring_buffer_t *rb);

// Adds a byte to the buffer
// Does not check if buffer full
void ring_buffer_put(ring_buffer_t *rb, uint8_t data);

// Get a byte from the buffer
// Does not check if buffer full
uint8_t ring_buffer_get(ring_buffer_t *rb);

// Indicates the number of bytes currently used in the buffer
uint8_t ring_buffer_available_bytes(ring_buffer_t *rb);

// Indicates if the buffer is full
uint8_t ring_buffer_is_full(ring_buffer_t *rb);

// Prints the buffer content
void ring_buffer_print(ring_buffer_t *rb);

// Processes the ring buffer into a datastreak
uint8_t process_ring_buffer(ring_buffer_t *rb);

#endif // __BUFFER_H__
