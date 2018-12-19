#!/bin/bash

cat << _end_ | gnuplot

set terminal postscript eps color
set output "grafico2.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'Datos2.txt' using 1:2 t "Tiempos medidos" , 'Datos2.txt' using 1:3 t "Tiempos estimados" 
_end_
