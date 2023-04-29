#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    //estrutura de dados
    int in1;
    int *p1;
    int **p2;
    p1 = &in1;
    p2 = &p1;
    in1 = 15;
    printf("endereco de in1 %p\n", &in1);
    printf("endereco de p1 %p\n", &p1);
    printf("endereco de p2 %p\n", &p2);
    printf("conteudo de p1 %p\n", p1);
    printf("conteudo de p2 %p\n", p2);
    printf("conteudo de in1 %d\n", in1);
}