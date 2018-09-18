#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *inicializacao(FILE **arq1, FILE **arq2, char prev1[], char prev2[], int *flag) {
	*arq1 = fopen("arquivo1.txt", "r");
	*arq2 = fopen("arquivo2.txt", "r");
	if (*arq1 != NULL && *arq2 != NULL) {
		*flag = 1;
	}
	FILE *arq3;
	arq3 = fopen("arquivo3.txt", "w");
	return arq3;
}

char *input(FILE *arq, char NOME_ANT[], char NOME[], int *flag) {
	fgets(NOME, 50, arq);
	if (feof(arq)) {
		flag = 0;
	} else if (strcmp(NOME,NOME_ANT)>=0) {
		printf("Erro na checagem de sequencia\n");
		exit(1);
	} 
	strcpy(NOME_ANT,NOME);
	return NOME;
}

void match() {
	int flag;
	FILE *arq1;
	FILE *arq2;
	FILE *saida;
	char prev1[50];
	char prev2[50];
	char NOME1[50];
	char NOME2[50];
	inicializacao(&arq1, &arq2, prev1, prev2, &flag);
	input(arq1, prev1, NOME1, &flag);
	input(arq2, prev2, NOME2, &flag);
	while (flag) {
		if (strlen(NOME1) < strlen(NOME2)) {
			input(arq1, prev1, NOME1, &flag);
		} else if (strlen(NOME1) > strlen(NOME2)) {
			input(arq2, prev2, NOME2, &flag);
		} else {
			fputs(NOME1, saida);
			fputs("\n", saida);
			input(arq1, prev1, NOME1, &flag);
			input(arq2, prev2, NOME2, &flag);
		}
	}
}

int main() {
	match();
	return 0;
}