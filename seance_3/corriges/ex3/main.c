#include <stdio.h>
#include <stdlib.h>

#include "test_utils.h"

// Ajouter ici les prototypes des fonctions à tester
T_data Puissance(T_data, int n); 
T_data Puissance_rec(T_data d , int n) ;
T_data PuissanceRapide(T_data, int n);
T_data PuissanceRapide_rec(T_data d, int n); 

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

	outputPath = "ex3/output"; // indiquer le chemin du répertoire où créer les fichiers
	// NB: s'il est relatif, il sera relatif au répertoire depuis lequel l'exercice est exécuté
	
    // Initialisation du générateur de nombres pseudo-aléatoires 
    srand((unsigned int)time(NULL));

/*
	d = Puissance(genData(2,NULL) , 10);
	printf("Puissance : 2^%d= %d\n",10, d.elt);

	d = Puissance_rec(genData(2,NULL) , 10);
	printf("Puissance rec : 2^%d= %d\n",10, d.elt);

	Test_Fn("PUISSANCE", Puissance, tab, MAX_ELT, m[MODE_EVAL_X] );
	Test_FnV2("PUISSANCE", Puissance, tab, 512, m[MODE_EVAL_X] );

	Test_Fn("PUISSANCE RECURSIVE", Puissance_rec, tab, MAX_ELT, m[MODE_EVAL_X] );
	Test_FnV2("PUISSANCE RECURSIVE", Puissance_rec, tab, 512, m[MODE_EVAL_X] );
*/	


	d = PuissanceRapide(genData(2,NULL) , 10);
	printf("Puissance rapide : 2^%d= %d\n",10, d.elt);

	d = PuissanceRapide_rec(genData(2,NULL) , 10);
	printf("Puissance rapide : 2^%d= %d\n",10, d.elt);

	Test_Fn("PUISSANCE RAPIDE", PuissanceRapide, tab, MAX_ELT, m[MODE_EVAL_X]);
	Test_FnV2("PUISSANCE RAPIDE", PuissanceRapide, tab, 512, m[MODE_EVAL_X]);

	Test_Fn("PUISSANCE RAPIDE REC", PuissanceRapide_rec, tab, MAX_ELT, m[MODE_EVAL_X] );
	Test_FnV2("PUISSANCE RAPIDE REC", PuissanceRapide_rec, tab, 512, m[MODE_EVAL_X] );


	
}



