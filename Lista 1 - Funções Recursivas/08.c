#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 201

int eh_letra(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char para_minusculo(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32; 
    }
    return c;
}

void contarFrequenciasRecursivo(const char *texto, int index, int frequencias[26]) {
    if (texto[index] == '\0') {
        return;
    }
    
    if (eh_letra(texto[index])) {
        int letraIndex = para_minusculo(texto[index]) - 'a';
        frequencias[letraIndex]++;
    }
    
    contarFrequenciasRecursivo(texto, index + 1, frequencias);
}

void encontrarMaximoRecursivo(int frequencias[26], int index, int *maxFreq) {
    if (index == 26) {
        return;
    }
    
    if (frequencias[index] > *maxFreq) {
        *maxFreq = frequencias[index];
    }
    
    encontrarMaximoRecursivo(frequencias, index + 1, maxFreq);
}

void imprimirLetrasMaisFrequentesRecursivo(int frequencias[26], int index, int maxFreq) {
    if (index == 26) {
        printf("\n");
        return;
    }
    
    if (frequencias[index] == maxFreq) {
        printf("%c", 'a' + index);
    }
    
    imprimirLetrasMaisFrequentesRecursivo(frequencias, index + 1, maxFreq);
}

void encontrarLetrasMaisFrequentes(const char *texto) {
    int frequencias[26] = {0};
    int maxFreq = 0;

    contarFrequenciasRecursivo(texto, 0, frequencias);

    encontrarMaximoRecursivo(frequencias, 0, &maxFreq);

    imprimirLetrasMaisFrequentesRecursivo(frequencias, 0, maxFreq);
}

int main() {
    int N;
    char texto[MAX_TAMANHO];

    scanf("%d", &N);
    getchar();

    while (N--) {
        fgets(texto, MAX_TAMANHO, stdin);
        texto[strcspn(texto, "\n")] = 0;
        encontrarLetrasMaisFrequentes(texto);
    }

    return 0;
}