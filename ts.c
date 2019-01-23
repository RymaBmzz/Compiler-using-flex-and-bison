ts.c : 
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


//fonctions
int biblioValid(int a,int b)
{
if(a==1) return 1;
else return -1;

}



elem* Creer_element(char* s,int nat,int typ,int tai)
{
elem* p;
p=(elem*)malloc(sizeof(elem));
if(p != NULL)
{
p->nom=s;
p->taille=tai;
p->nature=nat;
p->type=typ;
p->succ=NULL;
}
return p;
}

int liste_vide(liste_ele* p)
{ if(p->tete==NULL && p->queue==NULL)
  { printf("La liste est vide \n"); 
 return 1;}
  else {printf("La liste n'est pas vide \n");
   return -1;
}}

int verifsign(char* sign,char* idf,liste_ele* p){
char* s;
elem* m;
int typIdf;

if(p != NULL){
m=p->tete;
 printf("ici \n");
while(m->succ != NULL && strcmp(m->nom,idf) != 0 )
m=m->succ;

if(m->succ != NULL) typIdf= m->type;
             }

else {printf("Table des symboles vide \n");
return 0;}
 //printf("Type idf trouvé %d \n",typIdf);
if(typIdf == 0){ s="\"%d\"";
 printf("premier idf \n");
if( strcmp(sign,s) == 0 ) return 1;
else return -1 ;
}

if(typIdf == 1){ s="\"%f\"";
 printf("second idf \n");
if( strcmp(sign,s) ==0 ) return 1;
else return -1 ;
}

if(typIdf == 2){ s="\"%s\"";
 printf("third idf\n");
if( strcmp(sign,s) ==0 ) return 1;
else return -1 ;
}
 }


int verifiSignOut(char* s ,char* idf,liste_ele* p){
char* pos="deb";
int res;
int typid;
typid=getype(idf,p);
if( typid > -1 ) {
char* dd="%d";
char* ff="%f";
char* ss="%s";
pos = strstr(s,dd);
if(pos != NULL) 
if(pos != NULL)
{
if(typid == 0 ) { return 1;}
}

pos = strstr(s,ff);
if(pos != NULL)
{
if(typid == 1) return 1;
}

pos = strstr(s,ss);
if(pos != NULL)
{
if(typid == 2 ) return 1;
}
printf("Signe de formatage manquant \n");
return -1;
}
else printf("Type idf non valide %s \n", pos);
 return -1;
}


void affiche_liste(liste_ele* p)
{
//printf("Dans affiche liste \n");
elem* step;
printf("\n\t\t Nature: 0 variable, 1 constante \n \t\t Type  : 0 int ,1 float , 2 chaine \n \t\t Taille: 1 variable simple ,sinon [taille] \n\n\n");
printf("\t ** Table des symboles ****\n");
printf("\t Nom \t Nature \t Type \t Taille\n");
step=p->tete;
while(step != NULL)
{
printf("\t %s \t %d \t\t %d \t %d\n",step->nom,step->nature,step->type,step->taille);
step=step->succ;
//printf("dans boucle affich \n");
}
//if(step == NULL) printf("step est nulle \n");
printf("Fin d'affichage \n");
}



int recherche(liste_ele* p,char*s) //retourne 1 si existe et 0 sinn
{
elem* m;
if(p != NULL){
m=p->tete;
while(m->succ != NULL && strcmp(m->nom,s) != 0 )
m=m->succ;

if(m->succ != NULL)
         {
printf(" %s Existe deja \n",s);
return 1;}
else {    
if( strcmp(m->nom,s) == 0) {printf(" %s Existe deja \n",s);
return 1;
                           }
else{      
printf(" %s non trouvé \n",s); return 0;
    } //elem non trouvé
     }
}//fin if0
else {printf("Table des symboles vide\n");
return 0;}
}

int isItTab(char*s, liste_ele* p)
{
elem* m;
m=p->tete;
while(m->succ != NULL && strcmp(m->nom,s) != 0)
m=m->succ;
if(strcmp(m->nom,s)==0 ) {
 if((m->taille) >1) { 
return 1;}
else return -1 ;}
if(m->succ == NULL)
return -1;
}




int getnature(char*s, liste_ele* p)
{
printf("dans getnature\n");
elem* m;
int t=0;
m=p->tete;
while(m->succ != NULL && strcmp(m->nom,s) != 0)
m=m->succ;
if(m->succ == NULL)
return -1;
else { t=m->nature;
return t;}
}

int getype(char* s, liste_ele* p)
{
printf("dans getype\n");
elem* m;
int t=0;
m=p->tete;
while(m->succ != NULL && strcmp(m->nom,s) != 0)
m=m->succ;
if(strcmp(m->nom,s) ==0){
t=m->type;
return t;}
if(m->succ == NULL)
return -1;
}


int compareChaine(liste_ele* p,char* s,int typval)
{//modifier ici si je veux que type int go dans float
int typidf=getype(s,p);
printf("typ valeur est %d ,type idf est %d\n",typval, typidf);
if(typval != typidf) return -1; //type != 
else return 1; // type =
} 

int compare(int typval,int typidf)
{
printf("typ valeur est %d ,type idf est %d\n",typval, typidf);

if(typval != typidf) return -1; //type != 
else return 1;} // type =


liste_ele* insere(liste_ele* p,char* s,int nat,int typ,int tail)//utiliser en .y
{ elem* x;
if(recherche(p,s)==0)
{printf("Debut fonction insere\n");
x = Creer_element(s, nat, typ, tail);
//printf("Dans fonction insere\n");
if(p == NULL)//if1
{p=(liste_ele*) malloc(sizeof(liste_ele));
//printf(" Premier element à inserer dans tab\n");
if(p != NULL){//if2
p->tete=x;
p->queue=x;
//printf("premier element inséré c bon \n");
}//fin if2
}// fin if1
else{ //else du if1
//printf("element suivant à inserer dans tab\n");
(p->queue)->succ=x;
p->queue=x;
printf(" element suivant inséré c bon \n");
}//fin else du if1
} //fin if0 , existe deja
printf(" Insertion finie\n");
return p;
}

int verifie_val_cnst(liste_ele* p,char* s) 
{elem* m;
if(p != NULL){m=p->tete;
while(m->succ != NULL && strcmp(m->nom,s) != 1)
m=m->succ;
if(m->succ==NULL){ 
 printf("IDF non déclaré avant\n");
 return 0;       }
else {  
printf("Impossible de modifier la valeur d'une constante \n"); 
return -1;
     }
return 1;    }
else printf("Table vide \n");
return 0;
}

int verifie_taille_tab(int tai)
{//printf("Debut verifie taille \n");
if(tai<=0)  return -1;
else  return 1;
}

float calcul_res(float opr1,float opr2,int op) // 1 pr + 2 pr / ...
{
float res;
if(op == 1) 
res=opr1 + opr2;
if(op == 2) 
res=opr1 - opr2;
if(op == 3) 
res=opr1 * opr2;
if(op == 4) 
res=opr1 / opr2;
return res;
}


int Vectindi(liste_ele* liste, char *idf, int i){
elem* m; m=liste->tete;
while((strcmp(idf,m->nom)!=0))	m = m->succ;
if( i >= 0 && i < m->taille) return 1;
else return 0;
}