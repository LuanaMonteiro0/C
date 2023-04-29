#include <stdio.h>

int n;
int *vector;

void inicializar(int *vector, int n){
	//
	int i;
	for(i=0; i<n; i++){
		vector[i] = 0;
		printf("%d", vector[i]);
		// printf("vetor[%d] = %d\n", i, vector[i]);
	}

}
void main(int *vector){
	/*printf("digite o parametro n para o vetor: ");
	scanf("%d", &n);
	// int //vector[n];
	int vector[100];
	inicializar(vector, n);
	
	int vector[10];
	inicializar(vector, 10);
	*/
	
	char palavra[10];
	
	palavra[0] = '0';
	palavra[1] = 0;
	palavra[2] = 'A';
	printf("%c\n", palavra[0]);
	printf("%c\n", palavra[1]);
	printf("%c\n", palavra[2]);
	printf("%d\n", palavra[0]);
	printf("%d\n", palavra[1]);
	printf("%d\n", palavra[2]);
	printf("%s\n", palavra);

	
}
