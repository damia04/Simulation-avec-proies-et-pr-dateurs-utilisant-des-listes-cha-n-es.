#include <assert.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "ecosys.h"
int main(){
  int i;

  int energie=10;

  Animal *liste_proie = creer_animal(rand()%SIZE_X,rand()%SIZE_Y,energie);
  Animal *liste_predateur =creer_animal(rand()%SIZE_X,rand()%SIZE_Y,energie);




      for (i=0;i<4;i++){
        ajouter_animal(rand()%SIZE_X,rand()%SIZE_Y,energie, &liste_proie);
        ajouter_animal(rand()%SIZE_X,rand()%SIZE_Y,energie, &liste_predateur);
       
  }
Animal *liste_proie_test=NULL;
Animal *liste_predateur_test=NULL;
  ecrire_ecosys("liste_ecosys.txt",liste_proie,liste_predateur);
lire_ecosys("liste_ecosys.txt",&liste_predateur_test,&liste_proie_test);
afficher_ecosys(liste_proie_test,liste_predateur_test);

 Animal *tempProie=liste_proie_test;
 Animal *tempPred=liste_predateur_test;
 printf("proies: \n");
 while(tempProie){
   printf("x:%d y:%d e:%f\n",tempProie->x,tempProie->y,tempProie->energie);
   tempProie=tempProie->suivant;
 }
 printf("predateurs: \n");
 while(tempPred){
   printf("x:%d y:%d e:%f\n",tempPred->x,tempPred->y,tempPred->energie);
   tempPred=tempPred->suivant;
 }
 liste_proie_test=liberer_liste_animaux(liste_proie_test);
 liste_predateur_test=liberer_liste_animaux(liste_predateur_test);
 liste_proie=liberer_liste_animaux(liste_proie);
 liste_predateur=liberer_liste_animaux(liste_predateur);
 return 0;
  
  

}