#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 1000

char pilha[MAX_TAMANHO];
int t;

void criapilha() {
    t = 0;
}

void empilha(char y) {
    pilha[t++] = y;
}

char desempilha() {
    return pilha[--t];
}

int pilhavazia() {
    return t <= 0;
}

int extrairDiamantes(char *mina) {
    int diamantes = 0;
    criapilha();

    for (int i = 0; mina[i] != '\0'; i++) {
        if (mina[i] == '<') {
            empilha('<');
        } else if (mina[i] == '>') {
            if (!pilhavazia() && desempilha() == '<') {
                diamantes++;
            }
        }
    }

    return diamantes;
}

int main() {
    int N;
    char mina[MAX_TAMANHO];

    scanf("%d", &N);
    getchar();

    for (int i = 0; i < N; i++) {
        fgets(mina, MAX_TAMANHO, stdin);
        mina[strcspn(mina, "\n")] = 0;
        printf("%d\n", extrairDiamantes(mina));
    }

    return 0;
}