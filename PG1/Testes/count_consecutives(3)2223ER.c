#include <stdio.h>

int count_consecutive(int vals[], int idx, int dim) {
    int contador = 0;

    if (idx < 0 || idx >= dim) {
        printf("Índice inválido.\n");
        return -1;
    }

    int valor_alvo = vals[idx];

    for (int i = idx; i < dim; i++) {
        if(vals[i] == valor_alvo) {
        contador++;
        }
    }

    return contador;
}

int main() {
    int vals[11] = {1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0};
    int idx = 8, dim = 11;

    int count = count_consecutive(vals, idx, dim);

    if (count != -1) {
        printf("Subsequencia de %d's com inicio em %d e de dimensao %d\n", vals[idx], idx, count);
    }

    return 0;
}

/*
// Segunda forma
int main() {
    int dim, idx;

    printf("Digite o tamanho do array: ");
    scanf("%d", &dim);

    int vals[dim];

    printf("Digite os valores do array:\n");
    for (int i = 0; i < dim; i++) {
        scanf("%d", &vals[i]);
    }

    printf("Digite o indice inicial: ");
    scanf("%d", &idx);

    int count = count_consecutive(vals, idx, dim);

    if (count != -1) {
        printf("Subsequencia de %d's com inicio em %d e de dimensao %d\n", vals[idx], idx, count);
    }

    return 0;
}
*/

