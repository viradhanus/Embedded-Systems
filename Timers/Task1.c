//calculation
/*delay  = 2ms
XTAL = 16MHz
period = 1/16
Prescalar = 1:256
(1/16)*256 = 16
no of increments = 2000/16 = 125
initial timer reg value = 1+255-125
                        = 131=0x83
                        
*/
/*
Prescalar = 1:256

initial timer reg value = 1+255-125
                        = 131=0x83

OUTPUT:
Here dealy is 2ms, as it is really small we can't see blinking
properly
*/

#include <avr/io.h>

void delay_timer0(){
  TCNT0 = 0x83;//load timer counter register-initial-131
  
  TCCR0A = 0x00;//normal mode
  TCCR0B = 0x04;//256:1 scale
  
  while ((TIFR0 & 0x01) == 0);//check for overflow
  
  TCCR0A = 0x00;//setting to normal mode
  TCCR0B = 0x00;//turning off the timer
  
  TIFR0 = 0x01;//clearing the overflow flag
}

int main(void){
  DDRB = DDRB | (1<<5);//setting the 5th pin as output
  
  PORTB = PORTB & ~(1<<5);//pin 5 is set 0 initially
  
  while (1){
   
    PORTB = PORTB ^ (1<<5);//toggle the particular bit
    delay_timer0();  //calling the delay function 
   
  }
  
  return 0;
  
}