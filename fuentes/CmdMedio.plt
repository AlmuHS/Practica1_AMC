set title " Busqueda Hash Abierta.dat"
set key top left vertical inside
set grid
set xlabel "Talla (n)"
set ylabel "Tiempo (ms)"
plot "Hash Abierta.dat" using 1:2 with lines
quick(x) = a + b + c
fit quick(x) "Hash Abierta.dat" using 1:2 via a,b,c
plot "Hash Abierta.dat" using 1:2, quick(x)
set terminal png
set output "Hash Abierta.dat.png"
replot
pause 10 "Pulse Enter para continuar..."
