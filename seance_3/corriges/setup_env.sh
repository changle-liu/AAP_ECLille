#! /bin/bash

#Script shell de configuration de votre environnement
#Il faut l'invoquer par la commande 'source

PS1='\w \$ '
export GNUMAKEFLAGS=--no-print-directory

clear
echo "Préparation de votre environnement pour la séance 3"
echo "Pour produire l'exercice ex1 : "
echo "choix 1) exécuter la commande <make ex1> depuis la racine"
echo "choix 2) descendre dans le répertoire ex1 et exécuter <make>"
