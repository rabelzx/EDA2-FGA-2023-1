#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  int dado;
  struct celula *prox;
} celula;

void insere_inicio(celula *le, int x) {
  celula *novoNo = (celula *)malloc(sizeof(celula));
  novoNo->dado = x;
  novoNo->prox = le->prox;
  //cabeca le aponta para o endereço da novoNo celula
  le->prox = novoNo;
}

void insere_antes(celula *le, int x, int y) {
  celula *anterior = le;
  celula *atual = le->prox;

  //procurando o elemento y (ou o final da lista)
  while(atual != NULL && atual->dado != y){
    anterior = atual;
    atual = atual->prox;
  }

  if(atual == NULL){
    celula *novoNo = (celula *)malloc(sizeof(celula));
    novoNo->dado = x;
    novoNo->prox = NULL;
    //o ultimo elemento percorrido aponta para a novoNo celula
    anterior->prox = novoNo;
  }else{
    celula *novoNo = (celula *)malloc(sizeof(celula));
    novoNo->dado = x;
    //faz com que o ponteiro de nó novoNo aponte para o nó de y
    novoNo->prox = atual;
    anterior->prox = novoNo;
  }
}