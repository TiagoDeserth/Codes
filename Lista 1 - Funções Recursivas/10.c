#include <stdio.h>

#define N 9

int verificaArray(int array[], int index, int seen[]) {
    if (index == N)
        return 1;
    int num = array[index];
    if (num < 1 || num > 9 || seen[num])
        return 0;
    seen[num] = 1;
    return verificaArray(array, index + 1, seen);
}

int verificaLinhas(int sudoku[N][N], int linha) {
    if (linha == N)
        return 1;

    int seen[N + 1] = {0};
    if (!verificaArray(sudoku[linha], 0, seen))
        return 0;

    return verificaLinhas(sudoku, linha + 1);
}

int verificaColunas(int sudoku[N][N], int coluna, int linha) {
    if (coluna == N)
        return 1;
    if (linha == 0) {
        int seen[N + 1] = {0};
        for (int i = 0; i < N; i++) {
            int num = sudoku[i][coluna];
            if (num < 1 || num > 9 || seen[num])
                return 0;
            seen[num] = 1;
        }
    }
    return verificaColunas(sudoku, coluna + 1, linha);
}

int verificaRegiao(int sudoku[N][N], int lin_inicio, int col_inicio, int i, int j, int seen[]) {
    if (i == 3) 
        return 1;
    if (j == 3)
        return verificaRegiao(sudoku, lin_inicio, col_inicio, i + 1, 0, seen);

    int num = sudoku[lin_inicio + i][col_inicio + j];
    if (num < 1 || num > 9 || seen[num])
        return 0;
    seen[num] = 1;
    return verificaRegiao(sudoku, lin_inicio, col_inicio, i, j + 1, seen);
}

int verificaRegioes(int sudoku[N][N], int regiao) {
    if (regiao == N)
        return 1;

    int lin_inicio = (regiao / 3) * 3;
    int col_inicio = (regiao % 3) * 3;
    
    int seen[N + 1] = {0};
    if (!verificaRegiao(sudoku, lin_inicio, col_inicio, 0, 0, seen))
        return 0;

    return verificaRegioes(sudoku, regiao + 1);
}

int verificaSudoku(int sudoku[N][N]) {
    return verificaLinhas(sudoku, 0) && verificaColunas(sudoku, 0, 0) && verificaRegioes(sudoku, 0);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int instancia = 1; instancia <= n; instancia++) {
        int sudoku[N][N];

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        printf("Instancia %d\n", instancia);
        if (verificaSudoku(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
    }

    return 0;
}
