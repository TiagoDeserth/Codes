#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char texto[100][51];
    int max_tamanho;
    int i;
    int j;

    while (1) {
        scanf("%d", &N);
        if (N == 0) 
            break;

        getchar();

        max_tamanho = 0;

        for (i = 0; i < N; i++) {
            fgets(texto[i], sizeof(texto[i]), stdin);

            int tamanho = strlen(texto[i]);
            if (texto[i][tamanho - 1] == '\n') {
                texto[i][tamanho - 1] = '\0';
                tamanho--;
            }

            int k = 0;
            int espaco_encontrado = 0;
            for (j = 0; j < tamanho; j++) {
                if (texto[i][j] != ' ') {
                    if (espaco_encontrado && k > 0) {
                        texto[i][k++] = ' ';
                    }
                    texto[i][k++] = texto[i][j];
                    espaco_encontrado = 0;
                } else if (!espaco_encontrado) {
                    espaco_encontrado = 1;
                }
            }
            texto[i][k] = '\0';

            if (k > max_tamanho) {
                max_tamanho = k;
            }
        }

        for (i = 0; i < N; i++) {
            int tamanho = strlen(texto[i]);
            int num_espacos = max_tamanho - tamanho;
            for (j = 0; j < num_espacos; j++) {
                putchar(' ');
            }
            printf("%s\n", texto[i]);
        }

        printf("\n");
    }

    return 0;
}
