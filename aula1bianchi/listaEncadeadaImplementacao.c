#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    // listas encadeadas
typedef struct No{
    int info;
    struct No *prox;
}No;

void imprime(No *ini){
    No *p;
    p = ini;
    while(p){
        printf("%d \n", p->info);
        p = p->prox;
    }
}

void *busca(No *ini, int k){
    No *p = ini;
    while(p && p->info != k)
        p = p->prox;
    return p;
}

void removeItemBuscando(No *cabeca, int conteudoRemover){
    No *anterior, *presente;
    anterior = cabeca;
    presente = cabeca->prox;
    while(presente && presente->info != conteudoRemover){
        anterior = presente;
        presente = presente->prox;
    }
    if(presente){
        anterior->prox = presente->prox;
        free(presente);
    }
}

void insereItemBuscando( No *cabeca, int infoAnterior, int inserir){
    No *anterior, *presente, *novo;
    novo = malloc(sizeof(No));
    novo ->info = inserir;
    anterior = cabeca;
    presente = cabeca ->prox;
    while(presente && presente->info != infoAnterior){
        anterior = presente;
        presente = presente->prox;
    }
    novo->prox = presente;
    anterior->prox = novo;
}
  
No* inicializarALista(){
    No* cabeca;
    cabeca = malloc(sizeof(No));
    cabeca->prox = NULL;
    return (cabeca);
}

No* gerarListaEncadeada(){
    No* cabeca = inicializarALista();
    No* anterior = cabeca;
    //anterior -> prox = NULL;
    No* Item;
    for(int i=0; i<100; i++){
        Item = malloc(sizeof(No));
        Item -> info = i;
        Item ->prox = NULL;
        anterior -> prox = Item;
        anterior = Item;
    }
    return(cabeca);
}
void removeTodasAsOcorrencias(No *cabeca, int item){
     No *anterior, *presente;
    anterior = cabeca;
    presente = cabeca->prox;
    while(presente || presente -> info == item){
        if(presente -> info == item){
            anterior->prox = presente->prox;
            free(presente);
        }
        else{
            anterior = presente;
            presente = presente->prox;
        }
        
    }
    
}

void main(){
    No* ListaEncadeada = gerarListaEncadeada();
    imprime(ListaEncadeada);
    //lista gerada
    removeItemBuscando(ListaEncadeada, 95);
    imprime(ListaEncadeada);

    //removeTodasAsOcorrencias(ListaEncadeada, 92);
    //imprime(ListaEncadeada);


    }