///////////////////////////////////////////////////////
/////Programa que implementa uma Árvore de ordem 5/////
///////////////////////////////////////////////////////

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/////Declaração de estruturas/////

struct no {
	int numero;
	struct no *filho1;
	struct no *filho2;
	struct no *filho3;
	struct no *filho4;
	struct no *filho5;
};

/////Função que insere um no na árvore/////

struct no *inserir(struct no *raiz, int numero) {
	 
	if (raiz == NULL){
		//Caso fácil : a árvore está vazia
		raiz = (struct no*)malloc(sizeof(struct no));
		
		raiz -> numero = numero;
		raiz -> filho1 = NULL;
		raiz -> filho2 = NULL;
		raiz -> filho3 = NULL;
		raiz -> filho4 = NULL;
		raiz -> filho5 = NULL;
	}else{
		//Casp difícil : A arvore n esta vazoa
		int sorteio = (rand()%5);
		
		if (sorteio == 0){
			raiz -> filho1 = inserir(raiz -> filho1, numero);
			
		}else if (sorteio == 1) {
			raiz -> filho2 = inserir(raiz -> filho2, numero);
			
		}else if (sorteio == 2) {
			raiz -> filho3 = inserir(raiz -> filho3, numero);
			
		}else if (sorteio == 3) {
			raiz -> filho4 = inserir(raiz -> filho4, numero);
			
		}else if (sorteio == 4) {
			raiz -> filho5 = inserir(raiz -> filho5, numero);
					}
	}
	
	return raiz;
}

/////função que imprime a árvore/////

void imprimir(struct no *raiz, char *endentacao) {
	if (raiz != NULL){
		printf("%s%d\n", endentacao, raiz -> numero);
		
		char *temp = (char *) malloc(1024 *sizeof(char));
		strcpy(temp, endentacao);
		strcat(temp, "---");
		
		imprimir(raiz -> filho1, temp);
		imprimir(raiz -> filho2, temp);
		imprimir(raiz -> filho3, temp);
		imprimir(raiz -> filho4, temp);
		imprimir(raiz -> filho5, temp);
	}
}

/////função principal de execução do programa/////

int main (){
	// declaração de variaveis
	struct no *raiz = NULL;
	time_t t;
	char *endentacao = (char *) malloc(1024 * sizeof(char));
	
	// Inicialização da aleatoriedade
	srand((unsigned) time(&t));
	
	// manipulação de arvore
	strcpy(endentacao, "");
	
	raiz = inserir(raiz,1);
	raiz = inserir(raiz,2);
	raiz = inserir(raiz,3);
	raiz = inserir(raiz,4);
	raiz = inserir(raiz,5);
	
	
	imprimir(raiz,endentacao);
}





