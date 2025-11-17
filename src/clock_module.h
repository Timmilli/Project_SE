#include "constants.h"

#include "hall_sensor.h"
#include "led_com.h"

#include <avr/io.h>
#include <util/delay.h>

void clock_update();
/**
 * Update the clock, to now!
 */

void clock_set_time(long s,long min,long h);
/** 
 * Set up the current time of the clock
**/

long clock_get_seconds();
/**
 * Get the seconds of the clock
 */

long clock_get_minutes();
/**
 * Get the minutes of the clock
 */

long clock_get_hours();
/**
 * Get the hours of the clock
 */