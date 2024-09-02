#include <stdio.h>
#include <string.h>

int countWords(const char str[]){

/*
    //Apenas para conferir kk
    printf("%d\n", strlen(str));

    int contador1 = 0;

    //conta o numero de letras (com espaço)
    while(str[contador1] != '\0'){
        contador1++;
    }
    printf("Numero de letras (com espaco): %d\n", contador1);

    int contador2 = 0;

    // conta o numero de letras (sem espaço)
    while(str[contador2] != '\0'){
        if(str[contador2] != ' '){
            contador2++;
        }    
    }
    printf("Numero de letras (sem espaco): %d\n", contador2);
*/

    // Para contar apenas palavras
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


return contador;
}


int main(){

    char str[] = "Papai Noel";

    int num = countWords(str);

    printf("A frase %s tem %d palavras", str, num);

return 0;
}