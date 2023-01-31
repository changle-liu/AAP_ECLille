#! /bin/bash

#Script shell de configuration de votre environnement
#Il faut l'invoquer par la commande 'source

WHOAMI=$0
if [ $WHOAMI != 'bash' ];
then
	echo "Le script doit être appelé par la commande source setup_env.sh"
	exit 1
fi

PS1='\W \$ '
export GNUMAKEFLAGS=--no-print-directory

clear
echo "Préparation de votre environnement pour la séance 0"
echo "Pour produire l'exercice exo1 : "
echo "choix 1) exécuter la commande <make exo1> depuis la racine"
echo "choix 2) descendre dans le répertoire exo1 et exécuter <make>"
