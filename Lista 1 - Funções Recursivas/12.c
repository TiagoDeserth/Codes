#include <stdio.h>

void preencherMatriz(int matriz[][100], int ordem, int i, int j) {
    if (i >= ordem) {
        return;
    }
    if (j >= ordem) {
        preencherMatriz(matriz, ordem, i + 1, 0);
        return;
    }
    matriz[i][j] = (i >= j) ? (i - j + 1) : (j - i + 1);
    preencherMatriz(matriz, ordem, i, j + 1);
}

void imprimirMatriz(int matriz[][100], int ordem) {
    for (int i = 0; i < ordem; i++) {
        for (int j = 0; j < ordem; j++) {
            printf("%3d", matriz[i][j]);
            if (j < ordem - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int matriz[100][100];
    int ordem;

    while (1) {
        scanf("%d", &ordem);
        if (ordem == 0) {
            break;
        }
        preencherMatriz(matriz, ordem, 0, 0);
        imprimirMatriz(matriz, ordem);
    }

    return 0;
}
