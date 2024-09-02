#include <stdio.h>
#include <ctype.h>

int remove_case_letter (const char src[], char dst[], char letter){

    int tam = 0;
    int contador = 0;

    for(int i=0; src[i] != '\0'; i++){
         if(src[i] != tolower(letter)){
            dst[tam] = src[i];
            tam++;
         } else {
            contador++;
         }
    }
dst[tam] = '\0';

return contador;
}

int main(){
    char src[] = "Jordao Bruno Wiezel";
    char dst[50];
    char letter = 'o';

    int contador = remove_case_letter(src, dst, letter);

    printf("Frase: %s\nQuantidade de letras '%c' retirardas: %d", dst, letter, contador);

return 0;
}