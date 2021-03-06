set title " Busqueda Interpolacion.dat"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "Interpolacion.dat" using 1:2 with lines
quick(x) = a*x*log(x)+b*x+c
fit quick(x) "Interpolacion.dat" using 1:2 via a, b, c
plot "Interpolacion.dat" using 1:2, quick(x)
set terminal png
set output "Interpolacion.dat.png"
replot
pause 10 "Pulse Enter para continuar..."
