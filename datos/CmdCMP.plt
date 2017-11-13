set title "Comparacion tiempos entre Binaria.dat y Hash Cerrada.dat"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "Binaria.dat" using 1:2 with lines, "Hash Cerrada.dat" using 1:2 with lines
set terminal png
set output "Binaria.dat-Hash Cerrada.dat.png"
replot
pause 10 "Pulse Enter para continuar..."
