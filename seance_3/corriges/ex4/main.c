#include <stdio.h>
#include <stdlib.h>

#include "test_utils.h"

// Ajouter ici les prototypes des fonctions à tester
T_data RechercheDicho (T_data d, int n);
T_data RechercheDicho_rec (T_data d, int n); 

// mode, label, x, checkOrder 
T_mode m[] = {
	{MODE_TAB_ORDONNE, "ordonne", 0, 1}, 
	{MODE_TAB_ALEATOIRE, "aleatoire", 0, 1}, 
	{MODE_TAB_INVERSE, "inverse", 0, 1}, 
	{MODE_EVAL_X, "x=2.0", 2.0, 0}, 
	{MODE_TAB_ORDONNE, "ordonne_x=59", 59, 0}, 
	{MODE_TAB_ORDONNE, "hanoi", 1, 0}
};

int main(int argc, char *argv[])
{
    T_elt tab [MAX_ELT];
	T_data d; 

	outputPath = "ex4/output"; // indiquer le chemin du répertoire où créer les fichiers
	// NB: s'il est relatif, il sera relatif au répertoire depuis lequel l'exercice est exécuté
	
    // Initialisation du générateur de nombres pseudo-aléatoires 
    srand((unsigned int)time(NULL));


	Initialiser (tab, 512,MODE_TAB_ORDONNE); // contient 512 valeurs de 0 à 511

	d = RechercheDicho(genData(0,tab) , 512);
	if (d.pElt != NULL) printf("Trouvé : %d\n",*(d.pElt));
	else printf("Non trouvé : %d\n", 0);

	d = RechercheDicho(genData(512,tab) , 512);
	if (d.pElt != NULL) printf("Trouvé : %d\n",*(d.pElt));
	else printf("Non trouvé : %d\n", 512);

	d = RechercheDicho(genData(511,tab) , 512);
	if (d.pElt != NULL) printf("Trouvé : %d\n",*(d.pElt));
	else printf("Non trouvé : %d\n", 511);

	d = RechercheDicho(genData(59,tab) , 512);
	if (d.pElt != NULL) printf("Trouvé : %d\n",*(d.pElt));
	else printf("Non trouvé : %d\n", 59);

	Test_Fn("RECHERCHE DICHOTOMIQUE", RechercheDicho, tab, MAX_ELT, m[4]);
	Test_FnV2("RECHERCHE DICHOTOMIQUE", RechercheDicho, tab, 512, m[4]);


	Initialiser (tab, 512,MODE_TAB_ORDONNE);	// contient 512 valeurs de 0 à 511

	d = RechercheDicho_rec(genData(0,tab) , 512);
	if (d.pElt != NULL) printf("Trouvé : %d\n",*(d.pElt));
	else printf("Non trouvé : %d\n", 0);

	d = RechercheDicho_rec(genData(512,tab) , 512);
	if (d.pElt != NULL) printf("Trouvé : %d\n",*(d.pElt));
	else printf("Non trouvé : %d\n", 512);

	d = RechercheDicho_rec(genData(511,tab) , 512);
	if (d.pElt != NULL) printf("Trouvé : %d\n",*(d.pElt));
	else printf("Non trouvé : %d\n", 511);

	d = RechercheDicho_rec(genData(59,tab) , 512);
	if (d.pElt != NULL) printf("Trouvé : %d\n",*(d.pElt));
	else printf("Non trouvé : %d\n", 59);
	
	Test_Fn("RECHERCHE DICHOTOMIQUE REC", RechercheDicho_rec, tab, MAX_ELT, m[4]);
	Test_FnV2("RECHERCHE DICHOTOMIQUE REC", RechercheDicho_rec, tab, 512, m[4]);

	

}



