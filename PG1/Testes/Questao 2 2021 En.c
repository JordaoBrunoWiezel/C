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

int nextPalindrome(int n){

    int pal = 0;

    while(1){    
        pal = n++;
        if(pal == inverts(pal)){
            return pal;
        }
    }
    
}

int main(){
    int x = 1259;

    int resp = nextPalindrome(x);

    printf("O proximo palindromo e: %d", resp);

}
