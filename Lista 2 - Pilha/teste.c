#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int items[MAX_SIZE];
    int top;
} Pilha;

void inicializarPilha(Pilha *p) {
    p->top = -1;
}

int estaVazia(Pilha *p) {
    return p->top == -1;
}

int estaCheia(Pilha *p) {
    return p->top == MAX_SIZE - 1;
}

void push(Pilha *p, int valor) {
    if (estaCheia(p)) {
        printf("Erro: Pilha cheia\n");
        return;
    }
    p->items[++(p->top)] = valor;
}

int pop(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
    return p->items[(p->top)--];
}

int peek(Pilha *p) {
    if (estaVazia(p)) {
        printf("Erro: Pilha vazia\n");
        return -1;
    }
    return p->items[p->top];
}

void imprimirPilha(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia\n");
        return;
    }
    printf("Elementos da pilha: ");
    for (int i = 0; i <= p->top; i++) {
        printf("%d ", p->items[i]);
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);

    imprimirPilha(&pilha);

    printf("Elemento no topo: %d\n", peek(&pilha));

    printf("Removendo elemento: %d\n", pop(&pilha));
    printf("Removendo elemento: %d\n", pop(&pilha));

    imprimirPilha(&pilha);

    return 0;
}