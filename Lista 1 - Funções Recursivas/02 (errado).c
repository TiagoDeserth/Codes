#include <stdio.h>

// Função recursiva para calcular o vencedor no problema de Josephus
int josephus(int n, int m) {
    if (n == 1) {
        return 0; // Se houver apenas uma pessoa, ela é a sobrevivente
    } else {
        return (josephus(n - 1, m) + m) % n;
    }
}

// Função para encontrar o menor valor de m que coloca a região 13 como a última
int encontrarM(int n, int m) {
    if (josephus(n, m) == 12) { // Comparação com 12 porque os índices começam em 0
        return m;
    }
    return encontrarM(n, m + 1); // Tenta o próximo valor de m
}

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) {
            break; // Encerra a leitura se n for 0
        }
        printf("%d\n", encontrarM(n, 1)); // Inicia a busca por m a partir de 1
    }

    return 0;
}
