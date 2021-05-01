## Serial Communication
When a microprocessor communicates with the outside world, it provides the data in
byte-sized chunks. For some devices, such as printers, the information is simply
grabbed from the 8-bit data bus and presented to the 8-bit data bus of the device. This
can work only if the cable is not too long, because long cables diminish and even
distort the signals. Furthermore, an 8-bit data path is expensive. For these reasons,
serial communication is used for transferring data between two systems located at
distances of hundreds of feet to millions miles apart.

For the serial data communication to work, the byte of data must be converted to
serial bits using a parallel-in-serial-out shift register; then it can be transmitted over a
single data line. This also means that at the receiving end there must be a serial-inparallel-out 
shift register to receive the serial data and pack them into a byte.

Serial data communication uses two methods, asynchronous and synchronous. The
synchronous method needs to transmit the clock as a separate wire while it is not so
in asynchronous transmission. It is possible to write software to use either of these
methods, but the programs can be tedious and long. For this reason, special IC chips
are made by many manufacturers for serial data communications. These chips are
commonly referred to as USART (Universal Synchronous-Asynchronous ReceiverTransmitter).


### Execise 1 & Exercise 2 & Exercise 3 (Transmitting Bits Serially)
![](https://github.com/viradhanus/Embedded-Systems/blob/master/Serial%20Communication/circuit_for_ex_1_2_3.png)




