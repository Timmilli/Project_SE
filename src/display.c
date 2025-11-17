#include "constants.h"

#include "hall_sensor.h"
#include "clock_module.h"
#include "led_com.h"

#include <avr/io.h>
#include <util/delay.h>

float fabs(float x){
  if(x < 0){
    return -x;
  }else{
    return x;
  }
}


uint16_t  draw_fork(float angle,float location, uint8_t length){
  uint16_t res = ~0b0;
    if(fabs(angle-location) < 3){
      res = ~(res >> length);
      return res;
    }else{
      return 0b0;
    }
}

uint16_t draw_cadran(float angle){
  uint16_t res = 0b001;
  float angle12 = (float)((int)(angle * 5)%(30 * 5))/5;
  float angle4 = (float)((int)(angle * 5)%(90 * 5))/5;
  angle12 -= 3;
  angle4 -= 3;
  if(angle12 < 3){
    res |= 0b011;
  }
  if(angle4 < 3){
    res|= 0b0111;
  }
  return res;

}

uint16_t draw_clock(float angle){
  uint16_t datastreak = draw_cadran(angle);
  datastreak |= draw_fork(angle,360-(float)clock_get_seconds()/60*360,14);
  datastreak |= draw_fork(angle,360-(float)clock_get_minutes()/60*360,10);
  datastreak |= draw_fork(angle,360-(float)(clock_get_hours()%12)/12*360,6);
  return datastreak;
}

int display_main(){
  srand(time(NULL));
  setup_hall_sensor();
  setup_led_driver_com();
  uint16_t datastreak = 0b00000001;
  clock_set_time(0,30,4);
  
  while (1) { // Main loop
    clock_update();
    long angle = get_current_angle();
    datastreak = draw_clock(angle);
    write_datastreak(datastreak);
  }
  return 1;
}
