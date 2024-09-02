#include <stdio.h>

int saoIguais(int d[], int tamanho) {
    // Compara cada número com o primeiro
    for (int i = 1; i < tamanho; i++) {
        if (d[i] != d[0]) {
            return 0;  // Se um número for diferente, retorna falso
        }
    }

    return 1;  // Se todos os números forem iguais, retorna verdadeiro
}

int CrescenteDecrescente(int f[], int tamanho) {
    int crescente = 1;
    int decrescente = 1; 
    for (int i = 1; i < tamanho; i++) {
        if (f[i] > f[i-1]) {
            decrescente = 0;
        } else 
            if (f[i] < f[i-1]) {
            crescente = 0;
            }
    }

if(crescente){
    return 1;
} else if (decrescente){
    return -1;
} else {
    return 0;
}
}


int main() {
    int v[10000];
    int numero;
    int quantidade_numeros = 0;
printf("Digite uma sequência de dois ou mais inteiros naturais que termina com o valor 0: ");

     while (1) {
        if (scanf("%d", &numero) == 1) {

            if (numero == 0) {
                break;
            }
            v[quantidade_numeros] = numero;
            quantidade_numeros++;
        } else {
            break;
        }
     }

    if (quantidade_numeros < 2) {
        printf("Pelo menos dois números são necessários.\n");
        return 1;  // Encerra o programa se não forem fornecidos dois números
    }    

printf("Foram digitados %d numeros.\n", quantidade_numeros);

    if (saoIguais(v, quantidade_numeros)) {
        printf("Todos os numeros sao iguais.\n");
    } else {
        printf("Os numeros nao sao todos iguais.\n");

        if (CrescenteDecrescente(v, quantidade_numeros) == 1) {
            printf("Os numeros estao em ordem crescente.\n");
        } else if (CrescenteDecrescente(v, quantidade_numeros) == -1) {
            printf("Os numeros estao em ordem decrescente.\n");
        } else {
        printf("Os numeros estao em ordem arbitraria.\n");
        }
    }

return 0;
}
