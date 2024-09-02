#include <stdio.h>
#include <stdbool.h>

int i;

// Função para verificar se um número é oblongo
bool is_oblong(int n) {
    for(i = 0; i <= n; i++) {
        // Verifica se o produto de i e (i+1) é igual a n
        if (i * (i + 1) == n) {
            return true; // Retorna verdadeiro se for oblongo
        }
    }
    return false; // Retorna falso se não for oblongo
}

int main () {
    int num;

    // Solicita ao usuário para inserir uma sequência de números inteiros
    printf("Insira uma sequencia de numeros inteiros (termine com um caractere nao digito):\n");

    // Loop enquanto o usuário inserir números inteiros
    while (scanf("%d", &num) == 1) {
        // Verifica se o número é oblongo usando a função is_oblong
        if (is_oblong(num)) {
            printf("%d e oblongo.\n", num);
        } else {
            printf("%d nao e oblongo.\n", num);
        }
    }

    return 0; // Indica que o programa foi executado com sucesso
}
