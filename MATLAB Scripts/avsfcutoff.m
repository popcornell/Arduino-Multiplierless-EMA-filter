% plot a vs cutoff freq 
figure; hold all; 


alpha= 0.5:0.1:0.8 ; 
w= -pi:0.001:pi; 
color = 'brgc';

%H=zeros(length(alpha),length(w) ) ; 

xlim([0 0.5]); 
ylim([0 1.05]) ; 

for index = 1 : 5
    [Hz fVec] = freqz( [1-alpha(index)], [1 -alpha(index)], w );
  
    plot( fVec./(2*pi), (abs(Hz)), color(index), 'LineWidth', 1 ); 
    legText{index} = sprintf( '$\\alpha = {%d}$', alpha(index) );
end; 

hLeg = legend(legText,3);
 
set( hLeg, 'interpreter', 'latex' );

 


