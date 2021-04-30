//calculation for 50ms - timer 0
/*
delay = 2ms and loop 25 times
delay  = 2ms
XTAL = 16MHz
period = 1/16
Prescalar = 1:256
(1/16)*256 = 16
no of increments = 2000/16 = 125
initial timer reg value = 1+255-125
                        = 131=0x83
*/


//calculation for 500ms-timer 1
/*
delay = 500ms
XTAL = 16MHz
period = 1/16
Prescalar = 1:256
(1/16)*256 = 16
no of increments = (5 * 10^5)/16 = 31250
initial timer reg value = 1+65535-31250
                        = 34286 = 0x85EE
*/



#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char counter = 0;//global variable counter

//for 50 ms-Timer 0-1stpin PORT B
ISR(TIMER0_OVF_vect){
  TCNT0 = 0x83;//reload for next round
  counter++;//couter is incrementing
  if (counter == 25){
    PORTB = PORTB^(1<<1);//toggling after 50ms
    counter = 0;//counter is setto zero
  }
}

//for 500ms-Timer 1
ISR(TIMER1_OVF_vect){
  TCNT1 = 0x85EE;//reload for next round
  PORTB = PORTB ^ (1<<0);//0th pin is toggled   
}


int main(void){
  
  DDRB = 0x03;//0 and 1 pins are set as output
  PORTB = PORTB & ~(0x03);//initially pin 0 and pin 1 are set to 0
  
  //initial values in timer 0  registers
  TCNT0 = 0x83;//for timer 0-initial value = 131
  TCNT1 = 0x85EE;//for timer 1
  
  //set the TIMER0 under normal mode with 1:256 prescaler
  TCCR0A = 0x00;	//normal mode
  TCCR0B = 0x04;  //1:256
  
  //set the TIMER1 under normal mode with 1:256 prescaler
  TCCR1A = 0x00;	//normal mode
  TCCR1B = 0x04;  //1:256
  
  sei(); //enable global interrupts(set I)
  
  TIMSK0 |= (1<<TOIE0); //enable Timer0 overflow interrupt-timer 0
  TIMSK1 |= (1<<TOIE1);//enable Timer1 overflow interrupt-timer 1

  while(1){;}

  return 0;
    
}