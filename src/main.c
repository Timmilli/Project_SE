#include "constants.h"

#include "buffer.h"
#include "led_com.h"
#include "uart_com.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

struct ring_buffer rb;
uint16_t datastreak = 0b1111100000011111;
uint8_t nb_interrupt = 0;

ISR(USART_RX_vect) {
  datastreak = ~datastreak;
  while (!uart_available())
    ;
  uart_send_byte(nb_interrupt);
  nb_interrupt++;
  // if (!ring_buffer_is_full(&rb))
  //   ring_buffer_put(&rb, uart_read_byte());
}

ISR(USART_UDRE_vect) {
  if (!ring_buffer_available_bytes(&rb))
    uart_send_byte(ring_buffer_get(&rb));
}

int main(void) {
  setup_led_driver_com();
  uart_init(MYUBRR);
  ring_buffer_init(&rb);

  sei(); // activate interrupts

  while (1) {
    write_datastreak(datastreak);

    pwm(100);
  }
  return 1;
}
