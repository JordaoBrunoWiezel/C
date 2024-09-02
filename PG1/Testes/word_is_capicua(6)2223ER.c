#include <stdio.h>
#include <string.h>
#include <stdbool.h>


void chars_invert_orders(char str[], int idxLeft, int idxRight){
    
        int aux;

        while (idxLeft < idxRight) {
        aux = str[idxLeft];
        str[idxLeft] = str[idxRight];
        str[idxRight] = aux;
        idxLeft++;
        idxRight--;
    }
}

bool word_is_capicua(char word[]) {
    int tam = strlen(word);
    char word_invertida[tam+1];
    int resp;

    // Modifica o conteudo da string
    strcpy(word_invertida, word);

    chars_invert_orders(word_invertida, 0, tam - 1);


    // verifica string1 é estritamente igual a string2, se sim retorna o valor "0"
    resp = strcmp(word_invertida, word);
    if(resp==0){
        return true;
    } else {
        return false;
    }
}

    /*
    // Verificar se a palavra invertida é igual à original
    for (int i = 0; i < tam; i++) {
        if (word[i] != word_invertida[i]) {
            return false;
        }
    }
    return true;
}
*/

int main() {
    char palavra1[] = "radar";
    char palavra2[] = "Demenchuk Wiezel";

    chars_invert_orders(palavra2, 0, strlen(palavra2)-1);

    printf("Palabra invertida: %s\n", palavra2);



    bool b1 = word_is_capicua(palavra1);
    bool b2 = word_is_capicua(palavra2);

    printf("A palavra 'radar' e capicua? %s\n", b1? "Sim" : "Nao");
    printf("A palavra 'Demenchuk Wiezel' e capicua? %s\n", b2 ? "Sim" : "Nao");

return 0;
}