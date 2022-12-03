#include "explor.h"


//Chercher la solution le plus proche
char* explor(int n1, int n2 , int n3, int n4, int n5, int n6, int num_goal){
	int rest[10] = {n1, n2, n3, n4, n5, n6, PLUS, MOIN, MULT, DIVI};
	int resolu[11] = {0,0,0,0,0,0,0,0,0,0,0};
	T_elt t = {0,ENTIER};
	char best[30];
	char * explor;
	if((n1==num_goal)||(n2==num_goal)||(n3==num_goal)||(n4==num_goal)||(n5==num_goal)||(n6==num_goal)){
		memset(best, 0, sizeof(best));
		sprintf(best,"%d ",num_goal);
		explor = best;
		printf("%s\n",explor);
		return explor;	
	}
	develop(rest, num_goal, resolu, t, ECART, best);
	explor = best;
	return explor;	
}


//La fonction develop() est pour 
int develop(int * rest, int num_goal, int * resolu, T_elt t, int min_ecart, char * best){
	char * s;
	if(t.status != ENTIER) return 0; //Eviter des expressions inutiles
	if(min_ecart == 0) return 1; //Si la meilleure solution est trouvee, return 1
	if( (*(resolu+10)) != FIN){ 
		s = tab2s(resolu);
			if(strlen(s) != 0){
				t = rpn_eval(s);
			}
		T_elt reponse = rpn_eval(s);
		free(s);
		if( abs(reponse.value - num_goal) < min_ecart){
			s = tab2s(resolu);
			if(strlen(s) != 0){
				t = rpn_eval(s);
			}
			strcpy(best,s);
			free(s);
			min_ecart = reponse.value;
			if(min_ecart == 0) return 1;
		}
		return 0;
	}
	
	s = tab2s(resolu);
	
	if(strlen(s) != 0){
		T_elt reponse = rpn_eval(s);
		free(s);
		if( abs(reponse.value - num_goal) < min_ecart){
			s = tab2s(resolu);
			if(strlen(s) != 0){
				t = rpn_eval(s);
			}
			strcpy(best, s);
			free(s);			
			min_ecart = reponse.value - num_goal;
		}
		if( abs(reponse.value - num_goal) == 0){
			s = tab2s(resolu);
			if(strlen(s) != 0){
				t = rpn_eval(s);
			}
			strcpy(best, s);
			free(s);			
			min_ecart = 0;
			return 1;
		}
	}
	
	int i,j;
	int num_next;
	*(rest+6) = PLUS;
	*(rest+7) = MOIN;
	*(rest+8) = MULT;
	*(rest+9) = DIVI;
	for(i=0;i<10;i++){
		if( (*(rest+i)) != 0){
			num_next = *(rest+i);
			*(rest+i) = 0;
			j=0;
			while((resolu[j]!=0)&&(j<10)) j++;
			resolu[j] = num_next;
			s = tab2s(resolu);
			t = rpn_eval(s);
			free(s);
			int eval = develop(rest, num_goal, resolu, t, min_ecart, best);
			if(eval == 1) return 1; //Si la meilleure solution est trouvee, return 1 et la programme sera arretee.
			*(rest+i) = num_next; 
			resolu[j]=0;
		}
	}
	return 0;
}

//Transformer un tableau, par exemple resolu[], en une expression RPN sous forme de chaîne de caractères
char * tab2s(int * tab){
	int i;
	char * s;
	s = malloc(30*sizeof(char));
	memset(s, 0, 30);
	char int2s[5];
	for(i=0;i<11;i++){
		if(tab[i]!=0){
			if(tab[i]>0){
				memset(int2s, 0, sizeof(int2s));
				sprintf(int2s,"%d ",tab[i]);
				strcat(s,int2s);
			}else{
				switch(tab[i]){
					case PLUS :
						strcat(s,"+ ");
						break;
					case MOIN :
						strcat(s,"- ");
						break;
					case MULT :
						strcat(s,"* ");
						break;
					case DIVI :
						strcat(s,"/ ");
						break;
				}
			}
		}
	}
	return s;
}







