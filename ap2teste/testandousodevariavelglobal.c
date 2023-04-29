#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numero = 0;

int dez(){
	numero = 10;
	return numero;
}

int onze(){
	numero = numero + 1;
	return numero;
}

void main(){
	printf("%d\n", numero);	
	printf("%d\n", onze());	
	printf("%d\n", dez());
	printf("%d\n", onze());
	printf("%d\n", numero);	
	printf("%d\n", numero);	
	printf("%d\n", numero);	
}
