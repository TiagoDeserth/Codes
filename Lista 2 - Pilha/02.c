#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
char pilha[N];
int t;

void criapilha() {
    t = 0;
}

void empilha(char y) {
    pilha[t++] = y;
}

char desempilha() {
    return pilha[--t];
}

int pilhavazia(void) {
    return t <= 0;
}

int verificaParenteses(char string[]) {
    criapilha();
    for (int i = 0; string[i] != '\0'; ++i) {
        char c;
        switch (string[i]) {
        case ')': 
            if (pilhavazia()) 
                return 0;
            c = desempilha(); 
            if (c != '(')
                return 0;
            break;
        case '(': 
            empilha('(');
            break;
        default:
            break;
        }
    }
    return pilhavazia();
}

int main() {
    char string[1000];
    
    while (fgets(string, sizeof(string), stdin) != NULL) {
        size_t len = strlen(string);
        if (len > 0 && string[len - 1] == '\n') {
            string[len - 1] = '\0';
        }

        int resultado = verificaParenteses(string);
        
        if (resultado) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }

    return 0;
}