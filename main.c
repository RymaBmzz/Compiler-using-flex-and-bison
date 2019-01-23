#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include "time.h"
#include <string.h>
#include <ctype.h>
#include "Fonction.h"



int main()
{ char i;

system("color F5");

printf("            *******************************************************\n");
            Sleep(150);
 printf("                                                                         \n");
 printf("                                 WELCOME                                    \n");

            Sleep(150);
 printf("            *******************************************************\n\n\n\n");
 Sleep(200);
    printf("\t+---------------------------------------------------------------------+\n");
            Sleep(150);
    printf("\t|               EVALUATION D'EXPRESSION ARITHMETIQUE                  |\n");
            Sleep(200);
    printf("\t|            EN UTILISANT LES PILES ET LES ARBRES BINAIRES            |\n");
            Sleep(200);
    printf("\t|            REALISE PAR: AMIRAT Anfel && BOUMAZOUZA Ryma             |\n");
            Sleep(200);

    printf("\t+---------------------------------------------------------------------+\n\n\n\n");



int n;Pile *P,*R;
char S[30];element *T;
printf("Cliquez sur une touche pour Continuer\n");
scanf(" %c",&i);
system("cls");
do
{
do
{

printf("Veuillez introduire l'expression arithmetique a evaluer:\n\n");
scanf("%s",S);
T=convertTabAscii(S,&n);
}while(verification(S)==0);
printf("Affichage du vecture genere \n\n");
affichage_vect(T,n);
printf("\n");

P=const_pile(T,n);
R=const_pile(T,n);
printf("Affichage de la forme Postfixee de l'expression \n\n");
affichage_post(&P);
printf("\n");

printf("Etat de la Pile avant l'evaluation\n\n");
affichage_pile(&P);
//affichage_pile(&P);
printf("\n\n");
P=evaluation_Pile(P);
printf("\n\n");
printf("Le resultat de l'evaluation \n\n");
affichage_pile(&P);
printf("\n\n");
printf("Affichage de l'arbre contenant l'expression arithmetique\n\n");
R=invers_pile(R);
noeud *racine=NULL;
racine=const_arbre(&R);
aff_arbre(racine);
printf("\n\n");
racine=eval_arbre(racine);
printf("Le Resultat apres l'evaluation\n");
aff_arbre(racine);
printf("\n\n");
printf("Voulez-vous evaluer une autre expression? (Répondez: O pour oui N pour Non)");
scanf(" %c",&i);
system("cls");
}while(toupper(i)=='O');
printf("Merci pour votre attention !!\n\n");
}
