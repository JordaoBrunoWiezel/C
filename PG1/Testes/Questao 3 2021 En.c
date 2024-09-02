#include <stdio.h>

int countWords(const char str[]){

    /* Fiz errado, aqui esta contando quantas letras tem, preciso saber quantas palavras
    int tam = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] != ' '){
            tam++;
        }
    }
    */

   int contador = 0;

    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            contador++; // Cada vez que houver espaços, significa que houve uma palavra anterior a esse espaço
       }
    
   }
   contador++; // Contar a ultima palavra


    /* Outra forma(melhor )

    int contador = 0;
    int dentroDaPalavra = 0;  // Flag para indicar se estamos dentro de uma palavra

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            // Se encontramos uma letra, incrementamos o contador apenas se não estivermos dentro de uma palavra
            if (dentroDaPalavra == 0) {
                contador++;
                dentroDaPalavra = 1;  // Marcamos que estamos dentro de uma palavra
            }
        } else {
            // Se encontramos um espaço, marcamos que não estamos mais dentro de uma palavra
            dentroDaPalavra = 0;
        }
    }
    */


return contador;
}

int main(){

    char str[] = "aaa ab npnv fdf fv g aff arhrr";

    int resp = countWords(str);

    printf("A palavra %s tem %d palavras", str, resp);

return 0;
}    