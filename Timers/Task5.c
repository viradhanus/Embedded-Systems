/*
delay = 100ms---we get 4ms and going for loop 25 times
here delay = 4ms
XTAL = 16MHz
prescaler = 1:256
256 * (1/16) = 16
no of increments = (4000/16)=250
initial value = 1+255-250 = 6
                          = 0x06
*/

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char counter = 0;//global variable counter

ISR(TIMER0_OVF_vect){
  TCNT0 = 0x06;//reload for next round
  counter++;//couter is incrementing
  
  if (counter == 25){
    PORTB = PORTB^(1<<0);//toggling after 100ms
    counter = 0;//counter is setto zero
  }
  
  
  Serial.print(counter);
}


int main(void)
{
  DDRB = DDRB | 0x01; //set least sigificant bit as output,PB0 toggle)
  PORTB = PORTB | 0x01; //set least bit to one initially
  
  TCNT0 = 0x06;//initial value in timer register
  Serial.begin(9600);
 
  //set the TIMER0 under normal mode with 1:256 prescaler
  TCCR0A = 0x00;//normal mode
  TCCR0B = 0x04;//1:256 scale  
   
  sei(); //enable global interrupts(set I)
  
  TIMSK0 |= (1<<TOIE0);; //enable Timer0 overflow interrupt
 
 
  while(1){;}

    return 0;
}