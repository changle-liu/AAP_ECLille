#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/stat.h>
#include <math.h> 
// ceil, floor : #include <math.h>


#include "../include/traces.h" 
#include "../include/check.h" 

#define isINTREE(i,n)		(i<n)
#define iPARENT(i) 			(i-1)/2
#define iLCHILD(i) 			(2*i)+1
#define iRCHILD(i) 			(2*i)+2

void showPOT(int t[], int n);
void showPOT_rec(int t[], int n, int root, int indent);
static void genDotPOT_rec(int t[], int n, int root, FILE *fp); 
void createDotPOT(int t [], int n, const char *basename); 

char * outputPath = "./ex1";

int main(void) {


	int ex1[] = { 18, 15, 11, 10, 15, 6, 1, 7, 4, 9};   // 10
	
	// affichage pseudo graphique 
	showPOT(ex1, 10); 
	
	// affichage graphique 
	// NB: penser à changer la valeur de la variable globale outputPath 
	// pour spécifier le chemin de création des sous-répertoires
	createDotPOT(ex1, 10,"tas"); 
	
}

void showPOT(int t[], int n) {

	printf("Affichage d'un APO (nbElt : %d)\n",n);
	showPOT_rec(t,n,0,0); 
}

void showPOT_rec(int t[], int n, int root, int indent) {
	// affiche récursivement en mode pseudo graphique 
	// t : tas
	// n : taille du tas
	// root : indice de la racine du sous-arbre à afficher
	// indent : décalage à appliquer lors de l'affichage 
	 
	// ordre de récurrence  ?	
	int i;
	// cas de base
	if(! isINTREE(root, n)) return;
	// cas général 
	
	showPOT_rec(t, n, iRCHILD(root), indent+1);
	for(i=0;i<indent;i++){
		printf("\t");
	}
	printf("%d[%d]\n",t[root], root);
	showPOT_rec(t, n, iLCHILD(root), indent+1);

}


static void genDotPOT_rec(int t[], int n, int root, FILE *fp){
	// Attention : les fonction toString utilisent un buffer alloué comme une variable statique 
	// => elles renvoient toujours la même adresse 
	// => on ne peut pas faire deux appels à toString dans le même printf()
	
	// t : tas
	// n : taille du tas
	// root : indice de la racine du sous-arbre à produire
	// fp : flux correspondant à un fichier ouvert en écriture où écrire le sous-arbre
	
	if(! isINTREE(root, n)) return;	// cas de base 
	
	// cas général 
	if(isINTREE(iLCHILD(root), n)){
		fprintf(fp, "\t%d:sw", t[root]);
		fprintf(fp, " -> %d;\n", t[iLCHILD(root)]);
		genDotPOT_rec(t, n, iLCHILD(root), fp);
	}
	if(isINTREE(iRCHILD(root), n)){
		fprintf(fp, "\t%d:se", t[root]);
		fprintf(fp, " -> %d;\n", t[iRCHILD(root)]);
		genDotPOT_rec(t, n, iRCHILD(root), fp);
	}

}


void createDotPOT(int t [], int n,const char *basename) {
	static char oldBasename[FILENAME_MAX + 1] = "";
	static unsigned int noVersion = 0;

	char DOSSIER_DOT[FILENAME_MAX + 1]; 
	char DOSSIER_PNG[FILENAME_MAX + 1]; 

	char fnameDot [FILENAME_MAX + 1];
	char fnamePng [FILENAME_MAX + 1];
	char	cmdLine [2 * FILENAME_MAX + 20];
	FILE *fp;
	struct stat sb;
	

	// Au premier appel, création (si nécessaire) des répertoires
	// où seront rangés les fichiers .dot et .png générés par cette fonction	

	// il faut créer le répertoire outputPath s'il n'existe pas 
	if (stat(outputPath, &sb) == 0 && S_ISDIR(sb.st_mode)) {
    } else {
        printf("Création du répertoire %s\n", outputPath);
		mkdir(outputPath, 0777);
    }

	// il faut créer les répertoires outputPath/png et /dot 
	sprintf(DOSSIER_DOT, "%s/dot/",outputPath);
	sprintf(DOSSIER_PNG, "%s/png/",outputPath);

	if (oldBasename[0] == '\0') {
		mkdir(DOSSIER_DOT,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
		mkdir(DOSSIER_PNG,	S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH);
	}

	 // S'il y a changement de nom de base alors recommencer à zéro
	 // la numérotation des fichiers 

	if (strcmp(oldBasename, basename) != 0) {
		noVersion = 0;
		strcpy(oldBasename, basename); 
	}

	sprintf(fnameDot, "%s%s_v%02u.dot", DOSSIER_DOT, basename, noVersion);
	sprintf(fnamePng, "%s%s_v%02u.png", DOSSIER_PNG, basename, noVersion);

	CHECK_IF(fp = fopen(fnameDot, "w"), NULL, "erreur fopen dans saveDotBST"); 
	
	noVersion ++;
	fprintf(fp, "digraph %s {\n", basename);
	fprintf(fp, 
	"\tnode [\n"
		"\t\tfontname  = \"Arial bold\" \n"
		"\t\tfontsize  = \"14\"\n"
		"\t\tfontcolor = \"red\"\n"
		"\t\tstyle     = \"rounded, filled\"\n"
		"\t\tshape     = \"circle\"\n"
		"\t\tfillcolor = \"grey90\"\n"
		"\t\tcolor     = \"blue\"\n"
		"\t\twidth     = \"0.5\"\n"
		"\t]\n"
	"\n"
	"\tedge [\n"
		"\t\tcolor     = \"blue\"\n"
	"\t]\n\n"
	);


	genDotPOT_rec(t,n,0,fp);

	fprintf(fp, "}\n");	
	fclose(fp);

	sprintf(cmdLine, "dot -Tpng  %s -o %s", fnameDot, fnamePng);
	system(cmdLine);

	printf("Creation de '%s' et '%s' ... effectuee\n", fnameDot, fnamePng);
}















