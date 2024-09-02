#include <stdio.h>
#include <stdbool.h>

// Defina uma função bool perfect_numbers(int n1, int n2) que retorna true se n1 e n2 são números perfeitos. 
// Um número é perfeito se a soma de seus divisores próprios é igual ao próprio número. Por exemplo, os divisores 
// próprios de 6 são 1, 2, 3 e a soma deles é 6, então 6 é um número perfeito.

int sum_divisors(int n) {
    int sum = 1;
    for (int i = 1; i < n; i++) {
        if(n%i == 0){
            sum += i;
        }
        
    }
    return sum;
}

bool perfect_numbers(int n1, int n2) {
    if(sum_divisors(n1) == n2 && sum_divisors(n2) == n1){
        return true;
    }
return false;
}

int main() {
    printf("%d\n", perfect_numbers(6, 28));  // Deve imprimir 0
    return 0;
}
