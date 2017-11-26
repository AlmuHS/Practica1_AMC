set title "Comparacion tiempos entre Hash Cerrada.dat y Interpolacion.dat"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "Hash Cerrada.dat" using 1:2 with lines, "Interpolacion.dat" using 1:2 with lines
set terminal png
set output "Hash Cerrada.dat-Interpolacion.dat.png"
replot
pause 10 "Pulse Enter para continuar..."
