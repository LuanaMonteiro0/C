#include <stdio.h>
#include <conio.h>
// declaracao de vetores

int main(){
	printf("Hello world\n\n");
	int vetor[10]; //armazena 10 numeros inteiros
	//int veetor[]; sempre � necessario declarar o tamanho do vetor
	int i;
	int j;
	int mat[3][3];
	int *ponteiro;
	//vairavel que armazena a loca��o
	for (i=0; i<10; i++){
		vetor[i] = 10 + i;
		
	}
	for (i=0; i<10; i++){
		printf("vetor[%d] = %d\n", i, vetor[i]);
	}
	printf("vetor: %p\n", vetor);
	
	//%d imprime numeros inteiros
	//%p imprime hexadecimal
	// printf("&vetor [0]: %p\n", &vetor[0]);
	// printf("&vetor [1]: %p\n", &vetor[1]);
	// printf("&vetor [5]: %p\n", &vetor[5]);
	// printf("&vetor [8]: %p\n", &vetor[8]);
	//& imprime o endere�o do vetor
	for (i=0; i<10; i++){
		 printf("&vetor [%d] = %d - endereco: %p\n", i, vetor[i], &vetor[i]);
	}
	//constru�ao da matriz for dentro do for
	for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			mat[i][j] = i+j;
			printf("%p: [%d, %d]:%d\n", &mat[i][j], i, j, mat[i][j]);
		}
	}
	
/*	for (i=0; i<80; i++){
		veetor[i] = 10 + i;
		printf("veetor[%d] = %d\n", i, veetor[i]);	
	} */
	
	printf("matriz: %p\n", mat[4]);
	
	ponteiro = (int *)mat;
	printf("%d\n", ponteiro[4]);
	//ponteiro transforma a matriz em um vetor de enderecos
	
	
	
}


