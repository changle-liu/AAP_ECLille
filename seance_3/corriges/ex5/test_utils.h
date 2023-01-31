#include <time.h>

// NB : code extrait des sujets produits par Christian Vercauter à l'occasion des TPs de CAA

#ifndef _SORT_H_
	#define _SORT_H_

#define RaZ(r) memset(&(r), 0, sizeof(r))
#define MAX_ELT                 250000

typedef int T_elt;

typedef struct {
	T_elt elt; 
	T_elt * pElt; 
} T_data;  

typedef struct {
    unsigned long long  nbComparisons; // nombre de comparaisons effectuées
    unsigned long long  nbOperations;  // nombre d'opérations (affectations, multiplications suivant les problèmes)
    clock_t             duration_clock_t; // durée de la fonction en nombre de tops d'horloge    
} T_stat;

// Type pointeur sur une fonction 
// Cette fonction prend de manière générale deux arguments : 
// * un pointeur sur un T_Elt 
// (peut être l'adresse de début d'un tableau, ou simplement l'adresse d'une valeur à utiliser dans la fonction)
// * un entier relatif à la taille du problème considéré

typedef T_data (*T_pFToTest) ( T_data d, int n);

// Structure définissant une fonction à tester
typedef struct {
    char *name; //nom de la fonction 
    T_pFToTest fn; //pointeur sur la fonction a tester
    unsigned int limit; // nombre maximal d'élements qu'elle peut manipuler dans un temps raisonnable
} T_fnToTest;

extern T_stat stats;

#define MODE_TAB_ORDONNE 0
#define MODE_TAB_ALEATOIRE 1
#define MODE_TAB_INVERSE 2
#define MODE_EVAL_X 3

typedef struct {
	int mode; 		// parmi les constantes précédentes 
	char * label;
	T_elt x; 		// si MODE_EVAL_X : besoin d'une variable pour exécuter la fonction, quelle valeur utiliser ?  
	int checkOrder; // faut-il vérifier si la table est ordonnée ?
} T_mode; 

extern int nb[];
extern char * outputPath; 

// Nombre de valeurs affichées par ligne
#define NB_PER_LINE             10

// Longueur maximale de la ligne de commande construite pour appeler GnuPlot
#define CMDLINE_MAX             64

// Définition du nom de l'apllication GnuPlot
#define GNUPLOT                 "gnuplot"

void Initialiser (T_elt T[], int n, int mode);
int estOrdonne (T_elt T[], int n, int strict); 
void Afficher(T_elt T[], int n); 

void Creer_Fichiers(const char *nom, char *Filename_log, char *Filename_plt, T_mode m); 
void Test_Fn ( const char * nom, T_pFToTest fn , T_elt Table[], int nmax, T_mode m); 
void Test_FnV2 ( const char * nom, T_pFToTest fn , T_elt Table[], int nmax, T_mode m); 
T_data genData(T_elt e, T_elt * pE);

#endif
