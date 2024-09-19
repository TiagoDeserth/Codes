#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 300

typedef struct {
    int top;
    char arr[MAX];
} Pilha;

void criaPilha(Pilha *p) {
    p->top = -1;
}

void empilha(Pilha *p, char c) {
    if (p->top < MAX - 1) {
        p->arr[++(p->top)] = c;
    }
}

char desempilha(Pilha *p) {
    if (p->top >= 0) {
        return p->arr[(p->top)--];
    }
    return '\0';
}

char topoPilha(Pilha *p) {
    if (p->top >= 0) {
        return p->arr[p->top];
    }
    return '\0';
}

int pilhaVazia(Pilha *p) {
    return p->top == -1;
}

int precedencia(char op) {
    switch (op) {
        case '+': case '-':
            return 1;
        case '*': case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int ehOperador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void infixaParaPosfixa(char* infixa, char* posfixa) {
    Pilha p;
    criaPilha(&p);
    int j = 0;

    for (int i = 0; infixa[i] != '\0'; i++) {
        char c = infixa[i];
        
        if (isalnum(c)) {
            posfixa[j++] = c;
        } else if (c == '(') {
            empilha(&p, c);
        } else if (c == ')') {
            while (!pilhaVazia(&p) && topoPilha(&p) != '(') {
                posfixa[j++] = desempilha(&p);
            }
            desempilha(&p);
        } else if (ehOperador(c)) {
            while (!pilhaVazia(&p) && precedencia(topoPilha(&p)) >= precedencia(c)) {
                posfixa[j++] = desempilha(&p);
            }
            empilha(&p, c);
        }
    }

    while (!pilhaVazia(&p)) {
        posfixa[j++] = desempilha(&p);
    }
    
    posfixa[j] = '\0';
}

int main() {
    int N;
    scanf("%d\n", &N);
    
    char infixa[MAX];
    char posfixa[MAX];
    
    for (int i = 0; i < N; i++) {
        fgets(infixa, sizeof(infixa), stdin);
        infixa[strcspn(infixa, "\n")] = '\0';
        
        infixaParaPosfixa(infixa, posfixa);
        printf("%s\n", posfixa);
    }
    
    return 0;
}
