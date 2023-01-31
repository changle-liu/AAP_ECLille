#include <stdio.h>
#include <stdlib.h>

#include "test_utils.h"

// Ajouter ici les prototypes des fonctions à tester
T_data hanoi(T_data d, int n); 
 
// mode, label, x, checkOrder 
T_mode m[] = {
	{MODE_TAB_ORDONNE, "ordonne", 0, 1}, 
	{MODE_TAB_ALEATOIRE, "aleatoire", 0, 1}, 
	{MODE_TAB_INVERSE, "inverse", 0, 1}, 
	{MODE_EVAL_X, "x=2.0", 2.0, 0}, 
	{MODE_TAB_ORDONNE, "ordonne (x=59)", 59, 0}, 
	{MODE_TAB_ORDONNE, "hanoi", 1, 0}
};

int main(int argc, char *argv[])
{
    T_elt tab [MAX_ELT];
	T_data d; 

	outputPath = "ex5/output"; // indiquer le chemin du répertoire où créer les fichiers
	// NB: s'il est relatif, il sera relatif au répertoire depuis lequel l'exercice est exécuté
	
    // Initialisation du générateur de nombres pseudo-aléatoires 
    srand((unsigned int)time(NULL));


	Initialiser (tab,3,MODE_TAB_ORDONNE);
	// On initialise les 3 premières cases 
	// pour spécifier le pb de Hanoi 
	// tab[0] : num. tige départ 
	// tab[1] : num. tige arrivée
	// tab[2] : num. tige intermediaire
	hanoi(genData(1,tab),4); 
	// si elt vaut 1, il faut afficher des messages

	m[5].x = 0;
	// Ces appels n'afficheront rien 
	Test_Fn("HANOI", hanoi, tab, 20, m[5]);
	Test_FnV2("HANOI", hanoi, tab, 20, m[5]);

	
}



