#include <avr/io.h>

int main(void){
 
  DDRD = DDRD|(1<<6);//setting the 6th pin as output
 
/*
  Calculating the OCR0A value to get 50% duty cycle
 
  50 = 100(1+ocr0) / 256;
  ocr0 = 127
*/
  OCR0A = 127; //50% duty cycle

/*
  Calculating the Prescalar
  N = F(oscilator)/F(generated Wave)x 256
 
  N = 16M / 976.56 x 256
  N ~ 64
 
*/
  TCCR0B |= (1 << CS00) | (1 << CS01); // set prescaler to 64 and starts PWM
 
  TCCR0A |= (1 << COM0A1); // set none-inverting mode
  TCCR0A |= (1 << WGM01) | (1 << WGM00); // set fast PWM Mode
 
  while (1);
   
  return 0;
 
}

