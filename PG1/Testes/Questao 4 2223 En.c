#include <stdio.h>

void number_to_str(int n, char str_number[]){

int num;
int t = n;
int tam = 0;

    while(t != 0){
        t = t/10;
        tam++;
    }

    for(int i=tam-1; i >= 0; i--){
        num = n%10;
        str_number[i] = num + '0'; // Converte o dígito para caractere
        n = n/10; 
    }
    
str_number[tam] = '\0';
}

void encode(char dest[], const char src[]){

    int contador1 = 0;
    char numero[50];
    int indice = 0;

    for(int i =0; src[i] != '\0'; i++){
        if(src[i] == src[i+1]){
            contador1 ++;
        } else {
            contador1 += 1;
            number_to_str(contador1,numero);
            dest[indice] = src[i];
            dest[indice+1] = numero[0];
            indice += 2;
            contador1 = 0;
        }
    }
    dest[indice] = '\0';
}

int main() {
    char dest[50];
    char src[] = "aaabbcccd";

    encode(dest, src);

    printf("%s", dest);

}