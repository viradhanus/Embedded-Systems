/*
Authors:E/16/083 
        E/16/200
        E/16/368
         
*/

#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY_MS1 250
#define BLINK_DELAY_MS 50


int main (void){

    unsigned char x;
  
    DDRB = 0x0F;//0-3 pins of port B are set as output
    PORTB = 0x00;//initially values of all the pins are 0
  
    while(1){
    
        for(x = 0; x < 4; x++){//x is from 0 to 3 
    	
            PORTB = PORTB | (1<<x);//xth pin is given 1
  	        _delay_ms(BLINK_DELAY_MS1);//lit for 250ms
            PORTB = PORTB & ~(1<<x);  //xth pin is given 0
            _delay_ms(BLINK_DELAY_MS);//not lit for 50ms
        }
        for(x = 2; x > 0; x--){//then from 2 to 1
    	
            PORTB = PORTB | (1<<x);//xth pin is given 1
  	        _delay_ms(BLINK_DELAY_MS1);//lit for 250ms
            PORTB = PORTB & ~(1<<x);  //xth pin is given 0
            _delay_ms(BLINK_DELAY_MS);//not lit for 50ms
  
        }        
    }
  
    return 0;

}