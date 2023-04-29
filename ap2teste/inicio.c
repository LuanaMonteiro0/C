#include <stdio.h>
//#include <conio.h>

/*void = quero apenas que o programa retorne o codigo
void main()
{
    printf("Hello World!\n");
}
*/

// variavel global aluga menos espaço na memoria, demora menos para ser acessada - mais performance
int teste;

int soma (int a, int b){
    int soma;
    soma = a + b;
    return soma;
}

//int = o programa retorna um valor inteiro
int main()
{
    //printf recebe string - string = conjunto de caracteres que termina no 0
    int nu1, nu2, somalocal;
    printf("digite o primeiro numero: ");
    // & retorna o endereço de memoria da variavel
    scanf("%d", &nu1);
    printf("digite o segundo numero: ");
    scanf("%d", &nu2);
    somalocal = soma( nu1, nu2); 
    printf("A soma é %d!\n", somalocal);
    //getch(); // usar getch() para evitar que o programa feche antes de ver o print
    return 0; 
}
