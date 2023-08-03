///////Busca Binária/////////
//// PRECISA ESTAR ODERNADO ///////

#include <stdio.h>

int vetor [100000];
int i = 0;
int busca = 0;
int inicio = 0;
int fim = 0;
int meio = 0;

int main () {
	
	for (i = 0; i < 100000; i++){
		vetor[i] = i;
	}
	
	printf("Digite um valor para ser buscado: ");
	scanf("%d", &busca);
	
	inicio = 0;
	fim = 99999;
	while (fim >= inicio) {
		meio = ((inicio + fim)/2 );
		
		if (vetor[meio]== busca) {
		printf("Achei!! na posicao %d", meio);
		return 0;
		}else if (vetor[meio] > busca) {
			fim = (meio -1);
		}else {
			inicio = (meio + 1);
		}
	}
	printf("Nao existe se fudeo");
}
