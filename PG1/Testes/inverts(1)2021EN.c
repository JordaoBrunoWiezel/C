#include <stdio.h>

// Função que inverte um número
int inverts(int n) {
    int contador = 0;
    int n_auxiliar = n;

    while (n_auxiliar > 0) {
        n_auxiliar /= 10;
        contador++;
    }

    int order[contador];

    for (int i = 0; i < contador ; i++) {    
        order[i] = n % 10; // pega o ultimo numero
        n /= 10;          // Exclui o ultimo numero
    }


    // Primeira forma de digitar o numero inverso
    printf("Array na ordem inversa: ");
    for (int m = 0; m < contador; m++) {
        printf("%d", order[m]);
    }


    // Como a função é int, devo retornar o numero
    int inverted = 0;

    for (int i = 0; i < contador; i++) {
        inverted = inverted * 10 + order[i];
    }

    return inverted;
}

int main(){

    int num;
    printf("Escolha um numero: ");
    scanf("%d", &num);


    int resp = inverts(num);
    printf("\nNumero na ordem inversa: %d", resp);

return 0;     
}