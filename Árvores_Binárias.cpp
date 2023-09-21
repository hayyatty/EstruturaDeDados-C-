/*
	/////////////////////////////
	///////�RVORES BIN�RIAS//////
	/////////////////////////////

	+ Se a altura � h, ent�o :
		- tem no m�nimo h N�S
		- tem no m�ximo 2^h-1 N�S 
	
	+ Se a �rvore tem n >= 1 N�S, ent�o :
		- A altura � no m�nimo log(n+1)
			* Quando a �rvore � completa
			
		- A altura � no m�ximo n
			* Quando cada n� n�o terminal	
			
	
		   |1|
		   / \
		 |2| |3|
	
	+ Travessia - Pr�-ordem
		1,2,3
	+ Travessia - Em ordem
		2,1,3
	+ Travessia - P�s-ordem
		2,3,1	
			
			|1|	
			/ \ 	Pr� : 1,2,3,4,5,6
		  |2| |4|	Em : 3,2,1,5,4,6
		  /	  / \	P�s : 3,2,5,6,4,1
		|3| |5| |6|
						 
*/
	//////////////////////////////////////////////////////////
	///////Implementa��o da �rvore bin�rias e navaga��o//////
	/////////////////////////////////////////////////////////
	
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Declar��o de estruturas//

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

//Fun��o que insere um N� na lista//

struct no *inserir(struct no *raiz, int numero) {
	if (raiz == NULL) {
		//caso f�cil, �rvore vazia
		raiz = (struct no*) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL;
		raiz -> direita = NULL;
	} else {
		//caso facil, �rvore n�o est� vazia
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
//Navega��o em Pr�-ordem//

void navegarPreOrdem (struct no *raiz){
	if (raiz != NULL) {
		printf("%d\t", raiz -> numero);
		navegarEmOrdem (raiz -> esquerda);
		navegarEmOrdem (raiz -> direita);
	}
}

//Navega��o em Pos-ordem//

void navegarPosOrdem (struct no *raiz) {
	if (raiz != NULL) {
		navegarEmOrdem (raiz -> esquerda);
		navegarEmOrdem (raiz -> direita);
		printf("%d\t", raiz -> numero);
	}
}

//Fun��o principal de execu��o de programa//

int main() {
	//declara��o da �rvore
	struct no *raiz = NULL;
	
	//inicializa��o da aleatoriedade
	time_t t;
	srand((unsigned)time (&t));
	
	//Preenchimento da �rvore
	int i = 0;
	for(i = 0; i < 10; i++) {
		raiz = inserir(raiz, i);
	}
	
	//navega��es
	printf("\n=================================== Pr� Ordem ===============================\n");
	navegarPreOrdem(raiz);
	printf("\n=================================== Em Ordem ===============================\n");
	navegarEmOrdem(raiz);
	printf("\n=================================== P�s Ordem ===============================\n");
	navegarPosOrdem(raiz);
	
}

