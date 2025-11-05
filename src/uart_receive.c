#include "constants.h"

#include "led_com.h"
#include "uart_com.h"
#include "uart_receive.h"
#include <avr/io.h>
#include <util/delay.h>

unsigned char USART_Receive(void) {
  /* Wait for data to be received */
  while (!(UCSR0A & (1 << RXC0)))
    pwm(1);
  /* Get and return received data from buffer */
  return UDR0;
}

int uart_receive_main(void) {
  uart_init(MYUBRR);
  setup_led_driver_com();

  while (1) {
    unsigned char data = USART_Receive();
    write_datastreak((int8_t)data);
  }

  return 1;
}
