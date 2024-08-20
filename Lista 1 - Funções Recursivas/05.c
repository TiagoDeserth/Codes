#include <stdio.h>

int somaImparesConsecutivos(int X, int Y, int soma) {
    if (Y == 0) { 
        return soma;
    }
    
    if (X % 2 != 0) { 
        soma += X;
        Y--; 
    }
    
    return somaImparesConsecutivos(X + 1, Y, soma);
}

int main() {
    int N, X, Y;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X, &Y);
        printf("%d\n", somaImparesConsecutivos(X, Y, 0));
    }

    return 0;
}
