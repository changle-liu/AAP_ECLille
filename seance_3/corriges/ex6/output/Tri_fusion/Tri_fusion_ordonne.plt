#-------------------------------------------------------------------------+
# Fichier de commandes gnuplot : output/Tri_fusion/Tri_fusion_ordonne.plt |
#-------------------------------------------------------------------------+
#
set style data lines
set xlabel "Nombre d'éléments"
set ylabel "Nombre d'opérations"
set title  "TRI FUSION"
set grid
set terminal png
set output 'output/Tri_fusion/png/Tri_fusion_ordonne_op.png'
plot 'output/Tri_fusion/Tri_fusion_ordonne.dat' using 1:2 title 'ordonne'
set ylabel "Nombre de comparaisons"
set terminal png
set output 'output/Tri_fusion/png/Tri_fusion_ordonne_cmp.png'
plot 'output/Tri_fusion/Tri_fusion_ordonne.dat' using 1:3 title 'ordonne'
quit
