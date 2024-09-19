#include <stdio.h>
#include <stdlib.h>

#define MAX_VAGOES 1000

int pilha[MAX_VAGOES];
int topo;

void criaPilha() {
    topo = -1;
}

void empilha(int vagao) {
    pilha[++topo] = vagao;
}

int desempilha() {
    return pilha[topo--];
}

int pilhaVazia() {
    return topo == -1;
}

int verificaReorganizacao(int n, int *ordem) {
    criaPilha();
    int proximo_vagao = 1;
    int indice_ordem = 0;

    while (indice_ordem < n) {
        if (proximo_vagao <= n && proximo_vagao == ordem[indice_ordem]) {
            proximo_vagao++;
            indice_ordem++;
        } else if (topo >= 0 && pilha[topo] == ordem[indice_ordem]) {
            desempilha();
            indice_ordem++;
        } else if (proximo_vagao <= n) {
            empilha(proximo_vagao++);
        } else {
            return 0; 
        }
    }
    return 1; 
}

int main() {
    int n;
    int i;
    int ordem[MAX_VAGOES];

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            scanf("%d", &ordem[0]);
            if (ordem[0] == 0) {
                printf("\n");
                break;
            }

            for (i = 1; i < n; i++) {
                scanf("%d", &ordem[i]);
            }

            if (verificaReorganizacao(n, ordem)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}