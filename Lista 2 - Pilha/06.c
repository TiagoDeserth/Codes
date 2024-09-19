#include <stdio.h>
#include <string.h>

#define MAX_TAMANHO 1000000

int pilha[MAX_TAMANHO];
int minimos[MAX_TAMANHO];
int topo;

void inicializa_pilha() {
    topo = -1;
}

int pilha_vazia() {
    return topo == -1;
}

void empilha(int valor) {
    if (topo < MAX_TAMANHO - 1) {
        topo++;
        if (topo == 0) {
            minimos[topo] = valor;
        } else {
            minimos[topo] = (minimos[topo - 1] < valor ? minimos[topo - 1] : valor);
        }
        pilha[topo] = valor;
    }
}

int desempilha() {
    if (!pilha_vazia()) {
        return pilha[topo--];
    }
    return -1;
}

int min_atual() {
    if (!pilha_vazia()) {
        return minimos[topo];
    }
    return -1;
}

int main() {
    char operacao[5];
    int N, V;

    inicializa_pilha();

    if (scanf("%d", &N) != 1) {
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        if (scanf("%4s", operacao) != 1) {
            return 1;
        }

        if (strcmp(operacao, "PUSH") == 0) {
            if (scanf("%d", &V) != 1) {
                return 1;
            }
            empilha(V);
        } else if (strcmp(operacao, "POP") == 0) {
            if (pilha_vazia()) {
                printf("EMPTY\n");
            } else {
                desempilha();
            }
        } else if (strcmp(operacao, "MIN") == 0) {
            int min = min_atual();
            if (min == -1) {
                printf("EMPTY\n");
            } else {
                printf("%d\n", min);
            }
        } else {
            return 1;
        }
    }

    return 0;
}