quad.h : quadruplets marche 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct elementt{
char* op;
char* op1;
char* op2;
char* res;
struct elementt* succ;
}elemqd;

typedef struct elementq{
elemqd* tete;
elemqd* queue;
}liste_qd;

//header 
liste_qd* insere_qd(char* op,char* op1,char* op2 , char* r,liste_qd* p);
void affiche_listeqd(liste_qd* p);

//fonctions
liste_qd* insere_qd(char* op,char* op1,char* op2 , char* r,liste_qd* p)
{
elemqd* x;
x=(elemqd*) malloc(sizeof(elemqd));
if(x != NULL) 
{
x->op=op;
x->op1=op1;
x->op2=op2;
x->res=r;
x->succ=NULL;
}
if(p== NULL)
{p=(liste_qd*) malloc(sizeof(liste_qd));
p->tete=x;
p->queue=x;
}// p != null
else {(p->queue)->succ=x;
p->queue=x; }
op1=NULL; op2=NULL;
return p;
}



void affiche_listeqd(liste_qd* p)
{
//printf("Dans affiche liste \n");
elemqd* step;

printf("\t OP \t OPN1 \t OP2 \t RES\n");
step=p->tete;
while(step != NULL)
{
printf("\t %s \t %s \t %s \t %s\n",step->op,step->op1,step->op2,step->res);
step=step->succ;
//printf("dans boucle affich \n");
}
//if(step == NULL) printf("step est nulle \n");
printf("Fin d'affichage \n");
}