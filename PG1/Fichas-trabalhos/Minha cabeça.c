#include <stdio.h>

int my_cab(char n[]){

    int num = 0;
    int tam = 0;
    int contador1 = 0, contador2 = 0, indice = 0;
    
    while(n[tam] != '\0'){
        tam++;
    }

    for(int i = 0; i < tam -1 ; i++){
        if(n[i] >= '0' && n[i] <= '9'){
            if(n[i]==n[i+1]){
                contador1++;
                    if(contador1 > contador2){
                        contador2 = contador1;
                        indice = i - contador1 + 1;
                        num = n[indice] - '0'; // Converte o caracter (numero) para o numero correspondente
/* EXEMPLO:
int num = 5;
char char_digit = '7';

// Convertendo número para caractere
char char_representation = num + '0'; // char_representation terá o caractere '5'

// Convertendo caractere para número
int numeric_value = char_digit - '0'; // numeric_value terá o valor 7
*/

                    }
            } else {
                contador1 = 0;
            }
        }
    }
    contador2 += 1;
    printf("O indice da maior sequencia tem %d\n", indice);
    printf("O numero que tem maior sequencia: %d\n", num);

return contador2;
}

int main(){

    char cab[] = "a1b223b21321c11111";

    int cont = my_cab(cab);

    printf("A maior sequencia tem: %d", cont);

return 0;
}