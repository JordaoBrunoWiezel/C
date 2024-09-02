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

int main(){

    int x;
    printf("Digite um numero primo: ");
    scanf("%d", &x);

    if (is_prime(x)){
        printf("O numero e primo.");
    } else{
        printf("O numero nao e primo.");
    }
return 0;

}