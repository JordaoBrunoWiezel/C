#include <stdio.h>

typedef struct {
    int start; // índice do início do intervalo
    int size;  // dimensão do intervalo [ start .. start + size - 1 ]
} range_t;

range_t biggest_one_seq(const int big[], int length){

    if (length > 12) {
        return (range_t){0, 0};
    }

    int first_indice = -1; // Indice final
    int num_seq = 0; // Numero da seq
    int indice = -1; // Indice que muda a cada ciclo
    int current_seq = 0; // Sequencia q muda a cada ciclo


    for (int i = 0; i < length; i++) {
        if (big[i] == 1) {
            // Para salvar o primeiro indice da sequencia
            if (indice == -1) {
                indice = i;
            }
            current_seq++;

        } else { // Se acabar a seq de 1ns
            // Verifica se a seq é maior q a anterior, se sim, guarda os dados
            if (current_seq > num_seq) {
                first_indice = indice;
                num_seq = current_seq;
            }
            indice = -1;
            current_seq = 0;
        }
    }

    // Verifica novamente dps do loop
    if (current_seq > num_seq) {
        first_indice = indice;
        num_seq = current_seq;
    }
    return (range_t) {first_indice, num_seq};
}

int main() {
    int b[] = {1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1};
    int length = 12;
    range_t result = biggest_one_seq(b, length);

    printf("Resultado: { %d, %d }\n", result.start, result.size);

    return 0;
}