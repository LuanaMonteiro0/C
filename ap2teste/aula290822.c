//estruturas com struct
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXAL 3

typedef struct data{
	int dia;
	int mes;
	int ano;
} Data;

typedef struct ficha_aluno{
	char nome[50];
	Data data;
	int RA;
} Aluno;
//typedef struct ficha _aluno Aluno; 
//renomeia o struct ficha_aluno para apenas Aluno

void imprime_data(Data data){
	printf("%d/%d/%d", data.dia, data.mes, data.ano);
}

Aluno preencheAluno(char nome[50], Data data, int RA){
	Aluno aluno;
	strcpy(aluno.nome, nome);
	aluno.data = data;
	aluno. RA = RA;
	return aluno;
}

void imprime_aluno(Aluno aluno){
	printf("Nome: %s\nRA: %d\n", aluno.nome, aluno.RA);
	printf("data de nascimento: ");
	imprime_data(aluno.data);
	printf("\n");
}

Data preenche_data(int dia, int mes, int ano){
	Data aux;
	aux.dia = dia;
	aux.mes = mes;
	aux.ano = ano;
	return aux;
}



/*void recebe_aluno(Aluno aluno){
	printf("Digite o nome:\n ");
	scanf("%s", aluno.nome);
	printf("Digite o RA:\n ");
	scanf("%d", aluno.RA);
	printf("Digite a idade: \n");
	scanf("%d", aluno.idade);
}*/

int comparaData(Data data1, Data data2){
	if (data1.ano == data2.ano){
		if (data1.mes == data2.mes){
			if (data1.dia == data2.dia){
				return 0;
			}else{
				if (data1.dia < data2.dia){
					return -1;
				}else{
					return 1;
				}
			}
		}else{
			if (data1.mes == data2.mes){
				if(data1.mes < data2.mes){
					return -1;
				}else{
					return 1;
				}
			}
		}
	}else{
		if (data1.ano < data2.ano){
			return -1;
		}else{
			return 1;
		}
	}
}

Aluno le_dados_aluno(i){
	char nome[50];
	int dia, mes, ano, RA;
	printf("Nome do aluno %d: ", i+1);
	fgets(nome, 50, stdin);
	nome[strlen(nome)-1] = 0;
	printf("RA do aluno %d: ", i+1);
	scanf("%d", &RA);
	getchar();
	printf("Data de nascimento de aluno %d: ", i+1);
	scanf("%d/%d/%d", &dia, &mes, &ano);
	while(getchar() != '\n');
	return preencheAluno(nome, preenche_data(dia, mes, ano), RA);
}

int main(){
	Aluno aluno_teste;
	aluno_teste.data = preenche_data(10,10,2010);
	aluno_teste.RA = 123456;
	strcpy(aluno_teste.nome, "Jose da Silva");
	imprime_aluno(aluno_teste);
	Data data = preenche_data(10,12,2020);
	imprime_data(data);
	printf("\n\n\n\n");
	
	Aluno alunos[MAXAL];
	int i;
	int dia, mes, ano;
	
	for(i=0; i<MAXAL; i++){
		alunos[i] = le_dados_aluno(i);
	}
	for(i=0; i<MAXAL; i++){
	printf("Aluno %d:\n", i+1);
	imprime_aluno(alunos[i]);
	printf("\n");
	}
	printf("Digite a data de corte:");
    scanf("%d/%d/%d", &dia, &mes, &ano);
    while(getchar() != '\n');
    for (i=0; i<MAXAL; i++) {
        if(comparaData(alunos[i].data,
                       preenche_data(dia,mes,ano)) == 1) {
            printf("\n");
            printf("Aluno %d:\n", i+1);
            imprime_aluno(alunos[i]);
		}
	}
	return 0;
}

