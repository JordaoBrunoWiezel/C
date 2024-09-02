#include <stdio.h>
#include <stdbool.h>

bool is_prime (int n) {
        if (n <= 1) {
        return false;
    }

    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false; // Se for divisível por algum número, não é primo
        }
    }
return true;

}

int main() {
    int numero;
    printf("Escreva numeros inteiro terminado por uma letra\n");
    while(scanf("%d", &numero) == 1){

        if(numero < 1){
            continue;
        }

        if(is_prime(numero)){
            printf("Numero primo\n");
        } else {
            printf("Numero nao primo\n");
        }

    }
}