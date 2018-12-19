#!/bin/bash

cat << _end_ | gnuplot

set terminal postscript eps color
set output "grafico5.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'Datos5.txt' using 1:2 t "Tiempos medidos" w l , 'Datos5.txt' using 1:3 t "Tiempos estimados" w l
_end_
