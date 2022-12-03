#include <stdio.h>
#include <assert.h>
#include "traces.h" 
#include "explor.h"
#include <time.h>

//#define CLOCK_PER_SEC ((clock_t)1000)

//typedef long clock_t;
 
// C'est dans le fichier elt.h qu'on doit choisir l'implémentation des T_elt


int main(int argc, char ** argv) {
	if(argc != 8){ //Examiner la nombre d'elements saisis
		printf("ERROR!\nVeuillez saisir 6 cartons et 1 nombre a trouver.");
	}
	//clock_t start, finish;
	//double duree;
	//start = clock();
	char * s = explor(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),atoi(argv[5]),atoi(argv[6]),atoi(argv[7]));
	char s1[30];
	strcpy(s1,s);
	show_rpn(s1);
	//finish = clock();
	//duree = (double)(finish - start) / CLOCK_PER_SEC /1000.0;
	//printf("La duree d'execution du programme est : %f secondes.\n", duree);

	

	return 0;
}







