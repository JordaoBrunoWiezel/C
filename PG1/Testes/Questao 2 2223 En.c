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
    int x;
    printf("N? ");
    while(scanf("%d", &x)== 1){
        if(x <= 0){
            printf("N? ");
            continue;
        }

        if(is_prime(x)){
            printf("Numero primo\nN? ");
        }else {
            printf("Numero nao primo\nN? ");
        }
        
    }

return 0;
}