#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico1.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'Datos1.txt' using 1:2 t "Tiempos medidos" w l, 'Datos1.txt' using 1:3 t "Tiempos estimados" w l

set terminal postscript eps color
set output "grafico2.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'Datos2.txt' using 1:2 t "Tiempos medidos" w l, 'Datos2.txt' using 1:3 t "Tiempos estimados" w l

set terminal postscript eps color
set output "grafico3.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'Datos3.txt' using 1:2 t "Tiempos medidos" w l, 'Datos3.txt' using 1:3 t "Tiempos estimados" w l

set terminal postscript eps color
set output "grafico4.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'Datos4.txt' using 1:2 t "Tiempos medidos" w l, 'Datos4.txt' using 1:3 t "Tiempos estimados" w l
_end_
