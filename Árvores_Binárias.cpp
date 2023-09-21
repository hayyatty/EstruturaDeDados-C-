/*
	/////////////////////////////
	///////ÁRVORES BINÁRIAS//////
	/////////////////////////////

	+ Se a altura é h, então :
		- tem no mínimo h NÓS
		- tem no máximo 2^h-1 NÓS 
	
	+ Se a árvore tem n >= 1 NÓS, então :
		- A altura é no mínimo log(n+1)
			* Quando a árvore é completa
			
		- A altura é no máximo n
			* Quando cada nó não terminal	
			
	
		   |1|
		   / \
		 |2| |3|
	
	+ Travessia - Pré-ordem
		1,2,3
	+ Travessia - Em ordem
		2,1,3
	+ Travessia - Pós-ordem
		2,3,1	
			
			|1|	
			/ \ 	Pré : 1,2,3,4,5,6
		  |2| |4|	Em : 3,2,1,5,4,6
		  /	  / \	Pós : 3,2,5,6,4,1
		|3| |5| |6|
						 
*/
	//////////////////////////////////////////////////////////
	///////Implementação da árvore binárias e navagação//////
	/////////////////////////////////////////////////////////
	
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Declarção de estruturas//

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

//Função que insere um NÓ na lista//

struct no *inserir(struct no *raiz, int numero) {
	if (raiz == NULL) {
		//caso fácil, árvore vazia
		raiz = (struct no*) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	} else {
		//caso facil, árvore não está vazia
		if ((rand() % 2) == 0) {
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
		}else{
			raiz -> direita = inserir(raiz -> direita, numero);
		}
	}
	
	return raiz;
}

void navegarEmOrdem (struct no *raiz) {
	if (raiz != NULL) {
		navegarEmOrdem (raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegarEmOrdem (raiz -> direita);
	}
} 
//Navegação em Pré-ordem//

void navegarPreOrdem (struct no *raiz){
	if (raiz != NULL) {
		printf("%d\t", raiz -> numero);
		navegarEmOrdem (raiz -> esquerda);
		navegarEmOrdem (raiz -> direita);
	}
}

//Navegação em Pos-ordem//

void navegarPosOrdem (struct no *raiz) {
	if (raiz != NULL) {
		navegarEmOrdem (raiz -> esquerda);
		navegarEmOrdem (raiz -> direita);
		printf("%d\t", raiz -> numero);
	}
}

//Função principal de execução de programa//

int main() {
	//declaração da árvore
	struct no *raiz = NULL;
	
	//inicialização da aleatoriedade
	time_t t;
	srand((unsigned)time (&t));
	
	//Preenchimento da árvore
	int i = 0;
	for(i = 0; i < 10; i++) {
		raiz = inserir(raiz, i);
	}
	
	//navegações
	printf("\n=================================== Pré Ordem ===============================\n");
	navegarPreOrdem(raiz);
	printf("\n=================================== Em Ordem ===============================\n");
	navegarEmOrdem(raiz);
	printf("\n=================================== Pós Ordem ===============================\n");
	navegarPosOrdem(raiz);
	
}

