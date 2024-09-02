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

int count_mirror_numbers__in_interval(int start, int end){

    int contador = 0;

    for(int i = start; i <= end; i++){
        if(mirror_number(i)){
            contador++;
        }

    }
return contador;
}

int main() {
    int start = 1000;
    int end = 2000;

    int mirror = count_mirror_numbers__in_interval(start, end);

    printf("O intervalo de %d ate %d tem %d numeros mirror.", start, end, mirror);

return 0;
}

