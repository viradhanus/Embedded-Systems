/*
Authors:E/16/083 
        E/16/200
        E/16/368
         
*/

#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 500

int main (void){


  DDRB = 0x0F;//0-3 pins of port B are set as outputs
  PORTB =0x0F;//Four leds are lit at first
  
  while(1){
    
   	PORTB = ~PORTB;//then toggle
    _delay_ms(BLINK_DELAY_MS);//delay for 500ms
  }
  
  return 0;

}
