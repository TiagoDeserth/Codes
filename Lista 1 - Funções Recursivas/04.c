#include <stdio.h>

void imprimirJ(int I, int J) {
    if (J < I + 4) {
        return;
    }
    
    printf("I=%d J=%d\n", I, J);
    imprimirJ(I, J - 1);
}

void imprimirI(int I) {
    if (I > 9) {
        return;
    }
    
    imprimirJ(I, I + 6);
    imprimirI(I + 2); 
}

int main() {
    imprimirI(1);
    return 0;
}
