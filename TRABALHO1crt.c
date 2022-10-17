#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TRABALHO1.h"

void limpaBuffer(){
	while(getchar() != '\n');
}

void trocar(aluno *a, aluno *b){
	aluno aux = *a;
	*a = *b;
	*b = aux;
}

int menorElempron(aluno *vetorAlunos, int nAlunos, int primeiro){
	
	int i, menor = primeiro;
	for(i = primeiro + 1; i < nAlunos; i++){
		if(vetorAlunos[i].prontuario < vetorAlunos[menor].prontuario){
			menor = i;
		}
	}
	return menor;
}

int ordSelecpron(aluno *vetorAlunos, int nAlunos){
	int i, menor;
	for(i=0; i<nAlunos; i++){
		menor = menorElempron(vetorAlunos, nAlunos, i);
		trocar(&vetorAlunos[i], &vetorAlunos[menor]);
	}
}

void cadastraAluno(aluno *vetorAlunos, int *posicao){
	int bole;
    printf("Digite o prontuario do aluno:");
    scanf("%d", &vetorAlunos[*posicao].prontuario);
    limpaBuffer();
    printf("Digite o Nome do aluno:");
	//ERRO
    //scanf("%s", &vetorAlunos[*posicao].nome);
	scanf("%s", vetorAlunos[*posicao].nome);
    limpaBuffer();
    printf("Digite o sobrenome do aluno:");
    //ERRO
	//scanf("%s", &vetorAlunos[*posicao].sobrenome);
	scanf("%s", vetorAlunos[*posicao].sobrenome);
    limpaBuffer();
    printf("Data de nascimento\n");
    bole = 0;
    do{
    	printf("Digite o dia:");
    	scanf("%d", &vetorAlunos[*posicao].datadenascimento.dia);
	    bole = 1;
	    if(vetorAlunos[*posicao].datadenascimento.dia < 1 || vetorAlunos[*posicao].datadenascimento.dia > 31){
	    	printf("Dia de nascimento invalido!\n");
			bole = 0;
		}
	}while(bole == 0);	
    limpaBuffer();
    bole = 0;
    do{
    	printf("Digite o mes:");
    	scanf("%d", &vetorAlunos[*posicao].datadenascimento.mes);
	    bole = 1;
	    if(vetorAlunos[*posicao].datadenascimento.mes < 1 || vetorAlunos[*posicao].datadenascimento.mes > 12){
	    	printf("Mes de nascimento invalido!\n");
			bole = 0;
		}
	}while(bole == 0);
    limpaBuffer(); 
    bole = 0;
    do{
    	printf("Digite o ano:");
    	scanf("%d", &vetorAlunos[*posicao].datadenascimento.ano);
	    bole = 1;
	    if(vetorAlunos[*posicao].datadenascimento.ano < 1900 || vetorAlunos[*posicao].datadenascimento.ano > 2022){
	    	printf("Ano de nascimento invalido!\n");
			bole = 0;
		}
	}while(bole == 0);
    limpaBuffer(); 
    printf("Digite o curso do aluno:");
    scanf("%s", vetorAlunos[*posicao].curso);
    limpaBuffer();
    (*posicao)++;    
}

void salvaArquivo(aluno *vetorAlunos, int nAlunos){
    FILE *fp;
    int i, result;

    fp = fopen("alunos.dat", "wb");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return;
    }

    for (i = 0; i < nAlunos; i++)
    {
        result = fwrite(&vetorAlunos[i], sizeof(aluno), 1, fp);
        if (result != 1)
        {
            printf("Erro de escrita no arquivo. \n");
        }
    }
    fclose(fp);
}

int leArquivo(aluno *vetorAlunos){
    FILE *fp;
    int i, result;
    fp = fopen("alunos.dat", "rb");
    if (fp == NULL)
    {
        printf("Erro na abertura do arquivo.\n");
        return -1;
    }
    for (i = 0; i<MAXAL; i++) {
        result = fread(&vetorAlunos[i], sizeof(aluno), 1, fp);
        if (result != 1) {
            if (feof(fp)) {
                return i;
            } else {
                printf("Erro na leitura do arquivo.\n");
                return -1;
            }
        }
    }
}

int getMenu() {
    int i;
    printf ("===MENU INICIAL===\n0 - Sair\n1 - Cadastra\n2 - Imprime\n3 - Salva\n4 - Carrega\n5 - Busca e remo��o\n6-Ordena��oDigite a opcao: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}

void imprimeAlunos(aluno *vetorAlunos, int nAlunos) {
    int i;
    for (i=0; i<nAlunos; i++) {
        printf("Prontuario: %d\n", vetorAlunos[i].prontuario);
        printf("Nome completo: %s %s\n", vetorAlunos[i].nome, vetorAlunos[i].sobrenome);
        printf("Data de nascimento: %d/%d/%d \n", vetorAlunos[i].datadenascimento.dia, vetorAlunos[i].datadenascimento.mes, vetorAlunos[i].datadenascimento.ano);
        printf("Curso: %s\n", vetorAlunos[i].curso);
    }
}

void imprimeAluno (aluno *vetorAlunos, int nAluno) {
    printf("Prontuario: %d\n", vetorAlunos[nAluno].prontuario);
    printf("Nome completo: %s %s\n", vetorAlunos[nAluno].nome, vetorAlunos[nAluno].sobrenome);
    printf("Data de nascimento: %d/%d/%d \n", vetorAlunos[nAluno].datadenascimento.dia, vetorAlunos[nAluno].datadenascimento.mes, vetorAlunos[nAluno].datadenascimento.ano);
    printf("Curso: %s\n\n", vetorAlunos[nAluno].curso);
    
}

void buscaNomeSobrenome (aluno *vetorAlunos, int nAlunos){
	int i, v;
	char nome[TAMNOME];
	printf("Digite o nome a ser buscado: ");
	scanf("%s", nome);
	limpaBuffer();
	char sobrenome[TAMSOBRENOME];
	printf("Digite o sobrenome a ser buscado: ");
	scanf("%s", sobrenome);
	limpaBuffer();
	for (i=0; i<nAlunos; i++){
		//n�o encontra o certo
		/*char nomComp[TAMTOT];
		strcpy(nomComp, "");
		strcat(nomComp, vetorAlunos[i].nome);
		strcat(nomComp, " ");
		strcat(nomComp, vetorAlunos[i].sobrenome);
		printf(nomComp);
		int nome1 = strlen(nomComp);
		int nome2 = strlen(nomecompleto);
		if ( nome1  == nome2 ){
			if (strcmp(nomComp, nomecompleto) == 0){
				imprimeAluno(vetorAlunos, i);
			}
		}*/
		int snome1 = strlen(vetorAlunos[i].sobrenome);
		int snome2 = strlen(sobrenome);
		if ( snome1  == snome2 ){
			if (strcmp(vetorAlunos[i].sobrenome, sobrenome) == 0){
				int nome1 = strlen(vetorAlunos[i].nome);
				int nome2 = strlen(nome);
				if ( nome1  == nome2 ){
					if (strcmp(vetorAlunos[i].nome, nome) == 0){
						imprimeAluno(vetorAlunos, i);
						v = i;
					}
				}
			}
		}
	}
	mainRemove(vetorAlunos, nAlunos, v);
}

void buscaNome (aluno *vetorAlunos, int nAlunos){
	char nome[TAMNOME];
	int i, v;
	printf("Digite o nome a ser buscado: ");
	scanf("%s", nome);
	limpaBuffer();
	for (i=0; i<nAlunos; i++){
		int nome1 = strlen(vetorAlunos[i].nome);
		int nome2 = strlen(nome);
		if ( nome1  == nome2 ){
			if (strcmp(vetorAlunos[i].nome, nome) == 0){
				imprimeAluno(vetorAlunos, i);
				v = i;
			}
		}
	}
	mainRemove(vetorAlunos, nAlunos, v);
	
}

void buscaSobrenome (aluno *vetorAlunos, int nAlunos){
	char sobrenome[TAMSOBRENOME];
	int i, v;
	printf("Digite o sobrenome a ser buscado: ");
	scanf("%s", sobrenome);
	limpaBuffer();
	for (i=0; i<nAlunos; i++){
		int nome1 = strlen(vetorAlunos[i].sobrenome);
		int nome2 = strlen(sobrenome);
		if ( nome1  == nome2 ){
			if (strcmp(vetorAlunos[i].sobrenome, sobrenome) == 0){
				imprimeAluno(vetorAlunos, i);
				v = i;
			}
		}
		
	}
	mainRemove(vetorAlunos, nAlunos, v);
}

void buscaCurso (aluno *vetorAlunos, int nAlunos){
	char curso[TAMCURSO];
	int i, v;
	printf("Digite o curso (sigla) a ser buscado: ");
	scanf("%s", curso);
	limpaBuffer();
	for (i=0; i<nAlunos; i++){
		if (strcmp(vetorAlunos[i].curso, curso) == 0){
			imprimeAluno(vetorAlunos, i);
			v = i;
		}
	}
	mainRemove(vetorAlunos, nAlunos, v);
	
}

void buscaPront(aluno *vetorAlunos, int nAlunos){
	int prontuario, i, v;
	printf("Digite o prontuario a ser buscado: ");
	scanf("%d", &prontuario);
	limpaBuffer();
	for(i=0; i<nAlunos; i++){
		if(vetorAlunos[i].prontuario == prontuario){
			imprimeAluno(vetorAlunos, i);
			v = i;
			
		}
	}
	mainRemove(vetorAlunos, nAlunos, v);
}

void buscaDn(aluno *vetorAlunos, int nAlunos){
	int dia, mes, ano, i, v;
	printf("Digite o dia a ser buscado: ");
	scanf("%d", &dia);
	limpaBuffer();
	printf("Digite o mes a ser buscado: ");
	scanf("%d", &mes);
	limpaBuffer();
	printf("Digite o ano a ser buscado: ");
	scanf("%d", &ano);
	limpaBuffer();
	for(i=0; i<nAlunos; i++){
		if(vetorAlunos[i].datadenascimento.ano == ano){
			if(vetorAlunos[i].datadenascimento.mes == mes){
				if(vetorAlunos[i].datadenascimento.dia == dia){
					imprimeAluno(vetorAlunos, i);
					v = i;
				}	
			}	
		}
	}
	mainRemove(vetorAlunos, nAlunos, v);
}

void ordenaProntu(aluno *vetorAlunos, int nAlunos){
	ordSelecpron(vetorAlunos, nAlunos);
	imprimeAlunos(vetorAlunos, nAlunos);
	
}

void remover(aluno *vetorAlunos, int nAlunos, int item){
	int i;
	for(i = item; i < nAlunos-1; i++){
		vetorAlunos[i] = vetorAlunos[i + 1];
	}
	printf("REMOVIDO COM SUCESSO\n");
}

int getRemover(){
	int i;
	printf("1 - REMOVER \n0 - CANCELAR\n");
	scanf("%d", &i);
	limpaBuffer();
	return i;
}

int mainRemove(aluno *alunos, int numAlunos, int item){
	int menuRemove;
	menuRemove = getRemover();
	switch(menuRemove){
		case 1:remover(alunos, numAlunos, item);
				break;
	}
}

int getMenuBusca() {
    int i;
    printf ("===MENU DE BUSCA===\n0 - Sair\n1 - Nome e Sobrenome \n2 - Nome\n3 - Sobrenome\n4 - Prontuario\n5 - Data de Nascimento\n6 - Curso\nDigite a opcao: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}

int getMenuordenacao() {
    int i;
    printf ("===MENU DE ORDENA��O===\n0 - Sair\n1 - Nome e Sobrenome \n2 - Sobrenome e Nome\n3 - Data de Nascimento\n4 - Prontuario\n5 - Curso\nDigite a opcao: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}

int mainBusca(aluno *alunos, int numAlunos){
	int menuBusca;
	do{
		menuBusca = getMenuBusca();
		switch(menuBusca){
			case 1:printf("===BUSCA NOME E SOBRENOME===\n"); //ok
					buscaNomeSobrenome(alunos, numAlunos);
					break;
			case 2:printf("===BUSCA NOME===\n");//ok
					buscaNome(alunos, numAlunos);
					break;
			case 3:printf("===BUSCA SOBRENOME===\n");//ok
					buscaSobrenome(alunos, numAlunos);
					break;
			case 4:printf("===BUSCA PRONTUARIO===\n");//ok
					buscaPront(alunos, numAlunos);
					break;
			case 5:printf("===BUSCA DATA DE NASCIMENTO===\n");//ok
					buscaDn(alunos, numAlunos);
					break;	
			case 6:printf("===BUSCA CURSO===\n");//ok
					buscaCurso(alunos, numAlunos);
					break;			
		}
	}while(menuBusca != 0);
}

int mainOrdenada(aluno *alunos, int numAlunos){
	int menuOrdenacao;
	do{
		menuOrdenacao = getMenuordenacao();
		switch(menuOrdenacao){
			case 1:printf("===ORDENAR POR NOME E SOBRENOME NT\n");
					
					break;
			case 2:printf("===ORDENAR POR SOBRENOME E NOME NT\n");
					
					break;
			case 3:printf("===ORDENAR POR DATA DE NASCIMENTO NT\n");
					
					break;
			case 4:printf("===ORDENAR POR PRONTUARIO===\n"); //okkkk
					ordenaProntu(alunos, numAlunos);
					break;
			case 5:printf("===ORDENAR POR CURSO NT\n");
					
					break;
		}
		
	}while(menuOrdenacao != 0);
}

int main(){
    aluno alunos[MAXAL];
    int numAlunos = 0;
    int menu;
    do{
        menu = getMenu();
        switch(menu) {
            case 1: cadastraAluno(alunos, &numAlunos);//ok
                    break;
            case 2: imprimeAlunos(alunos, numAlunos);
                    break;
            case 3: salvaArquivo(alunos, numAlunos);
                    break;
            case 4: numAlunos = leArquivo(alunos);
                    break;
            case 5: mainBusca(alunos, numAlunos);//ok com remo��o b.o.
            		break;
            case 6: mainOrdenada(alunos, numAlunos);
        }
    } while (menu != 0);
}

