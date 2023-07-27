//Programa de transposicao de matrizes//

#include <stdio.h>

//declaracao//

int matriz [2][3];
int transposta[3][2];
int i = 0;
int j = 0;

//funcao principal//

int main () {
	//limpeza da memoria//
	for (i = 0 ; i < 2 ; i++){
		for (j = 0 ; j < 3 ; j++){
			matriz[i][j] = 0 ;
			transposta[j][i]= 0;
		}
	}
	//preenchimento da matriz
	for (i = 0 ; i < 2 ; i++){
		for (j = 0 ; j < 3 ; j++){
			printf("matriz [%d,%d] = ",i,j);
			scanf("%d", &matriz[i][j]);		
		}
	}
	for (i = 0 ; i < 2 ; i++){
		for (j = 0 ; j < 3 ; j++){
			transposta[j][i] = matriz[i][j];
		}
	}
	for (i = 0 ; i < 2 ; i++){
		for (j = 0 ; j < 3 ; j++){
			printf("matrizTransposta[%d][%d] = %d\n", j,i, transposta[j][i]);
		}
		printf("\n");
	}
	
}
