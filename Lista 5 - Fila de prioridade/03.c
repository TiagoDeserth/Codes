#include <stdio.h>
#include <stdlib.h>

#define FILHO_ESQ(i) (2 * i + 1)
#define FILHO_DIR(i) (2 * i + 2)
#define PAI(i) ((i - 1) / 2)

typedef struct {
    int criticidade;
    char tipo;
} Problema;

void troca(Problema *a, Problema *b) {
    Problema aux = *a;
    *a = *b;
    *b = aux;
}

void sobeHeap(Problema heap[], int pos) {
    int corr = pos;
    while (corr > 0 && (heap[PAI(corr)].tipo < heap[corr].tipo || 
           (heap[PAI(corr)].tipo == heap[corr].tipo && heap[PAI(corr)].criticidade < heap[corr].criticidade))) {
        troca(&heap[corr], &heap[PAI(corr)]);
        corr = PAI(corr);
    }
}

void desceHeap(Problema heap[], int pos, int tamanho) {
    int corr = pos;
    while (FILHO_ESQ(corr) < tamanho) {
        int filho = FILHO_ESQ(corr);
        if (FILHO_DIR(corr) < tamanho && (heap[FILHO_DIR(corr)].tipo > heap[filho].tipo || 
               (heap[FILHO_DIR(corr)].tipo == heap[filho].tipo && heap[FILHO_DIR(corr)].criticidade > heap[filho].criticidade)))
            filho = FILHO_DIR(corr);
        if (heap[corr].tipo > heap[filho].tipo || 
            (heap[corr].tipo == heap[filho].tipo && heap[corr].criticidade >= heap[filho].criticidade)) {
            break;
        }
        troca(&heap[corr], &heap[filho]);
        corr = filho;
    }
}

void insereHeap(Problema heap[], int *tamanho, Problema p) {
    heap[*tamanho] = p;
    sobeHeap(heap, *tamanho);
    (*tamanho)++;
}

Problema removeHeap(Problema heap[], int *tamanho) {
    Problema raiz = heap[0];
    (*tamanho)--;
    heap[0] = heap[*tamanho];
    desceHeap(heap, 0, *tamanho);
    return raiz;
}

int main() {
    int n, m, i, j;
    char tipo;
    int criticidade;
    Problema heap[10000];
    int tamanho = 0;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d%c", &criticidade, &tipo);
            Problema p;
            p.criticidade = criticidade;
            p.tipo = tipo;
            insereHeap(heap, &tamanho, p);
        }
    }

    while (tamanho > 0) {
        Problema p = removeHeap(heap, &tamanho);
        printf("%d%c\n", p.criticidade, p.tipo);
    }

    return 0;
}