#include <stdio.h>

int inverts(int n){

    int n_aux = n, tam = 0;

    while(n_aux > 0){
        n_aux /= 10;
        tam++;
    }

    int order[tam];

    for(int i = 0; i < tam; i++){
        order[i] = n%10; 
        n /= 10;  
    }

    int num = 0;

    for(int p=0; p < tam; p++){
        num = num*10 + order[p];
    }

return num;
}

int main(){

    int n = 1259;

    int resp = inverts(n);

    printf("Numero invertido: %d", resp);

return 0;
}