#include <stdio.h>
#include <stdbool.h>

bool is_tribonacci(int n){

    if (n < 0) {
        return false;  // Números negativos não pertencem à série de tribonacci
    }

    if (n == 0 || n == 1 || n == 2) {
        return true;
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

    int n;
    printf("Digite um numero e termine com um caracter nao digito \nN? ");
    while(scanf("%d", &n) == 1){
        if(is_tribonacci(n)){
            printf("E termo da serie tribonacci \nN? ");
        } else {
            printf("N? ");
        }
    }

return 0;    
}

