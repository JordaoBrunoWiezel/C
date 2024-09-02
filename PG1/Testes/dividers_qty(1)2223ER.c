#include <stdio.h>

int divider_qty(int n){

    int count = 0;
    for(int i=1; i <= n; i++){
        if(n%i==0){
        count++;
        }
    }

return count;
}

int main(){

int x;
printf("Digite um numero: ");
scanf("%d", &x);

int count = divider_qty(x);

printf("%d tem %d divisores", x, count);

return 0;    
}