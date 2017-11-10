#!/usr/bin/gnuplot
set title " Busqueda Hash Cerrada.dat"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "Hash Cerrada.dat" using 1:2 with lines
quick(x) = a + b + c
fit quick(x) "Hash Cerrada.dat" using 1:2 via a,b,c
plot "Hash Cerrada.dat" using 1:2, quick(x)
set terminal png
set output "Hash Cerrada.dat.png"
replot
pause 10 "Pulse Enter para continuar..."
