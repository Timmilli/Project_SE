#define __AVR_ATmega328P__
#include <avr/io.h>
#define F_CPU 13000000UL
#include <util/delay.h>

int main(void) {
  // Configure le bit 6 du registre DDRD en sortie
  DDRD |= (1 << PIND6);
  PIND |= (1 << PIND6);

  // Boucle infinie
  while (1) {
    PIND &= 0;
    _delay_ms(1000);
    PIND |= (1 << PIND6);
    _delay_ms(1000);
  }
}
