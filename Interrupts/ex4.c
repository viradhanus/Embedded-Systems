#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 200
#define RESET_DELAY_MS 1000

//unsigned char counter = 6;		//initialize counter variable
unsigned char base = 0;				//initialize base value
int val = 0;						//initialize base value

int main(void)
{
  	DDRB = DDRB|0x3F;		//set the least 6 bits of PORTB as output
  	DDRD = DDRD &~(1<<2);	//set PD2 (INT0) pin as input(push button A)
  	DDRD = DDRD &~(1<<3);	//set PD3 (INT1) pin as input(push button B)
    
	
  //Set for rising edge detection (for INT0)
  	EICRA |= (1<<ISC01);
  	EICRA |= (1<<ISC00);
  //Set for rising edge detection (for INT1)
  	EICRA |= (1<<ISC11);
  	EICRA |= (1<<ISC10);
  
  	sei();		//global interrupts enable
  
  	EIMSK |= (1<<INT0);		//enable external hardware interrupt for INT0
  	EIMSK |= (1<<INT1);		//enable external hardware interrupt for INT1
  
  	while(1){
  	
    }
  	return 0; 
}

//isr for the interrupt from pin PD2 (INT0)
ISR(INT0_vect){
  	arrFunc(0);	 //call the function (when push button A pressed send zero)
}

//isr for the interrupt from pin PD3 (INT1)
ISR(INT1_vect){
  	arrFunc(1);	 //call the function (when push button B pressed send one)
}

//function to find and display the binary number using LED's 
void arrFunc(unsigned char x){
  val = val + (x*(1<<base));		//update val after each function call
  PORTB = val;						//update PORTB and display the number
  base = base+1;					//increment the base
  
  //reset when the sequence reach upto 6 bit representation
  if(base == 6){
    _delay_ms(RESET_DELAY_MS);		//a reset delay of 500 ms
  	PORTB = PORTB &~(0x3F);			//set least 6 bits of PORTB to zero
    val = 0;
    base = 0;
  }
}