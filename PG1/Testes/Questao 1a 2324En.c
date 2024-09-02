#include <stdio.h>

int sum_divisors(int n){

int sum = 0;
    for(int i = 1; i < n; i++){

        if(n%i == 0){
            sum += i;
        }

    }

return sum;
}

int main () {

    int n = 220;

    int soma = sum_divisors(n);

printf("Soma dos divisores propios de %d: %d", n, soma);

return 0;
}