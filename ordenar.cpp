
//////Programa da Ordenação Direta////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vetor[10000000];
int i = 0;
int j = 0;
time_t t;

int main() {
    srand((unsigned) time(&t));

    // Preenchendo o vetor com valores aleatórios
    for (i = 0; i < 10000000; i++) {
        vetor[i] = rand() % 10000000; // Números aleatórios entre 0 e 99
    }

    for (i = 0; i < 10000000; i++) {
        printf("%d\n", vetor[i]);
    }

    for (i = 0; i < 9999999; i++) {
        for (j = (i + 1); j < 10000000; j++) {
            if (vetor[i] > vetor[j]) {
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
    }

    for (i = 0; i < 10000000; i++) {
        printf("%d\n", vetor[i]);
    }
}

