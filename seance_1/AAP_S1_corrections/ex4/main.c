#include <stdio.h>

//#define CLEAR2CONTINUE
#include "../include/traces.h" 

#define MAXLEN 10

int main(int argc, char ** argv) {
	
	int tab1[MAXLEN] = {0}; 
	int tab[] = {10,20,30,40,50}; 
	int * t = NULL; 
	int * p = NULL; 
	int i = 0; 

	CLRSCR(); 			
	WHOAMI(); 		
	
	/////////////////////////////////////////////////////////////////////////
	// Quelle erreur s’affiche lors de la compilation d’une affectation 
	// contenant le nom d’un tableau à gauche (tab1 = …) ?
	/////////////////////////////////////////////////////////////////////////

	CODE(tab1 = tab);
	NOTE("main.c:28:8: error: assignment to expression with array type\n");

	// correction 
	// tab1 = tab; // TODO: A commenter
	// => main.c:28:8: error: assignment to expression with array type
	

	/////////////////////////////////////////////////////////////////////////
	// Vérifier que l’identificateur tab 
	// représente bien l’adresse de la première case du tableau 
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	printf("tab vaut %p\n", tab);
	printf("&(tab[0]) vaut %p\n", &(tab[0]));
	printf("&(tab) vaut %p\n", &tab); 

	/////////////////////////////////////////////////////////////////////////
	// Vérifier que tab+i représente bien 
	// l’adresse de la ième case du tableau
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	i = 3; 
	printf("tab vaut %p\n", tab);
	printf("tab+%d vaut %p\n", i, tab+i);
	printf("l'adresse de tab[%d] (ie &(tab[%d])) est %p\n", i,i,&(tab[i]));
	printf("la valeur de tab[%d] est %d\n", i,tab[i]);
	printf("la valeur de *(tab+%d) est %d\n", i, *(tab+i));
	

		
	/////////////////////////////////////////////////////////////////////////
	// Vérifier l’arithmétique des pointeurs 
	// en utilisant les notations *(p+i) et p[i]
	// Créer un tableau d’entiers
	// Initialiser le contenu des cases du tableau
	// Créer un pointeur pointant sur le début du tableau
	// Utiliser le pointeur pour afficher le contenu du tableau 
	// et les adresses de ses cases (format %p dans printf)
	// Utiliser les deux notations *(p+i) et p[i]
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();
	TOUCH_HERE("Ben là, c'est à vous !\n");

	printf("Manipulation d'un tableau d'entiers de %d cases\n", MAXLEN);
	
	// TODO : initialiser le tableau tab1 (tab1[i] = i)

	// correction
	for(i=0;i<MAXLEN;i++) {	 
		tab1[i] = i; 
	}

	// TODO : Créer un pointeur pointant sur le début du tableau

	// correction
	p = tab1;

	// TODO : Utiliser le pointeur pour afficher le contenu du tableau
	// TODO : Utiliser les deux notations *(p+i) et p[i]

	// correction
	for(i=0;i<MAXLEN;i++) {
		printf("p[%d] = %d; *(p+%d) = %d\n", i, p[i], i, *(p+i));
		printf("&(p[%d]) = %p; p+%d = %p\n", i, &(p[i]), i, p+i);
	}

/*

	/////////////////////////////////////////////////////////////////////////
	// A traiter en TEA : 
	// int tab[] = {10,20,30,40,50};
	// int * t = NULL;
	// t = tab	; 
	// Quelles sont les autres manières d’initialiser le pointeur t pour qu’il pointe 		// vers le début de tab ?
	// Que vaut t[i] ?
	// Quelle est la différence entre t et tab ? Faire un dessin
	// Que fait (*t)++ ?
	// Que fait ++(*t) ?
	// Que fait *(t++) ?
	// Que fait *(++t) ?
	// Que valent ces expressions ?
	// Qu’est ce que *t++ ?
	/////////////////////////////////////////////////////////////////////////
	ENTER2CONTINUE();
	HR();

	t = tab;
	// on pourrait aussi écrire 
	// t = &tab; 
	// t = &(tab[0]);
	printf("On exécute t = tab\n");

	i=0;
	printf("t[%d] = %d ; tab[%d] = %d\n",i,t[i],i,tab[i]);

	i=1;
	printf("t[%d] = %d ; tab[%d] = %d\n",i,t[i],i,tab[i]);
 
	t=tab; t[0]=10;
	printf("\nCAS 1\n");
	printf("t=tab; t[0]=10;\n");
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);	
	printf("la valeur de (*t)++ est %d\n", (*t)++);
	printf("apres cette opération :\n"); 
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);

	t=tab; t[0]=10;
	printf("\nCAS 2\n");
	printf("t=tab; t[0]=10;\n");
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);	
	printf("la valeur de ++(*t) est %d\n", ++(*t));
	printf("apres cette opération :\n"); 
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);
	
	t=tab; t[0]=10;
	printf("\nCAS 3\n");
	printf("t=tab; t[0]=10;\n");
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);	
	printf("la valeur de *(t++) est %d\n", *(t++));
	printf("apres cette opération :\n"); 
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);
	
	t=tab; t[0]=10;
	printf("\nCAS 4\n");
	printf("t=tab; t[0]=10;\n");
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);	
	printf("la valeur de *(++t) est %d\n", *(++t));
	printf("apres cette opération :\n"); 
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);

	t=tab; t[0]=10;
	printf("\nCAS 5\n");
	printf("t=tab; t[0]=10;\n");
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);	
	printf("la valeur de *t++ est %d\n", *t++);
	printf("apres cette opération :\n"); 
	printf("la valeur de t est %p\n", t);
	printf("la valeur de *t est %d\n", *t);
	
*/

	return 0;
}


