#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho = 5;
    int *ptr;
    int i;

    // Aloca memória para 5 inteiros
    ptr = (int*)malloc(tamanho * sizeof(int));

    printf("Valor do ptr: %d\n", ptr);

    // Verifica se a alocação foi bem-sucedida
    if (ptr == NULL) {
        printf("Erro: memória não pôde ser alocada.\n");
        return 1;
    }

    // Preenche o array com valores
    for (i = 0; i < tamanho; i++) {
        ptr[i] = i * 10;
    }

    // Imprime os valores
    printf("Valores armazenados:\n");
    for (i = 0; i < tamanho; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(ptr);

    return 0;
}