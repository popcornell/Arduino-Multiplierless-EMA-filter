#include "ema_filter.h"

// constructor
simple_EMA_bitshift::simple_EMA_bitshift( int Mvalue, int init_val) { 

M= Mvalue; // assign value for M 
output=init_val; // seed initially 


}


int simple_EMA_bitshift::filter(int CurrentInput){

 input=CurrentInput; 
 output+= (input-output) >> M;
 return output; 
}

//optional seed function 
void simple_EMA_bitshift::seed(int init_val){ 

  output=init_val; 
}

