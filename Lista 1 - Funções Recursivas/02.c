#include <stdio.h>

int calcularUltimaPosicao(int N, int k) {
    int r = 0;
    for (int i = 1; i < N; i++) {
        r = (r + k) % i;
    }
    
    return r;
}

int main() {
    int N;
    int k;

    while (1) {
        scanf("%d", &N);
        if (N == 0) 
            break;

        k = 1;

        while (calcularUltimaPosicao(N, k) != 11) {
            k++;
        }

        printf("%d\n", k);
    }
    
    return 0;
}
