#include <stdio.h>

int count_consecutive(int vals[], int dim, int idx){

    int seq1 = 0;
    int n = vals[idx];

    for(int i = idx; i < dim; i++){
        if(vals[i] == n){
            seq1++;
                if(vals[i] != vals[i+1]){
                    break;
                }
        }
    }
return seq1;
}
/*
// Ou chatgpt
    int count = 0;

    // Verifica se o índice está dentro dos limites do array
    if (idx >= 0 && idx < dim) {
        // Obtém o valor a ser contado
        int target_value = vals[idx];

        // Inicia a contagem
        while (idx < dim && vals[idx] == target_value) {
            count++;
            idx++;
        }
    }

    return count;
}

*/

int main(){

    int vals[11]={1,1,1,0,0,0,1,1,0,0,0};
    int idx=8;
    int dim=11;

    int count = count_consecutive(vals, dim, idx);

    printf("Subsequencia de %d's com inicio em %d e de dimensao %d\n", vals[idx] , idx , count);

return 0;
}