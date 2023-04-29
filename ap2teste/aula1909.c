#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//algoritmos de ordenação - exemplo com inteiros

void troca(int *a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

int indiceMenorElemento(int vetor[], int n, int primeiro){
	int i, menor = primeiro;
	for (i = primeiro + 1; i < n; i++) {
		if (vetor[i] < vetor[menor])
		menor = i;
	}
	return menor;
}
int ordenar_selecao(int vetor[], int n) {
	int i, menor;
	for (i = 0; i < n; i++) {
		menor = indiceMenorElemento(vetor, n, i);
		troca(&vetor[i], &vetor[menor]);
	}
}
