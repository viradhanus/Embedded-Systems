#include <avr/io.h>
#include <util/delay.h>

//initialize function
void usart_init(){
  
  	UCSR0B  |= (1 << TXEN0 ); // Enable USART transmitter
  	UCSR0B  |= (1 << RXEN0 ); // Enable USART  receiver
  
	UCSR0C &= ~(1<<UPM01 | 1<<UPM00);	//No parity
	UCSR0C &= ~(1<<USBS0);	//1 stop bit

  	//8-bit
  	UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01);
	UCSR0B &= ~(1<<UCSZ02);
  
  /*calculation for baud rate - 16Mhz oscillator
  9600 = (16 * 10^6)/16(x+1)
  x + 1 = (10^6)/9600
  x = 103.1667
  x = 103 = 0x67
  */
  /*Set baud rate */
    UBRR0 = 0x67;
  
}


void usart_send(char data){
	//keep busy until ready for next byte  	
	while(!(UCSR0A & (1<<UDRE0)));
  
  	//Put data into buffer, sends the data 
  	UDR0 = data;
		
}


char usart_receive(void){
  //keep busy until data is received 
  while ( !(UCSR0A & (1<<RXC0)) );
  Serial.println(UDR0);
   
  //Get and return received data from buffer 
  return UDR0;
}

//function to send character wise 
void sendData(char arr[]){
	int i=0;
	while(arr[i] != '\0'){
		usart_send(arr[i]);
		i++;
	}
}


int main(){

  	usart_init();
  	Serial.begin(9600);
	sendData("Viraj E/16/083\n");
	sendData("Sumudu E/16/200\n");
	sendData("Hans E/16/368\n");
  
	return 0;
}


