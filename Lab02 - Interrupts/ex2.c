#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 200

int main(){
	DDRD &=~(1<<2);			//set PD2 (INT0) pin as input(push button)
      
    DDRB |= (1<<0);			//set PB0 pin as output (LED)

  	//Set for falling edge detection
  	EICRA |= (1<<ISC01);		
  	EICRA &=~(1<<ISC00);
  
  	sei();	//global interrupts enable
  
  	EIMSK |= (1<<INT0);		//enable external hardware interrupt for INT0
  
  	while(1){
    
    }
  	return 0;
}

//isr for the interrupt
ISR(INT0_vect){
  PORTB = PORTB^(1<<0);			//toggle only PB0 pin
  //_delay_ms(BLINK_DELAY_MS);	//delay of 200ms
}