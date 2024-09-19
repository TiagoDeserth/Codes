#include <stdio.h>
#include <stdlib.h>

#define FILHO_ESQ(i) (2 * i + 1)
#define FILHO_DIR(i) (2 * i + 2)
#define PAI(i) ((i - 1) / 2)

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void sobeHeap(int v[], int pos) {
    int corr = pos;
    while (corr > 0 && v[PAI(corr)] < v[corr]) {
        troca(&v[corr], &v[PAI(corr)]);
        corr = PAI(corr);
    }
}

int insereHeap(int v[], int m, int x) {
    v[m] = x;
    sobeHeap(v, m);
    return m + 1;
}

void desceHeap(int v[], int m, int pos) {
    int corr = pos, filho;
    while (FILHO_ESQ(corr) < m && (v[FILHO_ESQ(corr)] > v[corr] || (FILHO_DIR(corr) < m && v[FILHO_DIR(corr)] > v[corr]))) {
        filho = FILHO_ESQ(corr);
        if (FILHO_DIR(corr) < m && v[FILHO_DIR(corr)] > v[filho])
            filho = FILHO_DIR(corr);
        troca(&v[corr], &v[filho]);
        corr = filho;
    }
}

int removeHeap(int v[], int m, int *px) {
    *px = v[0];
    troca(&v[0], &v[m - 1]);
    desceHeap(v, m - 1, 0);
    return m - 1;
}

int main() {
    int n, op, x, i, m;
    int pilha[1000], topo = 0;
    int fila[1000], inicio = 0, fim = 0;
    int heap[1000], maior;
    int ehPilha, ehFila, ehFilaDePrioridade;

    while (scanf("%d", &n) != EOF) {
        topo = 0;
        inicio = fim = 0;
        m = 0; 

        ehPilha = 1;
        ehFila = 1;
        ehFilaDePrioridade = 1;

        for (i = 0; i < n; i++) {
            scanf("%d", &op);

            if (op == 1) {
                scanf("%d", &x);

                pilha[topo++] = x;

                fila[fim++] = x;

                m = insereHeap(heap, m, x);
            } else if (op == 2) {
                scanf("%d", &x);

                if (topo == 0 || pilha[topo - 1] != x)
                    ehPilha = 0;
                else
                    topo--;

                if (inicio == fim || fila[inicio] != x)
                    ehFila = 0;
                else
                    inicio++;

                if (m > 0) {
                    m = removeHeap(heap, m, &maior);
                    if (maior != x)
                        ehFilaDePrioridade = 0;
                } else {
                    ehFilaDePrioridade = 0;
                }
            }
        }

        if (ehPilha + ehFila + ehFilaDePrioridade > 1) {
            printf("not sure\n");
        } else if (ehPilha) {
            printf("stack\n");
        } else if (ehFila) {
            printf("queue\n");
        } else if (ehFilaDePrioridade) {
            printf("priority queue\n");
        } else {
            printf("impossible\n");
        }
    }

    return 0;
}
