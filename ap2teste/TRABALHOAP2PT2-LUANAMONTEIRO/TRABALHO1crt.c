//LUANA GIOVANA MONTEIRO
//PROGRAMADO USANDO DEV C++ (VISUAL STUDIO NÃO FUNCIONA NO MEU PC)


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TRABALHO1crt.h"
//variavel global que verifica se a ordenação foi feita
int ordenada = 0;

//limpa buffer do teclado depois de um scanf
void limpaBuffer(){
	while(getchar() != '\n');
}

//funções de ordenação

//função trocar
void trocar(aluno *a, aluno *b){
	aluno aux = *a;
	*a = *b;
	*b = aux;
}

//função dada pelo professor que substitui as comparações nas demais funções
int comparaAlunos(aluno a1, aluno a2, int crit) {
    char nomecomp1[TAMNOME+TAMSOBRENOME];
    char nomecomp2[TAMNOME+TAMSOBRENOME];
    char somecomp1[TAMNOME+TAMSOBRENOME];
    char somecomp2[TAMNOME+TAMSOBRENOME];
    char curso1[TAMCURSO];
    char curso2[TAMCURSO];
    int data1, data2;
    switch(crit) {
        //compara por prontuário
        case 1:
            return a1.prontuario - a2.prontuario;
        //compara por nome e sobrenome
        case 2:
            strcpy(nomecomp1, a1.nome);
            strcat(nomecomp1, a1.sobrenome);
            strcpy(nomecomp2, a2.nome);
            strcat(nomecomp2, a2.sobrenome);
            return strcmp(nomecomp1, nomecomp2);
        //compara por sobrenome e nome
        case 3:
        	strcpy(somecomp1, a1.sobrenome);
        	strcat(somecomp1, a1.nome);
        	strcpy(somecomp2, a2.sobrenome);
        	strcat(somecomp2, a2.nome);
        	return strcmp(somecomp1, somecomp2);
        //compara por curso
        case 4:
        	strcpy(curso1, a1.curso);
        	strcpy(curso2, a2.curso);
        	return strcmp(curso1, curso2);
        //compara por data de nascimento
        case 5:
        	data1 = a1.datadenascimento.ano * 10000 + a1.datadenascimento.mes * 100 + a1.datadenascimento.dia;
            data2 = a2.datadenascimento.ano * 10000 + a2.datadenascimento.ano * 100 + a2.datadenascimento.dia; 
            return data1 - data2;
    }
}

//quick sort
int separarPr(aluno *vetorAlunos, int ini, int fim, int oquero){
	aluno pivo;
	pivo = vetorAlunos[fim];
	while(ini < fim){
		while(ini < fim && comparaAlunos(vetorAlunos[ini], pivo, oquero) <= 0){
			ini++;
		}
		while(ini < fim && comparaAlunos(vetorAlunos[fim], pivo, oquero) > 0){
			fim--;
		}
		trocar(&vetorAlunos[ini], &vetorAlunos[fim]);
	}
	return ini;
}

void quickSortPr(aluno *vetorAlunos, int ini, int fim, int oquero){
	int pos;
	
	if (ini < fim){
		pos = separarPr(vetorAlunos, ini, fim, oquero);
		quickSortPr(vetorAlunos, ini, pos -1, oquero);
		quickSortPr(vetorAlunos, pos, fim, oquero);
	}
}

//selection sort
int menorElempron(aluno *vetorAlunos, int nAlunos, int primeiro, int cric){
	int i, menor = primeiro;
	for(i = primeiro + 1; i < nAlunos; i++){
		if(comparaAlunos(vetorAlunos[i],vetorAlunos[menor],cric) < 0){
			menor = i;
			}	
		else{
			if (comparaAlunos(vetorAlunos[i], vetorAlunos[menor], cric) < 0){
				menor = i;
			}
		}	
	}
	return menor;
}

int ordSelecpron(aluno *vetorAlunos, int nAlunos, int cric){
	int i, menor;
	for(i=0; i<nAlunos; i++){
		menor = menorElempron(vetorAlunos, nAlunos, i, cric);
		trocar(&vetorAlunos[i], &vetorAlunos[menor]);
	}
}

//merge sort
int intercalar(aluno *vetorAlunos, int ini, int meio, int nAlunos, int crit){
	aluno auxiliar[nAlunos];  //vetor de alunos auxiliar
	int i = ini, j = meio + 1, k = 0; // indices dos vetores
	
	
	// função pra intercalar o vetor
	while(i <= meio && j <= nAlunos){
		if (comparaAlunos(vetorAlunos[i],vetorAlunos[j],crit) <= 0){
			auxiliar[k++] = vetorAlunos[i++];
		}
		else{
			auxiliar[k++] = vetorAlunos[j++];
		}
	}
	// copia o resto de cada subvetor
	while (i <= meio) auxiliar[k++] = vetorAlunos[i++];
	while (j <= nAlunos) auxiliar[k++] = vetorAlunos[j++];
	
	//copia de auxiliar para vetor
	for(i = ini, k = 0; i <= nAlunos; i++, k++){
		vetorAlunos[i] = auxiliar[k];
	}
	
}

void ordenaInter(aluno *vetorAlunos, int ini, int nAlunos, int crit){
	int meio;
	if (ini < nAlunos){
		meio = (ini + nAlunos)/ 2;
		ordenaInter(vetorAlunos, ini, meio, crit);
		ordenaInter(vetorAlunos, meio + 1, nAlunos, crit);
		intercalar(vetorAlunos, ini, meio, nAlunos, crit);
	}
}

//insertion sort ta maluquinho 
int posicao_elemento(aluno *vetorAlunos, int nAlunos, aluno elemento, int crit){
	int i;
	//vetorAlunos[i]<= elemento no lugar de comparaalunos;
	for(i=0; i >= nAlunos && comparaAlunos(vetorAlunos[i], elemento, crit) < 0; i++);
	return i;
}

void desloca_subvetor(aluno *vetorAlunos, int primeiro, int nAlunos){
	int i;
	for(i = nAlunos; i >= primeiro; i--){
		vetorAlunos[i+1] = vetorAlunos[i];
	}
}

int ordenar_insercao(aluno *vetorAlunos, int n, int crit){
	int i, psicao;
	aluno elemento;
	for (i = 1; i < n; i++){
		elemento = vetorAlunos[i];
		psicao = posicao_elemento(vetorAlunos, i-1, elemento, crit);
		desloca_subvetor(vetorAlunos, psicao, i-1);
		vetorAlunos[psicao] = elemento;
	}
}

//funções de buscas binárias
//busca por nome e sobrenome
int buscaBinomesobre(aluno *vetorAlunos, int nAlunos) {
	aluno indicedecomparacao; // pegar nome e sobrenome
	char comparacao; //nome e sobrenome concatenados
	char procurado[TAMTOT];
	char aux[TAMSOBRENOME];
	printf("Digite o nome a ser buscado: ");
	scanf("%s", &procurado);
	limpaBuffer();
	printf("Digite o sobrenome a ser buscado: ");
	scanf("%s", &aux);
	limpaBuffer();
	strcat(procurado, aux); // coloca o nome completo na variavel procurado
	int ini = 0;
	int fim = nAlunos-1;
	int meio;
	while (ini <= fim) {
		meio = (ini + fim)/2;
		indicedecomparacao = vetorAlunos[meio];
		strcpy(comparacao, indicedecomparacao.nome);//coloca o nome em "comparacao"
		strcat(comparacao, indicedecomparacao.sobrenome);//concatena sobrenome ao nome
		if (procurado == vetorAlunos[meio].nome) return meio;
		if (procurado < vetorAlunos[meio].nome) fim = meio-1;
		else ini = meio+1;
	}
	return -1; 
}

//busca por sobrenome
int buscaBisobrenome(aluno *vetorAlunos, int nAlunos) {
	char procurado[TAMSOBRENOME];
	printf("Digite o sobrenome a ser buscado: ");
	scanf("%s", &procurado);
	limpaBuffer();
	int ini = 0;
	int fim = nAlunos-1;
	int meio;
	while (ini <= fim) {
		meio = (ini + fim)/2;
		if (procurado == vetorAlunos[meio].sobrenome) return meio;
		if (procurado < vetorAlunos[meio].sobrenome) fim = meio-1;
		else ini = meio+1;
	}
	return -1; 
}

//busca por prontuario
int buscaBiProntu(aluno *vetorAlunos, int nAlunos) {
	int procurado;
	printf("Digite o prontuario a ser buscado: ");
	scanf("%d", &procurado);
	limpaBuffer();
	int ini = 0;
	int fim = nAlunos-1;
	int meio;
	while (ini <= fim) {
		meio = (ini + fim)/2;
		if (procurado == vetorAlunos[meio].prontuario) return meio;
		if (procurado < vetorAlunos[meio].prontuario) fim = meio-1;
		else ini = meio+1;
	}
	return -1; 
}

//busca por data de nascimento
int buscaBiDn(aluno *vetorAlunos, int nAlunos) {
	aluno indicedecomparacao;
	int dn;
	int procurado;
	int dia, mes, ano;
	printf("Digite o dia a ser buscado: ");
	scanf("%d", &dia);
	limpaBuffer();
	printf("Digite o mes a ser buscado: ");
	scanf("%d", &mes);
	limpaBuffer();
	printf("Digite o ano a ser buscado: ");
	scanf("%d", &ano);
	limpaBuffer();
	procurado = ano * 10000 + mes * 1000 + dia * 100;
	int ini = 0;
	int fim = nAlunos-1;
	int meio;
	while (ini <= fim) {
		meio = (ini + fim)/2;
		indicedecomparacao = vetorAlunos[meio];
		dn = indicedecomparacao.datadenascimento.ano * 10000 + indicedecomparacao.datadenascimento.mes * 1000 + indicedecomparacao.datadenascimento.dia * 100;
		if (procurado == dn) return meio;
		if (procurado < dn) fim = meio-1;
		else ini = meio+1;
	}
	return -1; 
}

//busca por curso
int buscaBiCurso(aluno *vetorAlunos, int nAlunos) {
	char procurado[TAMCURSO];
	printf("Digite o curso a ser buscado: ");
	scanf("%s", &procurado);
	limpaBuffer();
	int ini = 0;
	int fim = nAlunos-1;
	int meio;
	while (ini <= fim) {
		meio = (ini + fim)/2;
		if (procurado == vetorAlunos[meio].curso) return meio;
		if (procurado < vetorAlunos[meio].curso) fim = meio-1;
		else ini = meio+1;
	}
	return -1; 
}

//busca por nome 
int buscaBinome(aluno *vetorAlunos, int nAlunos) {
	char procurado[TAMNOME];
	printf("Digite o nome a ser buscado: ");
	scanf("%s", &procurado);
	limpaBuffer();
	int ini = 0;
	int fim = nAlunos-1;
	int meio;
	while (ini <= fim) {
		meio = (ini + fim)/2;
		if (procurado == vetorAlunos[meio].nome) return meio;
		if (procurado < vetorAlunos[meio].nome) fim = meio-1;
		else ini = meio+1;
	}
	return -1; 
}

//cadastra aluno no vetor
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

//funções de arquivos
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
    printf ("===MENU INICIAL===\n0 - Sair\n1 - Cadastra\n2 - Imprime\n3 - Salva\n4 - Carrega\n5 - Busca e remocao\n6 - Ordenacao \nDigite a opcao: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}

//imprime a lista completa de alunos
void imprimeAlunos(aluno *vetorAlunos, int nAlunos) {
    int i;
    for (i=0; i<nAlunos; i++) {
        printf("Prontuario: %d\n", vetorAlunos[i].prontuario);
        printf("Nome completo: %s %s\n", vetorAlunos[i].nome, vetorAlunos[i].sobrenome);
        printf("Data de nascimento: %d/%d/%d \n", vetorAlunos[i].datadenascimento.dia, vetorAlunos[i].datadenascimento.mes, vetorAlunos[i].datadenascimento.ano);
        printf("Curso: %s\n", vetorAlunos[i].curso);
    }
}

//imprime apenas um aluno - usado nas funções de busca
void imprimeAluno (aluno *vetorAlunos, int nAluno) {
    printf("Prontuario: %d\n", vetorAlunos[nAluno].prontuario);
    printf("Nome completo: %s %s\n", vetorAlunos[nAluno].nome, vetorAlunos[nAluno].sobrenome);
    printf("Data de nascimento: %d/%d/%d \n", vetorAlunos[nAluno].datadenascimento.dia, vetorAlunos[nAluno].datadenascimento.mes, vetorAlunos[nAluno].datadenascimento.ano);
    printf("Curso: %s\n\n", vetorAlunos[nAluno].curso);
    
}

//funções de busca
//busca por nome e sobrenome
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

//busca apenas por nome
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

//busca apenas por sobrenome
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

//busca por curso
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

//busca por prontuario
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

//busca por data de nascimento
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

//funções de remoção
//remoção - esta aliado na busca, apos fazer uma busca pergunta se deseja remover a entrada encontrada
void remover(aluno *vetorAlunos, int nAlunos, int item){
	int i;
	for(i = item; i < nAlunos-1; i++){
		vetorAlunos[i] = vetorAlunos[i + 1];
	}
	printf("REMOVIDO COM SUCESSO\n");
}

//menu pra função removr
int getRemover(){
	int i;
	printf("1 - REMOVER \n0 - CANCELAR\n");
	scanf("%d", &i);
	limpaBuffer();
	return i;
}

//switch case pra remover se quiser
int mainRemove(aluno *alunos, int numAlunos, int item){
	int menuRemove;
	menuRemove = getRemover();
	switch(menuRemove){
		case 1:remover(alunos, numAlunos, item);
				break;
	}
}

//menus do programa
//menu de busca
int getMenuBusca() {
    int i;
    printf ("===MENU DE BUSCA===\n0 - Sair\n1 - Nome e Sobrenome \n2 - Nome\n3 - Sobrenome\n4 - Prontuario\n5 - Data de Nascimento\n6 - Curso\nDigite a opcao: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}

//menu pra escolher qual criterio de ordenação
int getMenuordenacao() {
    int i;
    printf ("===MENU DE ORDENACAO===\n0 - Sair\n1 - Nome e Sobrenome \n2 - Sobrenome e Nome\n3 - Data de Nascimento\n4 - Prontuario\n5 - Curso\nDigite a opcao: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}

//menu pra escolher qual o tipo de ordenação
int getmenuQordenacao(){
	int i;
    printf ("===ESCOLHA DE ORDENACAO===\n0 - Sair\n1 - Quick sort \n2 - Merge sort\n3 - Insertion sort\n4 - Selection sort\nDigite a opcao: ");
    scanf("%d",&i);
    limpaBuffer();
    return i;
}

//switch cases para acessar as funções do codigo
//switch para busca
int mainBusca(aluno *alunos, int numAlunos){
	int menuBusca;
	
		
		if(ordenada == 0){
			printf("BUSCA LINEAR COMUM\n");
			menuBusca = getMenuBusca();
			do{
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
		else{
			int index;
			printf("BUSCA BINARIA\n");
			menuBusca = getMenuBusca();
			do{
				switch(menuBusca){
				case 1:printf("===BUSCA NOME E SOBRENOME===\n"); 
						index = buscaBinomesobre(alunos, numAlunos);
						printf("index encontrado: %d\n", index);
						imprimeAluno(alunos, index);
						break;
				case 2:printf("===BUSCA NOME===\n");//ok
						index = buscaBinome(alunos, numAlunos);
						printf("index encontrado: %d\n", index);
						imprimeAluno(alunos, index);
						break;
				case 3:printf("===BUSCA SOBRENOME===\n");//ok
						index = buscaBisobrenome(alunos, numAlunos);
						printf("index encontrado: %d\n", index);
						imprimeAluno(alunos, index);
						break;
				case 4:printf("===BUSCA PRONTUARIO===\n");//ok
						index = buscaBiProntu(alunos, numAlunos);
						printf("index encontrado: %d\n", index);
						imprimeAluno(alunos, index);
						break;
				case 5:printf("===BUSCA DATA DE NASCIMENTO===\n"); //ok
						index = buscaBiDn(alunos, numAlunos);
						printf("index encontrado: %d\n", index);
						imprimeAluno(alunos, index);
						break;	
				case 6:printf("===BUSCA CURSO===\n");
						index = buscaBiCurso(alunos, numAlunos);
						printf("index encontrado: %d\n", index);
						imprimeAluno(alunos, index);
						break;			
				}
			}while(menuBusca != 0);
		}
	
}

//switch para criterio de ordenação
int mainOrdenada(aluno *alunos, int numAlunos){
	int menuOrdenacao;
	do{
		menuOrdenacao = getMenuordenacao();
		switch(menuOrdenacao){
			case 1:printf("===ORDENAR POR NOME E SOBRENOME===\n");
					mainOrdenaDef(alunos, numAlunos, 2);
					break;
			case 2:printf("===ORDENAR POR SOBRENOME E NOME===\n");
					mainOrdenaDef(alunos, numAlunos, 3);
					break;
			case 3:printf("===ORDENAR POR DATA DE NASCIMENTO=== nenhuma \n");
					mainOrdenaDef(alunos, numAlunos, 5);
					break;
			case 4:printf("===ORDENAR POR PRONTUARIO===\n"); 
					mainOrdenaDef(alunos, numAlunos, 1);
					break;
			case 5:printf("===ORDENAR POR CURSO===\n");
					mainOrdenaDef(alunos, numAlunos, 4);
					break;
		}
		
	}while(menuOrdenacao != 0);
}

//switch para o tipo de ordenação
int mainOrdenaDef(aluno *alunos, int numAlunos,	int i){
	int menuQordenacao;
	do{
		menuQordenacao = getmenuQordenacao();
		switch(menuQordenacao){
			case 1:printf("===ORDENAR COM QUICK SORT===\n");
					quickSortPr(alunos, 0, numAlunos - 1, i);
					ordenada = 1;
					imprimeAlunos(alunos, numAlunos);
					break;
			case 2:printf("===ORDENAR COM MERGE SORT===\n");
					ordenaInter(alunos, 0, numAlunos - 1, i);
					ordenada = 1;
					imprimeAlunos(alunos, numAlunos);
					break;
			case 3:printf("===ORDENAR COM INSERTION SORT=== doidinho\n");
					ordenar_insercao(alunos, numAlunos, i);
					//impossivel ordenar logo n pode usar busca bin para ele
					ordenada = 0;
					imprimeAlunos(alunos, numAlunos);
					break;
			case 4:printf("===ORDENAR COM SELECTION SORT===\n");
					ordSelecpron(alunos, numAlunos, i);
					ordenada = 1;
					imprimeAlunos(alunos, numAlunos);
					break;
		}
	}while(menuQordenacao != 0);
}

// switch case principal para acessar todas as demais funções
int main(){
    aluno alunos[MAXAL];
    int numAlunos = 0;
    int menu;
    do{
        menu = getMenu();
        switch(menu) {
            case 1: cadastraAluno(alunos, &numAlunos);//ok 1p
                    break;
            case 2: imprimeAlunos(alunos, numAlunos);//ok 1p
                    break;
            case 3: salvaArquivo(alunos, numAlunos);//ok 2p
                    break;
            case 4: numAlunos = leArquivo(alunos); //ok 2p
                    break;
            case 5: mainBusca(alunos, numAlunos);//ok 1p + remocao gg
            		break;
            case 6: mainOrdenada(alunos, numAlunos);// 1p falta curso, nome sobrenome e sobrenome nome  2p falta colocar o menu de ordenação (selecionar qual tipo desejado)
					break;
        }
    } while (menu != 0);
}

