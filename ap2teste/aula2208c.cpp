#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){/*
	int a;
	//manipulação de strings em c
	char strig[4] = "ana";
	char stringd[] = "ana";
	char stringt[4] = {'a', 'n', 'a', 0};	// caso declarar assim não pode esquecer o 0 se não a leitura não vai parar
	printf ("O nome possui %d letras", strlen(strig))
	char vetr[15];
	char vetor[] = "marcio";
	strcpy(vetr, vetor);
	*/
	//ex1 dia2208
	//HH:MM:SS
	char horaum[9] = "10:21:55";
	char horadois[9] = "15:58:22";
	char horum[3];
	char hordois [3];
	char minum [3];
	char mindois [3];
	char segum [3];
	char segdois [3];
	horum[0] = horaum[0];
	horum[1] = horaum[1];
	horum[2] = 0; 
	hordois[0] = horadois[0];
	hordois[1] = horadois[1];
	hordois[2] = 0; 
	minum[0] = horaum[3];
	minum[1] = horaum[4];
	minum[2] = 0; 
	mindois[0] = horadois[3];
	mindois[1] = horadois[4];
	mindois[2] = 0; 
	segum[0] = horaum[6];
	segum[1] = horaum[7];
	segum[2] = 0; 
	segdois[0] = horadois[6];
	segdois[1] = horadois[7];
	segdois[2] = 0; 
	int a, b, c, d, e, f, valor;
	a = (atoi(horum))*3600;
	b = (atoi(hordois))*3600;
	c = ((atoi(minum))*60)+ a;
	d = ((atoi(mindois))*60)+ b;
	e = (atoi(segum)) + c;
	f = (atoi(segdois)) + d;
	
	if (a < b){
		valor = f - e ;
	}
	else if(a > b){
		valor = e - f;
	}
	
	printf("%d\n", valor);
	
	int resphr, respmin, respseg;
	resphr = valor /3600;
	respmin = resphr % 3600;
	respseg = respmin % 60;
	
	printf("A diferença de horas correspondem á %d:%d%d\n", resphr, respmin, respseg);
	return 0;
}


