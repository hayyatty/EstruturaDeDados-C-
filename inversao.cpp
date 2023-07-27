//Inversao de vetor//

#include <stdio.h>

//declaracao de variaveis//

int vetorOriginal [10];
int vetorInvertido [10];
int i;

//Execucao do programa//

int main() {
	// limpeza da memória 
	for (i = 0 ; i < 10; i++) {
		vetorOriginal [i] = 0;
		vetorInvertido [i] = 0;
	}
	for (i = 0 ; i < 10; i++) {
		printf("Digite o valor para a posicao %d do vetor", i);
		scanf("%d", &vetorOriginal[i]);
	}
	//inversao do Vetor 
	for (i = 9 ; i >= 0 ; i--) {
		vetorInvertido[9 - i] = vetorOriginal[i];
	}
	
	//impresao do vetor invertido
	for (i = 0 ; i < 10 ; i++) {
		printf("vetorInvertido[%d] = %d\n ", i , vetorInvertido[i]);
	}
	
}
