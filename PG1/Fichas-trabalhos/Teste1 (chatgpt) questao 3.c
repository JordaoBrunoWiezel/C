#include <stdio.h>

/*3.[4] Implemente a função void merge_arrays(int arr1[], int size1, int arr2[], int size2, int merged[]) 
que recebe dois arrays ordenados (arr1 e arr2) e seus tamanhos (size1 e size2), e mescla os dois 
em um terceiro array ordenado (merged). */

void merge_arrays(int arr1[], int size1, int arr2[], int size2, int merged[]) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged[k] = arr1[i];
            i++;
        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        merged[k] = arr1[i];
        i++;
        k++;
    }

    while (j < size2) {
        merged[k] = arr2[j];
        j++;
        k++;
    }

    int aux = 0;
    
    for (int n = 0; n < size1 + size2 - 1; n++) {
        for (int m = 0; m < size1 + size2 - n - 1; m++) {
            if (merged[m] > merged[m + 1]) {
                aux = merged[m];
                merged[m] = merged[m + 1];
                merged[m + 1] = aux;
            }
        }
    }

}

int main() {
    int arr1[] = {1, 2, 5, 7};
    int size1 = 4;

    int arr2[] = {3, 4, 6, 8, 10, 9};
    int size2 = 6;

    int merged[10]; // Tamanho total dos arrays mesclados (size1 + size2)

    merge_arrays(arr1, size1, arr2, size2, merged);

    printf("Arrays mesclados: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}