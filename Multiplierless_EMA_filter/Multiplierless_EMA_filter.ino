#include "ema_filter.h"
int output ; 

simple_EMA_bitshift Filter(4 ,analogRead(A0)) ;

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // seed the filter
  
  
}

void loop() {
 
output = Filter.filter(analogRead(A0));  

  
  delay(5) ; // 5 ms sampling interval 
  
  // print the result:
  Serial.print(analogRead(A0));
  Serial.print(",");
  Serial.println(output);
}

