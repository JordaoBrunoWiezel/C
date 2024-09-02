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

bool phrase_is_capicua(char words[]){

    int tam = 0;
    char phrase_NoSpace[50];

    for(int i= 0; words[i] != '\0'; i++){
        if(words[i] != ' '){
            phrase_NoSpace[tam] = words[i];
            tam++;
        }
    }

    phrase_NoSpace[tam] = '\0';

    if(word_capicua(phrase_NoSpace)){
        return true;
    }
return false;
}

int main() {

    char teste[] = "anotaram a data da maratona";

    bool b = phrase_is_capicua(teste);

    if(b){
        printf("A frase %s e capicua\n", teste);
    } else{
        printf("A frase %s nao e capicua\n", teste);
    }

return 0;    
}