////// Programa da Busca Exaustiva ///////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int vetor [100000];
int i = 0;
int busca = 0;
int achei = 0;
time_t t;

int main () {
	
	srand((unsigned) time(&t));
	
	for (i = 0; i < 100000; i++){
		vetor[i] = (rand()% 100000);
	}
	
	printf("Digite um valor para ser buscado: ");
	scanf("%d", &busca);
	
	achei = -1 ;
	for (i = 0; i <100000; i++) {
		if (vetor [i] == busca) {
			achei = i;
			
		}
	}
	if (achei == -1) {
		printf("Nao existe");
	}else {
		printf("Achei na posicao %d", achei);
	}
	
}
