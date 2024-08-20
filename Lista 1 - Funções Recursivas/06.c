#include <stdio.h>

void processarNumeros(int numeros[], int index, int par[], int impar[], int j, int k) {
    if (index == 15) {
        for (int i = 0; i < k; i++) {
            printf("impar[%d] = %d\n", i, impar[i]);
        }
        for (int i = 0; i < j; i++) {
            printf("par[%d] = %d\n", i, par[i]);
        }
        return;
    }

    if (numeros[index] % 2 == 0) {
        par[j] = numeros[index];
        j++;
        if (j == 5) { 
            for (int i = 0; i < 5; i++) {
                printf("par[%d] = %d\n", i, par[i]);
            }
            j = 0;
        }
    } else {
        impar[k] = numeros[index];
        k++;
        if (k == 5) {
            for (int i = 0; i < 5; i++) {
                printf("impar[%d] = %d\n", i, impar[i]);
            }
            k = 0;
        }
    }

    processarNumeros(numeros, index + 1, par, impar, j, k);
}

int main() {
    int numeros[15];
    int par[5], impar[5];

    for (int i = 0; i < 15; i++) {
        scanf("%d", &numeros[i]);
    }

    processarNumeros(numeros, 0, par, impar, 0, 0);

    return 0;
}
