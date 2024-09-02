#include <stdio.h>
#include <stdbool.h>

int divider_qty(int n){

    int count = 0;
    for(int i=1; i <= n; i++){
        if(n%i==0){
        count++;
        }
    }

return count;
}

int main() {

    int numero, count;
    printf("Escreva um sequencia de numeros inteiros terminadoo por uma letra\nN? ");

    while (scanf("%d", &numero) == 1) {

        if(numero<1){
            printf("N? ");
		    continue;
        }
        count = divider_qty(numero);
        printf("Count: %d\nN? ", count);
    }


return 0;        
}