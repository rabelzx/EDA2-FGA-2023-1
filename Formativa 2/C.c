#include <stdio.h> 
#define SIZE 280001

void inicializarTabela(int t[]) {
  int i;

  for(i = 0; i < SIZE; i++) {
    t[i] = -1;
  }
}

//funcao hash (espalhamento)
int hash(int value) {
    return value % SIZE;
}

void inserir(int t[], int value) {
  int index = hash(value);
  while(t[index] != -1){
    if(t[index] == value)
      return;
    index = index + 1; 
  }
  t[index] = value;
}

int buscar(int t[], int value) {

  int index = hash(value);
  while(t[index] != -1) {
    if(t[index] == value)
      return 1; 
    else 
      index = index + 1;
  }
  return 0; 
} 

int main (){
  int tabela [SIZE]; 
  inicializarTabela(tabela); 

  int n, x;  
  scanf("%d", &n);
  
  for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        inserir(tabela, x);
    }

  while (scanf("%d", &x) == 1) {
    if (buscar(tabela, x)) 
        printf("sim\n");
    else 
        printf("nao\n");
  }
  
  return 0; 
}