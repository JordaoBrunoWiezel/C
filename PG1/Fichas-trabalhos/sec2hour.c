#include <stdio.h>

int main(){

    int s;
    printf ("Quantidade em segundos: ");
    scanf ("%d", &s);

    int H = s/3600; 
    int M = (s - H*3600)/60;
    int S = s - (H*3600 + M*60);

    printf ("%d segundos correspondem a %dh, %dm e %ds", s, H, M, S);

return 0;

}