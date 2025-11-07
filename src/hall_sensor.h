#ifndef __HALL_SENSOR_H__
#define __HALL_SENSOR_H__

#include "constants.h"

#include <avr/io.h>

/**
 * Sets up the hall sensor
 */
void setup_hall_sensor();

/**
 * Checks if the hall sensor is triggered
 * @return int 1 if triggered, 0 otherwise
 */
int hall_is_triggered() ;

#endif // __HALL_SENSOR_H__