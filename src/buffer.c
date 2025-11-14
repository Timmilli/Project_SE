#include "buffer.h"
#include <stdint.h>
#include <stdio.h>

// Initialise le buffer circulaire
void ring_buffer_init(struct ring_buffer *rb) {
  rb->counter = 0;
  rb->last_data_index = 0;
}

// Ajoute un octet dans le buffer circulaire
// Called only when not full
void ring_buffer_put(struct ring_buffer *rb, uint8_t data) {
  rb->data[rb->last_data_index++] = data;
}

// Récupère un octet du buffer circulaire
uint8_t ring_buffer_get(struct ring_buffer *rb) {
  if (rb->counter >= rb->last_data_index)
    rb->counter = 0;
  return rb->data[rb->counter++];
}

// Indique le nombre d'octets stockés dans le buffer circulaire
uint8_t ring_buffer_available_bytes(struct ring_buffer *rb) {
  return rb->last_data_index;
}

// Indique si le buffer circulaire est plein
uint8_t ring_buffer_is_full(struct ring_buffer *rb) {
  return rb->last_data_index >= RING_BUFFER_SIZE;
}

void ring_buffer_print(struct ring_buffer *rb) {
  for (uint8_t i = 0; i < rb->last_data_index; i++) {
    printf("%c", rb->data[i]);
  }
}
