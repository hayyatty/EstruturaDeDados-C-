//////////////////////////////////////
//Programa de Preenchimento de Vetor//
//////////////////////////////////////

#include <stdio.h>

///////////////////////////
//Declaracao de variaveis//
///////////////////////////

int vetor [10];
int i = 0;

///////////////////////////////////////////
//Funcao princial de execucao de programa//
///////////////////////////////////////////

int main() {
	// limpeza da memória 
	for (i = 0 ; i< 10 ; i++) {
		vetor [i] = 0;
	}
	
	//preenchimento do vetor 
	for (i = 0; i <10; i++) {
		printf("Digite o valor da posicao %d do vetor :", i);
		scanf("%d", &vetor[i]);
	
	}
	//impressao do vetor
	for (i = 0; i<10 ; i++ ) {
		printf("vetor[%d] = %d\n",i,vetor[i]);
	
	}
}
