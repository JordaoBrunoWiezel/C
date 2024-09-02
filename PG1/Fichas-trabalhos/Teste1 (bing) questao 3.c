#include <stdio.h>

// Escreva uma função int longest_alpha_seq(char data[]) que retorna o tamanho da maior sequência de caracteres 
// alfabéticos consecutivos na string data. Por exemplo, para a entrada "abc123defg", a função deve retornar 5 
// (correspondente à sequência defg).

int longest_alpha_seq(char data[]) {

    int cont1 = 0, cont2 = 0;

    for(int i=0; data[i] != 0; i++){
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