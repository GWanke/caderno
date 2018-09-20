#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializacao(FILE **arq1, FILE **arq2, FILE **arq3, char *prev1, char *prev2, int *flag) {
	strcpy(prev1, "0");
	strcpy(prev2, "0");
	*arq1 = fopen("arquivo1.txt", "r");
	*arq2 = fopen("arquivo2.txt", "r");
	if (*arq1 != NULL && *arq2 != NULL) {
		*flag = 1;
	}
	*arq3 = fopen("arquivo3.txt", "w");
}

void input(FILE *arq, char *NOME_ANT, char *NOME, int *flag) {
	fgets(NOME, 50, arq);
	if (feof(arq)) {
		*flag = 0;
	} else if (strcmp(NOME_ANT,NOME)>=0) {
		printf("Erro na checagem de sequencia\n");
		exit(1);
	} 
	strcpy(NOME_ANT,NOME);
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
	inicializacao(&arq1, &arq2, &saida, prev1, prev2, &flag);
	input(arq1, prev1, NOME1, &flag);
	input(arq2, prev2, NOME2, &flag);
	int comparacao;
	while (flag) {
		comparacao = strcmp(NOME1,NOME2);
		if (comparacao < 0) {
			fputs(NOME1, saida);	
			printf("%s\n", NOME1);	
			input(arq1, prev1, NOME1, &flag);
		} else if (comparacao > 0) {
			fputs(NOME2, saida);
			printf("%s\n", NOME2);	
			input(arq2, prev2, NOME2, &flag);
		} else {
			fputs(NOME1, saida);
			printf("%sa\n", NOME1);	
			input(arq1, prev1, NOME1, &flag);
			input(arq2, prev2, NOME2, &flag);
		}
	}
}

int main() {
	match();
	return 0;
}