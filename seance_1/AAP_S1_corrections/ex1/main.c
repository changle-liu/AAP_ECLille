#include <stdio.h>

// faut-il effacer l'écran avant de continuer lors des séparations ?
// #define CLEAR2CONTINUE

#include "../include/traces.h" // HR, CLRSCR, WHOAMI, NOTE, ENTER2CONTINUE ...

int main(int argc, char ** argv) {

	CLRSCR(); 		// Effacer l'écran	
	WHOAMI(); 		// Nom du programme, date & heure de compilation
	 

	/////////////////////////////////////////////////////////////////////////
	// Différentes manières d'exprimer le caractère 'A' 
	// à l'aide de littéraux 
	/////////////////////////////////////////////////////////////////////////
	
	NOTE("Différentes manières d'exprimer le caractère 'A' à l'aide de littéraux :\n\n"); // Affichage sans argument

	printf("'A'    <=> valeur %d <=> glyphe %c \n",'A','A');			// caractère 'A'
	printf("'\\x41' <=> valeur %d <=> glyphe %c \n",'\x41','\x41'); 	// caractère codé en hexadécimal '\x41'
	printf("'\\101' <=> valeur %d <=> glyphe %c \n",'\101','\101'); 	// caractère codé en octal '\101'
	printf("65     <=> valeur %d <=> glyphe %c \n",65,65); 				// decimal 65
	printf("0x41   <=> valeur %d <=> glyphe %c \n",0x41,0x41); 			// hexadécimal 0x41
	printf("0101   <=> valeur %d <=> glyphe %c \n",0101,0101); 			// octal 0101

	HR();				// Barre horizontale
	ENTER2CONTINUE();	// Attente pour continuer : videra l'écran ou non 
	


	return 0;
}
