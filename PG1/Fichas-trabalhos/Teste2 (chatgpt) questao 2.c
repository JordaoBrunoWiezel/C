#include <stdio.h>


// 2.a. [2 pontos] Implemente a função int longest_increasing_subarray(int arr[], int size) 
// que retorna o comprimento do maior subarray consecutivo crescente em um array de inteiros arr de tamanho size.
// Por exemplo, no array {1, 2, 3, 2, 5, 7, 8, 9}, o maior subarray consecutivo crescente é {2, 5, 7, 8, 9}, e o comprimento é 5.

int longest_increasing_subarray(int arr[], int size) {

    int comp1 = 0, comp2 = 0, indice = 0;

    for(int i = 0; i < size-1; i++){
        if(arr[i] < arr[i+1]){
            comp1++;
                if(comp1 > comp2){
                    comp2 = comp1;
                    indice = i - comp1 + 1;
                }
        } else {
            comp1 = 0;
        }
    }
    
    // Imprimir o maior subarray consecutivo crescente
    printf("O maior subarray consecutivo crescente é: ");
    for(int p = indice; p <= size - 1; p++){
        printf("%d ", arr[p]);
    }
    printf("\n");

return comp2 += 1;
}

// 2.b. [2 pontos] Defina a função void reverse_alternate_k(int arr[], int size, int k),
// que inverte a ordem dos elementos em cada bloco alternado de tamanho k no array arr.
// Se o tamanho do array não for múltiplo de k, os elementos restantes devem permanecer na mesma ordem.

void reverse_alternate_k(int arr[], int size, int k) {

    for (int i = 0; i < size; i += k * 2) {
        int inicio = i;
        int fim = (i + k - 1 < size) ? i + k - 1 : size - 1; // NAO SEI

        // Inverter os elementos do bloco alternado de tamanho k
        while (inicio < fim) {
            // Trocar os elementos
            int temp = arr[inicio];
            arr[inicio] = arr[fim];
            arr[fim] = temp;

            // Avançar e retroceder os índices
            inicio++;
            fim--;
        }
    }
}


