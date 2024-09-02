#include <stdio.h>
#include <stdnbool.h> 
#include <math.h>

// 1[4] a. [3] Implemente a função int sum_squares(int n) que retorna a soma dos quadrados dos números naturais até n.

int sum_squares(int n){
    
    int sum= 0;

    for(int i= 0; i <= n; i++){
        if(sum <= n){
            sum += i*i;
        }
    }

return sum;
}


/*
b. [1] Defina a função bool perfect_square_sum(int n1, int n2) que retorna true se a soma dos quadrados de n1 e n2 
for um quadrado perfeito. Dois números n1 e n2 são considerados perfeitos se a soma dos seus quadrados for um quadrado perfeito.

bool perfect_square_sum(int n1, int n2){

    int sum = pow(n1,2)+pow(n2,2);

    for(int i=0; i <= 9; i++){
        if(sqrt(sum) == i){
            return true;
        }
    }
    */

    //OU

bool perfect_square_sum(int n1, int n2){
    int sum = n1 * n1 + n2 * n2;
    int squareRoot = sqrt(sum);
    if(squareRoot * squareRoot == sum){
        return true;
    }
}
 


