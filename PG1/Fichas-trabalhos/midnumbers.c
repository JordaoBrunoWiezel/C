#include <stdio.h>
#include <locale.h>

int main(){
    setlocale(LC_ALL,"Portuguese");

    int n, i = 0;
    int greater, lower;
    int sum = 0;
    printf("Digite 4 numeros: ");

    while (i<4){
       if (scanf("%d", &n) != 1 || n < 0) {
            printf("Entrada invalida. Por favor, insira um numero inteiro positivo.\n");
            // Limpar o buffer de entrada para evitar loops infinitos
            while (getchar() != '\n');
            continue; // Reinicia o loop para pedir um novo número
        }
            if (i == 0) {
                greater = n;
                lower = n;

            }  else {
                if (n > greater) {
                    greater = n;
                }
                if (n < lower) {
                    lower = n;
                }
            }    
            sum += n;
            i++;

    }
    
    printf("soma = %d\n", sum);
    printf("maior= %d\n", greater);
    printf("menor = %d\n", lower);
    float r = (sum - greater - lower)/2.0;
    printf("%.1f", r);

return 0;
}


