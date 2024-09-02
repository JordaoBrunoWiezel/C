#include <stdio.h>

void number_to_str(int n, char str_number[]){

int num;
int t = n;
int tam = 0;

    while(t >= 0){
        t = t/10;
        tam++;
    }

    for(int i=tam-1; i >= 0; i--){
        num = n%10;
        str_number[i] = num + '0'; // Converte o dígito para o caractere correspondente (Converte o número 5 para o caractere '5'.)
        n = n/10; 
    }
    
str_number[tam] = '\0';
}

int main(){
    int n = 1543;
    char str_number[50];

    number_to_str(n, str_number);
    
    printf("str_number = %s\n", str_number);

return 0;
}
