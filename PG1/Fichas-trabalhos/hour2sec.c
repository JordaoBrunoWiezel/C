#include <stdio.h>
 int main(){

        int h, m, s;
        printf("Quantidade em horas, minutos e segundos: ");
        scanf("%d%d%d", &h,&m,&s);

        int H = h*3600;
        int M = m*60;

        int S = (H+M+s);

        printf("Quantidade em segundos: corresponde a: %d s\n", S);
return 0;
}