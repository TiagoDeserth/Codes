#include <stdio.h>
#include <stdlib.h>

typedef struct celula Celula;
struct celula {
  int conteudo;
  Celula *prox;
};

// Função para imprimir a lista
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

// Função de busca
Celula *busca(Celula *lst, int x) {
  Celula *p = lst;
  while (p != NULL && p->conteudo != x)
    p = p->prox;
  return p;
}

// Função de seleção (retorna o k-ésimo elemento)
Celula *selecao(Celula *lst, int k) {
  Celula *p = lst;
  int pos = 0;
  while (p != NULL && pos < k) {
    p = p->prox;
    pos++;
  }
  return p;
}

// Função de inserção no início
Celula *insere1(Celula *lst, int x) {
  Celula *nova;
  nova = malloc(sizeof(Celula));
  nova->conteudo = x;
  nova->prox = lst;
  return nova;
}

// Função de remoção
void remove1(Celula *p) {
  Celula *morta;
  morta = p->prox;
  p->prox = morta->prox;
  free(morta);
}

// Função de busca e inserção
Celula *buscaInsere1(Celula *lst, int x, int y) {
  Celula *p, *q, *nova;
  nova = malloc(sizeof(Celula));
  nova->conteudo = y;
  if (lst == NULL || lst->conteudo == x) {
    nova->prox = lst;
    return nova;
  }
  p = lst;
  q = p->prox;
  while (q != NULL && q->conteudo != x) {
    p = q;
    q = p->prox;
  }
  p->prox = nova;
  nova->prox = q;
  return lst;
}

// Função de busca e remoção
Celula *buscaRemove(Celula *lst, int x) {
  Celula *p, *morta;
  p = lst;
  if (p == NULL) 
    return p;
  if (p->conteudo == x){
    morta = p;
    p = morta->prox;
    free(morta);
    return p;
  }
  while (p->prox != NULL && p->prox->conteudo != x)
    p = p->prox;
  if (p->prox != NULL) {
    morta = p->prox;
    p->prox = morta->prox;
    free(morta);
  }
  return lst;
}

// Função main para testar as operações
int main() {
    Celula *lista = NULL; // Inicializa a lista vazia
    int N;
    
    printf("Inserindo elementos na lista:\n");

    for (int i = 10; i >= 1; i--) {
        scanf("%d", &N);
        lista = insere1(lista, N);
        //lista = insere1(lista, i * 10);
    }

    printf("Lista apos insercoes: \n");
    imprime(lista);

    // printf("\nBuscando o elemento 5:\n");

    // Celula *busca_resultado = busca(lista, 5);
    // if (busca_resultado != NULL) {
    //     printf("Elemento 5 encontrado!\n");
    // } else {
    //     printf("Elemento 5 nao encontrado.\n");
    // }

    // printf("\nSelecionando o terceiro elemento:\n");
    // Celula *terceiro = selecao(lista, 2); // índice 2 é o terceiro elemento
    // if (terceiro != NULL) {
    //     printf("O terceiro elemento eh: %d\n", terceiro->conteudo);
    // } else {
    //     printf("Nao ha terceiro elemento.\n");
    // }

    // printf("\nInserindo 25 antes de 5:\n");
    // lista = buscaInsere1(lista, 5, 25);
    // printf("Lista apos insercao: ");
    // imprime(lista);

    // printf("\nRemovendo o elemento 2:\n");
    // lista = buscaRemove(lista, 2);
    // printf("Lista apos remocao: ");
    // imprime(lista);

    // printf("\nRemovendo o primeiro elemento:\n");
    // if (lista != NULL) {
    //     lista = buscaRemove(lista, lista->conteudo);
    //     printf("Lista apos remocao do primeiro: ");
    //     imprime(lista);
    // }

    // Liberando a memória alocada
    while (lista != NULL) {
        Celula *temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}