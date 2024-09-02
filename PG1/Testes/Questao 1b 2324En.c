#include <stdio.h>
#include <stdbool.h>

int sum_divisors(int n){

int sum = 0;
    for(int i = 1; i < n; i++){

        if(n%i == 0){
            sum += i;
        }

    }

return sum;
}


bool friendly_numbers(int n1, int n2){
    if(sum_divisors(n1) == n2 && sum_divisors(n2) == n1){
        return true;
    }
return false;
}

int main(){

    int n1 = 220;
    int n2 = 284;

    if (friendly_numbers(n1, n2)){
        printf("Os numeros %d e %d sao amigos", n1, n2);
    }  else {
        printf("Os numeros %d e %d NAO sao amigos", n1, n2);
    }

return 0;
}