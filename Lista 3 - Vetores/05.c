#include <stdio.h>

#define TAMANHO 1000

int main() {
    int T, N[TAMANHO], i;

    scanf("%d", &T);

    for (i = 0; i < TAMANHO; i++) {
        N[i] = i % T;
    }

    for (i = 0; i < TAMANHO; i++) {
        printf("N[%d] = %d\n", i, N[i]);
    }
}