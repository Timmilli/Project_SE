#include "constants.h"

#include "buffer.h"
#include <avr/io.h>
#include <stdio.h>

void ring_buffer_init(ring_buffer_t *rb) {
  rb->tail = 0;
  rb->head = 0;
  for (uint8_t i = 0; i < RING_BUFFER_SIZE; i++)
    rb->data[i] = 0;
}

void ring_buffer_put(ring_buffer_t *rb, uint8_t data) {
  rb->data[rb->head] = data;
  rb->head = (rb->head + 1) % RING_BUFFER_SIZE;
}

uint8_t ring_buffer_get(ring_buffer_t *rb) {
  uint8_t data = rb->data[rb->tail];
  rb->tail = (rb->tail + 1) % RING_BUFFER_SIZE;
  return data;
}

uint8_t ring_buffer_available_bytes(ring_buffer_t *rb) {
  if (rb->head >= rb->tail) {
    return rb->head - rb->tail;
  } else {
    return RING_BUFFER_SIZE - (rb->tail - rb->head);
  }
}

uint8_t ring_buffer_is_full(ring_buffer_t *rb) {
  return ((rb->head + 1) % RING_BUFFER_SIZE) == rb->tail;
}

void ring_buffer_print(ring_buffer_t *rb) {
  for (uint8_t i = 0; i < RING_BUFFER_SIZE; i++) {
    printf("%c", rb->data[i]);
  }
}

uint8_t str_cmp(char fstr[3], char sstr[3]) {
  for (uint8_t i = 0; i < 3; i++) {
    if (fstr[i] != sstr[i])
      return 0;
  }
  return 1;
}

uint8_t process_ring_buffer(ring_buffer_t *rb) {
  // TODO
  // define transmission format (setHHMMSS)
  // check if length >= 9
  // then process
  // or ff
  if (ring_buffer_available_bytes(rb) >= 3) {
    char command[3] = "";
    for (uint8_t i = 0; i < 3; i++) {
      command[i] = ring_buffer_get(rb);
    }
    for (uint8_t i = 0; i < 6; i++) {
      ring_buffer_get(rb);
    }

    if (str_cmp(command, "set"))
      return SET_HOUR;
  }
  return NONE;
}
