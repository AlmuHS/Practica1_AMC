#!/usr/bin/gnuplot
set title " Busqueda SecuencialMedio.dat"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "SecuencialMedio.dat" using 1:2 with lines
set terminal png
set output "SecuencialMedio.dat.png"
replot
pause 10 "Pulse Enter para continuar..."
