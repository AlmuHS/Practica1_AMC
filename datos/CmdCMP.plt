#!/usr/bin/gnuplot
set title "Comparacion tiempos entre QuickSort.dat y Heapsort.dat"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "QuickSort.dat" using 1:2 with lines, "Heapsort.dat" using 1:2 with lines
set terminal pdf
set output "QuickSort.dat-Heapsort.dat.pdf."
replot
pause 10 "Pulse Enter para continuar..."
