#ifndef __BUFFER_H__
#define __BUFFER_H__

#include "constants.h"

#include <avr/io.h>

#define RING_BUFFER_SIZE 32

struct ring_buffer {
  uint8_t counter;         // such as counter < RING_BUFFER_SIZE
  uint8_t last_data_index; // such as last_data_index < RING_BUFFER_SIZE
  uint8_t data[RING_BUFFER_SIZE];
};

// Initialise le buffer circulaire
void ring_buffer_init(struct ring_buffer *rb);

// Ajoute un octet dans le buffer circulaire
void ring_buffer_put(struct ring_buffer *rb, uint8_t data);

// Récupère un octet du buffer circulaire
uint8_t ring_buffer_get(struct ring_buffer *rb);

// Indique le nombre d'octets stockés dans le buffer circulaire
uint8_t ring_buffer_available_bytes(struct ring_buffer *rb);

// Indique si le buffer circulaire est plein
uint8_t ring_buffer_is_full(struct ring_buffer *rb);

// Affiche le contenu du buffer
void ring_buffer_print(struct ring_buffer *rb);

#endif // __BUFFER_H__
