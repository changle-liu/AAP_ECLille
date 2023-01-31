#include <stdio.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

#define MAXTAB 26
#define IN_WORD 1
#define OUT_WORD 0
#define STATE(s) ((s==IN_WORD) ? "IN_WORD" : "OUT_WORD")
#define MAGIC_SPACES(c) (c=='\t') ? "" : ((c=='\n') ? "\t\t" : "\t")



#define STEP_1 1
#define STEP_2 2
#define STEP_3 3

void etape1(void); 
void etape2(void); 
void etape3(void);

int main(int argc, char ** argv) {
	int step=STEP_1; 

	CLRSCR();
	WHOAMI(); 

	// TODO: Cas d'étude : tout est écrit dans la trame de séance 
	// https://docs.google.com/document/d/1ELzc5StntLb2ZZqzKZY8cYReMCfd_tj9WXfu6TVKX7Q/edit?usp=sharing

	// TOUCH_HERE("Ben là, c'est à vous ! Liberté totale ! \n");
	// PROMPT("Les fichiers d'exemple sont dans le sous-répertoire exo11/extraits\n");

	if (argc>1) step = atoi(argv[1]);
	
	switch(step){
		case STEP_1 :
			printf("Etape 1\n");	 
			etape1();
		break;
		case STEP_2 : 
			printf("Etape 2\n");
			etape2();
		break;
		case STEP_3 : 
		default :
			printf("Etape 3\n");
			etape3();
	}


	return 0;
}

void etape1(void) {
	/////////////////////////////////////////////////////////////////////////
	// Etape 1 : Compléter l’exemple ci-dessus de façon à 
	// comptabiliser les caractères, 
	// ainsi que les lignes tapées au clavier par l’utilisateur.
	/////////////////////////////////////////////////////////////////////////

	char c;
	int nbCar=0; 
	int nbLines=0;

	printf("Saisir votre texte (Ctr+D sur ligne vide pour terminer)\n\n");
	
	while (	(c=getchar()) != EOF ) {
		if (c == '\n') {
			nbLines++; 
		} 
		nbCar++;

		#ifdef DEBUG 
			printf("%3d:\t'%c'%s\t%d\n", nbCar, c, MAGIC_SPACES(c),c);
		#endif
	}

	printf("Nb Car : %d\nNbLignes : %d\n",nbCar,nbLines);
}

void etape2(void) {
	/////////////////////////////////////////////////////////////////////////
	// De façon à ne pas trop compliquer les traitements, 
	// on considérera qu’un mot est une séquence de caractères
	// encadrée de séparateurs et dans un premier temps, 
	// seuls trois séparateurs seront pris en compte : 
	// le saut de ligne, l’espace et le caractère de tabulation ('\t' ).
	// Modifier le programme précédent de manière à ce qu’il compte 
	// également les mots du texte tapé au clavier, en gardant à l’esprit
	// qu’il ne faut pas modifier le nombre de mots lorsqu’on lit 
	// une séquence de séparateurs.
	/////////////////////////////////////////////////////////////////////////

	char c;
	int nbCar=0; 
	int nbLines=0;
	int nbWords=0;
	int state=OUT_WORD;

	printf("Saisir votre texte (Ctr+D sur ligne vide pour terminer)\n\n"); 
	
	while (	(c=getchar()) != EOF ) {		
		switch(c) {
			case '\n' : nbLines++;

			case ' ' : 
			case '\t' : nbCar++;
			if (state == IN_WORD) {
				nbWords++; 
				state = OUT_WORD;
			}
			break;
	
			default: nbCar++;state=IN_WORD;  
		}	
		#ifdef DEBUG 	
		printf("%3d:\t'%c'\t%s%d\t%s\n", nbCar, c, MAGIC_SPACES(c),c, STATE(state));
		#endif 
	}

	printf("Nb Car : %d\n",nbCar); 
	printf("NbLignes : %d\n",nbLines);
	printf("NbMots : %d\n",nbWords);
}

void etape3(void) {
	/////////////////////////////////////////////////////////////////////////
	// Compléter le programme précédent de façon à afficher 
	// en plus des résultats précédents : 
	// le nombre total de caractères alphabétiques,
	// un tableau présentant le nombre d’occurrences 
	// de chaque caractère alphabétique, ainsi que sa fréquence 
	// (rapport entre le nombre d’occurrences d’un caractère alphabétique 
	// sur le nombre total de caractères alphabétiques).
	/////////////////////////////////////////////////////////////////////////

	char c;
	int nbCar=0; 
	int nbLines=0;
	int nbWords=0;
	int state=OUT_WORD;
	int occurrences[MAXTAB] = {0};
	int i; 

	printf("Saisir votre texte (Ctr+D sur ligne vide pour terminer)\n\n"); 
	
	while (	(c=getchar()) != EOF ) {		
		switch(c) {
			case '\n' : nbLines++;

			case ' ' : 
			case '\t' : nbCar++;
			if (state == IN_WORD) {
				nbWords++; 
				state = OUT_WORD;
			}
			break;
	
			default: nbCar++;state=IN_WORD;
			if ( (c>= 'A')  && (c<= 'Z')){
				// traitement des lettres MAJUSCULES 
				// carLu -'A' : indice où stocker cette occurrence 
				occurrences[c -'A']++; 
			}
			if ( (c>= 'a')  && (c<= 'z')){
				// traitement des lettres MAJUSCULES 
				// carLu -'a' : indice où stocker cette occurrence 
				occurrences[c -'a']++; 
			}  
		}	

		#ifdef DEBUG 	
		printf("%3d:\t'%c'\t%s%d\t%s\n", nbCar, c, MAGIC_SPACES(c),c, STATE(state));
		#endif
	}

	printf("Nb Car : %d\n",nbCar); 
	printf("NbLignes : %d\n",nbLines);
	printf("NbMots : %d\n",nbWords);

	printf("+--------+----------+--------------+\n");
	printf("| Lettre | Nombre   |   Fréquence  |\n"); 

	// affichage des fréquences 
	for(i=0;i<MAXTAB;i++) {
		// case i - quelle lettre ? 'A' + i 
		printf("+--------+----------+--------------+\n");
		printf("+ %6c | %8d | %10.3f %s +\n", 'A'+i,occurrences[i],100 * (float) occurrences[i]/nbCar,"%" );
	}

	printf("+--------+----------+--------------+\n");
}
