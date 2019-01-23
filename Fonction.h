#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


/**Déclaration des structures**/
typedef struct element element;
typedef struct Pile Pile;
typedef struct file file;
typedef struct noeud noeud;
struct element
{
    float val;
    int type; // =1 si c'est une opérande ,0 si opérateur
};
struct Pile
{
    element info;
    struct pile *svt;
};
struct file
{
    element *info;
    file *svt;
};


struct noeud
{
    element info;
    noeud *filsg;
    noeud *filsd;
};
/**les primitives****/
//---------//
// La pile //
//---------//
void InitPile( Pile **Sommet);
int PileVide(Pile *Sommet);
void Empiler (Pile **Sommet,element x);
void Depiler(Pile **Sommet,element *x);
element SommetPile(Pile *Sommet);
//---------//
// La file //
//---------//
void InitFile( file **tete,file **queue);
int fileVide(file *tete);
void Enfiler (file **tete,file **queue,element *x);
void Defiler(file **tete,file **queue,element **x);
//---------//
// L'arbre //
//---------//
element info(noeud *p);
noeud *FG(noeud *p);
noeud *FD(noeud *p);
void aff_info(noeud *p,element x);
void aff_FG(noeud *p,noeud *q);
void aff_FD(noeud *p,noeud *q);
noeud *cree_noeud(element x);
int feuille(noeud *p);//1 si c une feuille 0 sinon
noeud  *liberer_noued(noeud *p);
/*********************Partie 1:Evaluation de la Pile**********/

/*Etape1:Analyse lexicale et syntaxique*/
int parenthese(char p[31]);//parentheses valides
int caractere_admis(char c);
int Ana_syntaxe(char M[31]);//1 si syntaxiquement correcte 0 sinon
int Ana_lexical(char p[31]);//1 si syntaxiquement correcte 0 sinon
int verification(char p[31]);// la fonction qui verifie l'expression si elle est correcte syntaxiquement et lexicalement
/*Etape2*/
int priorite(float x);
int operateur(element x);
int operande(element x);
float operation(float opr1,float opr2,float oprt);
element* convertTabAscii(char tab[31],int *n);//0 operateur 1 operande 2 parenthese
void affichage_vect(element *E,int n);
/*partie3: la construction et l'evaluation de la pile*/
Pile *const_pile(element *T,int n);
void affichage_pile(Pile **P);
void affichage_post(Pile **P);
Pile *evaluation_Pile(Pile *P);
/*******************Parite 2:Evaluation en utillusant las arbres binaires *****/
Pile *invers_pile(Pile *P);
noeud *const_arbre(Pile **p);
noeud *eval_arbre(noeud *racine);
int maxim(int x,int y);
int hauteur(noeud *racine);
int file_NULL(file *tete,file *queue);
void aff_arbre(noeud *racine);
