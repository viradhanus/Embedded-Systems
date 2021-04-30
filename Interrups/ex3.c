#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS 200

unsigned char z = 0;	//initialize z as global variable

int main(void)
{
  	DDRB = DDRB|0x3F;			//set the least 6 bits of PORTB as output
  	DDRD = DDRD &~(1<<2);		//set PD2 (INT0) pin as input(push button)
      
    //PORTB = PORTB &~(0b00111111); 		//set least 6 bits to zero initially
  	
  	//Set for falling edge detection
  	EICRA |= (1<<ISC01);
  	EICRA &=~(1<<ISC00);
  
  	sei();			//global interrupts enable
  
  	EIMSK |= (1<<INT0);		//enable external hardware interrupt for INT0
  
  	while(1){
  	
    }
  	return 0; 
}
//isr for the interrupt
ISR(INT0_vect){
  	//static unsigned char z = 0;			//a static variable defined as a counter(runs only first time)
	z = z+1;							//counter increments for each interrupt 
  	PORTB= z;							//output the counter values(push button released)
    _delay_ms(BLINK_DELAY_MS);			//delay
}