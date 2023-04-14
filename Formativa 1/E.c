#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3) {
  celula *no1 = l1->prox, *no2 = l2->prox, *no3 = l3; 
  
  while (no1 != NULL && no2 != NULL) {
    // aloca em noMenor o no com o menor dado
    celula **noMenor = (no1->dado < no2->dado) ? &no1 : &no2;
    no3->prox = *noMenor;
    *noMenor = (*noMenor)->prox;
    no3 = no3->prox;
  }
  //se no1 nao for nulo, e alocado em no3->prox
  no3->prox = no1 ? no1 : no2;
     
}