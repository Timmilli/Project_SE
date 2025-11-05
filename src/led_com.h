#ifndef __LED_COM_H__
#define __LED_COM_H__

#include "constants.h"

#include <avr/io.h>

int led_com_main(void);
void setup_led_driver_com();
void write_datastreak(int8_t powered_led_index);
void pwm(int clock_duration);

#endif // __LED_COM_H__
