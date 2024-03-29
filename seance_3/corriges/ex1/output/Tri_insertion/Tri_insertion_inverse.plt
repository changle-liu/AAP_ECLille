#-------------------------------------------------------------------------------+
# Fichier de commandes gnuplot : output/Tri_insertion/Tri_insertion_inverse.plt |
#-------------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "TRI INSERTION"
set grid
set terminal png
set output 'output/Tri_insertion/png/Tri_insertion_inverse_op.png'
plot 'output/Tri_insertion/Tri_insertion_inverse.dat' using 1:2 title 'inverse'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'output/Tri_insertion/png/Tri_insertion_inverse_cmp.png'
plot 'output/Tri_insertion/Tri_insertion_inverse.dat' using 1:3 title 'inverse'
quit
