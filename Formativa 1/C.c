#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void remove_depois(celula *p) {  
  if (p == NULL || p->prox == NULL)
    return;
  celula *temporaria = p->prox;
  p->prox = temporaria->prox;
  free(temporaria);
}

void  remove_elemento (celula *le, int x){
  celula *anterior = le;
  celula *atual = le->prox;

  //procurando pelo valor de x (ou pelo fim da lista)
  while (atual != NULL && atual->dado != x){
    anterior = atual;
    atual = atual->prox;
  }

  //caso em que encontrou o valor de x
  if (atual != NULL){
    anterior->prox = atual->prox;
    free(atual);
  }
}

void remove_todos_elementos (celula *le, int x){
  celula *anterior = le;
  celula *atual = le->prox;
  
  while (atual != NULL){
    if (atual->dado == x){
      //caso encontre uma ocorrencia de x, desaloca o no
      anterior->prox = atual->prox;
      celula *temporaria;
      atual = atual->prox;
      free(temporaria);
    } else {
      //caso não tenha encontrado continua procurando
      anterior = atual;
      atual = atual->prox;
    }
  }
}