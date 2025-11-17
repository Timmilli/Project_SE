#include "constants.h"

#include "buffer.h"
#include <avr/io.h>
#include <stdio.h>

void ring_buffer_init(struct ring_buffer *rb) {
  rb->tail = 0;
  rb->head = 0;
  for (uint8_t i = 0; i < RING_BUFFER_SIZE; i++)
    rb->data[i] = 0;
}

void ring_buffer_put(struct ring_buffer *rb, uint8_t data) {
  rb->data[rb->head] = data;
  rb->head = (rb->head + 1) % RING_BUFFER_SIZE;
}

uint8_t ring_buffer_get(struct ring_buffer *rb) {
  uint8_t data = rb->data[rb->tail];
  rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;
  return data;
}

uint8_t ring_buffer_available_bytes(struct ring_buffer *rb) {
  if (rb->head >= rb->tail) {
    return rb->head - rb->tail;
  } else {
    return RING_BUFFER_SIZE - (rb->tail - rb->head);
  }
}

uint8_t ring_buffer_is_full(struct ring_buffer *rb) {
  return ((rb->head + 1) % RING_BUFFER_SIZE) == rb->tail;
}

void ring_buffer_print(struct ring_buffer *rb) {
  for (uint8_t i = 0; i < RING_BUFFER_SIZE; i++) {
    printf("%c", rb->data[i]);
  }
}
