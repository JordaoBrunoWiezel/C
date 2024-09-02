#include <stdio.h>
#include <math.h>

int main(){

    // Declaração de variáveis
    float v;    // Valor a ser convertido
    int i, f, j; // Unidades de medida inicial, final e índice para loop

    // Solicita ao usuário que insira o valor
    printf("Insira o valor: ");
    scanf("%f", &v);

    // Apresenta as opções de unidades suportadas
    printf("As unidades suportadas são:\n 1 - milímetro\n 2 - centímetro\n 3 - decímetro\n 4 - metro\n 5 - decâmetro\n"); 
    printf(" 6 - hectômetro\n 7 - quilômetro.\n");

    // Solicita ao usuário que insira as unidades inicial e final
    printf("Insira a unidade do valor inicial:\n ");
    scanf("%d", &i);
    printf("Insira a unidade para o valor final:\n ");
    scanf("%d", &f);
    
    // Condição para determinar a direção da conversão
    if (i < f){
        // Loop para converter para unidades menores
        for (j = i; j <= 7; j++){
            if (j == f) {
                break; // Sai do loop quando atinge a unidade desejada
            }
            v /= 10; // Divide o valor por 10 para converter para uma unidade menor
        }
        // Apresenta o valor convertido
        printf("O valor convertido é: %f", v);
    }
    else{
        // Loop para converter para unidades maiores
        for (j = i; j >= 1; j--){
            if (j == f) {
                break; // Sai do loop quando atinge a unidade desejada
            }
            v *= 10; // Multiplica o valor por 10 para converter para uma unidade maior
        }
        // Apresenta o valor convertido, arredondado para o inteiro mais próximo
        printf("O valor convertido é: %d", (int)round(v));
    }

    return 0; // Indica que o programa foi executado com sucesso
}

