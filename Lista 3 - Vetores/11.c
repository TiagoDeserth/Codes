#include <stdio.h>
#include <string.h>

int main() {
    int N;
    char text[100][51]; 
    char line[51];
    int max_len;
    int len;
    int i;
    int j;

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        getchar();

        max_len = 0;

        for (i = 0; i < N; i++) {
            fgets(line, 51, stdin);

            len = strlen(line);
            if (line[len - 1] == '\n') {
                line[len - 1] = '\0';
                len--;
            }

            int k = 0, word_started = 0;
            for (j = 0; j < len; j++) {
                if (line[j] != ' ') {
                    if (word_started && line[j - 1] == ' ') {
                        text[i][k++] = ' ';
                    }
                    text[i][k++] = line[j];
                    word_started = 1;
                }
            }
            text[i][k] = '\0';

            len = strlen(text[i]);
            if (len > max_len) {
                max_len = len;
            }
        }

        for (i = 0; i < N; i++) {
            len = strlen(text[i]);
            for (j = 0; j < max_len - len; j++) {
                printf(" ");
            }
            printf("%s\n", text[i]);
        }

        printf("\n");
    }

    return 0;
}
