## Introduction of Timers
Many applications need to count occurrences of an event or generate time delays. So, there
are counter registers in microcontrollers for this purpose. When we want to count events,
we connect the external event source to the clock pin of the counter register. Then, when an
event occurs externally, the content of the counter is incremented; this way, the content of
the counter represents how many times the event has occurred.
When we want to generate time delays, we connect the oscillator to the clock pin of the
counter. So, when the oscillator 'ticks', the content of the counter is incremented. As a
result, the content of the counter register represents how many 'tick' events have occurred
from the time we have cleared the counter. Since the speed of the oscillator in a
microcontroller is known, we can calculate the 'tick' period. Therefore, using the content of
the counter register we can derive how much time has elapsed altogether.


### Exercise 1 & 2 & 3
![](https://github.com/viradhanus/Embedded-Systems/blob/master/Timers/Task1_circuit.png)


### Exercise 4
![](https://github.com/viradhanus/Embedded-Systems/blob/master/Timers/Task4_circuit.png)

### Exercise 5
![](https://github.com/viradhanus/Embedded-Systems/blob/master/Timers/Task5_circuit.png)

### Exercise 6
![](https://github.com/viradhanus/Embedded-Systems/blob/master/Timers/Task6_circuit.png)
