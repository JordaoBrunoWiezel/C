#include <stdio.h>

// 3.a. [2 pontos] Implemente a função int max_profit(int prices[], int size), que recebe um array de preços 
// de ações durante dias consecutivos e retorna o lucro máximo que pode ser obtido comprando e vendendo uma vez. 
// Você não pode vender antes de comprar.

int max_profit(int prices[], int size) {
    if (size < 2) {
        // Não é possível obter lucro com menos de dois preços
        return 0;
    }

    int min_price = prices[0]; // Inicializa o preço mínimo com o preço do primeiro dia
    int max_profit = 0; // Inicializa o lucro máximo como zero

    for (int i = 1; i < size; i++) {
        // Calcula o lucro potencial considerando o preço de compra no dia min_price e o preço de venda no dia atual prices[i]
        int current_profit = prices[i] - min_price;

            // Atualiza o lucro máximo se o lucro potencial for maior
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }

            // Atualiza o preço mínimo se encontrarmos um preço mais baixo
            if (prices[i] < min_price) {
            min_price = prices[i];
            }
    }

    return max_profit;
}

// 3.b. [2 pontos] Defina a função void rearrange_array(int arr[], int size), que rearranja o array arr de 
// modo que arr[0] <= arr[1] >= arr[2] <= arr[3] >= arr[4] ....

void rearrange_array(int arr[], int size){

    for(int i = 0; i < size -1; i++){
        for(int p = 0; p < size - i - 1; p++){
            if (arr[p] > arr[p + 1]) {
                aux[p] = arr[p];
                arr[p] = arr[p+1];
                arr[p+1] = aux[p];
            }
        }
   }

}