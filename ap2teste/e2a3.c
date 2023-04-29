#include <stdio.h>
#define MATSIZE 100

int matrizum[MATSIZE][MATSIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
int matrizdois[MATSIZE][MATSIZE] = {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}};
int resultado[MATSIZE][MATSIZE];
int i;
int j;
void imprimemat(int mat[MATSIZE][MATSIZE]){
	int i;
	int j;
	for (i = 0; i < MATSIZE; i++){
		for (j = 0; j < MATSIZE; j++){
			printf("[%d]", mat[i][j]);
		}
		printf("\n");
	}
	printf("\n");	
}

/* int multiplicamats(int matum[MATSIZE][MATSIZE], int matdois[MATSIZE][MATSIZE], int resultado[MATSIZE][MATSIZE]){
	for (i = 0; i < MATSIZE; i++){
		for (j = 0; j < MATSIZE; j++){
			// receba = 	&resultado[i][j];
		    resultado[i][j] = matum[i][j] * matdois[i][j];
		}
	}
	//return resultado;
} 

void main(){
	imprimemat(matrizum);
	imprimemat(matrizdois);
	mutiplicamats(matrizum, matrizdois, resultado);
	imprimemat(resultado);	
}
*/

/* void soma(int matum[MATSIZE][MATSIZE], int matdois[MATSIZE][MATSIZE], int resultado[MATSIZE][MATSIZE], int N){
	int i, j;
	for(i = 0; i < n; i++)
} */

void mulmat(int matum[MATSIZE][MATSIZE], int matdois[MATSIZE][MATSIZE], int resultado[MATSIZE][MATSIZE], int N){
	int i, j, k;
	for (i = 0; i < N; i++){
		for (j = 0; j < N; j++){
			resultado[i][j] = 0;
			for(k = 0; k < N; k++){
				resultado[i][j] += matum[i][k] + matdois[k][j]
			}
		}
	}
}



