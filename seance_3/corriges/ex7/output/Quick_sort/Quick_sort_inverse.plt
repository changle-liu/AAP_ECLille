#-------------------------------------------------------------------------+
# Fichier de commandes gnuplot : output/Quick_sort/Quick_sort_inverse.plt |
#-------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "QUICK SORT"
set grid
set terminal png
set output 'output/Quick_sort/png/Quick_sort_inverse_op.png'
plot 'output/Quick_sort/Quick_sort_inverse.dat' using 1:2 title 'inverse'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'output/Quick_sort/png/Quick_sort_inverse_cmp.png'
plot 'output/Quick_sort/Quick_sort_inverse.dat' using 1:3 title 'inverse'
quit
