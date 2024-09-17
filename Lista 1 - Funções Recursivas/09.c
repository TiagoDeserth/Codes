#include <stdio.h>
#include <string.h>

typedef struct {
	char palavra[51];
} string;

typedef struct {
	char saida[51];
} saida;

int ehLetra(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

void processarString(string* palavra, saida* textoSaida, int j, int k) {
	if (palavra->palavra[j] == '\0') {
		textoSaida->saida[k] = '\0'; 
		return;
	}

	if (ehLetra(palavra->palavra[j])) {
		textoSaida->saida[k++] = palavra->palavra[j++]; 
	} else {
		while (!ehLetra(palavra->palavra[j]) && palavra->palavra[j] != '\0') {
			j++; 
		}
		if (palavra->palavra[j] != '\0') {
			textoSaida->saida[k++] = ' '; 
		}
	}

	processarString(palavra, textoSaida, j, k);  
}

int encontrarMaior(saida* textoSaida, int i, int tam, int maiorAtual) {
	if (i == tam) {
		return maiorAtual;
	}

	int atual = strlen(textoSaida[i].saida);
	if (atual > maiorAtual) {
		maiorAtual = atual;
	}

	return encontrarMaior(textoSaida, i + 1, tam, maiorAtual); 
}

void exibirStrings(saida* textoSaida, int i, int tam, int maior) {
	if (i == tam) {
		return;
	}

	printf("%*s\n", maior, textoSaida[i].saida);
	exibirStrings(textoSaida, i + 1, tam, maior); 
}

void processarCasos(int casos) {
	if (casos == 0) {
		return;
	}

	string palavra[casos];
	saida textoSaida[casos];

	for (int i = 0; i < casos; i++) {
		scanf(" %[^\n]", palavra[i].palavra);
		processarString(&palavra[i], &textoSaida[i], 0, 0);
	}

	int maior = encontrarMaior(textoSaida, 0, casos, 0);
	exibirStrings(textoSaida, 0, casos, maior);

	scanf("%d", &casos);
	if (casos != 0) {
		printf("\n");
		processarCasos(casos); 
	}
}

int main() {
	int casos;
	scanf("%d", &casos);
	processarCasos(casos);
	return 0;
}
