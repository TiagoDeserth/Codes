#include <stdio.h>

#define MAX_PALAVRAS 50
#define MAX_TAMANHO_PALAVRAS 51

int main() {
    int N;
    int i, j;
    int max_tamanho;
    int tamanho_atual;
    char palavras[MAX_PALAVRAS][MAX_TAMANHO_PALAVRAS];
    int primeiro_caso = 1;

    while (1) {
        scanf("%d", &N);
        if (N == 0) 
            break;

        if (!primeiro_caso) {
            printf("\n");
        }
        primeiro_caso = 0;

        max_tamanho = 0;
        for (i = 0; i < N; i++) {
            scanf("%s", palavras[i]);
            tamanho_atual = 0;
            while (palavras[i][tamanho_atual] != '\0') {
                tamanho_atual++;
            }
            if (tamanho_atual > max_tamanho) {
                max_tamanho = tamanho_atual;
            }
        }

        for (i = 0; i < N; i++) {
            tamanho_atual = 0;
            while (palavras[i][tamanho_atual] != '\0') {
                tamanho_atual++;
            }
            for (j = 0; j < max_tamanho - tamanho_atual; j++) {
                printf(" ");
            }
            printf("%s\n", palavras[i]);
        }
    }

    return 0;
}
