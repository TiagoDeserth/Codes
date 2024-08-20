#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;
struct celula {
  int conteudo;
  Celula *prox;
};

void imprime(Celula *lst) {
  Celula *p = lst;
  int i = 0;
  while (p != NULL) {
    if (p->conteudo < 0){
        p->conteudo = 1;
    }
    printf("X[%d] = %d\n", i, p->conteudo);
    p = p->prox;
    i = i + 1;
  }
  printf("\n");
}

Celula *insere1(Celula *lst, int x) {
  Celula *nova;
  nova = malloc(sizeof(Celula));
  nova->conteudo = x;
  nova->prox = lst;
  return nova;
}

int main() {
    Celula *lista = NULL;
    int N;
    
    for (int i = 10; i >= 1; i--) {
        scanf("%d", &N);
        lista = insere1(lista, N);
    }

    imprime(lista);

    while (lista != NULL) {
        Celula *temp = lista;
        lista = lista->prox;
        free(temp);
    }
}