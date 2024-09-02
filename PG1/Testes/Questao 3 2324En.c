#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um número aleatório no intervalo [min, max]
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}


int random_subset(int numbers[], int numbers_size, int set[], int set_size) {

        if (set_size > numbers_size) {
        return -1;  // Não há elementos suficientes para criar o conjunto
    }

int indice;

    for(int i =0; i < set_size; i++){

        indice = rand_range(0, numbers_size - 1);
        set[i] = numbers[indice];
        numbers[indice] = numbers[numbers_size - 1 ];
        numbers_size--;

    }
return numbers_size;
}


//Chatgpt
int main() {
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int numbers_size = sizeof(numbers) / sizeof(numbers[0]);

    int set_size = 5;
    int set[5];

    int result = random_subset(numbers, numbers_size, set, set_size);

    if (result == -1) {
        printf("Não há elementos suficientes para criar o conjunto.\n");
    } else {
        printf("Conjunto produzido com sucesso. Nova dimensão de numbers: %d\n", result);
        printf("Conjunto gerado: ");
        for (int i = 0; i < set_size; i++) {
            printf("%d ", set[i]);
        }
        printf("\n");
    }

    return 0;
}