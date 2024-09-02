#include <stdio.h>

typedef struct {
    int start; // índice do início do intervalo
    int size;  // dimensão do intervalo [ start .. start + size - 1 ]
} range_t;

range_t next_seq_of_ones(const int bits[], int length, int start) {

    if (start < 0 || start >= length) {
        return (range_t){0, 0};
    }

    int seq = 0;
    int indice = start;

    if (bits[start] == 1) {
        for (int p = start; p < length && bits[p] == 1; p++) {
            seq++;
        }
        for (int k = start - 1; k >= 0 && bits[k] == 1; k--) {
            seq++;
            indice = k;
        }
        

    } else {
        // Se o bit em start não é 1, apenas contagem para a direita
            for(int i = start; i < length; i++){
                if (bits[i] == 1){
                    seq++;
                        if(seq == 1){
                            indice = i;
                        }
                }
            }
    }       

    // Retorna a estrutura range_t
    return (range_t){indice, seq};
}





int main() {
    int b[] = {1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1};
    int length = 12, start = 1;
    range_t result = next_seq_of_ones(b, length, start);

    printf("Resultado: { %d, %d }\n", result.start, result.size);

    return 0;
}
