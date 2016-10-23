# Arduino-Multiplierless-EMA-filter
###This repository contains a very simple class that implements a __Multiplierless__ first-order IIR/Exponential Mobile Average filter.


Basically the input-output relationship of an EMA filter which is: 

**y[n]=(1-alpha)y[n-1] + (alpha)x[n]**

(It is worth noting that in literature exists an equivalent version of this equation with the coefficients alpha and 1-alpha inverted.) 

can be rewritten as: 

**y[n]= y[n-1]+(alpha)(x[n]-y[n-1])**

Now if **alpha** which could be thought of sort of a __"smoothing factor"__ is chosen to be a factor of a power of two: 

**alpha = 1/(2^M)**

Looking more closely at the EMA equation it is clear that the lower the __"smoothing factor"__ and thus the cutoff frequency, 
the less the current output y[n] will be influenced by the current input x[n] but rather will rely more and more, as alpha decreases, 
on the previous output y[n-1]. 
So  the less the alpha, the more the output signal will be able to "resist" changes, hence the name __smoothing factor__. 

If this choice is made the filter can be implemented using the right bitshift operator: 

**y[n] += (x[n]-y[n-1]) >> M** 

This potentially allows for  a significant  **saving  in  cpu  cycles** especially for microcontroller such as Arduino. 
This saving in cpu cycles is obtained at the expense of flexibility, in fact only certain value for alpha are allowed. 

Additional information on Multiplierless EMA filters is available at https://www.dsprelated.com/showarticle/72.php. 

#MATLAB 
I've also included MATLAB code to **plot alpha vs fc/fs** for the filter where fs is the sampling frequency and fc is the cutoff frequency. 
This can be used to estimate correctly the smoothing factor alpha given the desired fc. 

For those who don't have MATLAB i've included in the image below the plot: 

!['o' output](http://i.imgur.com/JlU6bXM.png)

!['o' output](http://i.imgur.com/is0V6jf.png)

Moreover the included example .ino file can be used as a very simple test to find out wether the filter functions properly. 
In the main loop delay one can put the corresponding **sampling interval for the actual use case**, then the filtered 
and unfiltered signals can be seen via Arduino IDE serial plotter.  



