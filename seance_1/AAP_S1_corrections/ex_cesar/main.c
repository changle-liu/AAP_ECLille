#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//#define CLEAR2CONTINUE
#include "../include/traces.h" 

char * aveCesar(const char *s);
char * dyhCesar(const char *s);
char * cesar (const char * s, int decalage);
void test_aveCesar(void); 
void test_dyhCesar(void);
void test_cesar(void); 
void test_rot13(void); 

# define ALPHABSZ 26
# define MAXLEN 100
# define DEF_DECAL 3

#define rot13(s) cesar (s, 13)

int main (int argc , char * argv [])
{
	int n = 0;
	char ligne [MAXLEN + 1] = "";

	CLRSCR();
	WHOAMI(); 
	
	//test_aveCesar(); 
	//test_dyhCesar(); 
	//test_cesar();
	//test_rot13(); 

	// Commande shell de chiffrement-déchiffrement
 
	switch (argc) {
		case 3 :
			// deux arguments : <decalage> et <phrase>
			printf ("%s\n", cesar (argv [2] , atoi(argv [1])));
			return 0;

		case 2 :
			// un argument , deux cas : <decalage> OU <phrase>
			n = atoi(argv [1]);
			if (n == 0) {
				// la phrase est fournie, on la décode avec le décalage par défaut
				printf ("%s\n", cesar (argv [1], DEF_DECAL ));
				return 0;
			}
			// sinon, c'est un décalage : on l'a enregistré dans la variable n
			break ;

		case 1 : // pas d'argument
			n = DEF_DECAL ;
			break ;

		default :
			fprintf (stderr , " Usage : %s [<decalage >] [<phrase >]\n", argv [0]);
			return 1;
	} /* switch */
	
	// lecture sur l'entrée standard en appliquant le décalage n sélectionné
	while ( fgets (ligne , sizeof ( ligne ) - 1, stdin ) != NULL)
		printf ("%s", cesar (ligne , n));
	
	return 0;
}

char * aveCesar ( const char * s){
	// retourne le résultat du chiffrement de la chaîne de caractères 
	// transmise en paramètre
	// Consigne : développer cette fonction en utilisant les fonctions 
	// de la librairie standard, décrites dans string.h et ctype.h 

	char * res = strdup (s);	// duplication de s
	int i;

	for (i=0;i<strlen(s);i++) {
		if ( islower (s[i]))
			res[i] = (((s[i] - 'a')+3) % 26 ) + 'A';
		else if ( isupper (s[i]))
			res[i] = (((s[i] - 'A') + 3) % 26 ) + 'a'; 
	}	

	return res;
}

char * dyhCesar ( const char * s) {
	// retourne le résultat du déchiffrement de la chaîne de caractères 
	// transmise en paramètre
	// Consigne : développer cette fonction SANS UTILISER les fonctions 
	// de la librairie standard décrites dans string.h et ctype.h 

	int sizeS=0, i; 
	char * res;
	char *p;

	// calcul taille de s 
	for (; *(s+sizeS) != '\0'; sizeS++); 

	// allocation mémoire pour la copie 
	res = malloc((sizeS+1) * sizeof(char));	

	// copie des caractères de s vers res
	for (i=0;i<=sizeS;i++) {
		res[i] = s[i];
	}	
		
	// codage 
	for (p = res; *p != '\0'; p++)
		if ( (*p>= 'a') && (*p<='z') )
			*p = (((*p - 'a') - 3 + 26) % 26 ) + 'A';
		else if ( (*p>= 'A') && (*p<='Z') )
			*p = (((*p - 'A') - 3 + 26) % 26 ) + 'a';
	return res;
}

char * cesar (const char * s, int n){
	// retourne le résultat du chiffrement d'une chaine 
	// correspondant au décalage passé en paramètre 
	char * res = strdup (s);
	char * p;
	while (n < 0) n += ALPHABSZ ;
	for (p = res; *p != '\0'; p++)
		if ( islower (*p))
			*p = (((*p - 'a') + n) % ALPHABSZ ) + 'a';
		else if ( isupper (*p))
			*p = (((*p - 'A') + n) % ALPHABSZ ) + 'A';
	return res;
}

void test_aveCesar (void) {
	PRINT_FN(); NL();
	printf ("%s\n", aveCesar ("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
	printf ("%s\n", aveCesar ("TU QUOQUE MI FILI"));
	printf ("%s\n", aveCesar ("VENI VIDI VICI"));
	printf ("%s\n", aveCesar ("XIBX GXZQX BPQ"));
	printf ("%s\n", aveCesar ("PF SFP MXZBJ MXOX YBIIRJ"));
	printf ("\n");
}

/*
DEFGHIJKLMNOPQRSTUVWXYZABC
WX TXRTXH PL ILOL
YHQL YLGL YLFL
ALEA JACTA EST
SI VIS PACEM PARA BELLUM
*/

void test_dyhCesar (void) {
	PRINT_FN(); NL();
	printf ("%s\n", dyhCesar ("DEFGHIJKLMNOPQRSTUVWXYZABC"));
	printf ("%s\n", dyhCesar ("VDWRU \nDUHSR \nWHQHW \nRSHUD \nURWDV"));
	printf ("%s\n", dyhCesar ("GHPR GHV PDXA GHV PRWV"));
	printf ("%s\n", dyhCesar ("YDH YLFWLV"));
	printf ("\n");
}
/*ABCDEFGHIJKLMNOPQRSTUVWXYZ
SATOR 
AREPO 
TENET 
OPERA 
ROTAS
DEMO DES MAUX DES MOTS
VAE VICTIS
*/


void test_cesar(void) {
	PRINT_FN(); NL();
	printf ("%s\n", cesar ("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 3));
	printf ("%s\n", cesar ("TU QUOQUE MI FILI", 3));
	printf ("%s\n", cesar ("VENI VIDI VICI", 3));
	printf ("%s\n", cesar ("XIBX GXZQX BPQ", 3));
	printf ("%s\n", cesar ("PF SFP MXZBJ MXOX YBIIRJ", 3));
	printf ("\n");
	printf ("%s\n", cesar ("DEFGHIJKLMNOPQRSTUVWXYZABC", -3));
	printf ("%s\n", cesar ("VDWRU \nDUHSR \nWHQHW \nRSHUD \nURWDV", -3));
	printf ("%s\n", cesar ("GHPR GHV PDXA GHV PRWV", -3));
	printf ("%s\n", cesar ("YDH YLFWLV", -3));
	printf ("\n");
}

/*
DEFGHIJKLMNOPQRSTUVWXYZABC
WX TXRTXH PL ILOL
YHQL YLGL YLFL
ALEA JACTA EST
SI VIS PACEM PARA BELLUM

ABCDEFGHIJKLMNOPQRSTUVWXYZ
SATOR 
AREPO 
TENET 
OPERA 
ROTAS
DEMO DES MAUX DES MOTS
VAE VICTIS
*/


void test_rot13(void) {
	char * indication = "P'rfg fba svyf"; 
	char * decoded; 

	PRINT_FN(); NL();

	printf("Un homme vous montre un portrait et dit : « Je n’ai pas de frère ni de sœur, mais le père de cet homme est le fils de mon père. » Qui est représenté par le portrait ?\n");
	decoded = rot13(indication); 
	printf("La réponse est : %s\n",decoded);
	printf("rot13(rot13(%s)) = %s\n",indication, rot13(rot13(indication)));
	printf ("\n");
}
/*
Un homme vous montre un portrait et dit : « Je n’ai pas de frère ni de sœur, mais le père de cet homme est le fils de mon père. » Qui est représenté par le portrait ?
La réponse est : C'est son fils
rot13(rot13(P'rfg fba svyf)) = P'rfg fba svyf

*/

/*
Le script produit : 

1)	TW QLFE ACPYOCP L NPDLC EZFE NP BFT YP WFT LAALCETPYE ALD. - Alfw PWFLCO PE Lyocp MCPEZY -
2)	UX RMGF BDQZPDQ M OQEMD FAGF OQ CGU ZQ XGU MBBMDFUQZF BME. - Bmgx QXGMDP QF Mzpdq NDQFAZ -
3)	VY SNHG CERAQER N PRFNE GBHG PR DHV AR YHV NCCNEGVRAG CNF. - Cnhy RYHNEQ RG Naqer OERGBA -
4)	WZ TOIH DFSBRFS O QSGOF HCIH QS EIW BS ZIW ODDOFHWSBH DOG. - Doiz SZIOFR SH Obrfs PFSHCB -
5)	XA UPJI EGTCSGT P RTHPG IDJI RT FJX CT AJX PEEPGIXTCI EPH. - Epja TAJPGS TI Pcsgt QGTIDC -
6)	YB VQKJ FHUDTHU Q SUIQH JEKJ SU GKY DU BKY QFFQHJYUDJ FQI. - Fqkb UBKQHT UJ Qdthu RHUJED -
7)	ZC WRLK GIVEUIV R TVJRI KFLK TV HLZ EV CLZ RGGRIKZVEK GRJ. - Grlc VCLRIU VK Reuiv SIVKFE -
8)	AD XSML HJWFVJW S UWKSJ LGML UW IMA FW DMA SHHSJLAWFL HSK. - Hsmd WDMSJV WL Sfvjw TJWLGF -
9)	BE YTNM IKXGWKX T VXLTK MHNM VX JNB GX ENB TIITKMBXGM ITL. - Itne XENTKW XM Tgwkx UKXMHG -
10)	CF ZUON JLYHXLY U WYMUL NION WY KOC HY FOC UJJULNCYHN JUM. - Juof YFOULX YN Uhxly VLYNIH -
11)	DG AVPO KMZIYMZ V XZNVM OJPO XZ LPD IZ GPD VKKVMODZIO KVN. - Kvpg ZGPVMY ZO Viymz WMZOJI -
12)	EH BWQP LNAJZNA W YAOWN PKQP YA MQE JA HQE WLLWNPEAJP LWO. - Lwqh AHQWNZ AP Wjzna XNAPKJ -
13)	FI CXRQ MOBKAOB X ZBPXO QLRQ ZB NRF KB IRF XMMXOQFBKQ MXP. - Mxri BIRXOA BQ Xkaob YOBQLK -
14)	GJ DYSR NPCLBPC Y ACQYP RMSR AC OSG LC JSG YNNYPRGCLR NYQ. - Nysj CJSYPB CR Ylbpc ZPCRML -
15)	HK EZTS OQDMCQD Z BDRZQ SNTS BD PTH MD KTH ZOOZQSHDMS OZR. - Oztk DKTZQC DS Zmcqd AQDSNM -
16)	IL FAUT PRENDRE A CESAR TOUT CE QUI NE LUI APPARTIENT PAS. - Paul ELUARD ET Andre BRETON -
17)	JM GBVU QSFOESF B DFTBS UPVU DF RVJ OF MVJ BQQBSUJFOU QBT. - Qbvm FMVBSE FU Boesf CSFUPO -
18)	KN HCWV RTGPFTG C EGUCT VQWV EG SWK PG NWK CRRCTVKGPV RCU. - Rcwn GNWCTF GV Cpftg DTGVQP -
19)	LO IDXW SUHQGUH D FHVDU WRXW FH TXL QH OXL DSSDUWLHQW SDV. - Sdxo HOXDUG HW Dqguh EUHWRQ -
20)	MP JEYX TVIRHVI E GIWEV XSYX GI UYM RI PYM ETTEVXMIRX TEW. - Teyp IPYEVH IX Erhvi FVIXSR -
21)	NQ KFZY UWJSIWJ F HJXFW YTZY HJ VZN SJ QZN FUUFWYNJSY UFX. - Ufzq JQZFWI JY Fsiwj GWJYTS -
22)	OR LGAZ VXKTJXK G IKYGX ZUAZ IK WAO TK RAO GVVGXZOKTZ VGY. - Vgar KRAGXJ KZ Gtjxk HXKZUT -
23)	PS MHBA WYLUKYL H JLZHY AVBA JL XBP UL SBP HWWHYAPLUA WHZ. - Whbs LSBHYK LA Hukyl IYLAVU -
24)	QT NICB XZMVLZM I KMAIZ BWCB KM YCQ VM TCQ IXXIZBQMVB XIA. - Xict MTCIZL MB Ivlzm JZMBWV -
25)	RU OJDC YANWMAN J LNBJA CXDC LN ZDR WN UDR JYYJACRNWC YJB. - Yjdu NUDJAM NC Jwman KANCXW -

*/
