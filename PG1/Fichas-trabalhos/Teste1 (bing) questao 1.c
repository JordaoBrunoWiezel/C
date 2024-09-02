#include <stdio.h>
#include <stdbool.h>

// Escreva uma função em C chamada int count_primes(int n) que retorna a quantidade de números primos menores ou iguais a n. 
// Por exemplo, int c = count_primes(10) deve retornar 4, pois os números primos menores ou iguais a 10 são 2, 3, 5, 7

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int count_primes(int n) {
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime(i)) {
        count++;
        }
    }
    return count;
}

int main() {
    printf("%d\n", count_primes(10));  // Deve imprimir 4
    return 0;
}
