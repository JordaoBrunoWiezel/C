#include <stdio.h>

int greatest_dig_seq(char data[]){

    int seq1 = 0, seq2 = 0, indice = 0;

    for(int i = 0: data[i] != '\0'; i++){
        if(data[i] >= '0' && data[i] <= '9'){
            seq1++;
                if(seq1 > seq2){
                    seq2 = seq1;
                        if(seq1 == 1){
                            indice = i;
                        }
                }
        } else{
            seq1 = 0;
        }

    }
    printf("Indice da sequencia: %d", indice);


return seq2;
}