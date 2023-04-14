#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
int dado;
struct celula *prox;
} celula;

celula *busca (celula *le, int x) {
  celula *atual = le->prox;

  while (atual != NULL){
    if(atual->dado == x)
      return atual;
    atual = atual->prox;
  }

  //caso nao encontre nenhuma ocorrencia de x, retorna null
  return NULL;
}

celula *busca_rec (celula *le, int x){
  if (le == NULL){
    //lista vazia
    return NULL;
  }

  if(le->dado == x)
    return le;

  //chama a função novamente para o proximo no
  return busca_rec(le->prox, x);
}

