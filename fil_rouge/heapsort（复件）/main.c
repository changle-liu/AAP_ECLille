#include <stdio.h>
#include <stdlib.h>

#include "test_utils.h"

// Ajouter ici les prototypes des fonctions à tester
T_data heapSortV3(T_data, int n) ; 


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

	outputPath = "output"; // indiquer le chemin du répertoire où créer les fichiers
	// NB: s'il est relatif, il sera relatif au répertoire depuis lequel l'exercice est exécuté
	
    // Initialisation du générateur de nombres pseudo-aléatoires 
    srand((unsigned int)time(NULL));

	// Méthodes de tri 
	Test_Fn("TRI PAR TAS", heapSortV3, tab, MAX_ELT/10, m[MODE_TAB_ORDONNE] );
	Test_Fn("TRI PAR TAS", heapSortV3, tab, MAX_ELT/10, m[MODE_TAB_ALEATOIRE] );
	Test_Fn("TRI PAR TAS", heapSortV3, tab, MAX_ELT/10, m[MODE_TAB_INVERSE] );

	Test_FnV2("TRI PAR TAS", heapSortV3, tab, 512, m[MODE_TAB_ORDONNE] );
	Test_FnV2("TRI PAR TAS", heapSortV3, tab, 512, m[MODE_TAB_ALEATOIRE] );
	Test_FnV2("TRI PAR TAS", heapSortV3, tab, 512, m[MODE_TAB_INVERSE] );

	
}



