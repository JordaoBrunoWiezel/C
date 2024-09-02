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

// Função que conta o número de mirror numbers em um intervalo
int count_mirror_numbers_in_interval(int start, int end) {
    // Garante que start não seja maior que end
    if (start > end) {
        return 0;  // Intervalo inválido
    }

    int count = 0;

    // Itera sobre todos os números no intervalo
    for (int num = start; num <= end; num++) {
        // Verifica se o número é um mirror number
        if (mirror_number(num)) {
            count++;
        }
    }

    return count;
}

int main() {
    // Teste da função com alguns exemplos
    printf("%d\n", count_mirror_numbers_in_interval(1000, 2000)); // 10
    printf("%d\n", count_mirror_numbers_in_interval(2000, 3000)); // 9
    printf("%d\n", count_mirror_numbers_in_interval(3000, 4000)); // 10

    int start, end;

    // Recebe os valores de start e end
    printf("Digite o valor de start: ");
    scanf("%d", &start);

    printf("Digite o valor de end: ");
    scanf("%d", &end);

    // Chama a função e exibe o resultado
    int result = count_mirror_numbers_in_interval(start, end);
    printf("A quantidade de mirror numbers no intervalo e: %d\n", result);

    return 0;
}
