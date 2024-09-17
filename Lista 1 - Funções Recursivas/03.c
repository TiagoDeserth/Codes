#include <stdio.h>

#define TRUE 1
#define FALSE 0
#define MAX_TAMANHO 3502

int primos[MAX_TAMANHO] = { 0 }; 

int josephus(int n) {
    int retorno = 0;

    for (int i = 1; i <= n; ++i)
        retorno = (retorno + primos[n - i]) % i;

    return retorno + 1;  

int ehPrimo(int x) {
    if (x == 2)
        return TRUE;

    if (x % 2 == 0 || x < 2)
        return FALSE;

    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0)
            return FALSE;
    }

    return TRUE;
}

void preenchePrimos() {
    int i = 0;
    int j = 0;
    for (i = 2; j < MAX_TAMANHO; ++i) {
        if (ehPrimo(i))
            primos[j++] = i;
    }
}

int main() {
    preenchePrimos(); 

    int n;
    while (TRUE) {
        scanf("%d", &n);
        if (n == 0)
            break;
        printf("%d\n", josephus(n)); 
    }
    return 0;
}