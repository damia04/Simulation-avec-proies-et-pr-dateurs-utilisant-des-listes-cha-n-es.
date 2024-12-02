#include <assert.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <strings.h>
#include "ecosys.h"
 


#define NB_PROIES 20
#define NB_PREDATEURS 20
#define T_WAIT 100





int main(void) {
 
Animal *a1=creer_animal(13,10,10.0);
printf("Test Bouger");
printf("Avant: %d, %d, %.2f, [%d,%d]\n",a1->x,a1->y,a1->energie,a1->dir[0],a1->dir[1]);


bouger_animaux(a1);
printf("Apres: %d, %d, %.2f, [%d,%d]\n",a1->x,a1->y,a1->energie,a1->dir[0],a1->dir[1]);
printf("\n");
// test      reproduce
ajouter_animal(12,5,12.0,&a1);
ajouter_animal(12,6,13.0,&a1);
afficher_ecosys(a1,NULL);
reproduce(&a1,p_reproduce_proie);
afficher_ecosys(a1,NULL);
Animal * damia=a1;
while(damia){
printf("Apres reproduction: %d, %d, %.2f, [%d,%d]\n",damia->x,damia->y,damia->energie,damia->dir[0],damia->dir[1]);
damia=damia->suivant;}

a1=liberer_liste_animaux(a1);
// exercccice 5 rexercice 2
int monde[SIZE_X][SIZE_Y]={0};



Animal *proie=creer_animal(rand()%SIZE_X,rand()%SIZE_Y,10.0);
Animal *predateur=creer_animal(rand()%SIZE_X,rand()%SIZE_Y,10.0);
for (int i=0; i<19; i++) {
  ajouter_animal(rand()%SIZE_X,rand()%SIZE_Y,10.0,&proie);
  ajouter_animal(rand()%SIZE_X,rand()%SIZE_Y,100.0,&predateur);
  
}

FILE *f=fopen("Evol_pop.txt", "w");
if (f == NULL){
  printf("erreur d'ouverture");
  exit(1);
}
fprintf(f, "generation prois predateurs\n");

int cpt=0;
while((proie || predateur) && (cpt<200)){
fprintf(f,"cpt=%d proie=%d predateur=%d \n", cpt, compte_animal_it(proie), compte_animal_it(predateur));
  usleep(T_WAIT);
  rafraichir_proies(&proie,monde);
  rafraichir_predateurs(&predateur,&proie);
  rafraichir_monde(monde);
  cpt++;
  
}
fclose(f);
proie=liberer_liste_animaux(proie);
predateur=liberer_liste_animaux(predateur);
  return 0;

}
