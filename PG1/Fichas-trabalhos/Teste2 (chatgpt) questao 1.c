#include <stdio.h>`
#include <stdbool.h>

// 1a. [2 pontos] Implemente a função int prime_count(int start, int end) que conta o número de números primos 
// no intervalo fechado de start a end. Considere que start e end são inteiros positivos, e start é menor ou igual a end.

int is_prime(int p){

    for(int i = 0; i*i <= p; i++){
        if(p%i==0){
            return false;
        }
    }
return true;
}


int prime_count(int start, int end){

    int contador = 0;

    for(int i = start; i<= end; i++){
        if(is_prime(i)){
            contador++;
        }
    }
return contador;
}

// Defina a função bool twin_primes(int n1, int n2), que retorna verdadeiro se n1 e n2 são primos gêmeos. Dois números primos
// são considerados gêmeos se a diferença entre eles for 2. Por exemplo, (3, 5) e (11, 13) são pares de primos gêmeos.

bool twin_primes(int n1, int n2){
    
    if(is_prime(n1) && is_prime(n2) && abs(n1 - n2) == 2){
        return true;
    }
return false;
}