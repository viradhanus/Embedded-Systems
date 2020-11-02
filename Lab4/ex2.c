#include <avr/io.h>
#include <util/delay.h>
#define BLINK_DELAY 25

unsigned char i;

int main(void){
 
  DDRD = DDRD|(1<<6);//setting the PD6(OC0A) pin as output
 
  TCCR0B |= (1 << CS01) | (1 << CS00); // set prescaler to 64
 // TCCR0B &= ~(0<< CS00);
  TCCR0A |= (1 << COM0A1); // set non-inverting mode
  TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast PWM Mode
 
 
 //infinite loop
  while(1){
    //fade from off -> on
    for (i=0 ; i<256 ; i++){
      OCR0A = i; //increments
      _delay_ms(BLINK_DELAY);  //delay added to capture slowly fading of the LED
    }
   
    //fade from on -> off
    for (i=255; i>=0; i--){
      OCR0A = i; //decrements
      _delay_ms(BLINK_DELAY);  //delay
    }  
  }
 
  return 0;
}

//duty cycle(%) = (OCROA + 1)/256 * 100
//LED brightness increase when duty cycle increases