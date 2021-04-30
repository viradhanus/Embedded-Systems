#include <avr/io.h>

//initializing function
void  usart_init (void){
  
  /*Enable receiver and transmitter */
  UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
  
   /*8-bit data - UCSZ0 = 1, UCSZ1  = 1;
    no parity - UPM0 and UPM1 bits = 0
    1 stop bit - USBS0 = 0
    to write to UCSR0C register, URSEL = 1
  */
  
  UCSR0C |= (3<<UCSZ00);//8-bit data
  
  /*calculation for baud rate - 16Mhz oscillator
  9600 = (16 * 10^6)/16(x+1)
  x + 1 = (10^6)/9600
  x = 103.1667
  x = 103 = 0x67
  */
  
  UBRR0 = 0x67;
 
}

//sending data
void usart_send (unsigned char data){
  /* Put data into buffer, sends the data */
  UDR0 = data; 
  /*wait until buffer is empty*/
  while ( !( UCSR0A & (1<<UDRE0)) ) ;
}

//recieving data
unsigned char usart_receive (void){ 
  /* Wait for data to be received */
  while ( !(UCSR0A & (1<<RXC0)) );
  /* Get and return received data from buffer */
  return UDR0;
}


int main(){
  
	usart_init();
  
	while(1){
        //getting a character
        unsigned char c = usart_receive();
      
        if(c>='A' && c<='Z'){//whether alphabatical
				c =(char)((c-'A'+3)%26+'A');//getting the cipher
		}
		else if(c>='a' && c<='z'){
				c=(char)((c-'a'+3)%26+'a');
		}
        
        usart_send(c); 
        
	}

	return 0;
}

