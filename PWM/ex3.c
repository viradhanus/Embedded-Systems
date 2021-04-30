#include <avr/io.h>
#include <util/delay.h>

//appropriate delay
#define SOUND_DELAY 1000

unsigned char i;

int main(void){
  
  DDRD = DDRD|(1<<6);//setting the 6th pin as output
  
  OCR0A = 127;//50% duty cycle
  
   
  while(1){ 
    
    for (i = 5;i>=2;i--){
      TCCR0B = i;//starts from scalar 5 to 2(1024-->8)
      TCCR0A |= (1 << COM0A1); // set none-inverting mode
 	  TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast PWM Mode
      _delay_ms(SOUND_DELAY);//giving delay
    }
    
  }
  return 0;
}


  
/*
getting appropriate frequencies
f = (16M)/(256 x n)
 
when n = 1024
f = 61.035Hz
 
n = 256
f = 244.140Hz
 
n = 64
f = 976.5Hz
 
n = 8
f = 7812.5Hz
*/
 

/*
calculating the duty cycle
50 = 100(1+ocr0) / 256;
ocr0 = 127
*/