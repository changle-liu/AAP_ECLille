#---------------------------------------------------------------------------+
# Fichier de commandes gnuplot : output/Tri_par_tas/Tri_par_tas_inverse.plt |
#---------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "TRI PAR TAS"
set grid
set terminal png
set output 'output/Tri_par_tas/png/Tri_par_tas_inverse_op.png'
plot 'output/Tri_par_tas/Tri_par_tas_inverse.dat' using 1:2 title 'inverse'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'output/Tri_par_tas/png/Tri_par_tas_inverse_cmp.png'
plot 'output/Tri_par_tas/Tri_par_tas_inverse.dat' using 1:3 title 'inverse'
quit
