/*
- Complexidade para inserção, remoção e busca (nivel de esforço)
	*Listas encadeadas
		inserir e remover em ordem(1) -> independem do tamanho da lista
		buscar em ordem (n)
	*Vetores não-ordenados
		inserir e remover em ordem(1)
			+inserir no final
			+remover e trocar com o último e remover o último
		buscar em ordem (n)
	*Vetores ordenados
		buscar em ordem (log n)
		inserir e remover em ordem (n)
	*Arvores binárias de busca				
		As 3 operações levam ordem (log n)

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct no {
	int numero;
	struct no *esquerda;
	struct no *direita;
};

//Função que insere um no na arvore//

struct no *inserir (struct no *raiz, int numero) {
	if (raiz == NULL ) {
		//caso facil, arvore vazia
		raiz = (struct no *) malloc(sizeof(struct no));
		raiz -> numero = numero;
		raiz -> esquerda = NULL; 
		raiz -> direita = NULL;
	} else {
		// Caso difícil, a arvore nao esta vazia
		if (numero < raiz -> numero) {
			raiz -> esquerda = inserir(raiz -> esquerda, numero);
		}else{
			raiz -> direita = inserir(raiz -> direita, numero);
		}	
	}
	return raiz;
}
//funcao que busca um no na arvore//	

void buscar (struct no *raiz, int numero) {
	if (raiz == NULL) {
		printf("Não achei!!!!");
		
	}else if (raiz -> numero == numero) {
		printf ("Achei !!!!");
		
	}else if  (raiz -> numero > numero){
		buscar(raiz -> esquerda, numero);
		
	}else{
		buscar (raiz -> direita, numero);
		
	}
}

//Funcao que navega a arvor em ordem//

void navegar (struct no *raiz) {
	if (raiz != NULL){
		navegar(raiz -> esquerda);
		printf("%d\t", raiz -> numero);
		navegar(raiz -> direita);
	}
}

//funao que desenha o menu na tela//

int menu() {
	int opcao;
	printf("_______________________________________________\n");
	printf("||_______________Menu de opções______________||\n"); 
 	printf("||___________________________________________||\n");
	printf("|| 1 - inserir								 ||\n");
	printf("|| 2 - buscar								 ||\n");
	printf("|| 3 - navegar								 ||\n");
	printf("|| 4 - inicializar a Arvore Aleatoriamente   ||\n");
	printf("|| 5 - sair									 ||\n");
	printf("||___________________________________________||\n");
	printf("Digite a sua opção :\n");
	scanf("%d", &opcao);
	
	return opcao;
}

//funcao principal//

int main () {
	struct no *raiz  = NULL;
	int opcao = 0;
	int numero = 0;
	int i = 0;
	
	time_t t;
	srand((unsigned) time(&t));
	
	while (opcao != 5) {
		opcao = menu();
		
		if (opcao == 1) {
			printf("Digite o numero :\n");
			scanf ("%d",&numero);
			raiz = inserir(raiz, numero);
		} else if (opcao == 2) {
			printf("Digite o numero :\n");
			scanf ("%d",&numero);
			buscar(raiz, numero);
		} else if (opcao == 3) {
			navegar(raiz);
		} else if (opcao == 4) {
			for (i = 0; i < 1000; i++) {
				raiz = inserir(raiz, rand());
			}
		}
	}
}
