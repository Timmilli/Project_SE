#include "constants.h"

#include "merge_matrices.h"
#include <avr/io.h>
#include <stdio.h>

int main(int args, char *argv[]) {

  uint8_t hours_tens = 1;
  uint8_t hours_units = 2;
  uint8_t minutes_tens = 2;
  uint8_t minutes_units = 0;

  uint16_t mat[NUMBER_OF_POSITIONS];

  merge_matrices(mat, hours_units, hours_tens, minutes_units, minutes_tens);

  for (uint8_t i = 0; i < NUMBER_OF_POSITIONS; i++) {
    printf("%d: %d", i, mat[i]);
  }
  return 1;
}
