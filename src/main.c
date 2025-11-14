#include "constants.h"

#include "buffer.h"
#include "led_com.h"
#include "uart_com.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void) {
  setup_led_driver_com();
  uart_init(MYUBRR);
  struct ring_buffer rb;
  ring_buffer_init(&rb);

  uint16_t datastreak = 0;

  while (1) {
    pwm(5);

    write_datastreak(datastreak);
    if (datastreak == 0b1111111111111111) {
      datastreak = 0;
    } else {
      datastreak++;
    }
  }
  return 1;
}
