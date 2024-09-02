#include <stdio.h>
#include <stdbool.h>

bool mirror_number(int n) {
    // Verifica se o número está no intervalo de 0 a 9999
    if (n < 0 || n > 9999) {
        return false;
    }

    // Divide o número em dois grupos de 2 dígitos
    int group1 = n / 100;
    int group2 = n % 100;

    // Extrai os dígitos de cada grupo
    int digit1_group1 = group1 / 10;
    int digit2_group1 = group1 % 10;

    int digit1_group2 = group2 / 10;
    int digit2_group2 = group2 % 10;

    // Verifica se os grupos têm os mesmos dígitos por ordem invertida
    return (digit1_group1 == digit2_group2) && (digit2_group1 == digit1_group2);
}

int main() {
    // Teste da função com alguns exemplos
    printf("%d\n", mirror_number(1221)); // true
    printf("%d\n", mirror_number(3003)); // true
    printf("%d\n", mirror_number(0330)); // false *
    printf("%d\n", mirror_number(2222)); // true
    printf("%d\n", mirror_number(1234)); // false

    int num;
    printf("Digite um numero de 0 a 9999: ");
    scanf("%d", &num);

    // Chama a função e imprime o resultado
    if (mirror_number(num)) {
        printf("O numero %d e um numero mirror.\n", num);
    } else {
        printf("O numero %d não e um numero mirror ou esta fora do intervalo permitido.\n", num);
    }


    return 0;
}
