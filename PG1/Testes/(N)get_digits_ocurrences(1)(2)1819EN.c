
// JA COLOQUEI OS NUMEROS EM UM ARRAY, AGORA PRECISO VERIFICAR SE OS ARRAYS TEM PARES DE NUMEROS E INTERROMPER O ULTIMO LOOP 


#include <stdio.h>

void get_digits_ocurrences(int num, int ocurss[10]){

int digito;

    // Inicializa todos os arrays com o vlaor zero
    for (int i = 0; i < 10; i++) {
        ocurss[i] = 0;
    }


    while(num>0){
        digito = num % 10; // Obtem o ultimo digito
        ocurss[digito]++; // Incrementa cada digito 1 valor
        num /= 10;    // Remove o ultimo digito 
    }

}

int main() {
    int num;
    int ocorss[10];

    printf("Escolha um numero: ");
    scanf("%d", &num);

    // Chama a função para preencher o array com as ocorrências
    get_digits_ocurrences(num, ocorss);

    // Exibe as ocorrências
    for (int i = 0; i < 10; i++) {
        printf("Ocorrencias de %d: %d\n", i, ocorss[i]); 
    }


    get_digits_ocurrences(num, ocorss);
    for (int k = 0; k < 10; k++) {
        if (ocorss[k] == 2) {
            printf("Numero %d tem exatamente um par de digitos iguais.\n", num);
            printf("O numero %d se repete %d vezes\n", k, ocorss[k]);
            break;
        }
    }

    // Obetem o tamanho do numero, o contador sera o tamanho do numero e o num_auxiliar sera usado para nao alterar o valor do num
    int contador = 0;
    int num_auxiliar = num;
    while (num_auxiliar != 0) {
        num_auxiliar /= 10;
        contador++;
    }

    int aux, fim = contador - 1;
    int ordem[contador];

    // Obtem o ultimo numero e armazena no array (deixando o array na ordem inversa)
    for (int p = 0; p < contador; p++) {
        ordem[p] = num % 10;
        num /= 10;
    }

    // Inverte o array para a ordem correta (pq se o contador for um numero impar, da certo?)
    for (int k = 0; k < contador/2; k++) {
        aux = ordem[k];
        ordem[k] = ordem[fim];
        ordem[fim] = aux;
        fim--;
    }

    // Exibe o array na ordem certa
    printf("Array na ordem certa: ");
    for (int m = 0; m < contador; m++) {
        printf("%d", ordem[m]);
    }

    return 0;
}