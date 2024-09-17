#include <stdio.h>
#include <string.h>

#define MAX_DIGITOS 1001 

int encaixa(char *a, char *b, int a_tamanho, int b_tamanho) {
    if (b_tamanho == 0) {
        return 1;
    }
    
    if (a_tamanho == 0 || a_tamanho < b_tamanho) {
        return 0;
    }
    
    if (a[a_tamanho - 1] == b[b_tamanho - 1]) {
        return encaixa(a, b, a_tamanho - 1, b_tamanho - 1);
    } else {
        return 0;
    }
}

int main() {
    int N;
    char A[MAX_DIGITOS];
    char B[MAX_DIGITOS];
    
    scanf("%d", &N);
    
    while (N--) {
        scanf("%s %s", A, B);
        
        int a_tamanho = strlen(A);
        int b_tamanho = strlen(B);
        
        if (encaixa(A, B, a_tamanho, b_tamanho)) {
            printf("encaixa\n");
        } else {
            printf("nao encaixa\n");
        }
    }
    
    return 0;
}