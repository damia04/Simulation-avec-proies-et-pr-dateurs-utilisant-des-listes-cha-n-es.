/*
  BOURENANE LINA 21306093
============================
  BOUCHENNA DAMIA

*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "ecosys.h"
#include <string.h>
float p_ch_dir=0.5;
float p_reproduce_proie=0.3;
float p_reproduce_predateur=0.3;
int temps_repousse_herbe=-105;

/* PARTIE 1*/
/* Fourni: Part 1, exercice 4, question 2 */
Animal *creer_animal(int x, int y, float energie) {
  Animal *na = (Animal *)malloc(sizeof(Animal));
  assert(na);
  na->x = x;
  na->y = y;
  na->energie = energie;
  na->dir[0] = rand() % 3 - 1;
  na->dir[1] = rand() % 3 - 1;
  na->suivant = NULL;
  return na;
}


/* Fourni: Part 1, exercice 4, question 3 */
Animal *ajouter_en_tete_animal(Animal *liste, Animal *animal) {
  assert(animal);
  assert(!animal->suivant);
  animal->suivant = liste;
  return animal;
}

/* A faire. Part 1, exercice 6, question 2 */
void ajouter_animal(int x, int y,  float energie, Animal **liste_animal) {
  assert(x >= 0 && x < SIZE_X);
  assert(y >= 0 && y < SIZE_Y);
 *liste_animal=ajouter_en_tete_animal(*liste_animal,creer_animal(x,y,energie));


}

/* A Faire. Part 1, exercice 5, question 5 */
void enlever_animal(Animal **liste, Animal *animal) {
  Animal *a=*liste;
  if(a==animal){
    *liste=(*liste)->suivant;
    free(a);
    
  }
  else{

  while(a){
    if (a->suivant==animal){
      Animal *tmp=a->suivant;
      a->suivant=a->suivant->suivant;
      free(tmp);
    
    } else
 {   a=a->suivant;}
  }


}
  }

/* A Faire. Part 1, exercice 6, question 7 */
Animal* liberer_liste_animaux(Animal *liste) {
   Animal *temp ;
   while(liste){
    temp=liste;
   liste=liste->suivant;
   free(temp);
   }
   
  return NULL;
}

/* Fourni: part 1, exercice 4, question 4 */
unsigned int compte_animal_rec(Animal *la) {
  if (!la) return 0;
  return 1 + compte_animal_rec(la->suivant);
}

/* Fourni: part 1, exercice 4, question 4 */
unsigned int compte_animal_it(Animal *la) {
  int cpt=0;
  while (la) {
    ++cpt;
    la=la->suivant;
  }
  return cpt;
}



/* Part 1. Exercice 5, question 1, ATTENTION, ce code est susceptible de contenir des erreurs... */
void afficher_ecosys(Animal *liste_proie, Animal *liste_predateur) {
  unsigned int i, j;
  char ecosys[SIZE_X][SIZE_Y];
  Animal *pa=NULL;

  /* on initialise le tableau */
  for (i = 0; i < SIZE_X; ++i) {
    for (j = 0; j < SIZE_Y; ++j) {
      ecosys[i][j]=' ';
    }
  }

  /* on ajoute les proies */
  pa = liste_proie;
  while (pa) {
    ecosys[pa->x][pa->y] = '*';
    pa=pa->suivant;
  }

  /* on ajoute les predateurs */
  pa = liste_predateur;
  while (pa) {
      if ((ecosys[pa->x][pa->y] == '@') || (ecosys[pa->x][pa->y] == '*')) { /* proies aussi present */
        ecosys[pa->x][pa->y] = '@';
      } else {
        ecosys[pa->x][pa->y] = 'O';
      }
    pa = pa->suivant;
  }

  /* on affiche le tableau */
  printf("+");
  for (j = 0; j < SIZE_Y; ++j) {
    printf("-");
  }  
  printf("+\n");
  for (i = 0; i < SIZE_X; ++i) {
    printf("|");
    for (j = 0; j < SIZE_Y; ++j) {
      putchar(ecosys[i][j]);
    }
    printf("|\n");
  }
  printf("+");
  for (j = 0; j<SIZE_Y; ++j) {
    printf("-");
  }
  printf("+\n");
  int nbproie=compte_animal_it(liste_proie);
  int nbpred=compte_animal_it(liste_predateur);
  
  printf("Nb proies : %5d\tNb predateurs : %5d\n", nbproie, nbpred);

}


void clear_screen() {
  printf("\x1b[2J\x1b[1;1H");  /* code ANSI X3.4 pour effacer l'ecran */
}

/* PARTIE 2*/

/* Part 2. Exercice 4, question 1 */
void bouger_animaux(Animal *la) {
  Animal *a=la;
  while(a){
    if (rand()/(float)RAND_MAX < p_ch_dir){
     
    
    a->x=(a->x+a->dir[0]+SIZE_X)%SIZE_X;
    a->y=(a->y+a->dir[1]+SIZE_Y)%SIZE_Y;
   }
    a=a->suivant;

  }

}

/* Part 2. Exercice 4, question 3 */
void reproduce(Animal **la, float p_reproduce) {
  Animal *a=*la;
  while(a){
    if  (rand()/(float)RAND_MAX < p_reproduce){
       a->energie=(a->energie)/2;
      ajouter_animal(a->x,a->y,a->energie,la);
     
    }
    a=a->suivant;
  }

}


/* Part 2. Exercice 6, question 1 */
void rafraichir_proies(Animal **liste_proie, int monde[SIZE_X][SIZE_Y]) {
  bouger_animaux(*liste_proie);

  Animal* a=*liste_proie;
 
  while(a){

    a->energie-=1;

    if (a->energie<0){
 
      enlever_animal(liste_proie,a);
   
    }
    else if
      
    (monde[a->x][a->y]>0){
      a->energie+=monde[a->x][a->y];
      monde[a->x][a->y]=temps_repousse_herbe;
    }
    a=  a->suivant;
  }
reproduce(liste_proie,p_reproduce_proie);
}
/* Part 2. Exercice 7, question 1 */
Animal *animal_en_XY(Animal *l, int x, int y) {
    Animal *tmp=l;
    while(tmp){
if (tmp->x==x && tmp->y==y){
  return tmp;
}
    tmp=tmp->suivant;
    }

  return NULL;
} 

/* Part 2. Exercice 7, question 2 */
void rafraichir_predateurs(Animal **liste_predateur, Animal **liste_proie) {
   /*A Completer*/

  bouger_animaux(*liste_predateur);
  Animal* a=*liste_predateur;
  while(a){

    a->energie--;
    if (a->energie<0){

      enlever_animal(liste_predateur,a);
    }
    else{
  
    Animal* proie=animal_en_XY(*liste_proie,a->x,a->y);
  
 
    if (proie!=NULL){
  

    a->energie+=proie->energie;
    
           
    enlever_animal(liste_proie,proie);
    
    }}
 
    a=  a->suivant;
  }
  reproduce(liste_predateur,p_reproduce_predateur);

}

/* Part 2. Exercice 5, question 2 */
void rafraichir_monde(int monde[SIZE_X][SIZE_Y]){
for (int i=0;i<SIZE_X;i++){
  for (int j=0;j<SIZE_Y;j++){
   monde[i][j]++;
  }
  
}


}
void ecrire_ecosys(const char *nom_fichier,Animal *liste_proie,Animal *liste_predateur){
   FILE *f=fopen(nom_fichier,"w");
   if (f==NULL)
{
  printf("erreur d'ouverture");
  exit(1);
} 
 fprintf(f,"<proies>\n");
  Animal *liste_p=liste_proie;
  Animal *liste_pd=liste_predateur;
  while(liste_p){
    fprintf(f,"x=%d y=%d dir[%d %d] e=%f\n",liste_p->x,liste_p->y,liste_p->dir[0],liste_p->dir[1],liste_p->energie);
    liste_p=liste_p->suivant;
  }
  fprintf(f,"</proies>\n");

  fprintf(f,"<predateurs>\n");
    while(liste_pd){
    fprintf(f,"x=%d y=%d dir[%d %d] e=%f \n",liste_pd->x,liste_pd->y,liste_pd->dir[0],liste_pd->dir[1],liste_pd->energie);
    liste_pd=liste_pd->suivant;
  }
  fprintf(f,"</predateurs>\n");
  fclose(f);
}
void lire_ecosys(const char *nom_fichier, Animal **liste_predateur, Animal **liste_proie){
  FILE *f = fopen(nom_fichier,"r");

  char buffer[230];
  int x,y;
  float energie;
  int dir[2];
  fgets(buffer,230,f);
    while (fgets(buffer, 230, f) && strcmp(buffer, "</proies>\n") != 0){
      sscanf(buffer,"x=%d y=%d dir[%d %d] e=%f ",&x,&y,dir,dir+1,&energie);
       ajouter_animal(x,y,energie, liste_proie);
       (*liste_proie)->dir[0]=*dir;
       (*liste_proie)->dir[1]=*(dir+1);

    }
    fgets(buffer,230,f);
    while (fgets(buffer, 230, f) && strcmp(buffer, "</predateurs>\n") != 0){
      sscanf(buffer,"x=%d y=%d dir[%d %d] e=%f ",&x,&y,dir,dir+1,&energie);
       ajouter_animal(x,y,energie, liste_predateur);
       (*liste_predateur)->dir[0]=*dir;
       (*liste_predateur)->dir[1]=*(dir+1);

    }
    fclose(f);

  }
 

