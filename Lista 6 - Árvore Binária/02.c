#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct noh {
    char valor;
    struct noh *esq;
    struct noh *dir;
} Noh;

typedef Noh *Arvore;

Noh* criarNoh(char valor) {
    Noh *novo = (Noh*)malloc(sizeof(Noh));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

Noh* construirArvore(char* prefixo, char* infixo, int inicioIn, int fimIn, int* indicePrefixo) {
    if (inicioIn > fimIn) {
        return NULL;
    }
    
    Noh* raiz = criarNoh(prefixo[*indicePrefixo]);
    (*indicePrefixo)++;
    
    if (inicioIn == fimIn) {
        return raiz;
    }
    
    int indiceIn = 0;
    while (infixo[indiceIn] != raiz->valor) {
        indiceIn++;
    }
    
    raiz->esq = construirArvore(prefixo, infixo, inicioIn, indiceIn - 1, indicePrefixo);
    raiz->dir = construirArvore(prefixo, infixo, indiceIn + 1, fimIn, indicePrefixo);
    
    return raiz;
}

void posOrdem(Arvore r) {
    if (r != NULL) {
        posOrdem(r->esq);
        posOrdem(r->dir);
        printf("%c", r->valor);
    }
}

int main() {
    char prefixo[27], infixo[27];
    while (scanf("%s %s", prefixo, infixo) != EOF) {
        int len = strlen(prefixo);
        int indicePrefixo = 0;
        Arvore raiz = construirArvore(prefixo, infixo, 0, len - 1, &indicePrefixo);
        posOrdem(raiz);
        printf("\n");
    }
    return 0;
}
