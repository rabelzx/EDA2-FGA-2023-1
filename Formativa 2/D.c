#include <stdio.h>
#include <string.h>

#define TAM 101

//----------------------------
typedef struct {
    char key[20];
    int deleted;
    int hash; 
} No;

typedef struct {
  int tamanho;
  No entradas[101];
} hashTable;

//-----------------------
int hashFunction(char *key) {
  long sum = 0;
  long i = 1;
  while (*key != '\0') {
    sum += (*key) * i;
    ++i;
    ++key;
  }
    return (sum * 19) % TAM;
}

//-------------------------------
int buscar(hashTable *h, char *string) {
  int hash = hashFunction(string);
  for (int i = 0; i < 20; ++i) {
    int index = (hash + 23 * i + i * i) % 101;
    if (h->entradas[index].deleted == 0)
      return 0;
    if (h->entradas[index].deleted == 1)
      continue;
    if (h->entradas[index].hash == hash && (strcmp(h->entradas[index].key, string) == 0)) {
      return 1;
    }
  }
  return 0;
}

//------------------------------------------
void inserir(hashTable *table, char *string) {
  int h = hashFunction(string);

  if (buscar(table, string) == 1)
    return;

  for (int i = 0; i < 20; ++i) {
    int index = (h + 23 * i + i * i) % TAM;
    if (table->entradas[index].deleted == 0 || table->entradas[index].deleted == 1) {
       (table->tamanho)++;
       table->entradas[index].deleted = 2;
       table->entradas[index].hash = h;
       strcpy(table->entradas[index].key, string);
       break;
    }
  }
  return;
}
//-------------------------------------------
void deletar(hashTable *table, char *string) {
    int h = hashFunction(string);
    for (int i = 0; i < 20; ++i) {
        int index = (h + i * i + 23 * i) % TAM;
        if (table->entradas[index].deleted == 0) 
            return;
        if (table->entradas[index].deleted == 1) 
            continue; 
        if (table->entradas[index].hash == h && (strcmp(table->entradas[index].key, string) == 0)) {
          table->entradas[index].deleted = 1; 
          (table->tamanho)--;
        }
    }
}

//-------------------------------------------
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
      hashTable table;
    
      for (int i = 0; i < TAM; i++)
        table.entradas[i].deleted = 0; 
      table.tamanho = 0;
  
      int n;
      scanf("%d", &n);

      char string[50]; 
      for (int i = 0; i < n; ++i) {  
        scanf("%s", string); 
        if (string[0] == 'A') 
          inserir(&table, string + 4); 
        else
          deletar(&table, string + 4);
      }
    printf("%d\n", table.tamanho);
    
    for (int i = 0; i < TAM; i++) {
      if (table.entradas[i].deleted == 2) 
        printf("%d:%s\n", i, table.entradas[i].key);
    }
  }
  return 0;
}