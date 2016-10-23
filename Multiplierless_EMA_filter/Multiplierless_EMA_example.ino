#include "ema_filter.h"
int output ; 

simple_EMA_bitshift Filter(3 ,analogRead(A0)) ; // constructor must take the value for M and the seed value
// in this case M= 3
void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  
  
}

void loop() {

  // filtering 
  output = Filter.filter(analogRead(A0));  

  
  delay(5) ; // 5 ms sampling interval or 200 samples per second sampling frequency 

  // being in this case M=3, alpha is 1/(2^(M))= 1/8 and thus the cutoff frequency is, being the sampling frequency 200 sps, 4.26 Hz. 
  
  // print the result to Arduino IDE Serial Plotter:
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.println(output);
}
