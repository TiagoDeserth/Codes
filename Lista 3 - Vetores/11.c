#include <stdio.h>
#include <string.h>

typedef struct{
	char palavra[51];
} string;

typedef struct{
	char saida[51];
} saida;

int ehLetra(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void main() {
	int casos, aux, tam;
	int maior, atual;
    int i, j, k;

	scanf("%d", &casos);
	while (1) {	
		if (casos == 0)
			break;

		aux = casos;

		string palavra[aux];
		saida textoSaida[aux];

		i = 0;
		while (casos--)
			scanf(" %[^\n]", palavra[i++].palavra);

		i = 0;
		tam = aux;
		while (aux--) {
			j = 0;
			k = 0;
			while (1) {
				while (ehLetra(palavra[i].palavra[j]))	
					textoSaida[i].saida[k++] = palavra[i].palavra[j++];

				if (palavra[i].palavra[j] == '\0')
					break;

				while (!ehLetra(palavra[i].palavra[j])) {	
					j++;
					if (palavra[i].palavra[j] == '\0')
						break;
				}

				if (palavra[i].palavra[j] == '\0')
					break;

				textoSaida[i].saida[k++] = ' ';
			}
				
			textoSaida[i].saida[k] = '\0';
			i++;
		}	

		maior = 0;
		for(i = 0; i < tam; i++) {
			atual = strlen(textoSaida[i].saida);
			if (atual > maior)
				maior = atual;
		}

		for (i = 0; i < tam; i++)
			printf("%*s\n", maior, textoSaida[i].saida);

		scanf("%d", &casos);

		if(casos != 0)
			printf("\n");
	}

    return 0;
}
