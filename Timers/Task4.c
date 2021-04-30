/*
Calculation:
delay = 1s = 10^6 micro seconds
XTAL = 16MHz ---> 1/16(period)
Prescale = 1:256
(1/16)*256 = 16
No of increments = (10^6)/16=62500
Initial value in the timer register = 1+65535-62500
                                    =3036
                                    =0x0BDC
*/


#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define BLINK_DELAY 1000


ISR(TIMER1_OVF_vect){
  	TCNT1 = 0x0BDC;//reload for next round
    PORTB = PORTB^(1<<5);		//toggle PB5    
}

int main(void)
{
	
  	
  	DDRB = DDRB | 0x2F; //set pins 0-3 and 5 output(PB0-3 knight rider,PB5 toggle)
  	PORTB = PORTB & ~(0x2F);//initially those pins are set to zero
  
  	TCNT1 = 0x0BDC;//initial value-3036
  
  	
  	//set the TIMER1 under normal mode with 1:256 prescaler
  	TCCR1A = 0x00;	//normal mode
  	TCCR1B = 0x04;  //1:256 scaling
  				
  
  	sei();//enable global interrupts(set I)	
  
  	TIMSK1 |= (1<<TOIE1);	//enable Timer1 overflow interrupt
  
  	
  
  	//for knight rider circuit
    unsigned char i=0;//int i
    unsigned char condition = 0 ;
  
  	while(1){//infinite loop to keep the cpu busy
      
       //knight rider circuit
       PORTB = PORTB|(1<<i);//ith pin is given 1
       _delay_ms(BLINK_DELAY);//delay
       PORTB = PORTB & ~(1<<i);//ith pin is given is 0
       _delay_ms(BLINK_DELAY);//delay


      if(i==3){
        condition=1;//then i should be decreased by one
      }    
      if(i==0){
         condition=0;//then i should be increased by one
      }
      if (condition == 1){
        i=i-1;
      }
      if (condition == 0){
        i=i+1;
      }

   }

   	return 0;
}














