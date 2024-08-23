#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int conteudo;
    struct celula *prox;
} Celula;

Celula* criarCelula(int valor) {
    Celula *nova = (Celula*)malloc(sizeof(Celula));
    nova->conteudo = valor;
    nova->prox = NULL;
    return nova;
}

Celula* inserirNoFinal(Celula *inicio, int valor) {
    Celula *nova = criarCelula(valor);
    if (inicio == NULL) {
        return nova;
    }
    Celula *p = inicio;
    while (p->prox != NULL) {
        p = p->prox;
    }
    p->prox = nova;
    return inicio;
}

void substituirValores(Celula *inicio) {
    Celula *p = inicio;
    while (p != NULL) {
        if (p->conteudo <= 0) {
            p->conteudo = 1;
        }
        p = p->prox;
    }
}

void imprimirLista(Celula *inicio) {
    Celula *p = inicio;
    int i = 0;
    while (p != NULL) {
        printf("X[%d] = %d\n", i, p->conteudo);
        p = p->prox;
        i++;
    }
}

int main() {
    Celula *lista = NULL;
    int valor;

    for (int i = 0; i < 10; i++) {
        scanf("%d", &valor);
        lista = inserirNoFinal(lista, valor);
    }

    substituirValores(lista);

    imprimirLista(lista);

    while (lista != NULL) {
        Celula *temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}
