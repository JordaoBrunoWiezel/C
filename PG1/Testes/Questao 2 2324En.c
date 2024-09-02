#include <stdio.h>

int greatest_dig_seq(char data[]){

    int seq1 = 0, seq2 =0;

    for(int i = 0; data[i] != '\0'; i++){ 
        if (data[i] >= '0' && data[i] <= '9') {
            seq1++;
                if(seq1 > seq2){
                    seq2 = seq1;
                }
        } else {
            seq1= 0;
        }

    }
return seq2;
}

int main() {
    char data[] = "abcc123456789def12";

    int result = greatest_dig_seq(data);
    
    printf("A maior sequencia de digitos consecutivos tem tamanho: %d\n", result);

    return 0;
}