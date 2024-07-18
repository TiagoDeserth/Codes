#include <stdio.h>

double raiz_quadrada_2_recursiva(int n) {
    if (n == 0) {
        return 1.0;
    }
    return 1.0 + 1.0 / (1.0 + raiz_quadrada_2_recursiva(n - 1));
}

int main() {
    int N;
    scanf("%d", &N);
    
    if (N < 0 || N > 100) {
        printf("O número de repetições deve estar entre 0 e 100.\n");
        return 1;
    }

    double resultado = raiz_quadrada_2_recursiva(N);
    printf("%.10f\n", resultado);
}