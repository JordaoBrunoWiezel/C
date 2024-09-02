#include <stdio.h>

int main(){

    float f;
    printf ("Indique a temperatura em graus fahrenheit: ");
    scanf("%f", &f);

    float c = (f-32)/1.8;
    
    printf("A temperatura em graus celsius é de: %.2f graus.\n", c);

return 0;
}