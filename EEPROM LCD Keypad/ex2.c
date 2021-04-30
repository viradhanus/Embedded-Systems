#include <EEPROM.h>

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>

//initialize function
void usart_init(){
  
  	UCSR0B  |= (1 << TXEN0 ); // Enable USART transmitter
  	UCSR0B  |= (1 << RXEN0 ); // Enable USART  receiver
  
	UCSR0C &= ~(1<<UPM01 | 1<<UPM00);	//No parity
	UCSR0C &= ~(1<<USBS0);	//1 stop bit

  	//Set 8-bit
  	UCSR0C |= (1<<UCSZ00) | (1<<UCSZ01);
	UCSR0B &= ~(1<<UCSZ02);
  
    //calculation for baud rate - 16Mhz oscillator
    //9600 = (16 * 10^6)/16(x+1)
    //x + 1 = (10^6)/9600
    //x = 103.1667
    //x = 103 = 0x67

    //Set baud rate 
    UBRR0 = 0x67;

}

//To transmit a character
void usart_send(char data){
	//keep busy until ready for next byte  	
	while(!(UCSR0A & (1<<UDRE0)));
  
  	//Put data into buffer, sends the data 
  	UDR0 = data;		
}

//To return a recieved character
char usart_receive(void){
  //keep busy until data is received 
  while(!(UCSR0A & (1<<RXC0)));
  //Serial.println(UDR0);
   
  //Get and return received data from buffer 
  return UDR0;
}
  
void EEPROMwrite(unsigned int address, char data){

	// wait for completion of previous write
	while (EECR & (1<<EEPE));

	// set up address and data regs
	EEAR = address;
	EEDR = data;

	// write logical 1 to EEMPE
	EECR |= (1<<EEMPE);

	// start eeprom write
	EECR |= (1<<EEPE);
}

char EEPROMread(unsigned int address){

	// wait for completion of previous write
	while (EECR & (1<<EEPE));

	// set up address
	EEAR = address;

	// start eeprom read
	EECR |= (1<<EERE);

	return EEDR;
}

///*
int main(){
	

  char recievedData_c = 'i'; //initialize with some char
  unsigned int w_a = 0; //variable to increment address in while loop
  unsigned int r_a = 0; //variable to increment address in for loop
  
  usart_init();  //initialize USART
  
  while(recievedData_c != '\r'){
    
  	recievedData_c = usart_receive();	//get data from usart_receive()
    EEPROMwrite(w_a++, recievedData_c);	//write data to EEPROM
  
  }

  for (r_a = 0; r_a < 1024; r_a++){

      usart_send(EEPROMread(r_a));   //read data from EEPROM and transmit data
  }
  
  return 0;  


  
}
//*/
/*
int main(){
	
  	char recievedData;
	unsigned int i = 0;
  
  	// initialize the USART to work at 9600
  	usart_init();
  
  	while(1){
      
		recievedData = usart_receive();
      	EEPROM.write(i, recievedData);
		
  		
      	char fetchData = (char)EEPROM.read(i);
      	usart_send(fetchData);
      	i++;
    }

 }
*/
