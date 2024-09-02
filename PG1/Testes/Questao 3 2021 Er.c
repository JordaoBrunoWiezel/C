#include <stdio.h>

typedef struct {
int start; // índice do início do intervalo
int size; // dimensão do intervalo [ start .. start + size -1 ]
} range_t;

range_t next_seq_of_ones(const int bits[], int length, int start){


    int indice, contador = 0, contador1 = 0, contador2 = 0;

if(bits[start] == 1){

    for(int i = start; i < length; i++ ){
        if(bits[i] == 1){
            contador1++;
            printf("%d", contador1);
        } else {
            break;
        }
    }

    for(int p = start-1; p >= 0; p--){
        if(bits[p] == 1){
            contador2++;
            printf("%d", contador2);
            indice = p;
        } else {
            break;
        }
    }

    contador = contador1+contador2;

} else {
    for(int k = start; k < length; k++){
        if(bits[k] == 1){
            contador++;
                if(contador == 1){
                    indice = k;
                }
        }
    }
}

return (range_t){indice, contador};
}

int main(){

    int bits[] = {1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1};
    int length = 12;
    int start = 1;

    range_t result = next_seq_of_ones(bits, length, start);

    printf("Resultado: { %d, %d }\n", result.start, result.size);

    return 0;
}