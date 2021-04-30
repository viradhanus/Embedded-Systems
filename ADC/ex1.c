/*
Group 09
Exercise 1
*/

#include <avr/io.h>
#include <math.h>

unsigned char i;	//increment
unsigned int sum; 	//keep the total decimal value


int main(void){

	DDRD = 0xFF;//setting 8 bits of PORTD as output
	DDRC = DDRC &~(1<<1);  //setting ADC1 pin as input
	
 	//enable ADC (ADEN Bit - 7 in ADCSRA reg)
  	ADCSRA |= (1<<ADEN);
 
	//ADC pre-scalar select  
  	//XTAL = 16MHz
  	//for maximum accuracy input clock frequency < 200kHz
  	//f(ADC) = f(OSI) / prescalar
    //200kHz => 16MHz / prescalar
  	// prescalar => 80
  
  	//pre-scale 1:128 gives  XTAL/128 = 125 KHz 
  	ADCSRA |= 0x07; //ADCSRA[2:0] = 0b111;
    
  
  	//set AVCC as the reference voltage for ADC 
    ADMUX |= (1<<REFS0);
  	ADMUX = ADMUX &~(1<<REFS1);
      
    //right justify results
     ADMUX = ADMUX & ~(1<<ADLAR);
  	//ADMUX |= (1<<ADLAR);
      
    //select analog input channel ADC1 = MUX[3:0] = 0b0001
    ADMUX |= 0x01;
    
    Serial.begin(9600);
  	while(1){
  		ADCSRA |=(1<<ADSC);	//start conversion
  		while((ADCSRA & (1<<ADIF))==0);	//keep busy until Interrupt flag is set
      	//after conversion completes 
         
      	//find the decimal value using ADCL and ADCH
        for (i = 0; i < 8; ++i)
        {
          if(((ADCL>>i)&1) && i <= 7){
            sum = sum + pow(2,i);  
          }
          if(((ADCH>>i)&1) && i <= 1){
            sum = sum + pow(2,i+8);  
          }
        }  
      
      //find the portion of LED's to display 
      sum = (sum*8)/1024;
      Serial.println(sum); 
      
      //turn on LED portion
      for (i = 0; i < sum; ++i)
      {
         PORTD |= (1<<i) ;
      } 
  	}
  
   	//stepsize = Vref/2^(resolution)	Vref = 5V , resolution 10 bits		
  	//stepsize = 5/2^10 = 5/1024 = 8mV
  	//Dout = Vin/stepsize	Vin = 3.3v		Dout = (3.3)/stepsize = 675
   	
	//for Dout = 675
  	//No of LED's = (675/1024)*8 = 5.27 (approx. = 5)
  return 0;
}

