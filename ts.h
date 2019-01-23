ts.h:
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct ele{
char* nom;
int taille;
int nature;//var =0,cnst=1
int type;//int=0,float=1,str=2
struct ele* succ;
}elem;

typedef struct element{
elem* tete;
elem* queue;
}liste_ele;

//header 
int Vectindi(liste_ele* liste, char *idf, int i);
float calcul_res(float opr1,float opr2,int op);
int compareChaine(liste_ele* p,char* s,int typval);
int isItTab(char*s, liste_ele* p);
int getype(char*s, liste_ele* p);
int verifsign(char* sign,char* idf,liste_ele* p);
int biblioValid(int a,int b);
liste_ele* Creer_liste(char* s,int nat,int typ,int tai);
int liste_vide(liste_ele* p);
void affiche_liste(liste_ele* p);
int recherche(liste_ele* p,char*s);
liste_ele* insere(liste_ele* p,char* s,int nat,int typ,int tail);
int verifie_val_cnst(liste_ele* p,char* s);
int verifie_taille_tab(int tai);
int compare(int typval,int typidf);
int getnature(char*s, liste_ele* p);