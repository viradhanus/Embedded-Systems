/*
Group 09
Exercise 2
*/

#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY 100

int main(void){
 
  DDRB = DDRB | 0x01;//PortB 0th pin as output
  
  DDRC = DDRC &~(1<<1);  //setting ADC1 pin as input

  //enable ADC
  ADCSRA |= (1<<ADEN);
 
  //ADC pre-scalar select  - 128
  ADCSRA |= 0x07; //[2:0] = 0b111;
   
 
  //Internal vref is off
   ADMUX = ADMUX &~(1<<REFS0);
   ADMUX = ADMUX &~(1<<REFS1);
  //i gave 5v for AREF pin externally
     
   //left justify results
   ADMUX |= (1<<ADLAR);
     
   //select analog input channel ADC1 = MUX[3:0] = 0b0001
   ADMUX |= (1<<MUX0);
   ADMUX &= ~((1<<MUX3)|(1<<MUX2)|(1<<MUX1));
     
 Serial.begin(9600);
  while(1){
    
    ADCSRA |=(1<<ADSC); //start conversion
    
    while((ADCSRA & (1<<ADIF))==0); //keep busy until Interrupt flag is set
    
    Serial.println(ADCH);
    //after conversion completes
       
    if (ADCH < 100){
        PORTB |= (1<<0);//lighing the led
    }
    else{ 
        PORTB &= ~(1<<0);//turning off the led
    }
    
    //clear ADIF
    ADCSRA |= (1<<ADIF);
     
  }
    return 0;
}

//calculation
//XTAL = 16MHz
//16MHz/n < 200
//n>(16000/200)
//n>80
//for maximum accuracy input clock frequency < 200kHz
//pre-scale 1:128 gives  XTAL/128 = 125 KHz