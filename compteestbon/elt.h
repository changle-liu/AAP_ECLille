#ifndef _ELT_H_
	#define _ELT_H_ // prévient les includes multiples

	/////////////////////////////////////////////////////////////////////////
	// CHOISIR ICI CE QUE REPRESENTE LE TYPE T_elt 
	//#define ELT_CHAR		// un caractère ?
	//#define ELT_INT		// un entier (choix par défaut) ?
	//#define ELT_STRING	// une chaîne de caractères ?
	#define ELT_RPN		//un struct permettant de représenter les éléments extraits d’une expression RPN ainsi les résultats possibles d’une évaluation de RPN
	/////////////////////////////////////////////////////////////////////////
	#define IMPLEMENTATION_STATIC_CONTIGUOUS
	//#define IMPLEMENTATION_DYNAMIC_CONTIGUOUS
	//#define IMPLEMENTATION_DYNAMIC_LINKED

	#if ! defined(ELT_CHAR) && ! defined(ELT_INT) && ! defined(ELT_STRING) && ! defined(ELT_RPN)
	#define ELT_INT
	#endif

	#ifdef ELT_CHAR
	typedef char T_elt;
	char * genElt(void);
	#endif

	#ifdef ELT_INT
	typedef int T_elt; 
	char * genElt(void);
	#endif

	#ifdef ELT_STRING
	typedef char * T_elt; 
	char * genElt(void);
	#endif
	
	#ifdef ELT_RPN
	#define ENTIER 0 //Definition du champ status
	#define NON_ENTIER 1
	#define OPERATEUR 2
	#define INVALIDE 3
	#define PLUS -1 //Definition des values de operateurs
	#define MOIN -2
	#define MULT -3
	#define DIVI -4
	typedef struct t_elt {
		int value;//un champ value (entier) représentant un résultat ou un calcul intermédiaire
		int status;//un champ status permettant de représenter la nature du T_elt
	}T_elt;
	#endif

	// valable pour tous les types de T_elt 
	char * toString(T_elt  e);  
#endif 

