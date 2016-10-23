


%plot a in relationship with \omega cutoff
a = 0.00001:0.001:1; 
wc= acos((2-2*a-a.^2)./(2-2*a)) ; 
% see https://www.dsprelated.com/showarticle/182.php

figure; 

normfreq=wc./(2*pi) ; 
h=plot(a,normfreq,'LineWidth',1.0) ; 
ylabel('normalized freq(rad/sample)') ;
xlabel('a') ; 
grid on ; 
