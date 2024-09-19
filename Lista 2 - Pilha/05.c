#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define MAXN 105

typedef struct Celula {
    int elemento;
    struct Celula* proxima;
} Celula;

typedef struct Pilha {
    Celula* topo;
    int tamanho;
} Pilha;

Pilha* criaPilha() {
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha)); 
    pilha->tamanho = 0;
    pilha->topo = NULL;
    return pilha;
}

Celula* criaCelula(int x) {
    Celula* celula = (Celula*)malloc(sizeof(Celula));
    celula->elemento = x;
    celula->proxima = NULL;
    return celula;
}

void empilha(int x, Pilha* pilha) {
    Celula* temp = criaCelula(x);
    temp->proxima = pilha->topo;
    pilha->topo = temp;
    pilha->tamanho++;
}

void desempilha(Pilha* pilha) {
    if (pilha->topo == NULL) {
        return;
    }
    Celula* temp = pilha->topo;
    pilha->topo = pilha->topo->proxima;
    free(temp); 
}

int pilhaVazia(Pilha* pilha) {
    return pilha->topo == NULL;
}

int N, n[MAXN][3], pd[MAXN][MAXN][MAXN];
int soma;
int sucesso;

int resolver(int a, int b, int c) {
    if (a == N && b == N && c == N) {
        sucesso = 1;
        return 1;
    }
    if (a > N || b > N || c > N) return 0;
    if (pd[a][b][c] != -1) return pd[a][b][c];
    if (sucesso) return 1;

    if (n[a][0] % 3 == 0)
        pd[a + 1][b][c] = resolver(a + 1, b, c);

    if (n[b][1] % 3 == 0)
        pd[a][b + 1][c] = resolver(a, b + 1, c);

    if (n[c][2] % 3 == 0)
        pd[a][b][c + 1] = resolver(a, b, c + 1);

    if ((n[a][0] + n[b][1]) % 3 == 0)
        pd[a + 1][b + 1][c] = resolver(a + 1, b + 1, c);

    if ((n[a][0] + n[c][2]) % 3 == 0)
        pd[a + 1][b][c + 1] = resolver(a + 1, b, c + 1);

    if ((n[b][1] + n[c][2]) % 3 == 0)
        pd[a][b + 1][c + 1] = resolver(a, b + 1, c + 1);

    if ((n[a][0] + n[b][1] + n[c][2]) % 3 == 0)
        pd[a + 1][b + 1][c + 1] = resolver(a + 1, b + 1, c + 1);

    return 0;
}

int main() {
    while (scanf("%d", &N) && N) {
        soma = 0;
        sucesso = 0;
        memset(pd, -1, sizeof(pd));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 3; j++) {
                scanf("%d", &n[i][j]);
                soma += n[i][j];
            }
        }

        if (soma % 3 != 0) {
            printf("0\n");
            continue;
        }

        resolver(0, 0, 0);

        if (!sucesso) printf("0\n");
        else printf("1\n");
    }

    return 0;
}