#include <stdio.h>

int main() {
    int N;
    int freq[26]; 
    int max;
    int i;
    char str[201];

    scanf("%d", &N);
    while (N--) {
        for (i = 0; i < 26; i++) freq[i] = 0;
        max = 0;

        scanf(" %[^\n]", str);

        for (i = 0; str[i]; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
            if (str[i] >= 'a' && str[i] <= 'z') {
                int index = str[i] - 'a';
                freq[index]++;
                if (freq[index] > max) max = freq[index];
            }
        }

        for (i = 0; i < 26; i++)
            if (freq[i] == max) printf("%c", i + 'a');
        printf("\n");
    }

    return 0;
}