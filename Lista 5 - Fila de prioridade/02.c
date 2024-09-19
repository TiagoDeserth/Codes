#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tempo_livre;
    int id;
} Funcionario;

void troca(Funcionario *a, Funcionario *b) {
    Funcionario temp = *a;
    *a = *b;
    *b = temp;
}

void descerHeap(Funcionario heap[], int n, int i) {
    int menor = i;
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;

    if (esquerda < n && (heap[esquerda].tempo_livre < heap[menor].tempo_livre ||
                         (heap[esquerda].tempo_livre == heap[menor].tempo_livre && heap[esquerda].id < heap[menor].id))) {
        menor = esquerda;
    }
    if (direita < n && (heap[direita].tempo_livre < heap[menor].tempo_livre ||
                        (heap[direita].tempo_livre == heap[menor].tempo_livre && heap[direita].id < heap[menor].id))) {
        menor = direita;
    }
    if (menor != i) {
        troca(&heap[i], &heap[menor]);
        descerHeap(heap, n, menor);
    }
}

void subirHeap(Funcionario heap[], int n, int i) {
    while (i > 0 && (heap[i].tempo_livre < heap[(i - 1) / 2].tempo_livre ||
                     (heap[i].tempo_livre == heap[(i - 1) / 2].tempo_livre && heap[i].id < heap[(i - 1) / 2].id))) {
        troca(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void insereHeap(Funcionario heap[], int *n, Funcionario f) {
    heap[*n] = f;
    subirHeap(heap, *n + 1, *n);
    (*n)++;
}

Funcionario removeMin(Funcionario heap[], int *n) {
    Funcionario min = heap[0];
    heap[0] = heap[*n - 1];
    (*n)--;
    descerHeap(heap, *n, 0);
    return min;
}

int main() {
    int N, M;
    
    scanf("%d %d", &N, &M);
    
    int *tempo_funcionario = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &tempo_funcionario[i]);
    }
    
    int *itens_cliente = (int *)malloc(M * sizeof(int));
    for (int j = 0; j < M; j++) {
        scanf("%d", &itens_cliente[j]);
    }
    
    Funcionario *heap = (Funcionario *)malloc(N * sizeof(Funcionario));
    int tamanho_heap = 0;

    for (int i = 0; i < N; i++) {
        Funcionario funcionario = {0, i}; // Tempo inicial é 0
        insereHeap(heap, &tamanho_heap, funcionario);
    }

    // Processa cada cliente
    for (int j = 0; j < M; j++) {
        int cliente_itens = itens_cliente[j];
        
        Funcionario funcionario = removeMin(heap, &tamanho_heap);

        funcionario.tempo_livre += tempo_funcionario[funcionario.id] * cliente_itens;

        insereHeap(heap, &tamanho_heap, funcionario);
    }

    int tempo_total = 0;
    for (int i = 0; i < N; i++) {
        if (heap[i].tempo_livre > tempo_total) {
            tempo_total = heap[i].tempo_livre;
        }
    }
    
    printf("%d\n", tempo_total);

    free(tempo_funcionario);
    free(itens_cliente);
    free(heap);

    return 0;
}
