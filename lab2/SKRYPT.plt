set terminal pngcairo enhanced font 'arial,10' 
set output 'wykres.png'                        

set xlabel "log10x"                           
set ylabel "log10|E|"                          
set title "Wykres log10x vs log10|E|"           
set yrange [-17:2]

plot "dane3.dat" using 1:2 with points     
