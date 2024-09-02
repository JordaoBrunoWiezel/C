#include <stdio.h>
#include <stdbool.h>

bool is_prime(int n){

    if(n <= 1){
        return false;
    }

    for(int i = 2; i * i <= n; i++){
        if(n % i == 0){
            return false ;
        }
    }
return true;
}

int main() {
    int x = 2;

    if(is_prime(x)){
        printf("Numero primo");
    } else {
        printf("Numero nao primo");
    }
return 0;
}