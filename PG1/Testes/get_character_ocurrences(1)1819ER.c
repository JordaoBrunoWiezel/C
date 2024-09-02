#include <stdio.h>

void get_digits_ocurrences(char str[], int ocurrs[26]) {
    // Inicializa todos os arrays com o valor zero
    for (int i = 0; i < 26; i++) {
        ocurrs[i] = 0;
    }

    int letra;

    for (int p = 5; p >= 0; p--) {
        letra = str[p];
        ocurrs[letra - 'a']++;  // Ajusta para o índice certo
    }
}

int main() {
    char str[] = "abcdef";  // Adiciona ponto e vírgula
    int ocurrs[26];

    get_digits_ocurrences(str, ocurrs);

    for (int i = 0; i < 26; i++) {  // Corrige a condição do loop
        printf("Ocorrencias de %c: %d\n", 'a' + i, ocurrs[i]);  // Imprime a letra correspondente
    }

    return 0;  // Adiciona o return 0 no final do main
}
