#include <stdio.h>
#include <stdbool.h>

bool is_tribonacci(int n){

    if (n < 0) {
        return false;  // Números negativos não pertencem à série de tribonacci
    }

    int next_term;
    int a = 0, b = 0, c = 1;

    while (c < n) {
        next_term = a + b + c;
        a = b;
        b = c;
        c = next_term;
    }

    return (next_term == n);  // Retorna true se n for encontrado na série de tribonacci
}


int main() {
    // Exemplo de uso
    int number_to_check = 5;
    if (is_tribonacci(number_to_check)) {
        printf("%d pertence a serie de tribonacci.\n", number_to_check);
    } else {
        printf("%d NAO pertence a serie de tribonacci.\n", number_to_check);
    }

    return 0;
}
