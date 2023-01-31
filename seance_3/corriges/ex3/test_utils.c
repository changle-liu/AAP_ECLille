#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "test_utils.h"

// NB : code extrait des sujets produits par Christian Vercauter à l'occasion des TPs de CAA

const int Nb[]=
{
    1000  ,   2500,    5000,      10000,
    25000 ,  50000,   75000,     100000,
    150000, 200000, MAX_ELT, MAX_ELT +1,
}; // MAX_ELT vaut 250000

T_stat stats =
{
    0,  /* Nombre de comparaisons */
    0,  /* Nombre d'operations  */
    0   /* Durée en nombre de tops d'horloges */
};

char * outputPath = "."; 

T_data genData(T_elt e, T_elt * pE) {
	T_data d;
	d.elt = e; 
	d.pElt = pE; 
	return d; 
}

/**
 *  \fn             void Initialiser    (T_Elt T[], int n, int mode);
 *  \brief          Initialise les n premiers éléments de T dans le
 *                  mode 'mode'
 *  \param          T       la table d'éléments
 *  \param          n       le nombre d'élémemts
 *  \param          mode    le mode d'initialisation :
 *                  <ul>
 *                      <li>mode = 0    --> initialisation 'directe' (déjà ordonnée) </li>
 *                      <li>mode = 1    --> initialisation aléatoire </li>
 *                      <li>mode = 2    --> initialisation inverse </li>
 *                  </ul>
 */
void Initialiser (T_elt T[], int n, int mode)
{
    int i;


    for (i = 0; i < n; i++)
        switch (mode)
        {
        case MODE_TAB_ORDONNE :  // Ordonné
            T[i] = i;
            break;
        case MODE_TAB_ALEATOIRE :  //  Aléatoire
            T[i] = rand(); // NB : il y aura potentiellement des chiffres identiques dans le tableau
            break;
        case MODE_TAB_INVERSE :  // Inverse
            T[i] = n - i - 1;
            break;
        }
}


/**
 *  \fn             int  estOrdonne     (T_Elt T[], int n, int strict);
 *  \brief          Permet de contrôler que les n premiers éléments de T
 *                  sont bien ordonnés de façon non décroissante (strict = 0),
 *                  strictement croissnate (strict = 1)
 *  \param          T   la table
 *  \param          n   le nombre d'éléments de T à contrôler
 *  \param          strict  mode de contrôle
 *                  <ul>
 *                      <li>strict = 1 --> strictement croissant<\/i>
 *                      <li>strict = 0 --> non décroissante </li>
 *                  </ul>
 *  \return         1 si est ordonné, 0 sinon
 */
int estOrdonne (T_elt T[], int n, int strict)
{
    int i;
    if (strict)
        for (i = 1; i < n && T[i] > T[i-1]; i++);
    else
        for (i = 1; i < n && T[i] >= T[i-1]; i++);

    return i == n;
}

/**
 *  \fn             void Afficher       (T_Elt T[], int n);
 *  \brief          Affiche les valeurs des n premiers éléments de t
 *  \param          T   la table d'éléments
 *  \param          n   le nombre d'éléments à afficher
 */
void Afficher(T_elt T[], int n)
{
    int i;

    printf("\n");
    for (i = 1; i <=  (n > NB_PER_LINE ? NB_PER_LINE : n); i++)
        printf("------");
    printf("\n");

    for (i = 0; i < n; i++)
    {
        printf("%5d", T[i]);
        if ((i + 1) % NB_PER_LINE == 0)
            printf("\n");
        else
            printf(" ");
    }
    printf("\n");
    for (i = 1; i <=  (n > NB_PER_LINE ? NB_PER_LINE : n); i++)
        printf("------");
    printf("\n");
}


////// REFACTORISATION DES EXEMPLES ///////

/**
 *  \fn             void Creer_Fichiers(const char *nom, char *Filename_log, char *Filename_plt)
 *  \brief          Création du fichier de commande Gnuplot permettant l'affichage des courbes
 *                  d'évolution des nombres de comparaisons et d'opérations.
 *                  <p>Construit le nom du fichier de résultat </p>
 *  \param          nom     nom de la méthode de tri
 *  \param          Filename_log    Nom du fichier de données de Gnuplot
 *  \param          Filename_plt    Nom du fichier de commande Gnuplot
 *  \note           Arrêt du programme si la construction du fichier
 *                  de commandes échoue
 */
void Creer_Fichiers(const char *nom, char *Filename_log, char *Filename_plt, T_mode m)
{
    char Filename_op[FILENAME_MAX + 1];  // Fichier graph. des opérations 
    char Filename_cmp[FILENAME_MAX + 1]; // Fichier graph. des compar.
	char subPath[FILENAME_MAX + 1]; // répertoire des fichiers de ce test (cf. argument nom)
	char subPathPNG[FILENAME_MAX + 1]; // sous-répertoire png
	char nom2[FILENAME_MAX + 1]; // nom sans espaces
	
    FILE *fp;
    int i;
	struct stat sb;

	// Nom2 (sans espaces) 
    for (i = 0; i < strlen(nom); i++)
        if (i == 0)
            nom2[i] = nom[i];
        else
            nom2[i] = nom[i] == ' ' ? '_' : tolower(nom[i]);
    for (i--; nom2[i] == '_'; i--);
    nom2[i+1] = '\0';
	
	// répertoire de base de toutes les sorties
    if (stat(outputPath, &sb) == 0 && S_ISDIR(sb.st_mode)) {
    } else {
        printf("Création du répertoire %s\n", outputPath);
		mkdir(outputPath, 0777);
    }

	// TODO : il faudrait un sous-répertoire par nom

	sprintf(subPath, "%s/%s",outputPath, nom2);
	sprintf(subPathPNG, "%s/png",subPath);
	
	// Création des sous-répertoires
	 if (stat(subPath, &sb) == 0 && S_ISDIR(sb.st_mode)) {
    } else {
        printf("Création du répertoire %s\n", subPath);
		mkdir(subPath, 0777);
    }

	// répertoire subPath/png
	 if (stat(subPathPNG, &sb) == 0 && S_ISDIR(sb.st_mode)) {
    } else {
        printf("Création du répertoire %s\n", subPathPNG);
		mkdir(subPathPNG, 0777);
    }

	// On ajoute dataPath/ à Filename_log
	sprintf(Filename_log, "%s/%s_%s.dat",subPath,nom2,m.label);
	sprintf(Filename_plt, "%s/%s_%s.plt",subPath,nom2,m.label);
	sprintf(Filename_op, "%s/%s_%s_op.png",subPathPNG,nom2,m.label);
	sprintf(Filename_cmp, "%s/%s_%s_cmp.png",subPathPNG,nom2,m.label);

    /* Création du fichier de commandes Gnuplot */
    if ( (fp =fopen(Filename_plt, "wt")) == NULL)
    {
        perror(Filename_plt);
        exit(1);
    }
    fprintf(fp, "#--------------------------------");
    for (i= 0; i < strlen(Filename_plt); i++)
        fprintf(fp,"-");
    fprintf(fp, "-+\n");
    fprintf(fp, "# Fichier de commandes gnuplot : %s |\n", Filename_plt);
    fprintf(fp, "#--------------------------------");
    for (i= 0; i < strlen(Filename_plt); i++)
        fprintf(fp,"-");
    fprintf(fp, "-+\n");
    fprintf(fp, "#\n");

    fprintf(fp, "set style data lines\n");
    fprintf(fp, "set xlabel \"Nombre d'éléments\"\n");
    fprintf(fp, "set ylabel \"Nombre d'opérations\"\n");
    fprintf(fp, "set title  \"%s\"\n", nom);
    fprintf(fp, "set grid\n");
    fprintf(fp, "set terminal png\n");
    fprintf(fp, "set output '%s'\n", Filename_op);
    fprintf(fp, "plot '%s' using 1:2 title '%s'\n",  Filename_log, m.label);

    fprintf(fp, "set ylabel \"Nombre de comparaisons\"\n");
    fprintf(fp, "set terminal png\n");
    fprintf(fp, "set output '%s'\n", Filename_cmp);
    fprintf(fp, "plot '%s' using 1:3 title '%s'\n",  Filename_log, m.label);
    fprintf(fp, "quit\n");
    fclose(fp);
}



/**
 *  \fn             void Test_Tri(const char * nom,  void (*tri)(T_Elt [], int),
 *                  T_Elt Table[], int nmax);
 *  \brief          Exécute une méthode de tri, pour différentes
 *                  tailles de tables, et différents modes
 *                  d'initialisation de la table à trier
 *                  <p>Les résultats sont affichés sous forme de tableaux sur l'écran
 *                  </p>
 *  \param          nom     nom de la méthode
 *  \param          tri     pointeur sur la fonction de tri
 *  \param          Table   la table à trier
 *  \param          nmax    nombre maximal d'éléments à trier
 *
 *  \note           utilise, sans modifer, les variables globales
 *                  Nb et Modes, et met à jour la variable globale
 *                  resultat.
 * \warning
 *                  L'implémentation incorrecte de l'affichage d'entiers
 *                  "long long" avec le compilateur MinGW (gcc pour
 *                  Windows) conduit à des traitements spécifiques
 *
 */
void Test_Fn ( const char * nom,  T_pFToTest fn, T_elt Table[], int nmax, T_mode m)
{
    int i;
    clock_t start, stop;
    unsigned long nbH;
	T_data d; 

    printf("+-----------------------------+\n");
    printf("| %-27s |\n", nom);
    printf("+-----------+-----------------+----------------+----------------"
           "+----------------+\n");
    printf("| %8s  | %14s  |  %12s  |  %13s  |  %12s  |\n",
           "Taille","Mode", "Nb compar.",  "Nb opér.", "Duree (ms)");
    printf("+-----------+-----------------+----------------+----------------"
           "+----------------+\n");

	// TOM : plutôt que de parcourir les valeurs du tableau Nb[i]
	// On affiche plutôt 10 lignes, à partir de 1000
	// On ajoutera 

	
    //for (i = 0; Nb[i] <= nmax; i++){
	for (i = nmax/10; i <= nmax; i=i+nmax/10){
		switch (m.mode) {
			case MODE_TAB_ORDONNE : Initialiser(Table, i, MODE_TAB_ORDONNE);break; 
			case MODE_TAB_ALEATOIRE : Initialiser(Table, i, MODE_TAB_ALEATOIRE);break; 
			case MODE_TAB_INVERSE : Initialiser(Table, i, MODE_TAB_INVERSE);break; 
			case MODE_EVAL_X : break; 
		} 
        
        RaZ(stats);
        start = clock();

		d = genData(m.x, Table); // les données : le tableau Table, l'élément proposé dans le mode choisi 
		(*fn)(d, i); // appel de la fonction à tester  

        stop = clock();
		if ( (m.checkOrder) && (!estOrdonne(Table, i, m.mode == MODE_TAB_ORDONNE || m.mode == MODE_TAB_INVERSE))) {
            printf("Cette table n'est pas ordonnee\n");
		}
        else
        {
            printf("|  %6d   | %14s  |",
                   i ,
                   m.label);
            nbH = (unsigned long)(stats.nbComparisons/1000000);
            if (nbH > 0)
                printf("  %6lu%06lu  |", nbH,
                       (unsigned long)(stats.nbComparisons%1000000));
            else
                printf("  %6s%6lu  |", " ",
                       (unsigned long)(stats.nbComparisons%1000000));
            nbH = (unsigned long)(stats.nbOperations/1000000);
            if (nbH > 0)
                printf("  %6lu%06lu  |", nbH,
                       (unsigned long)(stats.nbOperations%1000000));
            else
                printf("  %6s%6lu  |", " ",
                       (unsigned long)(stats.nbOperations%1000000));

            stats.duration_clock_t = stop - start;
            printf("  %10.0f    |\n",
                   1000.*stats.duration_clock_t/CLOCKS_PER_SEC);
        }
    }
    printf("+-----------+-----------------+----------------+----------------"
           "+----------------+\n");
    printf("\n\n");
}

/**
 *  \fn             void Test_TriV2(const char * nom,  void (*tri)(T_Elt [], int),
 *                   T_Elt Table[], int nmax);
 *  \brief          2e version qui exécute une méthode de tri, pour différentes
 *                  tailles de tables, et différents modes
 *                  d'initialisation de la table à trier
 *                  <p>Les résultats sont affichés sous forme de graphes sur l'écran
 *                  </p>
 *  \param          nom     nom de la méthode
 *  \param          tri     pointeur sur la fonction de tri
 *  \param          Table   la table à trier
 *  \param          nmax    nombre maximal d'éléments à trier
 *
 *  \note           utilise, sans modifer, les variables globales
 *                  Nb et Modes, et met à jour la variable globale
 *                  resultat.
 *  \remarks        L'affichage graphique est réalisé à l'aide
 *                  de <a href="http://www.gnuplot.info/"> Gnuplot </a>
 *
 */
void Test_FnV2 ( const char * nom,  T_pFToTest fn,T_elt Table[], int nmax, T_mode m)
{
    int i;
    unsigned long nbH;
	T_data d; 
    char CmdLine[CMDLINE_MAX +1];
    FILE *fp;
    char Filename_log[FILENAME_MAX + 1];
    char Filename_plt[FILENAME_MAX + 1];

	// Tom: ajout du chemin dataPath dans les noms des fichiers 

    Creer_Fichiers(nom, Filename_log, Filename_plt, m);

    if ((fp = fopen(Filename_log, "wt")) == NULL)
    {
        perror(Filename_log);
        exit(2);
    }

    fprintf(fp, "#--");
    for (i= 0; i < strlen(nom); i++)
        fprintf(fp,"-");
    fprintf(fp, "--+\n");
    fprintf(fp, "#  %s  |\n", nom);
    fprintf(fp, "#--");
    for (i= 0; i < strlen(nom); i++)
        fprintf(fp,"-");
    fprintf(fp, "--+\n");
    fprintf(fp, "#\n");


    fprintf(fp,"#+--------+-----------------------------+\n");
    fprintf(fp,"#|        |           %s           |\n", m.label);
    fprintf(fp,"#| Taille | Opérations     Comparaisons |\n");
    fprintf(fp,"#+ -------+--------------+--------------+\n");

    for (i = 1; i <= nmax; i++)
    {
        fprintf(fp,"%8d   ", i);
        switch (m.mode) {
			case MODE_TAB_ORDONNE : Initialiser(Table, i, MODE_TAB_ORDONNE);break; 
			case MODE_TAB_ALEATOIRE : Initialiser(Table, i, MODE_TAB_ALEATOIRE);break; 
			case MODE_TAB_INVERSE : Initialiser(Table, i, MODE_TAB_INVERSE);break; 
			case MODE_EVAL_X : break; 
		} 
        
        RaZ(stats);
		d = genData(m.x, Table); // les données : le tableau Table, l'élément proposé dans le mode choisi 
		(*fn)(d,i); // appel de la fonction à tester 

        if ( (m.checkOrder) && (!estOrdonne(Table, i, m.mode == MODE_TAB_ORDONNE || m.mode == MODE_TAB_INVERSE))) {
            printf("Cette table n'est pas ordonnee\n");
		}
        else
        {
            nbH = (unsigned long)(stats.nbOperations/1000000);
            if (nbH > 0)
                fprintf(fp, "%6lu%06lu    ", nbH,
                        (unsigned long)(stats.nbOperations%1000000));
            else
                fprintf(fp, "%6s%6lu    ", " ",
                        (unsigned long)(stats.nbOperations%1000000));

            nbH = (unsigned long)(stats.nbComparisons/1000000);
            if (nbH > 0)
                fprintf(fp,"%6lu%06lu  ", nbH,
                        (unsigned long)(stats.nbComparisons%1000000));
            else
                fprintf(fp, "%6s%6lu  ", " ",
                        (unsigned long)(stats.nbComparisons%1000000));
        }
        
        fprintf(fp, "\n");
    }
    fprintf(fp,"#+ -------+--------------+--------------+--------------+--------------+--------------+--------------+\n");
    fclose(fp);
    sprintf(CmdLine,"%s %s 2>/dev/null\n", GNUPLOT, Filename_plt);
    system(CmdLine);
}




