
class simple_EMA_bitshift{ 
public: 
// input output filter block 

int input;
int output; 
int M; // alpha = 1/(2^M) M defines alpha

simple_EMA_bitshift( int Mvalue, int init_value) ; 
int filter(int CurrentInput);
void seed( int init_val); 
  
};

