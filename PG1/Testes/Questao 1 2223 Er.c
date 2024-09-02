#include <stdio.h>

int dividers_qty(int n){

    int contador = 0;

    for(int i=1; i <= n; i++){
        if(n%i == 0){
            contador++;
        }
    }

return contador;
}

int main(){

    int x;
    printf("Escolha um numero: ");
    scanf("%d", &x);

    int num = dividers_qty(x);

    printf("O numero %d tem %d divisores", x, num);

return 0;
}