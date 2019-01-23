#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include "Fonction.h"


/**les primitives****/
//---------//
// La pile //
//---------//
void InitPile( Pile **Sommet)// initialisatin de la pile
{
   (*Sommet=NULL);
}
//---------------------------------------------------------------------------------------------------------
int PileVide(Pile *Sommet)// verification si la pile vide(retourne 1) sinon(retourne0)
{

    if(Sommet==NULL)
        return 1;
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------
void Empiler (Pile **Sommet,element x)// empiler un nouveau element dans la pile
{
    Pile *p;
    p=(Pile *)malloc(sizeof(Pile));
    p->info=x;
    p->svt=*Sommet;
    *Sommet=p;
}
//---------------------------------------------------------------------------------------------------------

void Depiler(Pile **Sommet,element *x)// depiler un element depuis la pile
{
    Pile *temp;
    temp=*Sommet;
    *x = (*Sommet)->info;
    *Sommet= (*Sommet)->svt;
    free(temp);
}
//---------------------------------------------------------------------------------------------------------
element SommetPile(Pile *Sommet)// retourner la formation contenant de le sommet de la pile
{
    return(Sommet->info);
}
//---------------------------------------------------------------------------------------------------------
//---------//
// La file //
//---------//
void InitFile( file **tete,file **queue)//initialisation de la file
{
   (*tete=NULL);
   (*queue=NULL);
}
//--------------------------------------------------------------------------
int fileVide(file *tete)// verifier si la file vide ou non
{

    if(tete==NULL)
        return 1;
    else
        return 0;
}
//--------------------------------------------------------------------------
void Enfiler (file **tete,file **queue,element *x)
{
    file *p;
    p=(file *)malloc(sizeof(file));
    p->info=x;
    p->svt=NULL;
    if(*tete==NULL)
    {
       *tete=p;
       *queue=p;
    }
    else
    {
        (*queue)->svt=p;
        *queue=p;
    }


}
//---------------------------------------------------------------------------------------------------------
void Defiler(file **tete,file **queue,element **x)
{
    file *temp;
    temp=*tete;
    *x =(*tete)->info;
    *tete= (*tete)->svt;

        if (*tete==NULL)
        {
            *queue=NULL;
        }
    free(temp);
}
//----------------------------------------------------------------------------------------------------------
//---------//
// L'arbre //
//---------//
element info(noeud *p)// retourner l'information d'un noeud p
{
    return p->info;
}
//----------------------------------------------------------------------------------------------------------
noeud *FG(noeud *p)// retourner le fils gauche d'un noeud p
{
    return p->filsg;
}
//-----------------------------------------------------------------------------------------------------------
noeud *FD(noeud *p)// retourner le fils droit d'un noeud p
{
    return p->filsd;
}
//-----------------------------------------------------------------------------------------------------------
void aff_info(noeud *p,element x)// affecter une information x à un noeud p
{
    p->info=x;
}
//-----------------------------------------------------------------------------------------------------------
void aff_FG(noeud *p,noeud *q)// affecter le noeud q comme un fils gauche de p
{
    p->filsg=q;
}
//------------------------------------------------------------------------------------------------------------
void aff_FD(noeud *p,noeud *q)// affecter le noeud q comme un fils droit de p
{
    p->filsd=q;
}
//-------------------------------------------------------------------------------------------------------------
noeud *cree_noeud(element x)// la creation d'un noeud avec l'information x
{
    noeud *p;
    p=malloc(sizeof(noeud));
    aff_info(p,x);
   aff_FD(p,NULL);
    aff_FG(p,NULL);
}
//--------------------------------------------------------------------------------------------------------------
int feuille(noeud *p)//1 si c une feuille 0 sinon
{
    if((p->filsd==NULL)&&(p->filsg==NULL))
    {
        return 1;
    }
    else
        return 0;
}
//---------------------------------------------------------------------------------------------------------------
 noeud *liberer_noued(noeud *p)// supprimer noeud
{
    free(p);
return NULL;

}
//--------------------------------------------------------------------------------------------------------------
/*********************Partie 1:Evaluation de la Pile**********/
/*Etape1:Analyse lexicale et syntaxique*/
int parenthese(char p[31])//parenthese valide
{
    int i=0,s=0;
    while((s>=0)&&(i<strlen(p)))
    {
        if(p[i]=='('){s=s+1;}
        if(p[i]==')'){s=s-1;}
            i=i+1;
    }
    if(s==0) {return 1;}
    else return 0;
}
//-------------------------------------------------------------------------------------------------------------
int caractere_admis(char c)// verifier ce un caractere c est un caractere admis ou non
{
    if (((c>='0')&&(c<='9'))||(c=='.')||
    (c=='+')||(c=='-')||(c=='*')||(c=='%')||(c=='/')||(c=='e')||(c=='E')||(c=='(')||(c==')'))
    {
        return 1;
    }
    else return 0;
}
//------------------------------------------------------------------------------------------------------------
int Ana_syntaxe(char M[31])//1 si l'expression arithmetique syntaxiquement correct 0 sinon
{
int i=1;

if(M[0]=='%'||M[0]=='/'||M[0]=='*'||toupper(M[0]=='E'))//si le 1 caractère est un operateur
{
    return 0;
}
while(i<(strlen(M)-1))
{

 if ((M[i]=='+'||M[i]=='-')&&(M[i+1]=='/'||M[i+1]=='%'||M[i+1]=='*'||toupper(M[i+1])=='E'))//si on a un a un operateur (+ou -) suivi par un(%, *, /,ou bien E)
 {
     return 0;
 }
if(((M[i])=='%'||M[i]=='/'||M[i]=='*'||M[i]=='('||toupper(M[i+1])=='E')&&((M[i+1])=='%'||M[i+1]=='/'||M[i+1]=='*')){return 0;}//si on a un operateur (*,%,/,E) ou bien parenthèse ouvrante
                                                                                                        // suivi par (*,%,/)
 i++;
if((M[i]=='%'||M[i]=='/'||M[i]=='*'||M[i]=='-'||M[i]=='+'||toupper(M[i])=='E')&&(M[i+1]==')')){return 0;}// si on trouve un operateur suivi par ')'
}
if(M[i]=='%'||M[i]=='/'||M[i]=='*'||M[i]=='-'||M[i]=='+'||toupper(M[i])=='E') return 0;// si le dernier caractère est un operateur
return 1;// l'expression est correcte syntaxiquement

}
//-------------------------------------------------------------------------------------------------------------------------------------
int Ana_lexical(char p[31])//1 si l'expression arithmetique lexicalement correct 0 sinon
{
    int i=0;
    while(i<strlen(p))
    {
    if (caractere_admis(p[i])==0){return 0;}
    i++;
    }
    return 1;
}
//-------------------------------------------------------------------------------------------------------------------------------------
int verification(char p[31])// la fonction qui verifie l'expression si elle est correcte syntaxiquement et lexicalement
{
    if(parenthese(p)==0||Ana_syntaxe(p)==0){printf("\Syntaxe error!!\n\n");return 0;}
    if(Ana_lexical(p)==0){printf("\Lexical error!!\n\n");return 0;}
    printf("La fonction correct syntaxiqueme est lexicalement\n\n");
    return 1;
}
//-------------------------------------------------------------------------------------------------------------------------------------
/*Etape2*/
//retourner la priorité
int priorite(float x) //lui envoyer vec[i].val
{
    if(x=='*' || x=='/'||toupper(x)=='E')
        return 2;
    if(x=='+' || x=='-')
        return 1;
}
//----------------------------------------------------------------------------------------------------------------
// retourne 1 si c'est un opérateur et 0 sinon
int operateur(element x) //on lui donne en entrée vec[i]
{
    if(x.type==0)
        return 1;
    else
        return 0;

}
//------------------------------------------------------------------------------------------------------------------
// retourne 1 si c'est un opérande et 0 sinon
int operande(element x) //on lui donne en entrée vec[i]
{
    if(x.type==1)
        return 1;
    else
        return 0;
}
//-------------------------------------------------------------------------------------------------------------------
float operation(float opr1,float opr2,float oprt)// effectuer l'operation oprt entre opr1 et opr2
{
    switch((int) oprt)
    {
        case ((int)'+'):
        return opr1+opr2;
        break;
        case ((int)'*'):
        return opr1*opr2;
        break;
        case ((int)'-'):
        return opr1-opr2;
        break;
        case ((int)'/'):
        return opr1/opr2;
        break;
        case((int)'%'):
        return (int)opr1%(int)opr2;// par ce que le % et toujours entre 2 entier
        case((int)'e'):
        return(opr1*(pow(10,opr2)));
        case((int)'E'):
        return(opr1*(pow(10,opr2)));
        default :
            printf("vous avez rentre une operation inexistante\n");
            break;
    }
}
//----------------------------------------------------------------------------------------------------------------------------------
//cette fonction genere le vecteur qui contient l'expression
element* convertTabAscii(char tab[31],int *n)
{
    element* vec;
    int i,j,taille,l;
    float nbr;
    char s[30];
    taille=strlen(tab)+1;
    vec=malloc(taille*sizeof(element));
    j=0;

   for (i=0;i<taille;i++)
   {
    if((tab[i]>='0'&&tab[i]<='9')||tab[i]=='.')
    { l=0;
     while((tab[i]>='0'&&tab[i]<='9')||tab[i]=='.')
     {// mettre dans la chaine s si c'est un opérateur pr la convertir aprés en réel
        s[l]=tab[i];
        i++;
        l++;
     }
     s[l]='\0';

     nbr=atof(s);//mettre le réel dans le vecteur résultat
     vec[j].val=nbr;
     vec[j].type=1;
     j++;
     i--;
    }
    else

    { if(tab[i]=='('||tab[i]==')')
      {vec[j].val= (int) tab[i];
      vec[j].type=2;
      j++;
    }
    else
    {
        vec[j].val= (int) tab[i];
      vec[j].type=0;
      j++;
    }
   }
}
   *n=j-1;

    return vec;
}
//--------------------------------------------------------------------------------------------------------------------
void affichage_vect(element *E,int n)// affiche le vecteur
{
    int i;
    printf("||");
    for(i=0;i<n;i++)
    {
        printf("%.2f||",E[i].val);
    }
}
//--------------------------------------------------------------------------------------------------------------------
/*partie3: la construction et l'evaluation de la pile*/
Pile *const_pile(element *T,int n)// cette fonction contsruit une pile à partir du vecteur generer
{
    int i;
    element x;
    Pile *P,*R;
    InitPile(&P);InitPile(&R);
    for(i=0;i<n;i++)
    {
        if(operande(T[i])==1)
        {
        Empiler(&R,T[i]);

        }
        else
        {
            if(operateur(T[i])==1)
            {
                while((PileVide(P)==0)&&(operateur((SommetPile(P)))==1)&&(priorite(T[i].val)<=priorite((SommetPile(P)).val)))
                {
                    Depiler(&P,&x);Empiler(&R,x);
                }
                Empiler(&P,T[i]);


            }
            else
            {
                if((T[i]).val=='(')
                {
                    Empiler(&P,T[i]);
                }
                else
                {
                    while(PileVide(P)==0&&SommetPile(P).val!='(')
                    {
                        Depiler(&P,&x);Empiler(&R,x);
                    }
                    Depiler(&P,&x);
                }
            }
        }
    }
    while(PileVide(R)==0)
    {
        Depiler(&R,&x); Empiler(&P,x);
    }
    return P;
}
//------------------------------------------------------------------------------------------------------------------------------------
void affichage_post(Pile **P)//affiche la forme postfixée de l'expression
{ Pile *R;
InitPile(&R);
  element x;
  while(PileVide(*P)==0)
  {
      Depiler(P,&x);Empiler(&R,x);
      if (x.type==0||x.type==2)
      {
          printf("%c ",(char)x.val);
      }
      else
      {
          printf("%.2f ",x.val);
      }
  }

  while(PileVide(R)==0)
  {
      Depiler(&R,&x);Empiler(P,x);
  }
}
//--------------------------------------------------------------------------------------------------------
void affichage_pile(Pile **P)//l'affichage de la pile
{ Pile *R;
InitPile(&R);
  element x;
  while(PileVide(*P)==0)
  {
      Depiler(P,&x);Empiler(&R,x);
      if (x.type==0||x.type==2)
      {
          printf("|| %c ||\n",(char)x.val);
      }
      else
      {
          printf("||%.2f||\n",x.val);
      }
  }
  while(PileVide(R)==0)
  {
      Depiler(&R,&x);Empiler(P,x);
  }
}
//-------------------------------------------------------------------------------------------------------------
Pile *evaluation_Pile(Pile *P)// fonction d'evaluation de la pile
{  element x,op1,op2;
Pile *R;InitPile(&R);float res;
    while(PileVide(P)==0)
    {
       Depiler(&P,&x);
       if(operande(x)==1){Empiler(&R,x);}
       else
       {
           Depiler(&R,&op2);Depiler(&R,&op1);
           res=operation(op1.val,op2.val,x.val);
           printf("Etat de la Pile apres chaque evaluation\n\n");
           affichage_pile(&P);
           printf("\n");
           x.val=res;
           x.type=1;
           Empiler(&P,x);
       }
    }
    return R;
}
//---------------------------------------------------------------------------------------------------------------
/*******************Partie 02:Evaluation en utilisant las arbres binaires*****/
Pile *invers_pile(Pile *P)//inverse une pile pour l'utiliser dans la construction d'arbe
{
Pile *R;element x;
InitPile(&R);
while(PileVide(P)==0)
{
    Depiler(&P,&x);
    Empiler(&R,x);
}
return R;
}
//-------------------------------------------------------------------------------------------------------------------
noeud *const_arbre(Pile **p)// la fonction qui construit un arbre a partir d'une pile p
{
 noeud *a;
 element x;
 if(PileVide(*p)==0)
{

  Depiler(p,&x);
  a=cree_noeud(x);
 if(operateur(x)==1)
 {
   aff_FD(a,const_arbre(p));
  aff_FG(a, const_arbre(p));
 }

}
return a;
}
//--------------------------------------------------------------------------------------------------------------------
int maxim(int x,int y)// retourner le maximum entre x et y
{
    if (x>y) return x;
    else return y;
}
//-------------------------------------------------------------------------------------------------------------------
int hauteur(noeud *racine)// retourne la hauteur d'un arbre racine
{

    if(racine==NULL)return 0;
    if(racine !=NULL&&feuille(racine)==1) return 1;
    return (1+maxim(hauteur(FG(racine)),hauteur(FD(racine))));
}
//--------------------------------------------------------------------------------------------------------------------
int file_NULL(file *tete,file *queue)// verifier si la file contient que des NULL ou non
{
  element *x;
if ((tete->info!=NULL)||(queue->info!=NULL)){return 0;}

 do
 {
    Defiler(&tete,&queue,&x);
 }while((tete!=queue)&&(x==NULL));
 if(tete==NULL){return 0;}
 else return 1;
}
//--------------------------------------------------------------------------------------------------------------------
void aff_arbre(noeud *racine)// l'affichage d'arbre en utilisant le parcours par niveau(utilisation de la file)
{  file *tete1;file *queue1; file *tete2;file *queue2;
element*x;int j,i;
InitFile(&tete2,&queue2);
InitFile(&tete1,&queue2);
j=pow(2,hauteur(racine));
printf("\n");
for(i=0;i<j-1;i++)
{
     printf("  ");
}
if(operateur(info(racine))==1)
{
printf("<  %c  >",(char)info(racine).val);
}
else
{
    printf("<%.2f>",info(racine).val);
}

printf("\n\n");


Enfiler(&tete2,&queue2,racine);

while(file_NULL(tete2,queue2)==0)
{
   while(fileVide(tete2)==0)
   {
       Defiler(&tete2,&queue2,&x);
       if(x!=NULL)
       {
       Enfiler(&tete1,&queue1,FG(x));
       Enfiler(&tete1,&queue1,FD(x));
       }
       else
       {
       Enfiler(&tete1,&queue1,NULL);
       Enfiler(&tete1,&queue1,NULL);
       }
   }
   j=j/2;
while(fileVide(tete1)==0)
{
Defiler(&tete1,&queue1,&x);
for(i=0;i<j-1;i++)
{
    printf("  ");
}
if(x!=NULL)
{
     if(operateur(info(x))==1)
      {
          printf("<  %c  >",(char)info(x).val);
      }
     else
     {
      printf("<%.2f>",info(x).val);
     }
}
else
{
    printf("     ");
}

for(i=0;i<(j-2);i++)
{
        printf(" ");
}



    Enfiler(&tete2,&queue2,x);

    }
    printf("\n\n");

}
}
//----------------------------------------------------------------------------------------------------------------------------
noeud *eval_arbre(noeud *racine)// la fonction qui va faire l'evalution d'un arbre
{
    if(feuille(racine)==1){return racine;}
    if((feuille(FG(racine))==1)&&(feuille(FD(racine))==1))
       {
        racine->info.val= operation(FG(racine)->info.val,FD(racine)->info.val,racine->info.val);
         racine->info.type=1;
         aff_FG(racine,liberer_noued(FG(racine)));

        aff_FD(racine,liberer_noued(FD(racine)));
         return racine;
       }
    racine->info.val=operation(info(eval_arbre(FG(racine))).val,info(eval_arbre(FD(racine))).val,info(racine).val);
    racine->info.type=1;
    aff_FG(racine,liberer_noued(FG(racine)));
    aff_FD(racine,liberer_noued(FD(racine)));
    return racine;
}
//---------------------------------------------------------------------------------------------------------------------------------
