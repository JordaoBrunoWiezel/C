#include <stdio.h>

typedef struct {
int start; // índice do início do intervalo
int size; // dimensão do intervalo [ start .. start + size -1 ]
} range_t;

 range_t biggest_one_seq(const int bits[], int length){
    
    int seq1 = 0, seq2 = 0, indice = 0;

    for(int i = 0; i < length; i++){
        if(bits[i]==1){
            seq1++;
                if(seq1 > seq2){
                    seq2=seq1;
                    indice = i - seq1 + 1;
                }
        } else{
        seq1 = 0;
        }
    }

    range_t result;
    result.start = indice;
    result.size = seq2;
    return result;
 }

int main() {
    int b[] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1};
    int length = 12;
    range_t result = biggest_one_seq(b, length);

    printf("Resultado: { %d, %d }\n", result.start, result.size);

    return 0;
}
