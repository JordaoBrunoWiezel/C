#include <stdio.h>
#include <string.h>

void char_invert_order (char str[], int idxLeft, int idxRight){

    char invert;

    while(idxLeft<=idxRight){
        invert = str[idxLeft];
        str[idxLeft] = str[idxRight];
        str[idxRight] = invert;
        idxLeft++;
        idxRight--;
    }

    printf("%s", str);

}

int main() {

    char teste [] = "Jordao Bruno Wiezel";

    char_invert_order(teste, 0, strlen(teste)-1);

return 0;
}