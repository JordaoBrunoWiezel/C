
#include <stdio.h>

// Função que inverte um número
int inverts(int n) {
    int contador = 0;
    int n_auxiliar = n;

    while (n_auxiliar > 0) {
        n_auxiliar /= 10;
        contador++;
    }

    int order[contador];

    for (int i = 0; i < contador ; i++) {    
        order[i] = n % 10; // pega o ultimo numero
        n /= 10;          // Exclui o ultimo numero
    }

    int inverted = 0;

    for (int i = 0; i < contador; i++) {
        inverted = inverted * 10 + order[i];
    }

    return inverted;
}

// Função que encontra o próximo número palíndromo
int nextPalindrome(int n) {
    int count = 0;

    // Incrementa n até encontrar o próximo palíndromo
    while (1) {
        n++;
        count++;
        if (n == inverts(n)) {
            printf("O valor de n foi incrementado %d vezes.\n", count);
            return n;
        }
    }
}

int main() {
    int num;
    printf("Escolha um numero: ");
    scanf("%d", &num);

    int nextPalin = nextPalindrome(num);

    printf("O proximo palindromo a partir de %d: %d\n", num, nextPalin);

    return 0;
}