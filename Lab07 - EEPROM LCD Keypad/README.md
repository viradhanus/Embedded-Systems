## Introduction to EEPROM
EEPROM  (Electrically  Erasable  Programmable  Read-Only  Memory)  is  a  type  of  non-
volatile memory that allows individual bytes to be erased and reprogrammed. EEPROMs 
can be programmed and erased in-circuit, by applying special programming signals.  
 
The EEPROM in ATMEGA328P has a capacity of 1 KB. It can endure at least 100,000 
write/erase  cycles. The access between the  EEPROM  and the CPU is described in the 
following, specifying the EEPROM Address Registers, the EEPROM Data Register, and 
the EEPROM Control Register. 

The EEPROM Access Registers are accessible in the I/O space. If the user code contains 
instructions that write the EEPROM, some precautions must be taken. In heavily filtered 
power supplies, VCC is likely to rise or fall slowly on power up/down. This causes the 
device for some period of time to run at a voltage lower than specified as a minimum for 
the clock frequency used. In order to prevent unintentional EEPROM writes, a specific 
write procedure must be followed. When the EEPROM is read, the CPU is halted for four 
clock cycles before the next instruction is executed. When the EEPROM is written, the 
CPU is halted for two clock cycles before the next instruction is executed.  


### Encrypt/Decrypt text and display in LCD (Ex 3)
![](https://github.com/hansthisanke/Embedded-Systems-1/blob/master/EEPROM%20LCD%20Keypad/ex3_circuit.png)
