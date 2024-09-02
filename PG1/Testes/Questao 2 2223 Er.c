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
    printf("Conta todos os divisores de cada número lido e termina com um caracter nao di4gito\nN? ");
    while(scanf("%d", &x)==1){
        if(dividers_qty(x) < 1){
            printf("N? ");
            continue;
        }
        int num = dividers_qty(x);
        printf("count = %d\nN? ", num);
    }
return 0;
}