#include <stdio.h>

// Realize a função int greatest_char_seq(char data[]) que retorna a dimensão da maior 
// sequência de caracteres alfabéticos ('a'..'z' ou 'A'..'Z') consecutivos, presente na string data. 
// Na realização desta função não podem usar funções da biblioteca de C.

int greatest_char_seq(char data[]){

    int cont1 = 0, cont2 = 0;

    for(int i = 0; data[i] != '\0'; i++){
        if((data[i] >= 'a' && data[i] <= 'z') || (data[i] >= 'A' && data[i] <= 'Z')){
            cont1++;
                if(cont1 > cont2){
                    cont2 = cont1;
                }
        } else {
            cont1 = 0;
        }

    }

return cont2;
}