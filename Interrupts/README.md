## Introduction to Interrupts
A  Single  microcontroller  can  serve  several  peripherals.  There  are  two  methods  by  which 
devices receive service from the microcontroller: interrupts and polling. 
In the interrupt method, whenever any peripheral needs the microcontroller’s service, the 
device  notifies  it  by  sending  an  interrupt  signal.  Upon  receiving  an  interrupt  signal,  the 
microcontroller stops whatever it is doing and serves the device.  The program associated 
with the interrupt is called the Interrupt Service Routine (ISR). 
In polling, the microcontroller continuously monitors the status of several devices and serve  
each  of  them  as  certain  conditions  are  met.  However,  it  is  not  an  efficient  use  of  the 
microcontroller. 
The  most  important  reason  why  the  interrupt  method  is  preferable  is  that;  the  polling 
method  wastes  much  of  the  microcontroller’s  time  by  polling  devices  that  do  not  need 
service. 

### Use of polling method (Ex 1)
![](https://github.com/hansthisanke/Embedded-Systems-1/blob/master/Interrupts/ex1_circuit.png)


### Use of external interrupts (Ex 2)
![](https://github.com/hansthisanke/Embedded-Systems-1/blob/master/Interrupts/ex2_circuit.png)


### Display count of push button releases using LED's(binary)  (Ex 3)
![](https://github.com/hansthisanke/Embedded-Systems-1/blob/master/Interrupts/ex3_circuit.png)


### Two push buttons with external interrupts (Ex 4)
![](https://github.com/hansthisanke/Embedded-Systems-1/blob/master/Interrupts/ex4_circuit.png)

