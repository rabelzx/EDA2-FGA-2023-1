#include <stdio.h>
#include <stdlib.h>

int ocorrencias[1010];

int main()
{
    int N;
    scanf("%d", &N);

    int nota = 0, frequencia = 0;
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        if (++ocorrencias[x] > frequencia) {
            frequencia = ocorrencias[x];
            nota = x;
        }
        else if (ocorrencias[x] == frequencia && nota < x)
            nota = x;
      
    }
  
    printf("%d\n", nota);

    return 0;
}