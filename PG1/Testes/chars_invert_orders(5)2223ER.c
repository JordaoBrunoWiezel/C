#include <stdio.h>
#include <string.h>

void chars_invert_orders(char str[], int idxLeft, int idxRight){
    
    /*
    int aux, fim, tam = strlen(str);

    fim = tam-1;

    for (int i = 0; i < tam/2; i++) { // abcd -> dbcd -> dbca -> dcca -> dcba 
        aux = str[i];
        str[i] = str[fim];
        str[fim] = aux;
        fim--;
    }
}
    */

        int aux;

        while (idxLeft < idxRight) {
        aux = str[idxLeft];
        str[idxLeft] = str[idxRight];
        str[idxRight] = aux;
        idxLeft++;
        idxRight--;
    }
}


int main() {
    char palavra[] = "Demenchuk Wiezel";

    chars_invert_orders(palavra, 0, strlen(palavra)-1);

    printf("%s", palavra);

return 0;
}