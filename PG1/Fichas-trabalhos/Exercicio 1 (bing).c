#include <stdio.h>
#include <stdbool.h>

// a. Realize a função int prod_divisors(int n) que retorna o produto dos divisores próprios de n, 
// onde divisores próprios são todos os divisores positivos, exceto o próprio número.

int prod_divisors(int n){

    int prod = 0;

    for(int i = 1; i < n; i++){
        if(n%i==0){
            prod *= i;
        }
    }
return prod;
}

// b. Defina a função bool strange_numbers(int n1, int n2), que retorna true se n1 e n2 são números estranhos. 
//Dois números n1 e n2 são estranhos se o produto dos divisores próprios de cada um deles for igual ao outro número.
// Na realização desta função deverá utilizar a função prod_divisors realizada na alínea anterior.

bool strange_numbers(int n1, int n2){

    if(prod_divisors(n1) == n2 && prod_divisors(n2) == n1){
        return true;
    }
return false;
}