#include "rpn.h" 
#include<stdio.h>

//typedef struct t_elt {
//		int value;//un champ value (entier) représentant un résultat ou un calcul intermédiaire
//		int status;//un champ status permettant de représenter la nature du T_elt
//	}T_elt;

//Transformer une expression RPN sous forme de chaîne de caractères en une liste de T_elt
T_stack s2list(char * exp){
	T_stack s = newStack();
	int i = 0;
	int j;
	char c;//temp char extraité d'expression
	T_elt t;
	int num[3] = {0,0,0};
	int i_num = 0;
	int exp_long = strlen(exp);
	for(i=exp_long;i>0;i--){
		switch(c=*(exp+i-1)){
			case '+' :
				t.value = PLUS;
				t.status = 2;
				push(t,&s);
				break;
			case '-' :
				t.value = MOIN;
				t.status = 2;
				push(t,&s);
				break;
			case '*' :
				t.value = MULT;
				t.status = 2;
				push(t,&s);
				break;
			case '/' :
				t.value = DIVI;
				t.status = 2;
				push(t,&s);
				break;
			case ' ' :
				//si T_elt est un operateur, break
				if(i_num == 0) break;
				//si T_elt est un char représentante entier, on peut le transformer à un int 
				t.value = num[0] + num[1] * 10 + num[2] * 100;
				for(j=0;j<3-i_num;j++) t.value = t.value / 10;
				t.status = 0;
				push(t,&s);
				for(j=0;j<3;j++) num[j] = 0;
				i_num = 0;
				break;
			default :
				num[2-i_num] = c - '0';
				i_num++;
		}	
	}
	return s;
}


//Evalue une expression RPN
T_elt rpn_eval(char * exp){
	T_stack s = newStack();
	int i = 0;
	int j;
	char c;
	T_elt t1;
	T_elt t2;
	T_elt t = {0,INVALIDE};
	int num_ope = 0;//la nombre des operandes dans la liste
	int exp_long = strlen(exp);
	int num[3] = {0,0,0};
	int i_num = 0;
	for(i=0;i<exp_long;i++){
		switch(c=*(exp+i)){
			case '+' :
				if((num_ope == 1)||(num_ope == 0)) return t;
				t1 = pop(&s);
				t2 = pop(&s);
				t1.value = t1.value + t2.value;
				push(t1,&s);
				num_ope--;
				break;
			case '-' :
				if((num_ope == 1)||(num_ope == 0)) return t;
				t1 = pop(&s);
				t2 = pop(&s);
				t1.value = t2.value - t1.value;
				push(t1,&s);
				num_ope--;
				break;
			case '*' :
				if((num_ope == 1)||(num_ope == 0)) return t;
				t1 = pop(&s);
				t2 = pop(&s);
				t1.value = t1.value * t2.value;
				push(t1,&s);
				num_ope--;
				break;
			case '/' :
				if((num_ope == 1)||(num_ope == 0)) return t;
				t1 = pop(&s);
				t2 = pop(&s);
				if(t1.value == 0){
					t.status = INVALIDE;
					return t;
				}
				if((t2.value % t1.value) != 0 ){
					t.status = NON_ENTIER;
					return t;
				}
				t1.value = t2.value / t1.value;
				push(t1,&s);
				num_ope--;
				break;
			case ' ' :
				if(i_num == 0) break;
				t1.value = num[0] + num[1] * 10 + num[2] * 100;
				for(j=0;j<3-i_num;j++) t1.value = t1.value / 10;
				t1.status = 0;
				push(t1,&s);
				num_ope++;
				for(j=0;j<3;j++) num[j] = 0;
				i_num = 0;
				break;
			default :
				num[2-i_num] = c - '0';
				i_num++;
		}
	}	
	return pop(&s);
	
}


//L’affichage sous la forme demandée par le programme
void show_rpn(char * exp){
	T_stack s = newStack();
	int i = 0;
	int j;
	char c;
	T_elt t1;
	T_elt t2;
	int exp_long = strlen(exp);
	int num[3] = {0,0,0};
	int i_num = 0;
	for(i=0;i<exp_long;i++){
		switch(c=*(exp+i)){
			case '+' :
				t1 = pop(&s);
				t2 = pop(&s);
				printf("%d + %d = %d\n", t2.value, t1.value, t1.value + t2.value);
				t1.value = t1.value + t2.value;
				push(t1,&s);
				break;
			case '-' :
				t1 = pop(&s);
				t2 = pop(&s);
				printf("%d - %d = %d\n", t2.value, t1.value, t2.value - t1.value);
				t1.value = t2.value - t1.value;
				push(t1,&s);
				break;
			case '*' :
				t1 = pop(&s);
				t2 = pop(&s);
				printf("%d * %d = %d\n", t2.value, t1.value, t2.value * t1.value);
				t1.value = t1.value * t2.value;
				push(t1,&s);
				break;
			case '/' :
				t1 = pop(&s);
				t2 = pop(&s);
				printf("%d / %d = %d\n", t2.value, t1.value, t2.value / t1.value);
				t1.value = t2.value / t1.value;
				push(t1,&s);
				break;
			case ' ' :
				if(i_num == 0) break;
				t1.value = num[0] + num[1] * 10 + num[2] * 100;
				for(j=0;j<3-i_num;j++) t1.value = t1.value / 10;
				t1.status = 0;
				push(t1,&s);
				for(j=0;j<3;j++) num[j] = 0;
				i_num = 0;
				break;
			default :
				num[2-i_num] = c - '0';
				i_num++;
		}
	}		
}
