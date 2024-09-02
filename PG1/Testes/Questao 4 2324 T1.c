#include <stdio.h>

void array_start_even_end_odd(int res[], const int v[], int size) {
    int start = 0; // Índice para o início do array res
    int end = size - 1; // Índice para o final do array res

    for (int i = 0; i < size; i++) {
        if (v[i] % 2 == 0) {
            // Valor par, copia para o início de res
            res[start] = v[i];
            start++;
        } else {
            // Valor ímpar, copia para o final de res
            res[end] = v[i];
            end--;
        }
    }
}
int main() {
    int original[] = {2, 7, 4, 1, 8, 5, 6, 3};
    int size = 8;
    int result[size];

    array_start_even_end_odd(result, original, size);

    printf("Array resultante: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", result[i]);
    }

    return 0;
}