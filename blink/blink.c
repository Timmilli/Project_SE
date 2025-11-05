#define __AVR_ATmega328P__
#define F_CPU 13000000UL
#include <avr/io.h>
#include <util/delay.h>

void write_datastreak(int8_t powered_led_index) {
  for (int i = 0; i < 16; i++) {
    if ((1 << powered_led_index) & (1 << i)) {
      // SDI
      // turns on
      PORTB |= (1 << PB3);
    } else {
      // SDI
      // shuts off
      PORTB &= ~(1 << PB3);
    }

    // CLK
    // turns on
    PORTB |= (1 << PB5);
    // CLK
    // shuts off
    PORTB &= ~(1 << PB5);

    // SDI
    // shuts off
    PORTB &= ~(1 << PB5);
  }

  // LE
  // turns on
  PORTC |= (1 << PC2);
  // turns off
  PORTC &= ~(1 << PC2);
}

int blink_main(void) {
  // Setup pins in writing mode
  DDRB |= (1 << PB3) | (1 << PB5); // SDI | CLK
  DDRC |= (1 << PC1) | (1 << PC2); // OE / LE

  int8_t powered_led_index = 0;

  while (1) {
    // turns on
    for (int _ = 0; _ < 500; _++) {
      // OE on
      PORTC |= (1 << PC1);
      _delay_us(50);
      // OE off
      PORTC &= ~(1 << PC1);
      _delay_us(0.1);
    }

    write_datastreak(powered_led_index++);
    if (powered_led_index >= 16)
      powered_led_index = 0;
  }
}
