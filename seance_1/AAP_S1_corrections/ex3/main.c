#include <stdio.h>

// #define CLEAR2CONTINUE

#include "../include/traces.h" // DUMPHEAD, DUMPCHAR, ...

#define MAXLEN 100 

int main(int argc, char ** argv) { 
	char * p_c; 	// p_c pointe n'importe où
	char c = 'A'; 	// A vaut 65 
		
	int * p_i;		// A utiliser dans l'exercice 
	int i; 			// A utiliser dans l'exercice 

	CLRSCR(); 			
	WHOAMI(); 		
	
	CODE(char c = 'A');	
	CODE(char * p_c);

	DUMPHEAD();		// Légende des tableaux 
	DUMPCHAR(c); 	// Affichage d'un caractère 
	DUMPAD(p_c);	// Affichage d'un pointeur 

	HR();			
	NOTE1("Risque d'erreur de segmentation : p_c pointe n'importe où : %p...\n", p_c); 
	NOTE("Vouloir afficher ce qui se trouve à cet endroit n'a pas de sens\n");	

	DUMPHEAD();
	DUMPCHAR(*p_c);	

	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();	
	HR();		

	NOTE("On parvient à lire ce qui se trouve à cet endroit\n");
	NOTE("Modifier ce qui se trouve à cet endroit pourrait provoquer une erreur d'exécution\n");
	CODE(*p_c = 'B');
	
	// correction
	*p_c = 'B'; 	 	// TODO: A commenter : segmentation fault ! 

	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	// Il est conseillé d'initialiser systématiquement les pointeurs à NULL ! 
	p_c = NULL; 
	CODE(p_c = N \bULL);	// affiche le code exact : p_c = NULL 
	CODE(p_c = NULL); 		// afiche le code évalué par le précompilateur : p_c = ((void *) 0)
							// NULL, c'est une constante qui vaut ((void *) 0)
	NOTE1("p_c pointe vers l'adresse : %p...\n", p_c);

	DUMPHEAD();
	DUMPAD(p_c);
	
	NL();
	CODE(c=*p_c);
	NOTE("Erreur de segmentation lors de l'accès à *p_c : il pointe vers NULL !\n");
	NOTE("On ne peut lire lire ce qui se trouve à l'adresse NULL\n");
	
	// correction
	c=*p_c; 	// TODO: A commenter : segmentation fault !	
 

	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	
	CODE(p_c = &c);
	NOTE1("p_c pointe maintenant vers l'adresse de c : %p...\n", p_c);
	p_c = &c; 
	
	DUMPHEAD();
	DUMPCHAR(c);
	DUMPAD(p_c);
	DUMPCHAR(*p_c);
	
	/////////////////////////////////////////////////////////////////////////
	// Arithmétique des pointeurs
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	printf("Arithmétique des pointeurs \n");

	CODE((*p_c)++);
	NOTE("On incrémente la valeur pointée par p_c, c'est à dire le caractère c\n");
	(*p_c)++; 

	DUMPHEAD();
	DUMPCHAR(c);
	DUMPAD(p_c);
	DUMPCHAR(*p_c);

	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	printf("Arithmétique des pointeurs \n");

	*(++p_c); 
	CODE(*(++p_c));
	NOTE("ATTENTION à la priorité des opérateurs !!!\n");
	NOTE("Ici, on incrémente le pointeur p_c (arithmétique des pointeurs)\n");
	NOTE("Puis on essaye d'accéder à ce vers quoi pointe cette adresse\n");
	NOTE("Sans rien en faire...\n");
	NOTE("Certains compilateurs affichent d'ailleurs un warning : value computed is not used\n");


	DUMPHEAD();
	DUMPCHAR(c);
	DUMPAD(p_c);
	DUMPCHAR(*p_c);

	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	printf("Opérations sur des variables de type int\n");
	p_i = &i;
	i=3; 
	CODE(p_i = &i);
	CODE(i=3);

	NOTE("p_i+1 dénote l'adresse de la case mémoire située à côté de la variable i\n");
	NOTE("Essayer de lire le contenu situé à côté de la variable i n'a pas de sens\n");

	DUMPHEAD();		// Légende des tableaux 
	DUMPINT(i); 	// Affichage d'un entier i
	DUMPAD(p_i);	// Affichage d'un pointeur pointant sur i  
	DUMPINT(*p_i);	// Affichage de la valeur pointée par ce pointeur
	DUMPINT(*(p_i+1));	// Affichage de la valeur d'à côté de i 

}

