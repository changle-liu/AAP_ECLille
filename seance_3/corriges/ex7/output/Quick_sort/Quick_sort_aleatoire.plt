#---------------------------------------------------------------------------+
# Fichier de commandes gnuplot : output/Quick_sort/Quick_sort_aleatoire.plt |
#---------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "QUICK SORT"
set grid
set terminal png
set output 'output/Quick_sort/png/Quick_sort_aleatoire_op.png'
plot 'output/Quick_sort/Quick_sort_aleatoire.dat' using 1:2 title 'aleatoire'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'output/Quick_sort/png/Quick_sort_aleatoire_cmp.png'
plot 'output/Quick_sort/Quick_sort_aleatoire.dat' using 1:3 title 'aleatoire'
quit
