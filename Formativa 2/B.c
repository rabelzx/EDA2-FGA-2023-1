#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1572869u
#define key(a) (a.k)
#define eq(a, b) (a.k == b.k)
#define hash_k(k) (k % TAM)
#define key_t unsigned
#define eq_k(x, k) (key(x) == k)
#define hash(x) (hash_k(key(x)))

typedef struct Item {
    unsigned k;
    char v;
} Item;

typedef struct LinkedItem {
    Item item;
    struct LinkedItem *next;
} LinkedItem;

typedef struct tabela {
    unsigned size;
    LinkedItem **v;
} tabela;

tabela inicializar() {
    tabela ht = {.size = 0};
    ht.v = (LinkedItem **)malloc(TAM * sizeof(LinkedItem *));
    for (unsigned i = 0; i < TAM; i++)
        ht.v[i] = NULL;
    return ht;
}

int inserir(tabela *ht, Item x) {
    unsigned h = hash(x);
    if (!ht->v[h])
    {
        ht->v[h] = (LinkedItem *)malloc(sizeof(LinkedItem));
        *ht->v[h] = (LinkedItem){.next = NULL, .item = x};
        return 1;
    }
    LinkedItem *curr = ht->v[h];
    while (curr->next && !eq(curr->item, x))
        curr = curr->next;
    if (eq(curr->item, x))
        return 0;

    curr->next = (LinkedItem *)malloc(sizeof(LinkedItem));
    *curr->next = (LinkedItem){.item = x, .next = NULL};
    ht->size++;
    return 1;
}

LinkedItem *procurar(tabela ht, key_t k) {
    unsigned h = hash_k(k);
    LinkedItem *curr = ht.v[h];
    while (curr)
    {
        if (eq_k(curr->item, k))
            return curr;
        curr = curr->next;
    }
    return NULL;
}

int main()
{
    tabela ht = inicializar();
    Item item;
    unsigned mn = 1 << 31, mx = 0;
    while (scanf(" %d %c", &item.k, &item.v) == 2)
    {
        inserir(&ht, item);
        mn = item.k < mn ? item.k : mn;
        mx = item.k > mx ? item.k : mx;
    }

    for (unsigned i = mn; i <= mx; i++)
    {
        LinkedItem *li = procurar(ht, i);
        if (li)
            printf("%c", li->item.v);
    }
    printf("\n");
  
    return 0;
}