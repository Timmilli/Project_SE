#ifndef __ENCODING_H__
#define __ENCODING_H__

#include "constants.h"

#include <avr/io.h>

#define NUMBER_OF_POSITIONS 120

// Top left quarter
const uint16_t c1n0[NUMBER_OF_POSITIONS] = {0b0101011010100101011,
                                            0b0101011010100101011};
#define C1N0 c1n0

const uint16_t c1n1[NUMBER_OF_POSITIONS] = {0b0101011010100101011,
                                            0b0101011010100101011};
#define C1N1 c1n1

const uint16_t c1n2[NUMBER_OF_POSITIONS] = {0b0101011010100101011};
#define C1N2 c1n2

// Top right quarter
#define C2N0 c1n0
#define C2N1 c1n0
#define C2N2 c1n0
#define C2N3 c1n0
#define C2N4 c1n0
#define C2N5 c1n0
#define C2N6 c1n0
#define C2N7 c1n0
#define C2N8 c1n0
#define C2N9 c1n0

// Bottom left quarter
#define C3N0 c1n0
#define C3N1 c1n0
#define C3N2 c1n0
#define C3N3 c1n0
#define C3N4 c1n0
#define C3N5 c1n0

// Bottom right quarter
#define C4N0 c1n0
#define C4N1 c1n0
#define C4N2 c1n0
#define C4N3 c1n0
#define C4N4 c1n0
#define C4N5 c1n0
#define C4N6 c1n0
#define C4N7 c1n0
#define C4N8 c1n0
#define C4N9 c1n0

#endif // __ENCODING_H__
