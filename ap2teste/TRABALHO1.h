#ifndef _TRABALHO1_H
#define _TRABALHO1_H

#define TAMNOME 50
#define TAMSOBRENOME 50
#define TAMTOT 100
#define TAMCURSO 4
#define MAXAL 1000


typedef struct data{
	int dia;
	int mes;
	int ano;
}data;

typedef struct registro{
	char nome[TAMNOME];
	char sobrenome[TAMSOBRENOME];
	data datadenascimento;
	int prontuario;
	char curso[4];
}aluno;


#endif
