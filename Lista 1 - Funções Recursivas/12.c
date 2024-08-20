#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void preencheMatriz(int matriz[MAX][MAX], int n) {
    for (int linha = 0; linha < n; linha++) {
        for (int coluna = 0; coluna < n; coluna++) {
            matriz[linha][coluna] = abs(linha - coluna) + 1;
        }
    }
}

void imprimeMatriz(int matriz[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d", matriz[i][j]);
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int n;
    int matriz[MAX][MAX];

    while (1) {
        scanf("%d", &n);
        if (n == 0) 
            break;
        if (n < 0 || n > 100) 
            continue;

        preencheMatriz(matriz, n);
        imprimeMatriz(matriz, n);
    }

    return 0;
}
