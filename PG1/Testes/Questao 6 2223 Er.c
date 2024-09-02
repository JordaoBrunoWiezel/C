#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void char_invert_order (char str[], int idxLeft, int idxRight){

    char invert;

    while(idxLeft<=idxRight){
        invert = str[idxLeft];
        str[idxLeft] = str[idxRight];
        str[idxRight] = invert;
        idxLeft++;
        idxRight--;
    }

    printf("%s\n", str);

}

bool word_capicua(char word[]){

    int tam = strlen(word);
    char word_invertida[tam+1];

    // copiar a palavra original para a string invertida
    strcpy(word_invertida, word);

    char_invert_order(word_invertida, 0, strlen(word_invertida)-1);
    
    // verifica string1 é estritamente igual a string2, se sim retorna o valor "0"
    if(strcmp(word, word_invertida) == 0) {
        return true;
    }
return false;

}

int main() {

    char teste1[] = "Jordao Bruno Wiezel";
    char teste2[] = "radar";

    bool b1 = word_capicua(teste1);
    bool b2 = word_capicua(teste2);

    if(b1){
        printf("A palavra %s e capicua\n", teste1);
    } else{
        printf("A palavra %s nao e capicua\n", teste1);
    }

        if(b2){
        printf("A palavra %s e capicua", teste2);
    } else{
        printf("A palavra %s nao e capicua", teste2);
    }

return 0;    
}