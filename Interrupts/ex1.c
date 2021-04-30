#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 200

int main(void)
{
  	unsigned char z = 0;	//counter
  	DDRB = DDRB|0x3F;		//set the least significand 6 bits of PORTB output
  	DDRD = DDRD &~(1<<7);	//set PD7 pin as input(push button)
      
    //PORTB = PORTB &~(0b00111111); //set least significand 6 bits to zero initially
  
  	//loop infinitely
    while(1){
      if(PIND & (1<<7)){		//check if bit 7 of PORTD is set to 1
        z = z+1;				//increment counter
        PORTB = z;			//output the counter values(push button pressed)
        _delay_ms(BLINK_DELAY_MS);	//delay 
        
        while(PIND & (1<<7)){
        						//empty loop to run until the push button is released  
        						//otherwise the outer while loop keeps running and incrementing
        }
        
      
      }
    }
    return 0;
  
}