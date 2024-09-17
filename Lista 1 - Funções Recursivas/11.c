#include <stdio.h>

unsigned long long proximoNumero(unsigned long long n) {
    if (n % 2 == 0) {
        return n / 2;
    } else {
        return 3 * n + 1;
    }
}

unsigned long long maiorGranizo(unsigned long long n, unsigned long long maior) {
    if (n > maior) {
        maior = n;
    }
    
    if (n == 1) {
        return maior;
    }
    
    return maiorGranizo(proximoNumero(n), maior);
}

int main() {
    unsigned long long H;
    
    while (1) {
        scanf("%llu", &H);
        
        if (H == 0) {
            break;
        }
        
        printf("%llu\n", maiorGranizo(H, H));
    }
    
    return 0;
}