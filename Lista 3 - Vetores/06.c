#include <stdio.h>

#define TAMANHO 100
 
int main() {
    int i;
    double N[TAMANHO];
    double X;
    scanf("%lf", &X);
    N[0] = X;
    
    for (i = 1; i < TAMANHO; i++) {
        N[i] = N[i - 1] / 2;
    }
    
    for (i = 0; i < 100; i++) {
        printf("N[%d] = %.4lf\n", i, N[i]);
    }

    return 0;
}