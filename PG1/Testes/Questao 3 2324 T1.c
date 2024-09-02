#include <stdio.h>

int str_biggest_word(const char src[]){

int contador1 = 0, contador2 = 0;
    for(int i= 0; src[i] != '\0'; i++){
        if(src[i] != ' '){
            contador1++;
                if(contador1 >= contador2){
                    contador2 = contador1;
                }
        } else {
            contador1 = 0;
        } 
    }
return contador2;
}

int main(){
    char teste[] = "jordao Bruno Wiezel";

    int resp = str_biggest_word(teste);

    printf("A maior palavra tem %d letras", resp);

return 0;
}